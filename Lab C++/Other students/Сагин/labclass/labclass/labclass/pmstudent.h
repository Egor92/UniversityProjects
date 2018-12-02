#pragma once
#include "student.h"

class pmstudent: public student
{
	float hs,moop;
public:
	pmstudent()	{
		hs=0;	moop=0;}
	void input(){
		student::input();
		printf ("History: ");
		scanf ("%f",&hs);
		printf ("MOOP: ");
		scanf ("%f",&moop);}
	void print(){
		student::print();
		printf ("Hist.:%1.1f   MOOP:%1.1f \n",hs,moop);}
};