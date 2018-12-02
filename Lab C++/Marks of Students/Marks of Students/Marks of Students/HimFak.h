#pragma once
#include "Students.h"

class HimFak : public Students
{
	int BC, NF, LW;
public:
	HimFak() { BC=0; NF=0; LW=0; }
	void InputStudents(){
		Students :: InputStudents();
		printf ("    Input mark of Bases of Chemistry:\n    ->");
		scanf ("%i",&BC);
		printf ("    Input mark of Nuclear Fusion:\n    ->");
		scanf ("%i",&NF);
		printf ("    Input mark of Laboratory Works:\n    ->");
		scanf ("%i",&LW);
    }
	void PrintStudents(){
		Students :: PrintStudents();
		printf ("    Bases of Chemistry: %i\n",BC);
		printf ("    Nuclear Fusion: %i\n",NF);
		printf ("    Laboratory Works: %i\n",LW);
	}
};