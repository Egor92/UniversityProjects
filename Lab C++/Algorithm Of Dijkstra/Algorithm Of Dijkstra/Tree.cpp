#include "StdAfx.h"
#include "Tree.h"
#include <stdlib.h>


/*-----------------------------------------------------------------------------------------------*/
								//***** class Link *****//

Link::Link(){
	Value = 0; 
	Name = 0;
	Left = 0;
	Right = 0;	
}

/*-----------------------------------------------------------------------------------------------*/
								//***** class Tree *****//

Tree::Tree(){
	Head = 0; 
}

void Tree::Add(int Value, int Name){
	Link* tmp = this->Head; 
	Link* Fath; 
	bool Right = false; 

	if (this->Head == 0){ 
		this->Head = new Link(); 
		this->Head->Left = 0; 
		this->Head->Right = 0;
		this->Head->Name = Name;
		this->Head->Value = Value;
		return;
	}

	while (true){
		if (tmp == 0){ 
			tmp = new Link(); 
			tmp->Left = 0;
			tmp->Right = 0;
			tmp->Name = Name;
			tmp->Value = Value;
			if (Right) {
				Fath->Right = tmp;
			}else{
				Fath->Left = tmp;
			}
			return;
		}else{
			Fath = tmp;
			if (Value  >=  tmp->Value){
				Right = true;
				tmp = tmp->Right;
			}else{
				Right = false;
				tmp = tmp->Left;
			} 
		}
	}
}

void Tree::Add(Link *L1){
	Link* tmp = this->Head;
	Link* Fath; 
	int Value = L1->Value;
	int Name = L1->Name;
	bool Right;
	while (true){
		if (tmp == 0){
			tmp = L1;
			if (Right){
				Fath->Right = tmp;
			}else{
				Fath->Left = tmp;
			}
			return;
		}else{
			Fath = tmp;
			if (Value  >=  tmp->Value){
				Right = true;
				tmp = tmp->Right;
			}else{
				Right = false;
				tmp = tmp->Left;
			}
		}
	}
}

int Tree::Extract(){ 
	Link *tmp1;
	Link *tmp2;
	int Result = -1;
	tmp1 = this->Head;
	if (tmp1 == 0){
		return -1; 
	}
	if (Head->Left == 0){ 
		Result = this->Head->Name; 
		tmp1 = this->Head;
		Head = this->Head->Right; 
		delete [] tmp1; 
		return Result;
	}
	while (true){
		tmp2 = tmp1;
		tmp1 = tmp1->Left;
		if (tmp1->Left == 0){ 
			Result = tmp1->Name; 
			tmp2->Left = tmp1->Right; 
			delete [] tmp1; 
			return Result; 
		}
	}
	return Result;
}

void Tree::Remove(int Value, int Name){ 
	if (this->Head == 0){
		return; 
	}
	Link *tmp1;
	Link *tmp2;
	bool Right = false; 
	if (Value == this->Head->Value && Name == this->Head->Name){ 
		tmp1 = this->Head; 
		if (this->Head->Left == 0){
			this->Head = this->Head->Right;
			delete tmp1;
			return;
		}else if (this->Head->Right == 0){
			this->Head = this->Head->Left;
			delete tmp1;
			return;
		}else{ 
			tmp2 = this->Head->Left->Right; 
			this->Head->Left->Right = this->Head->Right; 
			this->Head = this->Head->Left; 
			if (tmp2 != 0){
				Add(tmp2);
			} 
			delete tmp1; 
			return;
		}
	}else{ 
		tmp1 = this->Head; 
		if (Value >= this->Head->Value){
			tmp2 = this->Head->Right;
			Right = true;
		}else{
			tmp2 = this->Head->Left;
			Right = false;
		}
		while (true){
			if (Value == tmp2->Value && Name == tmp2->Name){
				break; 
			}
			tmp1 = tmp2;
			if (Value >= tmp2->Value){
				tmp2 = tmp2->Right;
				Right = true;
			}else{
				tmp2 = tmp2->Left;
				Right = false;
			} 
			if (tmp2 == 0){
				break; 
			}
		}
		if (tmp2 != 0){ 
			Link *tmp3 = tmp2;
			Link *tmp4;
			if (tmp2->Left == 0){ 
				if (Right){
					tmp1->Right = tmp2->Right; 
				}else{
					tmp1->Left = tmp2->Right;
				}
				return;
			}else if (tmp2->Right == 0){ 
				if (Right) tmp1->Right = tmp2->Left; 
				else tmp1->Left = tmp2->Left;
				return;
			}else{
				tmp3 = tmp2; 
				tmp4 = tmp2->Left->Right; 
				tmp2->Left->Right = tmp2->Right; 
				if (Right){
					tmp1->Right = tmp2->Left;
				}else{
					tmp1->Left = tmp2->Left; 
				}
				if (tmp4 != 0){
					Add(tmp4);
				}
				delete tmp3; 
				return;
			}
		}else{
			return; 
		}
	}
}

void Tree::Change(int Value, int Name, int newval){ 
	Remove(Value, Name); 
	Add(newval, Name); 
}