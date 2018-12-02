class stack {
	public:
		int Size;	//Размер стека
		int Dim;	//A[Dim] - Указатель на вершину стека
		double *A;		//Указатель на начало стека
	public:
		stack (int Size, double *A);	//Создать стек
		void Put (double E);		//Положить данное на вершину стека
		double Get ();				//Изъять данное из стека
		int GetInt();
		double See();				//Просмотреть данное на вершине стека
		bool IsFull ();				//Проверка на полноту стека
		bool IsEmpty ();			//Проверка на пустоту стека
		void DeleteAll ();			//Удалить все данные из стека
};