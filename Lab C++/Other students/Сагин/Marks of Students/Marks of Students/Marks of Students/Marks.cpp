#include <stdio.h>
#include <conio.h>
#include "CVM.h"
#include "FizFak.h"
#include "HimFak.h"
#include "MatFak.h"
#include "Students.h"

int main()
{

	CVM ** Ukz;
	int I;
	int Quantity;
	int Select;

	printf ("***** Marks of Students *****\n\n");
	printf ("Input quantity of Students:\n");
	scanf ("%i",&Quantity);
	Ukz=new CVM*[Quantity];

	for (I=0;I<Quantity;I++){
		printf ("\nInput faculty of Student:\n");
		printf ("[1] Physical Faculty\n");
		printf ("[2] Chemical Faculty\n");
		printf ("[3] Mathematical Faculty\n->");
		scanf ("%i",&Select);
		
		if (Select==1){
				Ukz[I]=new FizFak();
				Ukz[I]->InputStudents();}
		if (Select==2){
				Ukz[I]=new HimFak();
				Ukz[I]->InputStudents();}
		if (Select==3){
				Ukz[I]=new MatFak();
				Ukz[I]->InputStudents();}
    }

    for (I=0;I<Quantity;I++){
		Ukz[I]->PrintStudents();
    }

    getch();
	return 0;
}