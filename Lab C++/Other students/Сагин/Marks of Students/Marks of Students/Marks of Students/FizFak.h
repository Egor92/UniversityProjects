#pragma once
#include "Students.h"

class FizFak : public Students
{
	int M, NP, MF;
public:
	FizFak() { M=0; NP=0; MF=0; }
	void InputStudents(){
		Students :: InputStudents();
		printf ("    Input mark of Mechanics:\n    ->");
		scanf ("%i",&M);
		printf ("    Input mark of Nuclear Physics:\n    ->");
		scanf ("%i",&NP);
		printf ("    Input mark of Magnetic Field:\n    ->");
		scanf ("%i",&MF);
    }
	void PrintStudents(){
		Students :: PrintStudents();
		printf ("    Mechanics: %i\n",M);
		printf ("    Nuclear Physics: %i\n",NP);
		printf ("    Magnetic Field: %i\n",MF);
	}
};