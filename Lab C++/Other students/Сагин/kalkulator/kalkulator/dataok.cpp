#pragma once
#include "stdafx.h"
#include "dataok.h"

dataok::dataok(){
	ErrCode=0; //��� �������� ������� ��� ������ �������
}
int dataok::GetErrCode(){ 
		int tmp=ErrCode; ErrCode=OK; 
		return tmp; //�������� ��� ������ � ������ ��� ������ ����
}

;