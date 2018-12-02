#pragma once
class Tnode{ 
public:
	int val; 
	int Name; 
	Tnode* l; 
	Tnode* r; 
	Tnode (); 
};
class Tree
{
private:
	Tnode *head; 
	void Insert (Tnode* head, int val, int Name); 
	void Insert(Tnode *head, Tnode *ins); 
public:
	Tree(void);
	void Insert (int val, int Name); 
	int DelMin(); 
	void Remove(int val, int Name); 
	void Change(int val, int Name, int newval); 
};
