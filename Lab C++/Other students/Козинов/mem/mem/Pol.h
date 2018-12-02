#pragma once

class Pol
{

	
public:int * a;
	Pol(void);

	Pol(const Pol & b);

	~Pol(void);
	Pol operator+(const Pol &b);
	Pol  operator = (const Pol &b);
};
