#pragma once
#include "CVM.h"

class Students : public CVM{
	char Surname[30];
	int MA, GA;
public:
	Students() { MA=0; GA=0; }
	void InputStudents(){
		printf("Input surname of student:\n->");
		scanf("%s",Surname);
		printf ("    Input mark of Mathematical Analysis:\n    ->");
		scanf ("%i",&MA);
		printf ("    Input mark of Geometry and Algebra:\n    ->");
		scanf ("%i",&GA);
    }
	void PrintStudents(){
		printf ("\n%s\n",Surname);
		printf ("    Mathematical Analysis: %i\n",MA);
		printf ("    Geometry and Algebra: %i\n",GA);
	}
};