#ifndef FUGURE
#define FUGURE


/*-----------------------------------------------------------------------------------------------*/
										//***** class TObject *****//

class TObject {
	public:
		TObject();
		virtual TObject* Show(System::Drawing::Graphics ^GraphicPanel, int RedNumber) = 0;
		virtual bool IsPoint();

};

/*-----------------------------------------------------------------------------------------------*/
										//***** class TPoint *****//

class TPoint : public TObject{
	public:
		int X;
		int Y;
		int Number;
	public:
		TPoint();
		TPoint(int X, int Y, int Number);
		void Initialize(int X, int Y);
		void Initialize(int X, int Y, int Number);
		int GetX();
		int GetY();
		TObject* Show(System::Drawing::Graphics ^GraphicPanel, int RedNumber);
		bool IsPoint();
};

/*-----------------------------------------------------------------------------------------------*/
										//***** class TLine *****//

class TLine : public TObject{
	public:
		TObject *P1;
		TObject *P2;
		bool IsVisible;
	public:
		TLine(TObject *P1, TObject *P2);
		TLine(TObject *P1, TObject *P2, bool IsVisible);
		void Delete();
		virtual TObject* Show(System::Drawing::Graphics ^GraphicPanel, int RedNumber);
		virtual bool IsTLine();
		virtual bool IsTCircle();
		virtual bool IsTRect();
};

/*-----------------------------------------------------------------------------------------------*/
										//***** class TCircle *****//

class TCircle : public TLine{
	public:
		TCircle(TObject *P1, TObject *P2):TLine(P1, P2){}
		TCircle(TObject *P1, TObject *P2, bool IsVisible):TLine(P1, P2, IsVisible){}
		TObject* Show(System::Drawing::Graphics ^GraphicPanel, int RedNumber);
		bool IsTLine();
		bool IsTCircle();
};

/*-----------------------------------------------------------------------------------------------*/
										//***** class TRect *****//

class TRect : public TLine{
	public:
		TRect(TObject *P1, TObject *P2):TLine(P1, P2){}
		TRect(TObject *P1, TObject *P2, bool IsVisible):TLine(P1, P2, IsVisible){}
		TObject* Show(System::Drawing::Graphics ^GraphicPanel, int RedNumber);
		bool IsTLine();
		bool IsTRect();
};

/*-----------------------------------------------------------------------------------------------*/
										//***** class TPlex *****//
class TPlex {
	public:
		TLine* Head;
	public:
		TPlex();
		TPlex(TLine *L1);
		TObject* GetHead();
		void PaintPlex(System::Drawing::Graphics ^GraphicPanel, int RedNumber);
		void Create(TLine *L1);
		TLine* SearchTLineForAdd(TPoint *Psearch);
		bool SideOfTLineForAdd(TLine *L1, TPoint *Psearch);
		void Delete(int Pi1, int Pi2, int WhatObjectIsSelect);

};


#endif