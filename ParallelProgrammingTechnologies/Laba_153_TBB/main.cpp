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
#include <tbb/parallel_for.h>
#include <tbb/blocked_range.h>

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

class K1
{
public:
	K1(double * k1_, const double ** uValues_, double minX_, double xH_, double xH2Inv_,
		double t_, double tH_, int ti_) :
		k1(k1_), uValues(uValues_), minX(minX_), xH(xH_), xH2Inv(xH2Inv_),
		t(t_), tH(tH_), ti(ti_)
	{
	}

	void operator()(const tbb::blocked_range<int> & range) const
	{
		for (int xi = range.begin(), end = range.end(); xi != end; ++xi)
		{
			double x = minX + xi * xH;
			k1[xi] = (uValues[xi + 1][ti - 1]
				- 2 * uValues[xi][ti - 1]
				+ uValues[xi - 1][ti - 1]) * xH2Inv
				+ fFunction(x, t - tH);
		}
	}

private:
	double * k1;
	const double ** uValues;
	double minX, xH, xH2Inv, t, tH;
	int ti;
};

class K2
{
public:
	K2(double * k2_, const double * kz1_, const double ** uValues_, double minX_, double xH_, double xH2Inv_,
		double t_, double tH_, int ti_) :
		k2(k2_), kz1(kz1_), uValues(uValues_), minX(minX_), xH(xH_), xH2Inv(xH2Inv_),
		t(t_), tH(tH_), ti(ti_)
	{
	}

	void operator()(const tbb::blocked_range<int> & range) const
	{
		for (int xi = range.begin(), end = range.end(); xi != end; ++xi)
		{
			double x = minX + xi * xH;
			k2[xi] = ((uValues[xi + 1][ti - 1] + tH * kz1[xi + 1] / 2.0)
				- 2 * (uValues[xi][ti - 1] + tH * kz1[xi] / 2.0)
				+ (uValues[xi - 1][ti - 1] + tH * kz1[xi - 1] / 2.0)) * xH2Inv
				+ fFunction(x, (t - tH) + tH / 2.0);
		}
	}

private:
	double * k2;
	const double * kz1;
	const double ** uValues;
	double minX, xH, xH2Inv, t, tH;
	int ti;
};

class K3
{
public:
	K3(double * k3_, const double * kz2_, const double ** uValues_, double minX_, double xH_, double xH2Inv_,
		double t_, double tH_, int ti_) :
		k3(k3_), kz2(kz2_), uValues(uValues_), minX(minX_), xH(xH_), xH2Inv(xH2Inv_),
		t(t_), tH(tH_), ti(ti_)
	{
	}

	void operator()(const tbb::blocked_range<int> & range) const
	{
		for (int xi = range.begin(), end = range.end(); xi != end; ++xi)
		{
			double x = minX + xi * xH;
			k3[xi] = ((uValues[xi + 1][ti - 1] + tH * kz2[xi + 1] / 2.0)
				- 2 * (uValues[xi][ti - 1] + tH * kz2[xi] / 2.0)
				+ (uValues[xi - 1][ti - 1] + tH * kz2[xi - 1] / 2.0)) * xH2Inv
				+ fFunction(x, (t - tH) + tH / 2.0);
		}
	}

private:
	double * k3;
	const double * kz2;
	const double ** uValues;
	double minX, xH, xH2Inv, t, tH;
	int ti;
};

class K4
{
public:
	K4(double * k4_, const double * kz3_, const double ** uValues_, double minX_, double xH_, double xH2Inv_,
		double t_, double tH_, int ti_) :
		k4(k4_), kz3(kz3_), uValues(uValues_), minX(minX_), xH(xH_), xH2Inv(xH2Inv_),
		t(t_), tH(tH_), ti(ti_)
	{
	}

	void operator()(const tbb::blocked_range<int> & range) const
	{
		for (int xi = range.begin(), end = range.end(); xi != end; ++xi)
		{
			double x = minX + xi * xH;
			k4[xi] = ((uValues[xi + 1][ti - 1] + tH * kz3[xi + 1])
				- 2 * (uValues[xi][ti - 1] + tH * kz3[xi])
				+ (uValues[xi - 1][ti - 1] + tH * kz3[xi - 1])) * xH2Inv
				+ fFunction(x, (t - tH) + tH);
		}
	}

private:
	double * k4;
	const double * kz3;
	const double ** uValues;
	double minX, xH, xH2Inv, t, tH;
	int ti;
};

class Kz1
{
public:
	Kz1(double * kz1_, const double ** uzValues_, int ti_) :
		kz1(kz1_), uzValues(uzValues_), ti(ti_)
	{
	}

	void operator()(const tbb::blocked_range<int> & range) const
	{
		for (int xi = range.begin(), end = range.end(); xi != end; ++xi)
			kz1[xi] = uzValues[xi][ti - 1];
	}

private:
	double * kz1;
	const double ** uzValues;
	int ti;
};

class Kz2
{
public:
	Kz2(double * kz2_, const double * k1_, const double ** uzValues_, double tH_, int ti_) :
		kz2(kz2_), k1(k1_), uzValues(uzValues_), tH(tH_), ti(ti_)
	{
	}

	void operator()(const tbb::blocked_range<int> & range) const
	{
		for (int xi = range.begin(), end = range.end(); xi != end; ++xi)
			kz2[xi] = uzValues[xi][ti - 1] + tH * k1[xi] / 2.0;
	}

private:
	double * kz2;
	const double * k1;
	const double ** uzValues;
	double tH;
	int ti;
};

class Kz3
{
public:
	Kz3(double * kz3_, const double * k2_, const double ** uzValues_, double tH_, int ti_) :
		kz3(kz3_), k2(k2_), uzValues(uzValues_), tH(tH_), ti(ti_)
	{
	}

	void operator()(const tbb::blocked_range<int> & range) const
	{
		for (int xi = range.begin(), end = range.end(); xi != end; ++xi)
			kz3[xi] = uzValues[xi][ti - 1] + tH * k2[xi] / 2.0;
	}

private:
	double * kz3;
	const double * k2;
	const double ** uzValues;
	double tH;
	int ti;
};

class Kz4
{
public:
	Kz4(double * kz4_, const double * k3_, const double ** uzValues_, double tH_, int ti_) :
		kz4(kz4_), k3(k3_), uzValues(uzValues_), tH(tH_), ti(ti_)
	{
	}

	void operator()(const tbb::blocked_range<int> & range) const
	{
		for (int xi = range.begin(), end = range.end(); xi != end; ++xi)
			kz4[xi] = uzValues[xi][ti - 1] + tH * k3[xi];
	}

private:
	double * kz4;
	const double * k3;
	const double ** uzValues;
	double tH;
	int ti;
};

class UValues
{
public:
	UValues(double ** uValues_, const double * k1_, const double * k2_,
		const double * k3_, const double * k4_, double tH_, int ti_) :
		uValues(uValues_), k1(k1_), k2(k2_), k3(k3_), k4(k4_), tH(tH_), ti(ti_)
	{
	}

	void operator() (const tbb::blocked_range<int> & range) const
	{
		for (int xi = range.begin(), end = range.end(); xi != end; ++xi)
			uValues[xi][ti] = uValues[xi][ti - 1] + (tH / 6.0) * (k1[xi] + 2 * k2[xi] + 2 * k3[xi] + k4[xi]);
	}

private:
	double ** uValues;
	const double * k1, *k2, *k3, *k4;
	double tH;
	int ti;
};

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
	for (int ti = 1; ti <= nt; ti++) {
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

		tbb::parallel_for(tbb::blocked_range<int>(2, nx - 1), K1(k1, (const double **)uValues, minX, xH, xH2Inv, t, tH, ti));

		// calculation kz1 for the first system of equations 
		////////////////////////////////////////////////////////////////////// 

		tbb::parallel_for(tbb::blocked_range<int>(1, nx), Kz1(kz1, (const double **)uzValues, ti));

		/////////////////////////////////////////////////////////////////////

		k2[1] = ((uValues[2][ti - 1] + tH * kz1[2] / 2.0)
			- 2 * (uValues[1][ti - 1] + tH * kz1[1] / 2.0)
			+ (uFunction(minX, (t - tH) + tH / 2.0))) * xH2Inv
			+ fFunction(minX + xH, (t - tH) + tH / 2.0);

		k2[nx - 1] = ((uFunction(maxX, (t - tH) + tH / 2.0))
			- 2 * (uValues[nx - 1][ti - 1] * xH2Inv + tH * kz1[nx - 1] * xH2Inv / 2.0)
			+ (uValues[nx - 2][ti - 1] * xH2Inv + tH * kz1[nx - 2] * xH2Inv / 2.0))
			+ fFunction(maxX - xH, (t - tH) + tH / 2.0);

		tbb::parallel_for(tbb::blocked_range<int>(2, nx - 1), K2(k2, (const double *)kz1, (const double **)uValues, minX, xH, xH2Inv, t, tH, ti));

		// calculating kz2 for the first system of equations
		///////////////////////////////////////////////////////////////////////////////

		tbb::parallel_for(tbb::blocked_range<int>(1, nx), Kz2(kz2, (const double *)k1, (const double **)uzValues, tH, ti));

		for (int xi = 1; xi < nx; xi++)
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

		tbb::parallel_for(tbb::blocked_range<int>(2, nx - 1), K3(k3, (const double *)kz2, (const double **)uValues, minX, xH, xH2Inv, t, tH, ti));

		// calculating kz3 for the first system of equations
		///////////////////////////////////////////////////////////////////////////////

		tbb::parallel_for(tbb::blocked_range<int>(1, nx), Kz3(kz3, (const double *)k2, (const double **)uzValues, tH, ti));

		///////////////////////////////////////////////////////////////////////////////

		k4[1] = ((uValues[2][ti - 1] * xH2Inv + tH * kz3[2] * xH2Inv)
			- 2 * (uValues[1][ti - 1] * xH2Inv + tH * kz3[1] * xH2Inv)
			+ (uFunction(minX, (t - tH) + tH) * xH2Inv))
			+ fFunction(minX + xH, (t - tH) + tH);

		k4[nx - 1] = ((uFunction(maxX, (t - tH) + tH))
			- 2 * (uValues[nx - 1][ti - 1] * xH2Inv + tH * kz3[nx - 1] * xH2Inv)
			+ (uValues[nx - 2][ti - 1] * xH2Inv + tH * kz3[nx - 2] * xH2Inv))
			+ fFunction(minX + xH, (t - tH) + tH);

		tbb::parallel_for(tbb::blocked_range<int>(2, nx - 1), K4(k4, (const double *)kz3, (const double **)uValues, minX, xH, xH2Inv, t, tH, ti));

		// calculating kz4 for the first system of equations
		///////////////////////////////////////////////////////////////////////////////

		tbb::parallel_for(tbb::blocked_range<int>(1, nx), Kz4(kz4, (const double *)k3, (const double **)uzValues, tH, ti));

		///////////////////////////////////////////////////////////////////////////////

		// calculating for all equations (components of vector) at fixed Ti
		tbb::parallel_for(tbb::blocked_range<int>(1, nx), UValues(uValues, (const double *)kz1, (const double *)kz2,
			(const double *)kz3, (const double *)kz4, tH, ti));
		tbb::parallel_for(tbb::blocked_range<int>(1, nx), UValues(uzValues, (const double *)k1, (const double *)k2,
			(const double *)k3, (const double *)k4, tH, ti));

		// last step by time => calc discrepancy
		if (ti == nt)
		{
			for (int xi = 1; xi < nx; xi++)
			{
				double x = minX + xi * xH;

				double diff = fabs(uValues[xi][ti] - uFunction(x, t));
				if (diff > maxDiff)
					maxDiff = diff;
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