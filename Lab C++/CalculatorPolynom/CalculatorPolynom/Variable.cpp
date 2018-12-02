#include "stdafx.h"
#include "GeorgeFunctions.h"
#include "Variable.h"
#include "stddef.h"

Link::Link(){
	Letter = NULL;
	Value = 0;
	MaxPower = 1;
	Next = NULL;
}

Link::Link(char Letter, double Value, int MaxPower){
	this->Letter = Letter;
	this->Value = Value;
	this->MaxPower = MaxPower;
	Next = NULL;
}

Variable::Variable(){
	First = NULL;
}

void Variable::Add (char Let){		//�������� ����������
	Link *V1 = First;		//��������� �� ����� ������
	Link *V2 = new Link;	//����� � ����� ����������
	V2->Letter = Let;		//��� ����� ���������� ��� (����������� � Let)
	V2->Value = 0;			//��� ����� ���������� �������� (�� ���������)
	V2->MaxPower = 1;		//���������� ��� �� ��������� �������� �������
	if (First == NULL){		//���� ���������� ��� ���
		First = V2;			//��������� ����� ����������
		First->Next = NULL;	//����������, ��� ������ ���������� ���
	}else{							//���� ���������� ��� ����
		while (V1->Next != NULL){	//���� ����� ������
			V1 = V1->Next;
		}
		V1->Next = V2;				//��������� ����� ���������� � ����� ������
		V2->Next = NULL;			//����������, ��� ������ ���������� ���
	}
}

void Variable::Delete (char Let){		//������� ����������
	Link *V1 = First;	//����� ����� ��������� ����������
	Link *V2 = V1;		//����� ����� ��������� ����������
	if (First != NULL){		//���� ���������� ������ ����
		while ((V1->Letter != Let) && (V1->Next != NULL)){		//���������� ��� ����������, ���� �� ����� ���������� � ������ Let ���� �� �������� �� ����� ������
			V2 = V1;			//�������� ��������� �� ���������� �����, ����� ��� �� ��������
			V1 = V1->Next;
		}
		if ((V1 == First) && (V1->Letter == Let)){	//���� ����������, ���. ��� ���� ������� ����� ������ � ������, ��...
			First = First->Next;	//...�������
		}
		else if (V1->Letter == Let){		//����� �� �� ���������� � ������ Let?
			V2->Next = V1->Next;	//���� �����, �� ������� �
		}
	}
}

void Variable::DeleteAll (){	//������� ��� ����������
	First = NULL;
}

void Variable::ReWriteValue (int N, double Val){	//���������� �������� ����������
	Link *V1 = First;
	for (int I=0; I<N; I++){	//������� �� ����������, ����������� �� N-��� ����� � ������
		V1 = V1->Next;
	}
	V1->Value = Val;
}

char Variable::GetLetter (int N){		//�������� ��� ���������� �� ������
	Link *V1 = First;
	for (int I=0; I<N; I++){	//������� �� ����������, ����������� �� N-��� ����� � ������
		V1 = V1->Next;
	}
	return V1->Letter;
}

double Variable::GetValueOfLetter (char Let){		//�������� �������� ����������
	Link *V1 = First;
	while (V1->Letter != Let){	//���������� ��� ����������, ���� �� ����� ���������� � ������ Let
		V1 = V1->Next;
	}
	return V1->Value;
}

double Variable::GetValueByNumber (int N){		//�������� �������� ���������� �� ������
	Link *V1 = First;
	for (int I=0; I<N; I++){	//������� �� ����������, ����������� �� N-��� ����� � ������
		V1 = V1->Next;
	}
	return V1->Value;
}

int Variable::GetNumberOfLetter (char Let){		//�������� ����� ���������� � ������
	int I = 0;	//��������� ���������� � ������ Let � ������
	Link *V1 = First;
	while (V1->Letter != Let){
		V1 = V1->Next;
		I++;
	}
	return I;
}

int Variable::GetMaxPower (int N){		//�������� ������������ ������� ����������
	Link *V1 = First;
	for (int I=0; I<N; I++){	//������� �� ����������, ����������� �� N-��� ����� � ������
		V1 = V1->Next;
	}
	return V1->MaxPower;
}

int Variable::GetMaxPowerAll (){				//�������� ������������ ������� ����� ���� ����������
	Link *V1 = First;
	int Power = 0;
	while (V1->Next != NULL){
		if (Power < V1->MaxPower){
			Power = V1->MaxPower;
		}
		V1 = V1->Next;
	}
	return Power;
}

void Variable::ReWriteMaxPower (char Let, int Power){	//���������� ������������ ������� ����������
	Link *V1 = First;
	while (V1->Letter != Let){
		V1 = V1->Next;
	}
	V1->MaxPower += Power;
}

bool Variable::HaveLetter(char Let){			//� ������� �� ����������
	Link *V1 = this->First;
	bool Have = false;
	if (V1 != NULL){
		while (V1 != NULL){
			if (V1->Letter == Let){
				Have = true;
			}
			V1 = V1->Next;
		}
	}
	return Have;
}