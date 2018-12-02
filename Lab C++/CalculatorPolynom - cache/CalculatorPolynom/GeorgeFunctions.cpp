#pragma once

#include "stdafx.h"
#include "GeorgeFunctions.h"
#include "Variable.h"
#include "stddef.h"

double PowIntOnInt (int A, int B){	//¬озводит число типа INT в степень числа типа INT
	double Answer = 1;
	while (B > 0){
		Answer *= A;
		B--;
	}
	while (B < 0){
		Answer /= A;
		B++;
	}
	return Answer;
}

int IntOfDiv (int A, int B){
	int C = 0;
	int N = -1;
	while (C <= A){
		C += B;
		N++;
	}
	return N;
}

int RestOfDiv (int A, int B){
	double Answer = A - B * IntOfDiv(A, B);
	return Answer;
}

