#include "StdAfx.h"
#include "Heap.h"

/*-----------------------------------------------------------------------------------------------*/
								//***** class Heap *****//

Heap::Heap(){
	Count = 0;
	SizeOfHeap = 0;
}

Heap::Heap(int SizeOfHeap){
	Count = 0; 
	this->SizeOfHeap = SizeOfHeap;
	Arr = new Field[SizeOfHeap];
}

Heap::~Heap(){
	SizeOfHeap = 0;
	Count = 0;
	delete [] Arr;
}

void Heap::Add(Field tmp){
	Arr[Count] = tmp; 
	Count++; 
	WeightOrder(Count-1); 
}

Field Heap::Extract(){
	Field tmp = Arr[0]; 
	Count--; 
	Arr[0] = Arr[Count];
	WeightOrder(0); 
	return tmp; 
}

int Heap::Left(int SizeOfHeap){
	int tmp = SizeOfHeap*2+1;
	if (tmp < Count){
		return tmp;
	}else{
		return -1;
	}
}

int Heap::Right(int SizeOfHeap){
	int tmp = SizeOfHeap*2+2;
	if (tmp < Count){
		return tmp;
	}else{
		return -1;
	}
}

int Heap::Parent(int SizeOfHeap){
	if (SizeOfHeap == 0){
		return -1; 
	}else{
		if (SizeOfHeap%2 == 0){
			return (SizeOfHeap/2-1);
		}else{
			return (SizeOfHeap/2);
		}
	}
}

void Heap::WeightOrder(int I){
	int LeftChild = Left(I); 
	int RightChild = Right(I); 
	int Father = Parent(I); 
	if ((LeftChild > 0 && Arr[I].Value > Arr[LeftChild].Value) ||
		(RightChild > 0 && Arr[I].Value > Arr[RightChild].Value)){ 
		if (RightChild>0&&Arr[RightChild].Value<Arr[LeftChild].Value){ 
			Field tmp = Arr[RightChild];
			Arr[RightChild] = Arr[I];
			Arr[I] = tmp;
			WeightOrder(RightChild);  
			return; 
		}else{ 
			Field tmp = Arr[LeftChild];
			Arr[LeftChild] = Arr[I];
			Arr[I] = tmp;
			WeightOrder(LeftChild);
			return;
		}
	}else{
		if (Father  >=  0 && Arr[Father].Value > Arr[I].Value){ 
			Field tmp = Arr[Father]; 
			Arr[Father] = Arr[I];
			Arr[I] = tmp;
			WeightOrder(Father); 
			return;
		}
	} 
}

void Heap::Init(int I, int Value){
	Arr[I].Value = Value; 
	WeightOrder(I); 
}

int Heap::GetName(int I){
	return Arr[I].Name; 
}

int Heap::GetValue(int I){
	return Arr[I].Value; 
}
