#pragma once
#include "student.h"

class mlivastudent: public student
{
	float toc,ca;
public:
	mlivastudent()	{
		toc=0;	ca=0;}
	void input(){
		student::input();
		printf ("The theory of counts: ");
		scanf ("%f",&toc);
		printf ("Computer algebra: ");
		scanf ("%f",&ca);}
	void print(){
		student::print();
		printf ("Theor.Coun.:%1.1f   Comp.Alg.:%1.1f \n",toc,ca);}
};