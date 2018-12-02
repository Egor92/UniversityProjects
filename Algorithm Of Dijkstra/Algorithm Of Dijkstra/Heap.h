#pragma once

/*-----------------------------------------------------------------------------------------------*/
								//***** struct Field *****//

struct Field{ 
	int Value; 
	int Name; 
};

/*-----------------------------------------------------------------------------------------------*/
								//***** class Heap *****//

class Heap{
	public:
		int Count; 
		int SizeOfHeap;  
		Field *Arr; 
	public:
		Heap();			//�����������
		Heap(int SizeOfHeap); 		//�����������
		~Heap();			//�����������
		void Add(Field tmp);		//���������� ������ ����
		Field Extract();			//������ ���� � ������� ����
		void WeightOrder(int I);	//"������������" ����
		void Init(int I, int Value); //������ I-���� ���� ����� ��������
		int GetValue(int I);		//�������� ��������
		int GetName(int I);			//�������� ���
		int Left(int SizeOfHeap);	//����� ������ �������
		int Right(int SizeOfHeap);	//����� ������� �������
		int Parent(int SizeOfHeap); //����� ������
};
