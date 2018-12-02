#include "StdAfx.h"
#include "Pol.h"

Pol::Pol(void)
{
	a = new int [2];
	a[0] = 1;
	a[1] = 1;
}

Pol::~Pol(void)
{
	delete[]a;
}
Pol Pol::operator+(const Pol &b){
	Pol res;

	res.a[0] = a[0] + b.a[0];
	res.a[1] = a[1] + b.a[1];

	return res;
}
Pol Pol::operator = (const Pol &b){
	a = new int [2];
	a[0] = b.a[0];
	a[1] = b.a[1];
	return *this;
}
Pol::Pol(const Pol & b){
	a = new int [2];
	a[0] = b.a[0];
	a[1] = b.a[1];
}