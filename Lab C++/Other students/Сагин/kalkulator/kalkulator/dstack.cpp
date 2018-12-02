#pragma once
#include "stdafx.h"
#include "dstack.h"
#include <stdio.h>
;

dstack::dstack(){ //���������� ���� ��� �������� �� �� ������� ������ ��� �����
	mem=0; 
	size=0; 
	verh=-1;
	freemem=size;
}


dstack::dstack(double *mem1, int size1){//���������� ���� ������� ������
	mem=mem1; 
	size=size1;
	verh=-1;
	freemem=size;
}


void dstack::Put (double val){
	if (size==0||IsFull()) {ErrCode=ERR; return;} //���� �� �������� ������ ��� ���� ��� ���� �����
	verh++; 
	freemem--; //��������� ������ ����� ������
	mem[verh]=val; //���������� �������� � ������
}


double dstack::Get (){
	if (IsEmpty()||size==0) {ErrCode=ERR; return 0;} //���� ���� �� ����
	char tmp=verh; 
	verh--;
	freemem++; //��������� ������ � ����� ����� ������
	return mem[tmp];
}


double dstack::See (){
	if (IsEmpty()||size==0) {ErrCode=ERR; return 0;} //���� ������ �� ���������� - ������
	return mem[verh]; //���������� �������
}


bool dstack::IsFull() {
	if (size==0) {ErrCode=ERR; return true;}; //���� ������ �� ���������� - ������
	if (freemem==0) return true; //���� ��� ��������� ������, ���� �����!
	return false;
}


bool dstack::IsEmpty() {
	if (size==0) {ErrCode=ERR; return true;};
	if (freemem==size) {return true;}; //���� ��� ������ ��������, ���� ����!
	return false;
}

void dstack::SetMem (double *mem1, int size1){
	mem=mem1; //������������� ��������� �� ����� ������
	size=size1; 
	verh=-1; //��� ���� ������ ��� ���������� ��������
	freemem=size; //������ ������ ����� ������� ��������!
}


;