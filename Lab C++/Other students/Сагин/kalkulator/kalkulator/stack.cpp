#pragma once
#include "stdafx.h"
#include "stack.h"
#include <stdio.h>
;

stack::stack(){ //вызывается если при создании мы не указали память для стека
	mem=0; 
	size=0; 
	verh=-1;
	freemem=size;
}


stack::stack(int *mem1, int size1){//вызывается если указали память
	mem=mem1; 
	size=size1;
	verh=-1;
	freemem=size;
}


void stack::Put (int val){
	if (size==0||IsFull()) {ErrCode=ERR; return;} //если не выделили память под стек или стек полон
	verh++; 
	freemem--; //свободной памяти стало меньше
	mem[verh]=val; //записываем значение в память
}


int stack::Get (){
	if (IsEmpty()||size==0) {ErrCode=ERR; return 0;} //если стек не пуст
	char tmp=verh; 
	verh--;
	freemem++; //свободной памяти в стеке стало больше
	return mem[tmp];
}


int stack::See (){
	if (IsEmpty()||size==0) {ErrCode=ERR; return 0;} //если память не выделялась - ошибка
	return mem[verh]; //возвращаем вершину
}


bool stack::IsFull() {
	if (size==0) {ErrCode=ERR; return true;}; //если память не выделялась - ошибка
	if (freemem==0) return true; //если нет свободной памяти, стек полон!
	return false;
}


bool stack::IsEmpty() {
	if (size==0) {ErrCode=ERR; return true;};
	if (freemem==size) {return true;}; //если вся память свободна, стек пуст!
	return false;
}

void stack::SetMem (int *mem1, int size1){
	mem=mem1; //устанавливаем указатель на новый массив
	size=size1; 
	verh=-1; //при этом теряем все предыдущие элементы
	freemem=size; //старую память нужно удалять отдельно!
}


;