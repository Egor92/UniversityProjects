class Data{
	public:
		Polynom *Pol;
		int Operation;
		Data *Next;
	public:
		Data();
		Data(Polynom *Pol);
		Data(int Operation);
};

class stack{
	public:
		Data *First;
	public:
		stack();
		bool IsEmpty();
		void Put(Polynom *Pol);
		void Put(int Operation);
		void Delete();
		Polynom SeePol();
		int	SeeOp();
		int Quantity();


};