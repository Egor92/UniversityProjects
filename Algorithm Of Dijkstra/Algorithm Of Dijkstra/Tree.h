#pragma once

/*-----------------------------------------------------------------------------------------------*/
								//***** class Link *****//

class Link{ 
	public:
		int Value; 
		int Name; 
		Link* Left; 
		Link* Right; 
		Link(); 
};

/*-----------------------------------------------------------------------------------------------*/
								//***** class Tree *****//

class Tree{
	public:
		Link *Head; 
	public:
		Tree();		//�����������
		void Add(int Value, int Name);		//���������� ������ ����
		void Add(Link* L1); 			//���������� ������ ����
		int Extract(); 			//������ ���� � ������� ������ � �������� ��� ���
		void Remove(int Value, int Name); 		//������� ����
		void Change(int Value, int Name, int newval);	//�������� ����
};
