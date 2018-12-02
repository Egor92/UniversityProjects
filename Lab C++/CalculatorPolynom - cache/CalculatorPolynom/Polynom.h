class Monom{
	public:
		double Alpha;
		int PowerNum;
		Monom *Next;
	public:
		Monom();
		Monom(double Alpha, int PowerNum);
		void InitializeMonom(char* C, int N, int Sign, Variable* Variables);	//Инициализировать моном и добавить его в начало списка мономов в полиноме
};

class Polynom{
	public:
		Polynom *Next;
		Monom *First;
	public:
		Polynom();
		Polynom(char *Name);
		Polynom(char* C, int N, int Sign, Variable* Variables);
		Polynom(const Polynom &P);
		Polynom operator+ (const Polynom &P);
		Polynom operator* (const Polynom &P);
		Polynom operator= (const Polynom &P);


};
