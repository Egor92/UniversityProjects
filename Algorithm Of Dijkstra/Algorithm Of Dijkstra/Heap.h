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
		Heap();			//Конструктор
		Heap(int SizeOfHeap); 		//Конструктор
		~Heap();			//Декструктор
		void Add(Field tmp);		//Добавление нового поля
		Field Extract();			//Изъять поле с вершины кучи
		void WeightOrder(int I);	//"Уравновесить" кучу
		void Init(int I, int Value); //Задать I-тому полю новое значение
		int GetValue(int I);		//Получить значение
		int GetName(int I);			//Получить имя
		int Left(int SizeOfHeap);	//Номер левого потомка
		int Right(int SizeOfHeap);	//Номер правого потомка
		int Parent(int SizeOfHeap); //Номер пердка
};
