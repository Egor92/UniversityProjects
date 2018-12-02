#pragma once
#include "Students.h"

class MatFak : public Students
{
	int DM, BP, DB;
public:
	MatFak() { DM=0; BP=0; DB=0; }
	void InputStudents(){
		Students :: InputStudents();
		printf ("    Input mark of Discrete Mathematic:\n    ->");
		scanf ("%i",&DM);
		printf ("    Input mark of Bases of Programming:\n    ->");
		scanf ("%i",&BP);
		printf ("    Input mark of DataBase:\n    ->");
		scanf ("%i",&DB);
    }
	void PrintStudents(){
		Students :: PrintStudents();
		printf ("    Discrete Mathematic: %i\n",DM);
		printf ("    Bases of Programming: %i\n",BP);
		printf ("    DataBase: %i\n",DB);
	}
};