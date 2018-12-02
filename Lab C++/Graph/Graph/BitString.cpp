#include "stdafx.h"
#include "BitString.h"

BitString::BitString (){
	ArrLength = 31;
	ArrMem = 1;
	Arr = new int[ArrMem];
	Arr[0]=0;
}

BitString::BitString (int X){
	ArrLength = X;
	if (ArrLength%32 == 0) {
		ArrMem = ArrLength/32-1;
	}
	else{
		ArrMem = (ArrLength/32);
	}
	Arr = new int[ArrMem + 1];

	for (int I=0; I<(ArrMem+1); I++)
		Arr[I] = 0;
}

BitString::~BitString(){
	delete []Arr;
}

int BitString::BitWhereArr (int X){   //Определить расположение бита в массиве
	return X/32;
}

int BitString::BitWherePos (int X){	//Определить расположение бита в Integer
	return 31 - X%32;
}

int BitString::BitGet (int X){	   //Извлечь Бит
	int I;
	I = Arr[BitWhereArr(X)];		//Int, сод. иксный бит
	I = I << (31 - BitWherePos(X));	//Убираем лишнее справа
	I = I >> 31;					//Убираем лишнее слева
	return (-I);
}

void BitString::BitUp (int X){    //Установить "1"
	int I;
	I = 1 << BitWherePos(X);
	Arr[0] = I | Arr[BitWhereArr(X)];
}

void BitString::BitDown(int X){  //Установить "0"
	int I;
	I = 1 << BitWherePos(X);
	I = (~I);
	I = I & Arr[BitWhereArr(X)];
}

