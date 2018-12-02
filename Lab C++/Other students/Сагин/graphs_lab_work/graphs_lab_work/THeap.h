#pragma once
struct Value{ 
	int val; 
	int Name; 
};
class kucha
{
	int count; 
	int n;  
	Value *massiv; 
public:
	kucha(void);
	kucha(int n); 
	~kucha();
	void dobavit(Value tmp);
	Value izvl(); 
	void vosst(int i); 
	void izmenit(int i, int val); 
	int GetVal(int i); 
	int GetName(int i); 
	int left(int n); 
	int right(int n); 
	int grant(int n); 
};
