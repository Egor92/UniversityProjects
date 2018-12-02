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
		void Add (char Let);		//�������� ����������
		void Delete (char Let);		//������� ����������
		void DeleteAll ();			//������� ��� ����������
		void ReWriteValue (int N, double Val);	//���������� �������� ����������
		char GetLetter (int N);		//�������� ��� ���������� �� ������
		double GetValueOfLetter (char Let);		//�������� �������� ����������
		double GetValueByNumber (int N);		//�������� �������� ���������� �� ������
		int GetNumberOfLetter (char Let);		//�������� ����� ���������� � ������
		int GetMaxPower (int N);				//�������� ������������ ������� ����������
		int GetMaxPowerAll ();				//�������� ������������ ������� ����� ���� ����������
		void ReWriteMaxPower (char Let, int Power);	//���������� ������������ ������� ����������
		bool HaveLetter(char Let);			//� ������� �� ����������
};


