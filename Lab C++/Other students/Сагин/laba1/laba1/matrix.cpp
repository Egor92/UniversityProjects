#include <stdio.h>
#include "matrix.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
void copyM (double* a, double* b,int n)
{
	int i,j;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			b[i*n+j]=a[i*n+j];
}
void printM (double* a, double* b, int n)
{
	int i,j;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
			printf ("%3.1lf ",a[i*n+j]);
		printf ("  %lf",b[i]); 
		printf ("\n");
	}
}
void scanM (double* a,  double* b, int n)
{
	int i,j;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
		{
			printf ("a[%d,%d]=",i,j);
			scanf ("%lf",&a[i*n+j]);
		}
	for (i=0;i<n;i++)
	{
		printf ("b[%d]=",i);
		scanf ("%lf",&b[i]);
	}
	
}
void rndM (double* a, double* b, int n)
{
	int t1,t2,t;
	int i,j;
	printf ("input min, max: ");
	scanf ("%d %d",&t1,&t2);
	if ((t1<=0)&&(t2>=0))
		t=abs(t1)+t2;
	else
		if ((t1<0)&&(t2<=0))
			t=abs(t1)-abs(t2);
		else
			t=t2-t1;
	srand((unsigned)time(NULL));
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			a[i*n+j]=(double)rand() / (RAND_MAX + 1) * (t2 - t1) + t1;
	for (i=0;i<n;i++)
		b[i]=(double)rand() / (RAND_MAX + 1) * (t2 - t1) + t1;
}

void multiM (double* a, double* x, double* b, int n)
{
	int i,j;
	double tmp;
	for (i=0;i<n;i++)
	{
		tmp=0;
		for (j=0;j<n;j++)
			tmp+=x[j]*a[i*n+j];
		b[i]=tmp;
	}

}
double oprM (double* a, int n)
{
	int i,j,k;
	int znak=1; //знак определителя
	double tmp;
	for (k=0;k<n-1;k++)
	{
		//находим максимальный по модулю элемент в столбце
		int  imax=k;
		for (i=k+1;i<n;i++)
			if (fabs(a[i*n+k])>fabs(a[n*imax+k])) imax=i;
		if (fabs(a[i*imax+k])==0) return 0;
		//ставим строку с максимальным элементом в начало
		if (imax!=k)
		{
			znak=znak*(-1);
				for (i=k;i<n;i++)
				{ 
					tmp=a[k*n+i];
					a[k*n+i]=a[imax*n+i];
					a[imax*n+i]=tmp;
				}
		}
		//зануляем столбец
		for (i=k+1;i<n;i++)
		{
			tmp=a[i*n+k]/a[k*n+k];
			for (j=k;j<n;j++)
				a[i*n+j]-=tmp*a[k*n+j];
		}	
	}
	tmp=1;
	for (i=0;i<n;i++)
		tmp=tmp*a[i*n+i];
	tmp=tmp*znak;
	return tmp;
}
void gausM (double* a, double* b, double* x, int n)
{
	int i,j,k;
	double tmp;
	//приводим к треугольному виду
	for (k=0;k<n-1;k++)
	{
		int  imax=k;
		for (i=k+1;i<n;i++)
			if (fabs(a[i*n+k])>fabs(a[n*imax+k])) imax=i;
		if (imax!=k)
			for (i=k;i<n;i++)
			{ 
				tmp=a[k*n+i];
				a[k*n+i]=a[imax*n+i];
				a[imax*n+i]=tmp;
			}
		tmp=b[k];
		b[k]=b[imax];
		b[imax]=tmp;
		for (i=k+1;i<n;i++)
		{
			tmp=a[i*n+k]/a[k*n+k];
			b[i]-=tmp*b[k];
			for (j=k;j<n;j++)
				a[i*n+j]-=tmp*a[k*n+j];
		}
	}
	x[n-1]=b[n-1]/a[(n-1)*n+(n-1)];
	for (i=n-2;i>=0;i--)
	{
		tmp=b[i];
		for (j=n-1;j>i;j--)
			tmp-=x[j]*a[i*n+j];
		x[i]=tmp/a[i*n+i];
	}
}
void kramerM (double* a, double* acopy, double* b, double* x, int n)
{
	int i,j;
	double tmp1,tmp2;
	copyM (a, acopy, n);
	tmp1=oprM (a,n);
	copyM (acopy, a, n);
	for (i = 0;i < n; i++)
	{
		for (j=0;j<n;j++)
			a[j*n+i]=b[j];
		tmp2=oprM(a,n);
		copyM (acopy, a, n);
		x[i]=tmp2/tmp1;
	}
}
