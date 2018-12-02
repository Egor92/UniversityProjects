//#define PRINT_TO_CONSOLE 1

#include <iostream>
#include <math.h>
#include <fstream>
#include <cmath>
#include <stdio.h>
#ifdef PRINT_TO_CONSOLE
#include <conio.h>
#endif
#include "timer.h"
#include <cilk/cilk.h>

using namespace std;

#define M_PI 3.1415926535897932384626433832795

double uFunction(double x, double t)
{
	// source U function
	return t*t*sin(M_PI*x);
}

double dudtFunction(double x, double t)
{
	// derivative of U with respect to T
	return 2 * t*sin(M_PI*x);
}

double d2udx2Function(double x, double t)
{
	// the second derivative of U with respect to X
	return -t*t*M_PI*M_PI*sin(M_PI*x);
}

double d2udt2Function(double x, double t)
{
	// the second derivative of U with respect to X
	return 2 * sin(M_PI*x);
}

double fFunction(double x, double t)
{
	return d2udt2Function(x, t) - d2udx2Function(x, t);
}

int main(int argc, const char * argv[])
{
	int nx = 1000;
	int nt = 1000;


#ifndef PRINT_TO_CONSOLE
	std::ifstream ifs(argv[1]);
	if (!ifs.fail()) {
		ifs >> nx;
		ifs >> nt;
		ifs.close();
	}
#endif


	// initializing
	const double minX = 0;
	const double maxX = 1.0;

	const double minT = 0;
	const double maxT = 1.0e-2;

	double xH = (maxX - minX) / nx;
	double tH = (maxT - minT) / nt;

	double** uValues = new double*[nx + 1];    // uValues[x][t] -> x.[0, nx], t.[0, nt]
	for (int i = 0; i <= nx; i++) {
		uValues[i] = new double[nt + 1];
	}

	double * k1 = new double[nx + 1];
	double * k2 = new double[nx + 1];
	double * k3 = new double[nx + 1];
	double * k4 = new double[nx + 1];

	k1[0] = k1[nx] = 0;
	k2[0] = k2[nx] = 0;
	k3[0] = k3[nx] = 0;
	k4[0] = k4[nx] = 0;

	double** uzValues = new double*[nx + 1];    // uValues[x][t] -> x.[0, nx], t.[0, nt]
	for (int i = 0; i <= nx; i++) {
		uzValues[i] = new double[nt + 1];
	}

	// for z calculation
	double * kz1 = new double[nx + 1];
	double * kz2 = new double[nx + 1];
	double * kz3 = new double[nx + 1];
	double * kz4 = new double[nx + 1];

	kz1[0] = kz1[nx] = 0;
	kz2[0] = kz2[nx] = 0;
	kz3[0] = kz3[nx] = 0;
	kz4[0] = kz4[nx] = 0;

	// initializing boundary conditions
	// t = 0
	for (int i = 0; i <= nx; i++) {
		uValues[i][0] = uFunction(minX + i * xH, minT);
	}
	// x = 0
	for (int i = 0; i <= nt; i++) {
		uValues[0][i] = uFunction(minX, minT + i * tH);
	}
	// x = 11
	for (int i = 0; i <= nt; i++) {
		uValues[nx][i] = uFunction(maxX, minT + i * tH);
	}

	// intializing the first derevative z = du/dt
	for (int i = 0; i <= nx; i++) {
		uzValues[i][0] = dudtFunction(minX + i * xH, minT);
	}

	double maxDiff = 0;
	double xH2Inv = 1.0 / (xH * xH);


#ifndef PRINT_TO_CONSOLE
	Timer timer;
	timer.start();
#endif

	// solving system of equations
	for(int ti = 1; ti <= nt; ti++) {
		double t = minT + ti * tH;
		const double tH2 = tH / 2.0;

		k1[1] = (uValues[2][ti - 1]
			- 2 * uValues[1][ti - 1]
			+ uFunction(minX, t - tH)) * xH2Inv
			+ fFunction(minX + xH, t - tH);

		k1[nx - 1] = (uFunction(maxX, t - tH)
			- 2 * uValues[nx - 1][ti - 1]
			+ uValues[nx - 2][ti - 1]) * xH2Inv
			+ fFunction(maxX - xH, t - tH);

		cilk_for(int xi = 2; xi < nx - 1; xi++)
		{
			double x = minX + xi * xH;
			k1[xi] = (uValues[xi + 1][ti - 1]
				- 2 * uValues[xi][ti - 1]
				+ uValues[xi - 1][ti - 1]) * xH2Inv
				+ fFunction(x, t - tH);
		}

		// calculation kz1 for the first system of equations 
		////////////////////////////////////////////////////////////////////// 

		cilk_for(int xi = 1; xi < nx; xi++)
			kz1[xi] = uzValues[xi][ti - 1];

		/////////////////////////////////////////////////////////////////////

		k2[1] = ((uValues[2][ti - 1] + tH * kz1[2] / 2.0)
			- 2 * (uValues[1][ti - 1] + tH * kz1[1] / 2.0)
			+ (uFunction(minX, (t - tH) + tH / 2.0))) * xH2Inv
			+ fFunction(minX + xH, (t - tH) + tH / 2.0);

		k2[nx - 1] = ((uFunction(maxX, (t - tH) + tH / 2.0))
			- 2 * (uValues[nx - 1][ti - 1] * xH2Inv + tH * kz1[nx - 1] * xH2Inv / 2.0)
			+ (uValues[nx - 2][ti - 1] * xH2Inv + tH * kz1[nx - 2] * xH2Inv / 2.0))
			+ fFunction(maxX - xH, (t - tH) + tH / 2.0);

		cilk_for(int xi = 2; xi < nx - 1; xi++)
		{
			double x = minX + xi * xH;
			k2[xi] = ((uValues[xi + 1][ti - 1] + tH2 * kz1[xi + 1])
				- 2 * (uValues[xi][ti - 1] + tH2 * kz1[xi])
				+ (uValues[xi - 1][ti - 1] + tH2 * kz1[xi - 1])) * xH2Inv
				+ fFunction(x, (t - tH) + tH2);
		}

		// calculating kz2 for the first system of equations
		///////////////////////////////////////////////////////////////////////////////

		cilk_for(int xi = 1; xi < nx; xi++)
			kz2[xi] = uzValues[xi][ti - 1] + tH2 * k1[xi];

		///////////////////////////////////////////////////////////////////////////////

		k3[1] = ((uValues[2][ti - 1] + tH2 * kz2[2])
			- 2 * (uValues[1][ti - 1] + tH2 * kz2[1])
			+ (uFunction(minX, (t - tH) + tH2))) * xH2Inv
			+ fFunction(minX + xH, (t - tH) + tH / 2.0);

		k3[nx - 1] = ((uFunction(maxX, (t - tH) + tH2))
			- 2 * (uValues[nx - 1][ti - 1] + tH2 * kz2[nx - 1])
			+ (uValues[nx - 2][ti - 1] + tH2 * kz2[nx - 2])) * xH2Inv
			+ fFunction(maxX - xH, (t - tH) + tH2);

		cilk_for(int xi = 2; xi < nx - 1; xi++)
		{
			double x = minX + xi * xH;
			k3[xi] = ((uValues[xi + 1][ti - 1] + tH2 * kz2[xi + 1])
				- 2 * (uValues[xi][ti - 1] + tH2 * kz2[xi])
				+ (uValues[xi - 1][ti - 1] + tH2 * kz2[xi - 1])) * xH2Inv
				+ fFunction(x, (t - tH) + tH2);
		}

		// calculating kz3 for the first system of equations
		///////////////////////////////////////////////////////////////////////////////

		cilk_for(int xi = 1; xi < nx; xi++)
		{
			double x = minX + xi * xH;
			kz3[xi] = uzValues[xi][ti - 1] + tH2 * k2[xi];
		}

		///////////////////////////////////////////////////////////////////////////////

		k4[1] = ((uValues[2][ti - 1] * xH2Inv + tH * kz3[2] * xH2Inv)
			- 2 * (uValues[1][ti - 1] * xH2Inv + tH * kz3[1] * xH2Inv)
			+ (uFunction(minX, (t - tH) + tH) * xH2Inv))
			+ fFunction(minX + xH, (t - tH) + tH);

		k4[nx - 1] = ((uFunction(maxX, (t - tH) + tH))
			- 2 * (uValues[nx - 1][ti - 1] * xH2Inv + tH * kz3[nx - 1] * xH2Inv)
			+ (uValues[nx - 2][ti - 1] * xH2Inv + tH * kz3[nx - 2] * xH2Inv))
			+ fFunction(minX + xH, (t - tH) + tH);

		cilk_for(int xi = 2; xi < nx - 1; xi++)
		{
			double x = minX + xi * xH;
			k4[xi] = ((uValues[xi + 1][ti - 1] + tH * kz3[xi + 1])
				- 2 * (uValues[xi][ti - 1] + tH * kz3[xi])
				+ (uValues[xi - 1][ti - 1] + tH * kz3[xi - 1])) * xH2Inv
				+ fFunction(x, (t - tH) + tH);
		}

		// calculating kz4 for the first system of equations
		///////////////////////////////////////////////////////////////////////////////

		cilk_for(int xi = 1; xi < nx; xi++)
			kz4[xi] = uzValues[xi][ti - 1] + tH * k3[xi];

		///////////////////////////////////////////////////////////////////////////////

		// calculating for all equations (components of vector) at fixed Ti
		cilk_for(int xi = 1; xi < nx; xi++)
		{
			double x = minX + xi * xH;

			// вычисляем выражения для первой системы, которые и являются ответом (n штук)
			// при их вычислении (точнее для вычисления kz используем выражения из  uzValues)  
			uValues[xi][ti] = uValues[xi][ti - 1] + (tH / 6.0) * (kz1[xi] + 2 * kz2[xi] + 2 * kz3[xi] + kz4[xi]);

			uzValues[xi][ti] = uzValues[xi][ti - 1] + (tH / 6.0) * (k1[xi] + 2 * k2[xi] + 2 * k3[xi] + k4[xi]);


			// last step by time => calc discrepancy
			if (ti == nt) {
				double diff = fabs(uValues[xi][ti] - uFunction(x, t));
				if (diff > maxDiff) {
					maxDiff = diff;
				}

#ifdef PRINT_TO_CONSOLE
				std::cout << "calc: " << uValues[xi][ti] << "; real: " << uFunction(x, t) << std::endl;
#endif
			}
		}
	}

#ifndef PRINT_TO_CONSOLE
	timer.stop();
	std::ofstream timeLog;
	timeLog.open(argv[3]);
	timeLog << timer.getElapsed();


	std::ofstream ofs(argv[2]);
	std::cout << maxDiff << std::endl;
	ofs << maxDiff;
	ofs.close();
#endif


#ifdef PRINT_TO_CONSOLE
	std::cout << "maxDiff = " << maxDiff << std::endl;
#endif


	delete[] k1;
	delete[] k2;
	delete[] k3;
	delete[] k4;

	delete[] kz1;
	delete[] kz2;
	delete[] kz3;
	delete[] kz4;

	for (int i = 0; i <= nx; i++) {
		delete[] uValues[i];
	}

	delete uValues;

	for (int i = 0; i <= nx; i++) {
		delete[] uzValues[i];
	}

	delete uzValues;

#ifdef PRINT_TO_CONSOLE
	_getch();
#endif

	return 0;
}