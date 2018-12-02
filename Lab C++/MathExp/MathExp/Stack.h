class stack {
	public:
		int Size;	//������ �����
		int Dim;	//A[Dim] - ��������� �� ������� �����
		double *A;		//��������� �� ������ �����
	public:
		stack (int Size, double *A);	//������� ����
		void Put (double E);		//�������� ������ �� ������� �����
		double Get ();				//������ ������ �� �����
		int GetInt();
		double See();				//����������� ������ �� ������� �����
		bool IsFull ();				//�������� �� ������� �����
		bool IsEmpty ();			//�������� �� ������� �����
		void DeleteAll ();			//������� ��� ������ �� �����
};