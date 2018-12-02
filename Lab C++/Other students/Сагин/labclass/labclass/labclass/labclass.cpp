#include <stdio.h>
#include <conio.h>
#include "stdt.h"
#include "student.h"
#include "mostudent.h"
#include "pmstudent.h"
#include "mlivastudent.h"
#include "ptistudent.h"
#include "chifastudent.h"
;
int main ()
{
	stdt ** arr;
	int n;
	printf ("input quantity of students:");
	scanf ("%d",&n);
	arr=new stdt*[n];
	printf ("1. MO student\n2. CHIFA student\n3. MLIVA student\n4. PTI student\n5. PM student\n");
	int ts; int i;
	for (i=0;i<n;i++){
		printf ("chair: ");
		scanf ("%d",&ts);
		switch (ts){
			case 1: {arr[i]=new mostudent(); arr[i]->input(); break;}
			case 2: {arr[i]=new chifastudent(); arr[i]->input();break;}
			case 3: {arr[i]=new mlivastudent(); arr[i]->input();break;}
			case 4: {arr[i]=new ptistudent(); arr[i]->input();break;}
			case 5: {arr[i]=new pmstudent(); arr[i]->input();break;}
        }
    }
	printf ("\n");
	for (i=0;i<n;i++){
		arr[i]->print();
    }
	getch();
}