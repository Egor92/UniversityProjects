#pragma once
#include "student.h"

class mostudent: public student
{
	float avs,dm;
public:
	mostudent()	{
		avs=0;	dm=0;}
	void input(){
		student::input();
		printf ("AVS: ");
		scanf ("%f",&avs);
		printf ("Discrete Math.: ");
		scanf ("%f",&dm);}
	void print(){
		student::print();
		printf ("AVS:%1.1f   DM:%1.1f \n",avs,dm);}
};