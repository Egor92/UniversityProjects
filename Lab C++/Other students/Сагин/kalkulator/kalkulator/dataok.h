#include "stdafx.h"
#pragma once
#define OK 0 //���, ��������� ��� ������ is valid
#define ERR -1 //���, ��������� ��� � �������� ��������� ������
;
class dataok{
protected:
	int ErrCode; //����������� ��� ������, ������� ����� �������� �������
public:
	dataok(); //��� �������� ������� ��� ������ �������
	int GetErrCode(); //�������� ��� ������ � ������ ��� ������ ����
};
