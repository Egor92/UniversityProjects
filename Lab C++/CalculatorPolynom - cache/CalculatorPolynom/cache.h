#include <string> 
using namespace std;

class Field{
	public:
		int Name;
		std::string Value;
	public:
		Field();										//Конструктор
		Field(int Name, std::string Value);				//Конструктор
		void Initialize(int Name, std::string Value);	//Инициализация переменной класса Field
};

class CircleBuffer{
	private:
		Field* Memory;
		int Begin;
		int End;
		int Size;
	public:
		CircleBuffer(Field* Memory, int Size);			//Конструктор
		int PlusOne(int A);								//Перемещение переменной в буфере на единицу
		Field* Find(int Name);							//Поиск в буфере элемента по имени
		void Add(int Name, std::string Value);			//Добавление элемента в буфер
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
		Cache(int CountBuffers, int SizeGlobal,int SizeCache);	//Конструктор
		int SizeOfBuffer(int NumBuffer);				//Определение размера буфера по его номеру
		int PlusOne(int A);								//Перемещение переменной в буфере на единицу	
		Field* FindInCache(int Name);					//Поиск в кэш-памяти элемента по имени
		Field* FindInGlobal(int Name);					//Поиск в "глобальной" памяти элемента по имени
		void Add(int Name, std::string Value);			//Добавление элемента в память (глобальную и кэш)
};
