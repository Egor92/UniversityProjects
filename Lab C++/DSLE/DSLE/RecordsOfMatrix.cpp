#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "RecordsOfMatrix.h"

void PrintMatrix (double* A, double* B, int N)
{
	int I,J;
	for (I=0;I<N;I++)
	{
		for (J=0;J<N;J++)
			printf ("%3.2f ",A[I*N+J]);
		printf ("| %3.2f\n",B[I]);
	}		
}

void ManualInputMatrix (double* A, double* B, int N)
{
	int I,J;
	for (I=0;I<N;I++)
		for (J=0;J<N;J++)
		{
			printf ("Input A[%d,%d]=",I,J);
			scanf ("%lf",&A[I*N+J]);
		}

		for (I=0;I<N;I++)
		{
			printf ("Input B[%d]=",I);
			scanf ("%lf",&B[I]);
		}
}

void RandomInputMatrix (double* A, double* B, int N)
{
	int T1,T2,T;
	int I,J;
	printf ("\nInput the Min, the Max: ");
	scanf ("%d %d",&T1,&T2);
	if ((T1<=0)&&(T2>=0))
		T=abs(T1)+T2;
	else
		if ((T1<0)&&(T2<=0))
			T=abs(T1)-abs(T2);
		else
			T=T2-T1;
	srand((unsigned)time(NULL));
	for (I=0;I<N;I++)
		for (J=0;J<N;J++)
			A[I*N+J]=(double)rand() / (RAND_MAX + 1) * (T2 - T1) + T1;
	for (I=0;I<N;I++)
		B[I]=(double)rand() / (RAND_MAX + 1) * (T2 - T1) + T1;
}

void CopyMatrixA (double* A, double* B,int N)
{
	int I,J;
	for (I=0;I<N;I++)
		for (J=0;J<N;J++)
			B[I*N+J]=A[I*N+J];
}

void CopyMatrixB (double* A, double* B,int N)
{
	int I;
	for (I=0;I<N;I++)
		B[I]=A[I];
}

void ReplacementStrings (double* ACopy, double* BCopy, int Str1, int Str2, int* XIndex, int N)
{
	int I;
	double StrTemporary;
	for (I=0;I<N;I++)
	{
		StrTemporary=ACopy[Str2*N+I];
		ACopy[Str2*N+I]=ACopy[Str1*N+I];
		ACopy[Str1*N+I]=StrTemporary;
	}
	StrTemporary=BCopy[Str2];
	BCopy[Str2]=BCopy[Str1];
	BCopy[Str1]=StrTemporary;

	I=XIndex[Str2];
	XIndex[Str2]=XIndex[Str1];
	XIndex[Str1]=I;
	}

void ReplacementColumn (double* ACopy, int Str1, int Str2, int N)
{
	int I;
	double StrTemporary;
	for (I=0;I<N;I++)
	{
		StrTemporary=ACopy[N*I+Str2];
		ACopy[N*I+Str2]=ACopy[N*I+Str1];
		ACopy[N*I+Str1]=StrTemporary;
	}
}

void ReplacementStringsKrammer (double* ACopy, double* BCopy, int Str1, int Str2, int N)
{
	int I;
	double StrTemporary;
	for (I=0;I<N;I++)
	{
		StrTemporary=ACopy[Str2*N+I];
		ACopy[Str2*N+I]=ACopy[Str1*N+I];
		ACopy[Str1*N+I]=StrTemporary;
	}
}

void CalcDetKrammer (double* ACopy, double* BCopy, double* Det, int Str1, int N)
{
	int I,Index;
	for (I=0;I<N;I++) ACopy[I*N+Str1]=BCopy[I];
	for (I=0;I<N;I++)
	{
		SearchTheMax (ACopy, I, N, Index);
		if (Index != I)  ReplacementStringsKrammer (ACopy,BCopy,Index,I,N);
		DivisionOfStringsDown (ACopy,BCopy,N,I);
	}
	Det[Str1]=1;
	for (I=0;I<N;I++) Det[Str1]=Det[Str1]*ACopy[I*N+I];

}
void SearchTheMax (double* ACopy, int Column, int N, int &Index)
{
	int I;
	double Max;
	Max=abs(ACopy[Column*N+Column]);
	Index = Column;
	for (I=Column + 1;I<N;I++)
		if ((abs(ACopy[I*N+Column]))>Max)
		{
			Max=abs(ACopy[I*N+Column]);
			Index=I;
		}
	if (Max==0) Index=-1;
}

void DivisionOfStringsDown (double* ACopy, double* BCopy, int N, int Str)
{
	int I,J;
	double Div;
	//Columns
	for (I=(Str+1);I<N;I++)
	{
		//Divider calculation
		Div=ACopy[I*N+Str]/ACopy[Str*N+Str];
		//Strings	
		for (J=Str;J<N;J++)
		{
			ACopy[I*N+J]=ACopy[I*N+J]-ACopy[Str*N+J]*Div;
		}
		//Transformations over the Matrix B
		BCopy[I]=BCopy[I]-BCopy[Str]*Div;
	}
}

void DivisionOfStringsUp (double* ACopy, double* BCopy, int N, int Str)
{
	int I,J;
	double Div;
	//Columns
	for (I=(Str-1);I>(-1);I--)
	{
		//Divider calculation
		Div=ACopy[I*N+Str]/ACopy[Str*N+Str];
		//Strings	
		for (J=Str;J>(-1);J--)
		{
			ACopy[I*N+J]=ACopy[I*N+J]-ACopy[Str*N+J]*Div;
		}
		//Transformations over the Matrix B
		BCopy[I]=BCopy[I]-BCopy[Str]*Div;
	}
}

void Gauss (double* A, double* B, double* ACopy, double* BCopy, double* X, double* XChanging, int* XIndex, int N)
{
	int I,Index;
	double J;
	
	//Copy the Matrixes A and B
	CopyMatrixA (A,ACopy,N);
	CopyMatrixB (B,BCopy,N);
	
	for (I=0;I<N;I++)
	{
		SearchTheMax (ACopy, I, N, Index);
		if (Index==-1)
		{
			printf("The Matrix is degenerate\n");
			break;
		}
		if (Index != I)  ReplacementStrings (ACopy,BCopy,Index,I,XIndex,N);
		printf("\nReplacementStrings:\n"); //+++++++++++++
		PrintMatrix (ACopy,BCopy,N); //+++++++++++++	
		DivisionOfStringsDown (ACopy,BCopy,N,I);
		printf ("The Matrixes A and B after DivisionOfStrings:\n"); //+++++++++++++
		PrintMatrix (ACopy,BCopy,N); //+++++++++++++
	}

	printf("2nd half\n");

	for (I=(N-1);I>(-1);I--)
	{
		DivisionOfStringsUp (ACopy,BCopy,N,I);
		printf ("The Matrixes A and B after DivisionOfStrings:\n"); //+++++++++++++
		PrintMatrix (ACopy,BCopy,N); //+++++++++++++
	}

	
	for (I=0;I<N;I++)
	XChanging[I]=BCopy[I]/ACopy[I*N+I];

	for (I=0;I<N;I++)
	{
	X[I]=XChanging[XIndex[I]];
	}

}

void Kramer (double* A, double* B, double* ACopy, double* BCopy, double* X, int N)
{
	int I,J,K,Index,Znak;
	double DetA,*Det;

	Det=new double [N];

	Znak=1;
	//Copy the Matrixes A and B
	CopyMatrixA (A,ACopy,N);
	CopyMatrixB (B,BCopy,N);
	for (I=0;I<N;I++)
	{

		SearchTheMax (ACopy, I, N, Index);
		if (Index==-1)
		{
			printf("The Matrix is degenerate\n");
			break;
		}

		if (Index != I)  ReplacementStringsKrammer (ACopy,BCopy,Index,I,N);
		if (abs((Index-I)%2)==1) Znak=Znak*(-1);

		DivisionOfStringsDown (ACopy,BCopy,N,I);

	}

	DetA=Znak;
	for (I=0;I<N;I++) DetA=DetA*ACopy[I*N+I];
	printf("\nDetA: %f\n",DetA); //+++++++++++++

	for (I=0;I<N;I++)
	{
		printf("\n ***** Vychislenie N%i *****\n",I); //+++++++++++++

		Znak=1;
		//Copy the Matrixes A and B
		CopyMatrixA (A,ACopy,N);
		CopyMatrixB (B,BCopy,N);
		
		//Замена столбцов
		for (K=0;K<N;K++) ACopy[K*N+I]=BCopy[K];
		printf("\nZamena stolbtsov:\n"); //+++++++++++++
		PrintMatrix (ACopy,BCopy,N); //+++++++++++++	

		for (J=0;J<N;J++)
		{
			SearchTheMax (ACopy, J, N, Index);
			if (Index==-1)
			{
				printf("The Matrix is degenerate\n");
				break;
			}

			if (Index != J)  ReplacementStringsKrammer (ACopy,BCopy,Index,J,N);
			if (abs((Index-J)%2)==1) Znak=Znak*(-1);
			printf("\nZnak: %i\n",Znak); //+++++++++++++
			printf("\nReplacementStringsKrammer:\n"); //+++++++++++++
			PrintMatrix (ACopy,BCopy,N); //+++++++++++++	

			DivisionOfStringsDown (ACopy,BCopy,N,J);
			printf("\nDivisionOfStrings:\n"); //+++++++++++++
			PrintMatrix (ACopy,BCopy,N); //+++++++++++++
		}
		Det[I]=Znak;
		for (J=0;J<N;J++) Det[I]=Det[I]*ACopy[J*N+J];
		printf("\nDet[%i]: %f\n",I,Det[I]); //+++++++++++++
	}

	for (I=0;I<N;I++) X[I]=Det[I]/DetA;
}