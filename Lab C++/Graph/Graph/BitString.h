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
		int BitWhereArr (int X);	//���������� ������������ ���� � �������
		int BitWherePos (int X);	//���������� ������������ ���� � Integer
		int BitGet (int X);			//������� ���
		void BitUp (int X);			//���������� "1"
		void BitDown (int X);		//���������� "0"
};