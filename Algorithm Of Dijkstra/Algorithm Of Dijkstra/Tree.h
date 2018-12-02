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
		Tree();		//Конструктор
		void Add(int Value, int Name);		//Добавление нового поля
		void Add(Link* L1); 			//Добавление нового поля
		int Extract(); 			//Изъять поле с вершины дерева и получить его имя
		void Remove(int Value, int Name); 		//Удалить поле
		void Change(int Value, int Name, int newval);	//Изменить поле
};
