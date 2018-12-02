class BitString {
	public:
		int *Arr;
		int ArrLength;
		int ArrMem;
	public:
		BitString ();
		BitString (int X);
		~BitString ();
	public:
		int BitWhereArr (int X);	//Определить расположение бита в массиве
		int BitWherePos (int X);	//Определить расположение бита в Integer
		int BitGet (int X);			//Извлечь Бит
		void BitUp (int X);			//Установить "1"
		void BitDown (int X);		//Установить "0"
};