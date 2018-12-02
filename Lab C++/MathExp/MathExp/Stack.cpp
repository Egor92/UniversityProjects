#pragma once
#include "stdafx.h"
#include "stack.h"

stack::stack (int Size, double *A){	//Создать стек
	this->Size = Size;
	this->A = A;
	Dim = -1;
}

void stack::Put (double E){	//Положить данное на вершину стека
	if ( !IsFull() ) {
		Dim++;
		A[Dim] = E;
	}
}

double stack::Get (){		//Изъять данное из стека
	double I;
	if ( !IsEmpty() ){
		I = A[Dim];
		Dim--;
	 return I;
	}
}

int stack::GetInt (){		//Изъять данное из стека
	int I;
	if ( !IsEmpty() ){
		I = A[Dim];
		Dim--;
	 return I;
	}
}
double stack::See(){		//Росмотреть данное на вершине стека
	if ( !IsEmpty() ){
		return A[Dim];
	}}

bool stack::IsFull (){		//Проверка на полноту стека
	if ( Dim == (Size - 1) ) return 1;
}

bool stack::IsEmpty (){		//Проверка на пустоту стека
	if ( Dim == -1 ) return 1;
}

void stack::DeleteAll (){		//Удалить все данные из стека
	Dim = -1;
}