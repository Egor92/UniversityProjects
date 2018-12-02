#include <stdio.h>
#include <conio.h>
#include "matrix.h"

int n,pm;
double* a;
double* acopy;
double* b1;
double* b;
double* x;
int main()
{
	int i,j;
	printf ("input n: ");
	scanf ("%d",&n);
	a=new double [n*n];
	acopy=new double [n*n];
	x=new double [n];
	b=new double [n];
	b1=new double [n];
	printf ("1 - ru4noy vvod\n2 - slu4ayniy\n");
	scanf ("%d",&pm);
	if (pm==1) scanM (a,b,n);
	else rndM (a,b,n);
	copyM (a,acopy,n);
	for (i=0;i<n;i++);
		b1[i]=b[i];
	printf ("A=\n");
	printM (a,b,n);
	printf ("\n");
	double d=oprM(a,n);
	copyM (acopy,a,n);
	if (d!=0)
	{
		kramerM (a,acopy,b,x,n);
		printM (a,b,n);
		printf ("\n");
		printf ("x=\n");
		for (i=0;i<n;i++)
			printf ("%lf ",x[i]);
		printf ("\n");
	}
	else
		printf ("matrica virogdennaya");
	printf ("\n");
	copyM (acopy,a,n);
	multiM (a,x,b1,n);
	printf ("A*x=\n");
	for (i=0;i<n;i++)
			printf ("%lf ",b1[i]);
	
	
	
	delete [] a;
	delete [] acopy;
	delete [] b;
	delete [] b1;
	delete [] x;
	getch();
}