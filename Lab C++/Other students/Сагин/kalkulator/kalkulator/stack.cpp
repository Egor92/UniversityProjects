#pragma once
#include "stdafx.h"
#include "stack.h"
#include <stdio.h>
;

stack::stack(){ //���������� ���� ��� �������� �� �� ������� ������ ��� �����
	mem=0; 
	size=0; 
	verh=-1;
	freemem=size;
}


stack::stack(int *mem1, int size1){//���������� ���� ������� ������
	mem=mem1; 
	size=size1;
	verh=-1;
	freemem=size;
}


void stack::Put (int val){
	if (size==0||IsFull()) {ErrCode=ERR; return;} //���� �� �������� ������ ��� ���� ��� ���� �����
	verh++; 
	freemem--; //��������� ������ ����� ������
	mem[verh]=val; //���������� �������� � ������
}


int stack::Get (){
	if (IsEmpty()||size==0) {ErrCode=ERR; return 0;} //���� ���� �� ����
	char tmp=verh; 
	verh--;
	freemem++; //��������� ������ � ����� ����� ������
	return mem[tmp];
}


int stack::See (){
	if (IsEmpty()||size==0) {ErrCode=ERR; return 0;} //���� ������ �� ���������� - ������
	return mem[verh]; //���������� �������
}


bool stack::IsFull() {
	if (size==0) {ErrCode=ERR; return true;}; //���� ������ �� ���������� - ������
	if (freemem==0) return true; //���� ��� ��������� ������, ���� �����!
	return false;
}


bool stack::IsEmpty() {
	if (size==0) {ErrCode=ERR; return true;};
	if (freemem==size) {return true;}; //���� ��� ������ ��������, ���� ����!
	return false;
}

void stack::SetMem (int *mem1, int size1){
	mem=mem1; //������������� ��������� �� ����� ������
	size=size1; 
	verh=-1; //��� ���� ������ ��� ���������� ��������
	freemem=size; //������ ������ ����� ������� ��������!
}


;