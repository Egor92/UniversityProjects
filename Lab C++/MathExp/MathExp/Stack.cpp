#pragma once
#include "stdafx.h"
#include "stack.h"

stack::stack (int Size, double *A){	//������� ����
	this->Size = Size;
	this->A = A;
	Dim = -1;
}

void stack::Put (double E){	//�������� ������ �� ������� �����
	if ( !IsFull() ) {
		Dim++;
		A[Dim] = E;
	}
}

double stack::Get (){		//������ ������ �� �����
	double I;
	if ( !IsEmpty() ){
		I = A[Dim];
		Dim--;
	 return I;
	}
}

int stack::GetInt (){		//������ ������ �� �����
	int I;
	if ( !IsEmpty() ){
		I = A[Dim];
		Dim--;
	 return I;
	}
}
double stack::See(){		//���������� ������ �� ������� �����
	if ( !IsEmpty() ){
		return A[Dim];
	}}

bool stack::IsFull (){		//�������� �� ������� �����
	if ( Dim == (Size - 1) ) return 1;
}

bool stack::IsEmpty (){		//�������� �� ������� �����
	if ( Dim == -1 ) return 1;
}

void stack::DeleteAll (){		//������� ��� ������ �� �����
	Dim = -1;
}