#include "stdafx.h"
#include "Variable.h"
#include "GeorgeFunctions.h"
#include "Polynom.h"
#include "stddef.h"
#include "stack.h"

Data::Data(){
	this->Pol->First = NULL;
	this->Operation = -1;
	this->Next = NULL;
}

Data::Data(Polynom *Pol){
	this->Pol = new Polynom(*Pol);
	this->Operation = -1;
	this->Next = NULL;
}

Data::Data(int Operation){
	//this->Pol->First = NULL;
	this->Operation = Operation;
	this->Next = NULL;
}

stack::stack(){
	this->First = NULL;
}

bool stack::IsEmpty(){
	if (this->First == NULL){
		return true;
	}else{
		return false;
	}
}

void stack::Put(Polynom *Pol){
	Data *NewData = new Data(Pol);
	if (this->First != NULL){
		NewData->Next = this->First;
	}
	this->First = NewData;
}

void stack::Put(int Operation){
	Data *NewData = new Data(Operation);
	if (!this->IsEmpty()){
		NewData->Next = this->First;
	}
	this->First = NewData;
}

void stack::Delete(){
	this->First = this->First->Next;
}

Polynom stack::SeePol(){
	return *this->First->Pol;
}

int	stack::SeeOp(){
	return this->First->Operation;
}

int stack::Quantity(){
	Data *D1 = this->First;
	int N = 0;
	while (D1 != NULL){
		D1 = D1->Next;
		N++;
	}
	return N;
}


