#include "stdafx.h"
#include "drob.h"

drob::drob(){
	this->chisl = 0;
	this->znam = 1;
}

drob::drob(drob &A){
	chisl = A.chisl;
	znam = A.znam;
}

drob::drob(int chisl){
	this->chisl = chisl;
	this->znam = 1;
}

drob::drob(int chisl, int znam){
	this->chisl = chisl;
	this->znam = znam;
}

void drob::sokratit(){
	if (znam<0){
		znam = znam * (-1);
		chisl = chisl * (-1);
	}
	int max = chisl;
	if (max < 0){
		max = -max;
	}
	if (chisl < znam){
		max = znam;
	}
	for (int i=max; i>0	; i--){
		if ((chisl % i == 0) && (znam % i == 0)){
			chisl = chisl/i;
			znam = znam/i;
		}
	}
	if (chisl == 0){
		znam = 1;
	}
}

void drob::initialize(int a, int b){
	this->chisl = a;
	this->znam = b;
}

drob minus(drob A, drob B){
	drob C;
	C.chisl = A.chisl*B.znam - A.znam*B.chisl;
	C.znam = A.znam*B.znam;
	C.sokratit();
	return C;
}

drob delit(drob A, int B){
	drob C;
	C.chisl = A.chisl;
	C.znam = A.znam*B;
	C.sokratit();
	return C;
}

drob delit(drob A, drob B){
	drob C;
	C.chisl = A.chisl*B.znam;
	C.znam = A.znam*B.chisl;
	C.sokratit();
	return C;
}

drob umnozhit(drob A, int B){
	drob C;
	C.chisl = A.chisl*B;
	C.znam = A.znam;
	C.sokratit();
	return C;
}

drob umnozhit(drob A, drob B){
	drob C;
	C.chisl = A.chisl*B.chisl;
	C.znam = A.znam*B.znam;
	C.sokratit();
	return C;
}

drob plus(drob A, drob B, drob C){
	drob D;
	D.chisl = A.chisl*B.znam*C.znam + A.znam*B.chisl*C.znam + A.znam*B.znam*C.chisl;
	D.znam = A.znam*B.znam*C.znam;
	D.sokratit();
	return D;
}
