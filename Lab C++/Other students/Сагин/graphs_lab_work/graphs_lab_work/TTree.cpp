#include "StdAfx.h"
#include "TTree.h"
#include <stdlib.h>


Tnode::Tnode(){
	val=0; 
	Name=0;
	l=0;
	r=0;	
}
Tree::Tree(void)
{
	head=0; 
}
void Tree::Insert(Tnode *head, int val, int Name){
	Tnode* tmp=head; 
	Tnode* pr; 
	bool r; 
	while (1){
		if (tmp==0){ 
			tmp=new Tnode(); 
			tmp->l=0;
			tmp->r=0;
			tmp->Name=Name;
			tmp->val=val;
			if (r) {pr->r=tmp;} 
			else {pr->l=tmp;}
			return;
		}else{
			pr=tmp;
			if (val>=tmp->val) {r=true; tmp=tmp->r;} 
			else  {r=false; tmp=tmp->l;} 
		}
	}
}
void Tree::Insert(Tnode *head, Tnode *ins){
	Tnode* tmp=head;
	Tnode* pr; 
	int val=ins->val;
	int Name=ins->Name;
	bool r;
	while (1){
		if (tmp==0){
			tmp=ins;
			if (r) {pr->r=tmp;}
			else {pr->l=tmp;}
			return;
		}else{
			pr=tmp;
			if (val>=tmp->val) {r=true; tmp=tmp->r;}
			else  {r=false; tmp=tmp->l;}
		}
	}
}
void Tree::Insert(int val, int Name){
	if (head==0){ 
			head=new Tnode(); 
			head->l=0; 
			head->r=0;
			head->Name=Name;
			head->val=val;
			return;
	}
	Insert(head,val,Name); 
}
int Tree::DelMin(){ 
	Tnode *tmp1, *tmp2;
	int res=-1;
	tmp1=head;
	if (tmp1==0) return -1; 
	if (head->l==0){ 
		res=head->Name; 
		tmp1=head;
		head=head->r; 
		delete [] tmp1; 
		return res;
	}
	while (1){
		tmp2=tmp1;
		tmp1=tmp1->l;
		if (tmp1->l==0){ 
			res=tmp1->Name; 
			tmp2->l=tmp1->r; 
			delete [] tmp1; 
			return res; 
		}
	}
	return res;
}
void Tree::Remove(int val, int Name){ 
	if (head==0) return; 
	Tnode *tmp1, *tmp2;
	bool r; 
	if (val==head->val&&Name==head->Name){ 
		tmp1=head; 
		if (head->l==0) {head=head->r; delete tmp1; return;} 
		else if (head->r==0) {head=head->l; delete tmp1; return;}
		else{ 
			tmp2=head->l->r; 
			head->l->r=head->r; 
			head=head->l; 
			if (tmp2!=0) {Insert(head,tmp2);} 
			delete tmp1; 
			return;
		}
	}else{ 
		tmp1=head; 
		if (val>=head->val) {tmp2=head->r; r=true;}
		else {tmp2=head->l; r=false;} 
		while (1){
			if (val==tmp2->val&&Name==tmp2->Name) break; 
			tmp1=tmp2;
			if (val>=tmp2->val) {tmp2=tmp2->r; r=true;} 
			else {tmp2=tmp2->l; r=false;} 
			if (tmp2==0) break; 
		}
		if (tmp2!=0){ 
			Tnode *tmp3=tmp2;
			Tnode *tmp4;
			if (tmp2->l==0){ 
				if (r) tmp1->r=tmp2->r; 
				else tmp1->l=tmp2->r;
				return;
			}else if (tmp2->r==0){ 
				if (r) tmp1->r=tmp2->l; 
				else tmp1->l=tmp2->l;
				return;
			}else{
				tmp3=tmp2; 
				tmp4=tmp2->l->r; 
				tmp2->l->r=tmp2->r; 
				if (r) tmp1->r=tmp2->l;
				else tmp1->l=tmp2->l; 
				if (tmp4!=0) Insert(tmp1,tmp4);
				delete tmp3; 
				return;
			}
		}else return; 
	}
}


void Tree::Change(int val, int Name, int newval){ 
	Remove(val,Name); 
	Insert(newval,Name); 
}