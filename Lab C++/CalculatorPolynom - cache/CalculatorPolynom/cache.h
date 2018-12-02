#include <string> 
using namespace std;

class Field{
	public:
		int Name;
		std::string Value;
	public:
		Field();										//�����������
		Field(int Name, std::string Value);				//�����������
		void Initialize(int Name, std::string Value);	//������������� ���������� ������ Field
};

class CircleBuffer{
	private:
		Field* Memory;
		int Begin;
		int End;
		int Size;
	public:
		CircleBuffer(Field* Memory, int Size);			//�����������
		int PlusOne(int A);								//����������� ���������� � ������ �� �������
		Field* Find(int Name);							//����� � ������ �������� �� �����
		void Add(int Name, std::string Value);			//���������� �������� � �����
};

class Cache{
	public:
		Field* MemGlobal;
		Field* MemCache;
	private:
		CircleBuffer** Buffer;
		int CountBuffers;
		int End;
	public:
		int SizeGlobal;
		int SizeCache;
	public:
		Cache(int CountBuffers, int SizeGlobal,int SizeCache);	//�����������
		int SizeOfBuffer(int NumBuffer);				//����������� ������� ������ �� ��� ������
		int PlusOne(int A);								//����������� ���������� � ������ �� �������	
		Field* FindInCache(int Name);					//����� � ���-������ �������� �� �����
		Field* FindInGlobal(int Name);					//����� � "����������" ������ �������� �� �����
		void Add(int Name, std::string Value);			//���������� �������� � ������ (���������� � ���)
};
