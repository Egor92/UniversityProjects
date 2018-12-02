#include "StdAfx.h"
#include "THeap.h"

kucha::kucha(void)
{
	count=0;
	n=0;
}
kucha::kucha(int n){
	count=0; 
	this->n=n;
	massiv=new Value[n];
}
kucha::~kucha(){
	n=0;
	count=0;
	delete [] massiv;
}
void kucha::dobavit(Value tmp){
	massiv[count]=tmp; 
	count++; 
	vosst(count-1); 
}
Value kucha::izvl(){
	Value tmp=massiv[0]; 
	count--; 
	massiv[0]=massiv[count];
	vosst(0); 
	return tmp; 
}
int kucha::left(int n){
	int tmp=n*2+1;
	if (tmp<count) return tmp;
	else return -1; 
}
int kucha::right(int n){
	int tmp=n*2+2;
	if (tmp<count) return tmp;
	else return -1; 
}
int kucha::grant(int n){
	if (n==0) return -1; 
	else
		if (n%2==0) return n/2-1;
		else return n/2;
}
void kucha::vosst(int i){
	int lt=left(i); 
	int rt=right(i); 
	int gt=grant(i); 
	if ((lt>0&&massiv[i].val>massiv[lt].val)||(rt>0&&massiv[i].val>massiv[rt].val)){ 
		if (rt>0&&massiv[rt].val<massiv[lt].val){ 
			Value tmp=massiv[rt];
			massiv[rt]=massiv[i];
			massiv[i]=tmp;
			vosst(rt);  
			return; 
		}else{ 
			Value tmp=massiv[lt];
			massiv[lt]=massiv[i];
			massiv[i]=tmp;
			vosst(lt);
			return;
		}
	}else{
		if (gt>=0&&massiv[gt].val>massiv[i].val){ 
			Value tmp=massiv[gt]; 
			massiv[gt]=massiv[i];
			massiv[i]=tmp;
			vosst(gt); 
			return;
		}
	} 
}
void kucha::izmenit(int i, int val){
	massiv[i].val=val; 
	vosst(i); 
}
int kucha::GetName(int i){
	return massiv[i].Name; 
}
int kucha::GetVal(int i){
	return massiv[i].val; 
}
