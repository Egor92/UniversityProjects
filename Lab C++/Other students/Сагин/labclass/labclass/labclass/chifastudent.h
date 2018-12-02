#pragma once
#include "student.h"

class chifastudent: public student
{
	float df,nm;
public:
	chifastudent()	{
		df=0;	nm=0;}
	void input(){
		student::input();
		printf ("differential equations: ");
		scanf ("%f",&df);
		printf ("Numerical methods: ");
		scanf ("%f",&nm);}
	void print(){
		student::print();
		printf ("Diff.Eq.:%1.1f   Num.Meth.:%1.1f \n",df,nm);}
};