#include <stdio.h>
#include <conio.h>
#include "RecordsOfMatrix.h"

int N,Menu,I,J;
int Index;
double* A;
double* B;
double* ACopy;
double* BCopy;
double* X;
double* XChanging;
int* XIndex;

int main()
{
	A=new double [N*N];
	B=new double [N];
	ACopy=new double [N*N];
	BCopy=new double [N];
	X=new double [N];
	XChanging=new double [N];
	XIndex=new int [N];

	//The main menu
	printf ("Decision of Systems of Linear's Equation\n");
	printf ("Input the dimension of Matrix\n-> ");
	scanf ("%d",&N);
	printf ("\n");
	printf ("Select the type of filling of Matrix:\n[1] Manual input\n[2] Random input\n-> ");
	scanf ("%d",&Menu);
	printf ("\n");
	if (Menu==1) ManualInputMatrix (A,B,N); //Manual Input of Matrix
			else RandomInputMatrix (A,B,N); //Random Input of Matrix
	for (I=0;I<N;I++) XIndex[I]=I;
	printf ("\nThe Matrixes A and B:\n");
	PrintMatrix (A,B,N);

	printf ("\n");
	printf ("Select the type of a finding of the matrix's decision\n[1] Method of Gauss\n[2] Method of Krammer\n-> ");
	scanf ("%d",&Menu);
	printf ("\n");
	if (Menu==1) Gauss (A,B,ACopy,BCopy,X,XChanging,XIndex,N); //Method of Gauss
	else Kramer (A,B,ACopy,BCopy,X,N); //Method of Krammer

	//Print Matrix X:
	printf ("\nMatrix X:\n");
	for (I=0;I<N;I++)
		printf ("X[%i]= %3.2f\n",I,X[I]);

	getch();
	return 0;
}
