#pragma once
#include "stdt.h"
class student: public stdt{
	float ma,ga;
	char name[50];
public:
	student (){
		ma=0; ga=0;}
	void input(){
		printf ("name: ");
		scanf ("%s",name);
		printf ("MatAnalis: ");
		scanf ("%f",&ma);
		printf ("Alg. & Geom.: ");
		scanf ("%f",&ga);}
	void print(){
		printf ("%s  ",name);
		printf ("MA:%1.1f   GA:%1.1f   ",ma,ga);
	}
};