class Link{
	public:
		char Letter;
		double Value;
		int MaxPower;
		Link *Next;
	public:
		Link ();
		Link (char Letter, double Value, int MaxPower);
};

class Variable{
	public:
		Link *First;
	public:
		Variable ();
		void Add (char Let);		//Добавить переменную
		void Delete (char Let);		//Удалить переменную
		void DeleteAll ();			//Удалить все переменные
		void ReWriteValue (int N, double Val);	//Переписать значение переменной
		char GetLetter (int N);		//Получить имя переменной по номеру
		double GetValueOfLetter (char Let);		//Получить значение переменной
		double GetValueByNumber (int N);		//Получить значение переменной по номеру
		int GetNumberOfLetter (char Let);		//Получить номер переменной в списке
		int GetMaxPower (int N);				//Получить максимальную степень переменной
		int GetMaxPowerAll ();				//Получить максимальную степень среди всех переменных
		void ReWriteMaxPower (char Let, int Power);	//Переписать максимальную степень переменной
		bool HaveLetter(char Let);			//В наличии ли переменная
};


