#pragma once
#include "student.h"

class ptistudent: public student
{
	float lm,apt;
public:
	ptistudent()	{
		lm=0;	apt=0;}
	void input(){
		student::input();
		printf ("Likelihood models: ");
		scanf ("%f",&lm);
		printf ("Applied probability theory: ");
		scanf ("%f",&apt);}
	void print(){
		student::print();
		printf ("Lik.Mod.:%1.1f   App.Prob.T.:%1.1f \n",lm,apt);}
};