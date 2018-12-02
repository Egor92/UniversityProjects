// file.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	FILE *f, *g;
	int a = 10; 
	
	//g = fopen("..//Debug//text.txt", "w");
	
	//fprintf(g,"%d",a);

	//fclose(g);

	f = fopen("..//Debug//text.txt", "r");  /* открыли для чтения */
	fscanf(f,"%d",&a);
	fscanf(f,"%d",&a);
	a=a*a;
	

	return 0;
}

