#pragma once

#include "stdafx.h"
#include "Variable.h"
#include "GeorgeFunctions.h"
#include "Polynom.h"
#include "stack.h"
#include "stddef.h"


namespace CalculatorPolynom {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  ButtonExit;
	protected: 
	private: System::Windows::Forms::Button^  ButtonCE;
	private: System::Windows::Forms::Button^  ButtonMonomCancel;
	private: System::Windows::Forms::GroupBox^  BoxDGV;
	private: System::Windows::Forms::DataGridView^  DGV;
	private: System::Windows::Forms::Button^  ButtonBracketOpen;
	private: System::Windows::Forms::Button^  ButtonBracketClose;
	private: System::Windows::Forms::TextBox^  TBLetterAdd;
	private: System::Windows::Forms::Button^  ButtonLetterAdd;
	private: System::Windows::Forms::TextBox^  TBPowerAdd;
	private: System::Windows::Forms::Button^  ButtonPowerAdd;
	private: System::Windows::Forms::Button^  ButtonCancel;
	private: System::Windows::Forms::Button^  ButtonComma;
	private: System::Windows::Forms::Button^  Button4;
	private: System::Windows::Forms::Button^  Button0;
	private: System::Windows::Forms::Button^  Button9;
	private: System::Windows::Forms::Button^  Button2;
	private: System::Windows::Forms::Button^  Button5;
	private: System::Windows::Forms::Button^  Button1;
	private: System::Windows::Forms::Button^  Button7;
	private: System::Windows::Forms::Button^  Button8;
	private: System::Windows::Forms::Button^  Button6;
	private: System::Windows::Forms::Button^  Button3;
	private: System::Windows::Forms::Button^  ButtonCalc;
	private: System::Windows::Forms::Button^  ButtonMines;
	private: System::Windows::Forms::Button^  ButtonMult;
	private: System::Windows::Forms::Button^  ButtonPlus;
	private: System::Windows::Forms::TextBox^  TBPole2;
	private: System::Windows::Forms::TextBox^  TBPole1;
	private: System::Windows::Forms::Label^  LabelHelp;
	private: System::Windows::Forms::GroupBox^  BoxDGV2;
	private: System::Windows::Forms::DataGridView^  DGV2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Переменная;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Значение;
	private: System::Windows::Forms::NumericUpDown^  Numeric;
	private: System::Windows::Forms::Button^  ButtonNew;

	private: System::Windows::Forms::Button^  ButtonUse;
	private: System::Windows::Forms::Button^  ButtonEquate;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

String^ AddSpace(String^ Str){
	String^ S1;
	S1 = " " + Str + " ";
	return S1;
}

void DeleteLastSimbol(){	//Удаляет последний символ в TBPole2
	int I;
	char C;
	String ^T = ""; //В эту строку запишем всё, кроме последнего символа
	String ^S = this->TBPole2->Text;	//Строка TBPole2
	if (S->Length > 0){		//Если в TBPole2 что-то написано
		if (S[S->Length-1]>97 && S[S->Length-1]<123){	//Последний символ - это переменная? (код символа от 98 до 122 - это латинские буквы)
			C = S[S->Length-1];		//Если переменная, то запомним этот символ
		}
	}
	for (I=0; I<this->TBPole2->Text->Length-1; I++){
		T += this->TBPole2->Text[I];
	}
	this->TBPole2->Text = T;	//Вывести результат
}

String^ DeleteFirstMines(String^ Str){	//Удаляет первый символ "минус"
	String^ S1;
	for (int I=1; I<Str->Length; I++){
		S1 += Str[I];
	}
	return S1;
}

void PrintOperation (int Operation){	//Смотрит на TBPole2 и ставит операцию, в зависимости от оценки ситуации 
	if (this->TBPole2->Text->Length > 0){	//←Если в строке что-то написано... ↓и последний символ - операция, то...
		if (this->TBPole2->Text[this->TBPole2->Text->Length-1] == ','){	//Последний символ - запятая?
			DeleteLastSimbol();	//Удалить запятую
		}
		if (SimbolsOperations->IndexOf(this->TBPole2->Text[this->TBPole2->Text->Length-1]) > -1){
			DeleteLastSimbol();	//Удалить из строки эту операцию, т.к. мы поставим вместо неё другую...*
		}
	}
	this->TBPole2->Text += SimbolsOperations[Operation].ToString();	//*...Вот эту!
}

void MayPrintOperation (int Operation){		//Смотрит на TBPole2 и ставит операцию, в зависимости от оценки ситуации..
											//..Также рассматривает возможность замены последней операции на новую  
	//Операция Operation не должна стоять в начале строки TBPole2
	if (this->TBPole2->TextLength == 1){	//Если в строке TBPole2 только один символ...
		if (SimbolsOperations->IndexOf(this->TBPole2->Text[0]) > -1){	//...и он - операция, то...
			DeleteLastSimbol();											//...удаляем его
		}
	}
	if (this->TBPole2->TextLength > 1){	//Если в строке TBPole2 более одного символа,...
		if (this->TBPole2->Text[this->TBPole2->TextLength-2] == '('){	//...и предпредыдущий символ - открывающаяся скобка и...
			if (SimbolsOperations->IndexOf(this->TBPole2->Text[this->TBPole2->TextLength-1]) > -1){		//...предыдущий символ - операция, то...
				DeleteLastSimbol();		//Удаляем операцию
			}
		}
	}
	if (this->TBPole2->TextLength > 0){	//В других случаях, если строка TBPole2 не пуста,...
		if (this->TBPole2->Text[this->TBPole2->TextLength-1] != '('){	//...и предыдущий символ - не открывающаяся скобка,то...
			PrintOperation(Operation);		//Пишем Operation
		}
	}
}

String^ TranslatePolynom(Polynom *P){		//Переводит полином в 
	stack *ListOfPowers;
	stack *ListOfPowersReverce;
	int Conv;
	int I;
	String ^Answer = "";
	Polynom *Pol = new Polynom(*P);
	while(Pol->First != NULL){
		if((Pol->First->Alpha > 0) && (Answer->Length > 0)){
			Answer += "+";
		}
		Answer += Pol->First->Alpha.ToString();
		ListOfPowersReverce = new stack();
		ListOfPowers = new stack();
		Conv = Pol->First->PowerNum;
		for (I=0; I<NumOfLetters-1; I++){
			ListOfPowersReverce->Put(RestOfDiv(Conv, Variables->GetMaxPowerAll()+1));
			Conv = IntOfDiv(Conv, Variables->GetMaxPowerAll()+1);
		}ListOfPowersReverce->Put(Conv);
		
		while(!ListOfPowersReverce->IsEmpty()){
			ListOfPowers->Put(ListOfPowersReverce->SeeOp());
			ListOfPowersReverce->Delete();
		}
		
		for (I=0; I<NumOfLetters; I++){
			if (ListOfPowers->SeeOp() == 1){
				Answer += (Convert::ToChar(Variables->GetLetter(I))).ToString();
			}
			else if(ListOfPowers->SeeOp() > 1){
				Answer += (Convert::ToChar(Variables->GetLetter(I))).ToString();
				Answer += "[" + ListOfPowers->SeeOp().ToString() + "]";
			}
			ListOfPowers->Delete();
		}
		Pol->First = Pol->First->Next;
	}
	return Answer;
}

void PrintNumber (int Number){	//Смотрит на TBPole2 и ставит цифру, в зависимости от оценки ситуации 
	if (this->TBPole2->Text->Length == 1){	//Если в TBPole2 однин символ...
		if (this->TBPole2->Text[this->TBPole2->TextLength-1] == '0'){	//...и это - "ноль"
			DeleteLastSimbol();	//Удаляем "ноль"
		}
	}
	if (this->TBPole2->Text->Length > 1){	//Если в TBPole2 более одного символa
		//Любую цифру нельзя ставить после "ноля", стоящего после операции
		if (this->TBPole2->Text[this->TBPole2->TextLength-1] == '0'){
			if (SimbolsOperations->IndexOf(this->TBPole2->Text[this->TBPole2->TextLength-2]) > -1){
				DeleteLastSimbol();	//Удаляем "ноль"
			}
		}
	}
	if (this->TBPole2->Text->Length > 0){	//Если в TBPole2 что-то написано
		//Число нельзя ставить сразу после закрывающейся скобки
		if ((this->TBPole2->Text[this->TBPole2->Text->Length-1] == ')') || (this->TBPole2->Text[this->TBPole2->Text->Length-1] == ']') || (SimbolsEnglish->IndexOf(this->TBPole2->Text[this->TBPole2->Text->Length-1]) > -1)){
			this->TBPole2->Text += "*";		//Втавить умножить в TBPole2
		}
		this->TBPole2->Text += Number.ToString();	//Втавить цифру в TBPole2
	}else{	//Если в TBPole2 ничего нет, то просто вставить
		this->TBPole2->Text += Number.ToString();	//Втавить цифру в TBPole2
	}
}

char* StrToChar (String ^S){	//Переводит строку в массив ЧАРОВ
	char* C;
	C = new char[S->Length-1];
	for (int I = 0; I<S->Length; I++){
		C[I] = S[I];	//Копируем символы из строки в массив ЧАРОВ
	}
	return C;	//Возвращаем указатель на массив ЧАРОВ
}

void ReWriteDGVvariables (Variable *Variables, int NumOfLetters){	//Переписывает таблицу инициализации переменных
	this->DGV->RowCount = NumOfLetters;
	for (int I=0; I<NumOfLetters; I++){
		this->DGV->Rows[I]->Cells[0]->Value = Convert::ToChar(Variables->GetLetter(I)).ToString();
		this->DGV->Rows[I]->Cells[1]->Value = Variables->GetValueByNumber(I).ToString();
	}
}

void MouseMoveClear(){		//Закрашивает шрифт кнопок чёрным цветом
	this->ButtonPlus->ForeColor = System::Drawing::Color::Black;
	this->ButtonMines->ForeColor = System::Drawing::Color::Black;
	this->ButtonMult->ForeColor = System::Drawing::Color::Black;
	this->ButtonCalc->ForeColor = System::Drawing::Color::Black;
	this->Button0->ForeColor = System::Drawing::Color::Black;
	this->Button1->ForeColor = System::Drawing::Color::Black;
	this->Button2->ForeColor = System::Drawing::Color::Black;
	this->Button3->ForeColor = System::Drawing::Color::Black;
	this->Button4->ForeColor = System::Drawing::Color::Black;
	this->Button5->ForeColor = System::Drawing::Color::Black;
	this->Button6->ForeColor = System::Drawing::Color::Black;
	this->Button7->ForeColor = System::Drawing::Color::Black;
	this->Button8->ForeColor = System::Drawing::Color::Black;
	this->Button9->ForeColor = System::Drawing::Color::Black;
	this->ButtonPowerAdd->ForeColor = System::Drawing::Color::Black;
	this->ButtonLetterAdd->ForeColor = System::Drawing::Color::Black;
	this->ButtonBracketOpen->ForeColor = System::Drawing::Color::Black;
	this->ButtonBracketClose->ForeColor = System::Drawing::Color::Black;
	this->ButtonComma->ForeColor = System::Drawing::Color::Black;
	this->ButtonCancel->ForeColor = System::Drawing::Color::Black;
	this->ButtonMonomCancel->ForeColor = System::Drawing::Color::Black;
	this->ButtonCE->ForeColor = System::Drawing::Color::Black;
	this->ButtonExit->ForeColor = System::Drawing::Color::Black;
}

bool VariableIsAvailable (char Let){	//Проверяет наличие переменной с именем Let в TBPole2
	bool IsAvailable = false;		//Текущий статус - "не нашел"
	for(int I=0; I<this->TBPole2->TextLength; I++){	//Проверяем каждый символ
		if (this->TBPole2->Text[I] == Let){
			IsAvailable = true;		//Ура-а-а-а-а-а-а-а-а-а, нашли-и-и-и-и-и!
		}
	}
	return IsAvailable;
}


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->ButtonExit = (gcnew System::Windows::Forms::Button());
			this->ButtonCE = (gcnew System::Windows::Forms::Button());
			this->ButtonMonomCancel = (gcnew System::Windows::Forms::Button());
			this->BoxDGV = (gcnew System::Windows::Forms::GroupBox());
			this->DGV = (gcnew System::Windows::Forms::DataGridView());
			this->Переменная = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Значение = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ButtonBracketOpen = (gcnew System::Windows::Forms::Button());
			this->ButtonBracketClose = (gcnew System::Windows::Forms::Button());
			this->TBLetterAdd = (gcnew System::Windows::Forms::TextBox());
			this->ButtonLetterAdd = (gcnew System::Windows::Forms::Button());
			this->TBPowerAdd = (gcnew System::Windows::Forms::TextBox());
			this->ButtonPowerAdd = (gcnew System::Windows::Forms::Button());
			this->ButtonCancel = (gcnew System::Windows::Forms::Button());
			this->ButtonComma = (gcnew System::Windows::Forms::Button());
			this->Button4 = (gcnew System::Windows::Forms::Button());
			this->Button0 = (gcnew System::Windows::Forms::Button());
			this->Button9 = (gcnew System::Windows::Forms::Button());
			this->Button2 = (gcnew System::Windows::Forms::Button());
			this->Button5 = (gcnew System::Windows::Forms::Button());
			this->Button1 = (gcnew System::Windows::Forms::Button());
			this->Button7 = (gcnew System::Windows::Forms::Button());
			this->Button8 = (gcnew System::Windows::Forms::Button());
			this->Button6 = (gcnew System::Windows::Forms::Button());
			this->Button3 = (gcnew System::Windows::Forms::Button());
			this->ButtonCalc = (gcnew System::Windows::Forms::Button());
			this->ButtonMines = (gcnew System::Windows::Forms::Button());
			this->ButtonMult = (gcnew System::Windows::Forms::Button());
			this->ButtonPlus = (gcnew System::Windows::Forms::Button());
			this->TBPole2 = (gcnew System::Windows::Forms::TextBox());
			this->TBPole1 = (gcnew System::Windows::Forms::TextBox());
			this->LabelHelp = (gcnew System::Windows::Forms::Label());
			this->BoxDGV2 = (gcnew System::Windows::Forms::GroupBox());
			this->ButtonNew = (gcnew System::Windows::Forms::Button());
			this->ButtonUse = (gcnew System::Windows::Forms::Button());
			this->Numeric = (gcnew System::Windows::Forms::NumericUpDown());
			this->DGV2 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ButtonEquate = (gcnew System::Windows::Forms::Button());
			this->BoxDGV->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DGV))->BeginInit();
			this->BoxDGV2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Numeric))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DGV2))->BeginInit();
			this->SuspendLayout();
			// 
			// ButtonExit
			// 
			this->ButtonExit->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->ButtonExit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->ButtonExit->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->ButtonExit->Location = System::Drawing::Point(497, 283);
			this->ButtonExit->Name = L"ButtonExit";
			this->ButtonExit->Size = System::Drawing::Size(70, 60);
			this->ButtonExit->TabIndex = 56;
			this->ButtonExit->Text = L"Exit";
			this->ButtonExit->UseVisualStyleBackColor = true;
			this->ButtonExit->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::ButtonExit_MouseMove);
			this->ButtonExit->Click += gcnew System::EventHandler(this, &Form1::ButtonExit_Click);
			// 
			// ButtonCE
			// 
			this->ButtonCE->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->ButtonCE->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->ButtonCE->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->ButtonCE->Location = System::Drawing::Point(421, 283);
			this->ButtonCE->Name = L"ButtonCE";
			this->ButtonCE->Size = System::Drawing::Size(70, 60);
			this->ButtonCE->TabIndex = 53;
			this->ButtonCE->Text = L"CE";
			this->ButtonCE->UseVisualStyleBackColor = true;
			this->ButtonCE->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::ButtonCE_MouseMove);
			this->ButtonCE->Click += gcnew System::EventHandler(this, &Form1::ButtonCE_Click);
			// 
			// ButtonMonomCancel
			// 
			this->ButtonMonomCancel->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->ButtonMonomCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->ButtonMonomCancel->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->ButtonMonomCancel->Location = System::Drawing::Point(345, 283);
			this->ButtonMonomCancel->Name = L"ButtonMonomCancel";
			this->ButtonMonomCancel->Size = System::Drawing::Size(70, 60);
			this->ButtonMonomCancel->TabIndex = 52;
			this->ButtonMonomCancel->Text = L"‹M";
			this->ButtonMonomCancel->UseVisualStyleBackColor = true;
			this->ButtonMonomCancel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::ButtonMonomCancel_MouseMove);
			this->ButtonMonomCancel->Click += gcnew System::EventHandler(this, &Form1::ButtonMonomCancel_Click);
			// 
			// BoxDGV
			// 
			this->BoxDGV->Controls->Add(this->DGV);
			this->BoxDGV->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->BoxDGV->Location = System::Drawing::Point(573, 10);
			this->BoxDGV->Name = L"BoxDGV";
			this->BoxDGV->Size = System::Drawing::Size(227, 333);
			this->BoxDGV->TabIndex = 54;
			this->BoxDGV->TabStop = false;
			this->BoxDGV->Text = L"Объявление переменных";
			// 
			// DGV
			// 
			this->DGV->AllowUserToAddRows = false;
			this->DGV->BackgroundColor = System::Drawing::SystemColors::Control;
			this->DGV->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->DGV->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DGV->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->Переменная, this->Значение});
			this->DGV->EnableHeadersVisualStyles = false;
			this->DGV->Location = System::Drawing::Point(6, 19);
			this->DGV->Name = L"DGV";
			this->DGV->RowHeadersVisible = false;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->DGV->RowsDefaultCellStyle = dataGridViewCellStyle1;
			this->DGV->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->DGV->Size = System::Drawing::Size(215, 308);
			this->DGV->TabIndex = 26;
			this->DGV->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::DGV_CellValueChanged);
			this->DGV->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::DGV_MouseMove);
			// 
			// Переменная
			// 
			this->Переменная->HeaderText = L"Переменная";
			this->Переменная->MaxInputLength = 1;
			this->Переменная->Name = L"Переменная";
			this->Переменная->ReadOnly = true;
			this->Переменная->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Переменная->Width = 98;
			// 
			// Значение
			// 
			this->Значение->HeaderText = L"Значение";
			this->Значение->Name = L"Значение";
			this->Значение->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Значение->Width = 98;
			// 
			// ButtonBracketOpen
			// 
			this->ButtonBracketOpen->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->ButtonBracketOpen->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->ButtonBracketOpen->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->ButtonBracketOpen->Location = System::Drawing::Point(345, 217);
			this->ButtonBracketOpen->Name = L"ButtonBracketOpen";
			this->ButtonBracketOpen->Size = System::Drawing::Size(70, 60);
			this->ButtonBracketOpen->TabIndex = 50;
			this->ButtonBracketOpen->Text = L"(";
			this->ButtonBracketOpen->UseVisualStyleBackColor = true;
			this->ButtonBracketOpen->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::ButtonBracketOpen_MouseMove);
			this->ButtonBracketOpen->Click += gcnew System::EventHandler(this, &Form1::ButtonBracketOpen_Click);
			// 
			// ButtonBracketClose
			// 
			this->ButtonBracketClose->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->ButtonBracketClose->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->ButtonBracketClose->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->ButtonBracketClose->Location = System::Drawing::Point(421, 217);
			this->ButtonBracketClose->Name = L"ButtonBracketClose";
			this->ButtonBracketClose->Size = System::Drawing::Size(70, 60);
			this->ButtonBracketClose->TabIndex = 51;
			this->ButtonBracketClose->Text = L")";
			this->ButtonBracketClose->UseVisualStyleBackColor = true;
			this->ButtonBracketClose->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::ButtonBracketClose_MouseMove);
			this->ButtonBracketClose->Click += gcnew System::EventHandler(this, &Form1::ButtonBracketClose_Click);
			// 
			// TBLetterAdd
			// 
			this->TBLetterAdd->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(254)));
			this->TBLetterAdd->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->TBLetterAdd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->TBLetterAdd->Location = System::Drawing::Point(345, 151);
			this->TBLetterAdd->Name = L"TBLetterAdd";
			this->TBLetterAdd->Size = System::Drawing::Size(222, 35);
			this->TBLetterAdd->TabIndex = 48;
			this->TBLetterAdd->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->TBLetterAdd->TextChanged += gcnew System::EventHandler(this, &Form1::TBLetterAdd_TextChanged);
			this->TBLetterAdd->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::TBLetterAdd_MouseMove);
			// 
			// ButtonLetterAdd
			// 
			this->ButtonLetterAdd->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->ButtonLetterAdd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->ButtonLetterAdd->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->ButtonLetterAdd->Location = System::Drawing::Point(345, 187);
			this->ButtonLetterAdd->Name = L"ButtonLetterAdd";
			this->ButtonLetterAdd->Size = System::Drawing::Size(222, 24);
			this->ButtonLetterAdd->TabIndex = 49;
			this->ButtonLetterAdd->Text = L"Добавить переменную";
			this->ButtonLetterAdd->UseVisualStyleBackColor = true;
			this->ButtonLetterAdd->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::ButtonLetterAdd_MouseMove);
			this->ButtonLetterAdd->Click += gcnew System::EventHandler(this, &Form1::ButtoLetterAdd_Click);
			// 
			// TBPowerAdd
			// 
			this->TBPowerAdd->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(254)));
			this->TBPowerAdd->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->TBPowerAdd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->TBPowerAdd->Location = System::Drawing::Point(345, 85);
			this->TBPowerAdd->Name = L"TBPowerAdd";
			this->TBPowerAdd->Size = System::Drawing::Size(222, 35);
			this->TBPowerAdd->TabIndex = 46;
			this->TBPowerAdd->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->TBPowerAdd->TextChanged += gcnew System::EventHandler(this, &Form1::TBPowerAdd_TextChanged);
			this->TBPowerAdd->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::TBPowerAdd_MouseMove);
			// 
			// ButtonPowerAdd
			// 
			this->ButtonPowerAdd->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->ButtonPowerAdd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->ButtonPowerAdd->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->ButtonPowerAdd->Location = System::Drawing::Point(345, 121);
			this->ButtonPowerAdd->Name = L"ButtonPowerAdd";
			this->ButtonPowerAdd->Size = System::Drawing::Size(222, 24);
			this->ButtonPowerAdd->TabIndex = 47;
			this->ButtonPowerAdd->Text = L"Добавить степень";
			this->ButtonPowerAdd->UseVisualStyleBackColor = true;
			this->ButtonPowerAdd->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::ButtonPowerAdd_MouseMove);
			this->ButtonPowerAdd->Click += gcnew System::EventHandler(this, &Form1::ButtonPowerAdd_Click);
			// 
			// ButtonCancel
			// 
			this->ButtonCancel->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->ButtonCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold));
			this->ButtonCancel->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->ButtonCancel->Location = System::Drawing::Point(254, 283);
			this->ButtonCancel->Name = L"ButtonCancel";
			this->ButtonCancel->Size = System::Drawing::Size(70, 60);
			this->ButtonCancel->TabIndex = 45;
			this->ButtonCancel->Text = L"<";
			this->ButtonCancel->UseVisualStyleBackColor = true;
			this->ButtonCancel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::ButtonCancel_MouseMove);
			this->ButtonCancel->Click += gcnew System::EventHandler(this, &Form1::ButtonCancel_Click);
			// 
			// ButtonComma
			// 
			this->ButtonComma->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->ButtonComma->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold));
			this->ButtonComma->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->ButtonComma->Location = System::Drawing::Point(102, 283);
			this->ButtonComma->Name = L"ButtonComma";
			this->ButtonComma->Size = System::Drawing::Size(70, 60);
			this->ButtonComma->TabIndex = 37;
			this->ButtonComma->Text = L",";
			this->ButtonComma->UseVisualStyleBackColor = true;
			this->ButtonComma->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::ButtonComma_MouseMove);
			this->ButtonComma->Click += gcnew System::EventHandler(this, &Form1::ButtonComma_Click);
			// 
			// Button4
			// 
			this->Button4->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->Button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold));
			this->Button4->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->Button4->Location = System::Drawing::Point(102, 151);
			this->Button4->Name = L"Button4";
			this->Button4->Size = System::Drawing::Size(70, 60);
			this->Button4->TabIndex = 35;
			this->Button4->Text = L"4";
			this->Button4->UseVisualStyleBackColor = true;
			this->Button4->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Button4_MouseMove);
			this->Button4->Click += gcnew System::EventHandler(this, &Form1::Button4_Click);
			// 
			// Button0
			// 
			this->Button0->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->Button0->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold));
			this->Button0->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->Button0->Location = System::Drawing::Point(178, 283);
			this->Button0->Name = L"Button0";
			this->Button0->Size = System::Drawing::Size(70, 60);
			this->Button0->TabIndex = 41;
			this->Button0->Text = L"0";
			this->Button0->UseVisualStyleBackColor = true;
			this->Button0->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Button0_MouseMove);
			this->Button0->Click += gcnew System::EventHandler(this, &Form1::Button0_Click);
			// 
			// Button9
			// 
			this->Button9->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->Button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold));
			this->Button9->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->Button9->Location = System::Drawing::Point(254, 85);
			this->Button9->Name = L"Button9";
			this->Button9->Size = System::Drawing::Size(70, 60);
			this->Button9->TabIndex = 42;
			this->Button9->Text = L"9";
			this->Button9->UseVisualStyleBackColor = true;
			this->Button9->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Button9_MouseMove);
			this->Button9->Click += gcnew System::EventHandler(this, &Form1::Button9_Click);
			// 
			// Button2
			// 
			this->Button2->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->Button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold));
			this->Button2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->Button2->Location = System::Drawing::Point(178, 217);
			this->Button2->Name = L"Button2";
			this->Button2->Size = System::Drawing::Size(70, 60);
			this->Button2->TabIndex = 40;
			this->Button2->Text = L"2";
			this->Button2->UseVisualStyleBackColor = true;
			this->Button2->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Button2_MouseMove);
			this->Button2->Click += gcnew System::EventHandler(this, &Form1::Button2_Click);
			// 
			// Button5
			// 
			this->Button5->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->Button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold));
			this->Button5->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->Button5->Location = System::Drawing::Point(178, 151);
			this->Button5->Name = L"Button5";
			this->Button5->Size = System::Drawing::Size(70, 60);
			this->Button5->TabIndex = 39;
			this->Button5->Text = L"5";
			this->Button5->UseVisualStyleBackColor = true;
			this->Button5->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Button5_MouseMove);
			this->Button5->Click += gcnew System::EventHandler(this, &Form1::Button5_Click);
			// 
			// Button1
			// 
			this->Button1->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->Button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold));
			this->Button1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->Button1->Location = System::Drawing::Point(102, 217);
			this->Button1->Name = L"Button1";
			this->Button1->Size = System::Drawing::Size(70, 60);
			this->Button1->TabIndex = 36;
			this->Button1->Text = L"1";
			this->Button1->UseVisualStyleBackColor = true;
			this->Button1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Button1_MouseMove);
			this->Button1->Click += gcnew System::EventHandler(this, &Form1::Button1_Click);
			// 
			// Button7
			// 
			this->Button7->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->Button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold));
			this->Button7->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->Button7->Location = System::Drawing::Point(102, 85);
			this->Button7->Name = L"Button7";
			this->Button7->Size = System::Drawing::Size(70, 60);
			this->Button7->TabIndex = 34;
			this->Button7->Text = L"7";
			this->Button7->UseVisualStyleBackColor = true;
			this->Button7->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Button7_MouseMove);
			this->Button7->Click += gcnew System::EventHandler(this, &Form1::Button7_Click);
			// 
			// Button8
			// 
			this->Button8->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->Button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold));
			this->Button8->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->Button8->Location = System::Drawing::Point(178, 85);
			this->Button8->Name = L"Button8";
			this->Button8->Size = System::Drawing::Size(70, 60);
			this->Button8->TabIndex = 38;
			this->Button8->Text = L"8";
			this->Button8->UseVisualStyleBackColor = true;
			this->Button8->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Button8_MouseMove);
			this->Button8->Click += gcnew System::EventHandler(this, &Form1::Button8_Click);
			// 
			// Button6
			// 
			this->Button6->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->Button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold));
			this->Button6->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->Button6->Location = System::Drawing::Point(254, 151);
			this->Button6->Name = L"Button6";
			this->Button6->Size = System::Drawing::Size(70, 60);
			this->Button6->TabIndex = 43;
			this->Button6->Text = L"6";
			this->Button6->UseVisualStyleBackColor = true;
			this->Button6->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Button6_MouseMove);
			this->Button6->Click += gcnew System::EventHandler(this, &Form1::Button6_Click);
			// 
			// Button3
			// 
			this->Button3->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->Button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold));
			this->Button3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->Button3->Location = System::Drawing::Point(254, 217);
			this->Button3->Name = L"Button3";
			this->Button3->Size = System::Drawing::Size(70, 60);
			this->Button3->TabIndex = 44;
			this->Button3->Text = L"3";
			this->Button3->UseVisualStyleBackColor = true;
			this->Button3->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Button3_MouseMove);
			this->Button3->Click += gcnew System::EventHandler(this, &Form1::Button3_Click);
			// 
			// ButtonCalc
			// 
			this->ButtonCalc->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->ButtonCalc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold));
			this->ButtonCalc->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->ButtonCalc->Location = System::Drawing::Point(10, 283);
			this->ButtonCalc->Name = L"ButtonCalc";
			this->ButtonCalc->Size = System::Drawing::Size(70, 60);
			this->ButtonCalc->TabIndex = 33;
			this->ButtonCalc->Text = L"=";
			this->ButtonCalc->UseVisualStyleBackColor = true;
			this->ButtonCalc->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::ButtonCalc_MouseMove);
			this->ButtonCalc->Click += gcnew System::EventHandler(this, &Form1::ButtonCalc_Click);
			// 
			// ButtonMines
			// 
			this->ButtonMines->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->ButtonMines->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Bold));
			this->ButtonMines->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->ButtonMines->Location = System::Drawing::Point(10, 151);
			this->ButtonMines->Name = L"ButtonMines";
			this->ButtonMines->Size = System::Drawing::Size(70, 60);
			this->ButtonMines->TabIndex = 31;
			this->ButtonMines->Text = L"—";
			this->ButtonMines->UseVisualStyleBackColor = true;
			this->ButtonMines->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::ButtonMines_MouseMove);
			this->ButtonMines->Click += gcnew System::EventHandler(this, &Form1::ButtonMines_Click);
			// 
			// ButtonMult
			// 
			this->ButtonMult->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->ButtonMult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold));
			this->ButtonMult->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->ButtonMult->Location = System::Drawing::Point(10, 217);
			this->ButtonMult->Name = L"ButtonMult";
			this->ButtonMult->Size = System::Drawing::Size(70, 60);
			this->ButtonMult->TabIndex = 32;
			this->ButtonMult->Text = L"•";
			this->ButtonMult->UseVisualStyleBackColor = true;
			this->ButtonMult->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::ButtonMult_MouseMove);
			this->ButtonMult->Click += gcnew System::EventHandler(this, &Form1::ButtonMult_Click);
			// 
			// ButtonPlus
			// 
			this->ButtonPlus->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->ButtonPlus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold));
			this->ButtonPlus->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->ButtonPlus->Location = System::Drawing::Point(10, 85);
			this->ButtonPlus->Name = L"ButtonPlus";
			this->ButtonPlus->Size = System::Drawing::Size(70, 60);
			this->ButtonPlus->TabIndex = 30;
			this->ButtonPlus->Text = L"+";
			this->ButtonPlus->UseVisualStyleBackColor = true;
			this->ButtonPlus->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::ButtonPlus_MouseMove);
			this->ButtonPlus->Click += gcnew System::EventHandler(this, &Form1::ButtonPlus_Click);
			// 
			// TBPole2
			// 
			this->TBPole2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(254)));
			this->TBPole2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->TBPole2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->TBPole2->Location = System::Drawing::Point(10, 44);
			this->TBPole2->Name = L"TBPole2";
			this->TBPole2->ReadOnly = true;
			this->TBPole2->Size = System::Drawing::Size(557, 35);
			this->TBPole2->TabIndex = 29;
			this->TBPole2->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::TBPole2_MouseMove);
			// 
			// TBPole1
			// 
			this->TBPole1->BackColor = System::Drawing::Color::White;
			this->TBPole1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->TBPole1->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->TBPole1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->TBPole1->Location = System::Drawing::Point(10, 10);
			this->TBPole1->Name = L"TBPole1";
			this->TBPole1->ReadOnly = true;
			this->TBPole1->Size = System::Drawing::Size(557, 35);
			this->TBPole1->TabIndex = 55;
			this->TBPole1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::TBPole1_MouseMove);
			// 
			// LabelHelp
			// 
			this->LabelHelp->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->LabelHelp->Cursor = System::Windows::Forms::Cursors::Default;
			this->LabelHelp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->LabelHelp->Location = System::Drawing::Point(10, 350);
			this->LabelHelp->Name = L"LabelHelp";
			this->LabelHelp->Size = System::Drawing::Size(1023, 25);
			this->LabelHelp->TabIndex = 57;
			this->LabelHelp->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->LabelHelp->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::LabelHelp_MouseMove);
			// 
			// BoxDGV2
			// 
			this->BoxDGV2->Controls->Add(this->ButtonEquate);
			this->BoxDGV2->Controls->Add(this->ButtonNew);
			this->BoxDGV2->Controls->Add(this->ButtonUse);
			this->BoxDGV2->Controls->Add(this->Numeric);
			this->BoxDGV2->Controls->Add(this->DGV2);
			this->BoxDGV2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->BoxDGV2->Location = System::Drawing::Point(806, 10);
			this->BoxDGV2->Name = L"BoxDGV2";
			this->BoxDGV2->Size = System::Drawing::Size(227, 333);
			this->BoxDGV2->TabIndex = 55;
			this->BoxDGV2->TabStop = false;
			this->BoxDGV2->Text = L"Объявление полиномов";
			// 
			// ButtonNew
			// 
			this->ButtonNew->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->ButtonNew->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->ButtonNew->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->ButtonNew->Location = System::Drawing::Point(6, 303);
			this->ButtonNew->Name = L"ButtonNew";
			this->ButtonNew->Size = System::Drawing::Size(50, 24);
			this->ButtonNew->TabIndex = 51;
			this->ButtonNew->Text = L"Новый";
			this->ButtonNew->UseVisualStyleBackColor = true;
			this->ButtonNew->Click += gcnew System::EventHandler(this, &Form1::ButtonNew_Click);
			// 
			// ButtonUse
			// 
			this->ButtonUse->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->ButtonUse->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->ButtonUse->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->ButtonUse->Location = System::Drawing::Point(62, 273);
			this->ButtonUse->Name = L"ButtonUse";
			this->ButtonUse->Size = System::Drawing::Size(159, 24);
			this->ButtonUse->TabIndex = 50;
			this->ButtonUse->Text = L"Использовать";
			this->ButtonUse->UseVisualStyleBackColor = true;
			this->ButtonUse->Click += gcnew System::EventHandler(this, &Form1::ButtonUse_Click);
			// 
			// Numeric
			// 
			this->Numeric->BackColor = System::Drawing::Color::White;
			this->Numeric->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold));
			this->Numeric->Location = System::Drawing::Point(6, 275);
			this->Numeric->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {0, 0, 0, 0});
			this->Numeric->Name = L"Numeric";
			this->Numeric->Size = System::Drawing::Size(50, 22);
			this->Numeric->TabIndex = 27;
			// 
			// DGV2
			// 
			this->DGV2->AllowUserToAddRows = false;
			this->DGV2->BackgroundColor = System::Drawing::SystemColors::Control;
			this->DGV2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->DGV2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DGV2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->dataGridViewTextBoxColumn1, 
				this->dataGridViewTextBoxColumn2});
			this->DGV2->EnableHeadersVisualStyles = false;
			this->DGV2->Location = System::Drawing::Point(6, 19);
			this->DGV2->Name = L"DGV2";
			this->DGV2->RowHeadersVisible = false;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->DGV2->RowsDefaultCellStyle = dataGridViewCellStyle2;
			this->DGV2->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->DGV2->Size = System::Drawing::Size(215, 250);
			this->DGV2->TabIndex = 26;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"Имя";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ReadOnly = true;
			this->dataGridViewTextBoxColumn1->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridViewTextBoxColumn1->Width = 64;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Полином";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->ReadOnly = true;
			this->dataGridViewTextBoxColumn2->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridViewTextBoxColumn2->Width = 132;
			// 
			// ButtonEquate
			// 
			this->ButtonEquate->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->ButtonEquate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->ButtonEquate->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->ButtonEquate->Location = System::Drawing::Point(62, 303);
			this->ButtonEquate->Name = L"ButtonEquate";
			this->ButtonEquate->Size = System::Drawing::Size(159, 24);
			this->ButtonEquate->TabIndex = 52;
			this->ButtonEquate->Text = L"Присвоить";
			this->ButtonEquate->UseVisualStyleBackColor = true;
			this->ButtonEquate->Click += gcnew System::EventHandler(this, &Form1::ButtonEquate_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(1040, 383);
			this->Controls->Add(this->BoxDGV2);
			this->Controls->Add(this->LabelHelp);
			this->Controls->Add(this->ButtonExit);
			this->Controls->Add(this->ButtonCE);
			this->Controls->Add(this->ButtonMonomCancel);
			this->Controls->Add(this->BoxDGV);
			this->Controls->Add(this->ButtonBracketOpen);
			this->Controls->Add(this->ButtonBracketClose);
			this->Controls->Add(this->TBLetterAdd);
			this->Controls->Add(this->ButtonLetterAdd);
			this->Controls->Add(this->TBPowerAdd);
			this->Controls->Add(this->ButtonPowerAdd);
			this->Controls->Add(this->ButtonCancel);
			this->Controls->Add(this->ButtonComma);
			this->Controls->Add(this->Button4);
			this->Controls->Add(this->Button0);
			this->Controls->Add(this->Button9);
			this->Controls->Add(this->Button2);
			this->Controls->Add(this->Button5);
			this->Controls->Add(this->Button1);
			this->Controls->Add(this->Button7);
			this->Controls->Add(this->Button8);
			this->Controls->Add(this->Button6);
			this->Controls->Add(this->Button3);
			this->Controls->Add(this->ButtonCalc);
			this->Controls->Add(this->ButtonMines);
			this->Controls->Add(this->ButtonMult);
			this->Controls->Add(this->ButtonPlus);
			this->Controls->Add(this->TBPole2);
			this->Controls->Add(this->TBPole1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Полиномиальный калькулятор";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->BoxDGV->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DGV))->EndInit();
			this->BoxDGV2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Numeric))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DGV2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	int LetterLast;	//Предыдущий символ записанный в TBLetterAdd
	bool FlagTBLetterAddChanged;	//Показывает, изменили ли мы уже TBLetterAdd
	String ^NumberTBPowerAddLast;	//Предыдущая строка записанная в TBPowerAdd
	bool FlagTBPowerAddChanged;	//Показывает, изменили ли мы уже TBPowerAdd
	String ^SimbolsEnglish;	//Строка символов, состоящая из букв латинского алфавита
	String ^SimbolsNumbers;	//Строка символов, состоящая из цифр
	String ^SimbolsMonom;	//Строка символов, входящих в моном
	String ^SimbolsNumbersComma;	//Строка символов, состоящая из цифр и запятой
	String ^SimbolsOperations;	//Строка символов, состоящая из арифметических операций
	String ^SimbolsOperAndBracket;	//Строка для поиска сохранённого полинома
	int NumOfBrackets;	//Кол-во незакрытых скобок в TBPole2
	int NumOfLetters;	//Количество используемых переменных
	int NumOfPolynums;	//Количество сохранённых полиномов
	int SavePolynom;	//Запоминает, в какую ячейку сохранить полином
	Variable *Variables;		//Список переменных


	/*---------------------------------------------------------------------------------------------------*/
								//При запуске приложения сделать следующее//

private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
	LetterLast = -1;	//Предыдущий символ записанный в TBLetterAdd
	FlagTBLetterAddChanged = false;	//Показывает, изменили ли мы уже TBLetterAdd
	NumberTBPowerAddLast = "";	//Предыдущая строка записанная в TBPowerAdd
	FlagTBPowerAddChanged = false;	//Показывает, изменили ли мы уже TBPowerAdd
	SimbolsEnglish = "abcdefghijklmnopqrstuvwxyz";	//Строка символов из букв латинского алфавита
	SimbolsNumbers = "0123456789";	//Строка символов, состоящая из цифр
	SimbolsMonom = "0123456789,abcdefghijklmnopqrstuvwxyz[]";	//Строка символов, входящих в моном
	SimbolsNumbersComma = "0123456789,";	//Строка символов, состоящая из цифр и запятой
	SimbolsOperations = "+-*";	//Строка символов, состоящая из арифметических операций
	SimbolsOperAndBracket = "+-*(";	//Строка для поиска сохранённого полинома
	NumOfBrackets = 0;	//Кол-во незакрытых скобок в TBPole2
	NumOfLetters = 0;	//Количество используемых переменных
	NumOfPolynums = 1;	//Количество сохранённых полиномов
	SavePolynom = 0;	//Запоминает, в какую ячейку сохранить полином
	Variables = new Variable;		//Список переменных

	this->DGV2->RowCount = 1;
	this->DGV2->Rows[0]->Cells[0]->Value = "#0";
	this->DGV2->Rows[0]->Cells[1]->Value = "0";
}


	/*---------------------------------------------------------------------------------------------------*/
									// ******** MOUSE_MOVE ******** //

private: System::Void TBPole1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	MouseMoveClear();
	this->LabelHelp->Text = "Поле для выдачи результата";
}
private: System::Void TBPole2_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	MouseMoveClear();
	this->LabelHelp->Text = "Поле для ввода выражения";
}
private: System::Void ButtonPlus_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	MouseMoveClear();
	this->ButtonPlus->ForeColor = System::Drawing::Color::Red;
	this->LabelHelp->Text = "Операция сложения";
}
private: System::Void ButtonMines_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	MouseMoveClear();
	this->ButtonMines->ForeColor = System::Drawing::Color::Red;
	this->LabelHelp->Text = "Операция вычитания";
}
private: System::Void ButtonMult_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	MouseMoveClear();
	this->ButtonMult->ForeColor = System::Drawing::Color::Red;
	this->LabelHelp->Text = "Операция умножения";
}
private: System::Void ButtonCalc_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	MouseMoveClear();
	this->ButtonCalc->ForeColor = System::Drawing::Color::Red;
	this->LabelHelp->Text = "Вычислить результат";
}
private: System::Void Button0_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	MouseMoveClear();
	this->Button0->ForeColor = System::Drawing::Color::Red;
	this->LabelHelp->Text = "Ноль";
}
private: System::Void Button1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	MouseMoveClear();
	this->Button1->ForeColor = System::Drawing::Color::Red;
	this->LabelHelp->Text = "Один";
}
private: System::Void Button2_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	MouseMoveClear();
	this->Button2->ForeColor = System::Drawing::Color::Red;
	this->LabelHelp->Text = "Два";
}
private: System::Void Button3_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	MouseMoveClear();
	this->Button3->ForeColor = System::Drawing::Color::Red;
	this->LabelHelp->Text = "Три";
}
private: System::Void Button4_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	MouseMoveClear();
	this->Button4->ForeColor = System::Drawing::Color::Red;
	this->LabelHelp->Text = "Четыре";
}
private: System::Void Button5_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	MouseMoveClear();
	this->Button5->ForeColor = System::Drawing::Color::Red;
	this->LabelHelp->Text = "Пять";
}
private: System::Void Button6_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	MouseMoveClear();
	this->Button6->ForeColor = System::Drawing::Color::Red;
	this->LabelHelp->Text = "Шесть";
}
private: System::Void Button7_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	MouseMoveClear();
	this->Button7->ForeColor = System::Drawing::Color::Red;
	this->LabelHelp->Text = "Семь";
}
private: System::Void Button8_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	MouseMoveClear();
	this->Button8->ForeColor = System::Drawing::Color::Red;
	this->LabelHelp->Text = "Восемь";
}
private: System::Void Button9_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	MouseMoveClear();
	this->Button9->ForeColor = System::Drawing::Color::Red;
	this->LabelHelp->Text = "Девять";
}
private: System::Void TBPowerAdd_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	MouseMoveClear();
	this->LabelHelp->Text = "Поле для ввода степени переменной";
}
private: System::Void ButtonPowerAdd_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	MouseMoveClear();
	this->ButtonPowerAdd->ForeColor = System::Drawing::Color::Red;
	this->LabelHelp->Text = "Возвести переменную в степень";
}
private: System::Void TBLetterAdd_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	MouseMoveClear();
	this->LabelHelp->Text = "Поле для ввода переменной";
}
private: System::Void ButtonLetterAdd_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	MouseMoveClear();
	this->ButtonLetterAdd->ForeColor = System::Drawing::Color::Red;
	this->LabelHelp->Text = "Добавить переменную";
}
private: System::Void ButtonBracketOpen_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	MouseMoveClear();
	this->ButtonBracketOpen->ForeColor = System::Drawing::Color::Red;
	this->LabelHelp->Text = "Открывающаяся скобка";
}
private: System::Void ButtonBracketClose_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	MouseMoveClear();
	this->ButtonBracketClose->ForeColor = System::Drawing::Color::Red;
	this->LabelHelp->Text = "Закрывающаяся скобка";
}
private: System::Void ButtonComma_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	MouseMoveClear();
	this->ButtonComma->ForeColor = System::Drawing::Color::Red;
	this->LabelHelp->Text = "Запятая";
}
private: System::Void ButtonCancel_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	MouseMoveClear();
	this->ButtonCancel->ForeColor = System::Drawing::Color::Red;
	this->LabelHelp->Text = "Отмена";
}
private: System::Void ButtonMonomCancel_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	MouseMoveClear();
	this->ButtonMonomCancel->ForeColor = System::Drawing::Color::Red;
	this->LabelHelp->Text = "Отменить ввод монома";
}
private: System::Void ButtonCE_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	MouseMoveClear();
	this->ButtonCE->ForeColor = System::Drawing::Color::Red;
	this->LabelHelp->Text = "Очистить поле ввода выражения";
}
private: System::Void ButtonExit_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	MouseMoveClear();
	this->ButtonExit->ForeColor = System::Drawing::Color::Red;
	this->LabelHelp->Text = "Выйти из программы";
}
private: System::Void DGV_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	MouseMoveClear();
	this->LabelHelp->Text = "Таблица инициализации переменных";
}
private: System::Void LabelHelp_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	MouseMoveClear();
	this->LabelHelp->Text = "Справка";
}
private: System::Void Form1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	MouseMoveClear();
	this->LabelHelp->Text = "";
}

	/*---------------------------------------------------------------------------------------------------*/
								//Добавить операцию сложения в TBPole2//

private: System::Void ButtonPlus_Click(System::Object^  sender, System::EventArgs^  e) {
	MayPrintOperation(0);
}

		 
	/*---------------------------------------------------------------------------------------------------*/
								//Добавить операцию вычитания в TBPole2//

private: System::Void ButtonMines_Click(System::Object^  sender, System::EventArgs^  e) {
	PrintOperation(1);
}


	/*---------------------------------------------------------------------------------------------------*/
								//Добавить операцию умножения в TBPole2//

private: System::Void ButtonMult_Click(System::Object^  sender, System::EventArgs^  e) {
	MayPrintOperation(2);
}


	/*---------------------------------------------------------------------------------------------------*/
									//Добавить цифру "0" в TBPole2//

private: System::Void Button0_Click(System::Object^  sender, System::EventArgs^  e) {
	if (this->TBPole2->TextLength == 0){	//Если в TBPole2 нет символов
		PrintNumber(0);		//Записываем "ноль"
	}
	if (this->TBPole2->TextLength > 1){	//Если в TBPole2 что-то написано
		//Цифру "0" можно ставить только после какой-либо цифры
		if ( (this->TBPole2->Text[this->TBPole2->TextLength-1] != '0') || (SimbolsOperations->IndexOf(this->TBPole2->Text[this->TBPole2->TextLength-2]) == -1) ){	
			//Если предыдущий символ - не "ноль" или предпредыдущий символ - не операция, то...
			PrintNumber(0);		//... можем записывать "ноль"
		}
	}
	if (this->TBPole2->TextLength == 1){	//Если в TBPole2 записан один символ...
		if (this->TBPole2->Text[0] != '0'){	//...и этот символ - не "ноль", то...
			PrintNumber(0);		//...записываем "ноль"
		}
	}
}

	/*---------------------------------------------------------------------------------------------------*/
									//Добавить цифру "1" в TBPole2//

private: System::Void Button1_Click(System::Object^  sender, System::EventArgs^  e) {
	PrintNumber(1);
}

	/*---------------------------------------------------------------------------------------------------*/
									//Добавить цифру "2" в TBPole2//

private: System::Void Button2_Click(System::Object^  sender, System::EventArgs^  e) {
	PrintNumber(2);
}

	/*---------------------------------------------------------------------------------------------------*/
									//Добавить цифру "3" в TBPole2//

private: System::Void Button3_Click(System::Object^  sender, System::EventArgs^  e) {
	PrintNumber(3);
}

	/*---------------------------------------------------------------------------------------------------*/
									//Добавить цифру "4" в TBPole2//

private: System::Void Button4_Click(System::Object^  sender, System::EventArgs^  e) {
	PrintNumber(4);
}

	/*---------------------------------------------------------------------------------------------------*/
									//Добавить цифру "5" в TBPole2//

private: System::Void Button5_Click(System::Object^  sender, System::EventArgs^  e) {
	PrintNumber(5);
}

	/*---------------------------------------------------------------------------------------------------*/
									//Добавить цифру "6" в TBPole2//

private: System::Void Button6_Click(System::Object^  sender, System::EventArgs^  e) {
	PrintNumber(6);
}

	/*---------------------------------------------------------------------------------------------------*/
									//Добавить цифру "7" в TBPole2//

private: System::Void Button7_Click(System::Object^  sender, System::EventArgs^  e) {
	PrintNumber(7);
}

	/*---------------------------------------------------------------------------------------------------*/
									//Добавить цифру "8" в TBPole2//

private: System::Void Button8_Click(System::Object^  sender, System::EventArgs^  e) {
	PrintNumber(8);
}

	/*---------------------------------------------------------------------------------------------------*/
									//Добавить цифру "9" в TBPole2//

private: System::Void Button9_Click(System::Object^  sender, System::EventArgs^  e) {
	PrintNumber(9);
}


	/*---------------------------------------------------------------------------------------------------*/
									//Добавить запятую в TBPole2//

private: System::Void ButtonComma_Click(System::Object^  sender, System::EventArgs^  e) {
	int I = this->TBPole2->TextLength-1;
	String ^S = "";	//Эту строку мы добавим к TBPole2, в зависимости от ситуации она может быть равна "," или "0,"
	bool FlagMayPrintComma = true;	//Показывает, можно ли ставить запятую
	while ( (I > -1) && (SimbolsNumbersComma->IndexOf(this->TBPole2->Text[I]) > -1) ){	//Идём "влево" по TBPole2, пока встречаются цифры и запятые
		if (this->TBPole2->Text[I] == ','){	//И вот как раз, если встретили запятую,...
			FlagMayPrintComma = false;	//...то её ставить нельзя, т.к. она уже поставлена, флаг опускаем
			break;
		}
		I--;
	}
	if (FlagMayPrintComma == true){	//Если запятую поставить позволительно, то...
		S = ",";	//...ставим
	}
	//Существуют и другие варианты:
	if ( (this->TBPole2->TextLength == 0) ){
		S = "0,";	//Если поле пустое - поставим "0,"
	}
	if ( (this->TBPole2->TextLength > 0) && (this->TBPole2->Text[this->TBPole2->TextLength-1] == ']') ){
		S = "0,";	//После фигурной скобки поставим "0,"
	}
	if ( (this->TBPole2->TextLength > 0) && (this->TBPole2->Text[this->TBPole2->TextLength-1] == '(') ){
		S = "0,";	//После открывающейся круглой скобки поставим "0,"
	}
	if ( (this->TBPole2->TextLength > 0) && (SimbolsOperations->IndexOf(this->TBPole2->Text[this->TBPole2->TextLength-1]) > -1) ){
		S = "0,";	//После операции ставим "0,"
	}
	this->TBPole2->Text += S;
}


	/*---------------------------------------------------------------------------------------------------*/
									//Удалить последний символ в TBPole2//

private: System::Void ButtonCancel_Click(System::Object^  sender, System::EventArgs^  e) {
	int I = this->TBPole2->TextLength-1;
	if (this->TBPole2->TextLength > 0){
		if (this->TBPole2->Text[this->TBPole2->TextLength-1] == ']'){	//Если встретили квадратную скобку...
			while (this->TBPole2->Text[I] != '['){	//...стираем всё до открывающейся скобки
				DeleteLastSimbol();
				I--;
			}
		}
		if (this->TBPole2->TextLength > 3){
			if (this->TBPole2->Text->Substring(this->TBPole2->TextLength-3, 3) == " = "){
				this->TBPole2->Text = "";
			}
		}
	}
	if ((this->TBPole2->TextLength > 0) && (this->TBPole2->Text[this->TBPole2->TextLength-1] == '(')){	//Если встретили круглую открывающуюся скобку...
		DeleteLastSimbol();	//...удаляем...
		NumOfBrackets--;	//...уменьшаем счетчик незакрытых скобок
	}
	else if ((this->TBPole2->TextLength > 0) && (this->TBPole2->Text[this->TBPole2->TextLength-1] == ')')){	//Если встретили круглую закрывающуюся скобку...
		DeleteLastSimbol();	//...удаляем...
		NumOfBrackets++;	//...увеличиваем счетчик незакрытых скобок
	}
	else{
		DeleteLastSimbol();
	}
}


	/*---------------------------------------------------------------------------------------------------*/
									//Изменение числа в TBPowerAdd//

private: System::Void TBPowerAdd_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	int I;
	String ^S = this->TBPowerAdd->Text;	//Просто S писать короче, чем this->TBPowerAdd->Text :-)
	bool FlagAllRight = true;	//Показывает, что выражение в TBPowerAdd состоит только из цифр
	if (FlagTBPowerAddChanged == false){	//Если функция вызывается впервые
		for (I=0; I<S->Length; I++){
			if (SimbolsNumbers->IndexOf(S[I]) == -1){	//Для каждого символа из TBPowerAdd проверяем, цифра ли это?
				FlagAllRight = false;	//Если хотя бы один символ - не цифра, то FlagAllRight = false
			}
		}
		if (FlagAllRight == false){	//Если хотя бы один символ - не цифра, то
			FlagTBPowerAddChanged = true;	//Блокируем возможность входа в функцию, пока мы не выполним до конца эту
			this->TBPowerAdd->Text = NumberTBPowerAddLast;	//Так как какой-то из символов - не цифра,..
							//...то записываем выражение, которое стояло в TBPowerAdd до ввода нового символа
		}
		NumberTBPowerAddLast = this->TBPowerAdd->Text;	//Обновляем значение последнего ПРАВИЛЬНОГО выражения
		FlagTBPowerAddChanged = false;	//Всё! эту функцию выполнили, можно будет в неё зайти в другой раз
	}
}


	/*---------------------------------------------------------------------------------------------------*/
						//Добавление степени к переменной в TBPole2 числа из TBPowerAdd//

private: System::Void ButtonPowerAdd_Click(System::Object^  sender, System::EventArgs^  e) {
	if (this->TBPowerAdd->TextLength > 0){	//Если число ввели
		if (SimbolsEnglish->IndexOf(this->TBPole2->Text[this->TBPole2->TextLength-1]) > -1){	//Последний символ в TBPole2 - это переменная?
			Variables->ReWriteMaxPower (this->TBPole2->Text[this->TBPole2->TextLength-1], Convert::ToInt32(this->TBPowerAdd->Text)-1);	//Обновляем информацию о максимальной степени
			this->TBPole2->Text += "[" + this->TBPowerAdd->Text + "]";	//Возводим в степень
			this->TBPowerAdd->Text = "";		//Число изымаем, ну,... так красиво получиться
		}
	}
}


	/*---------------------------------------------------------------------------------------------------*/
									//Изменение символа в TBLetterAdd//

private: System::Void TBLetterAdd_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	char LetterNow;	//Настоящий символ записанный в TBLetterAdd
	if (FlagTBLetterAddChanged == false){	//Если функция вызывается впервые
		this->TBLetterAdd->Text = this->TBLetterAdd->Text->ToLower();	//Переводим большие символы в маленькие
		if (this->TBLetterAdd->Text->Length == 0){	//Если текстбокс пуст, то
			LetterNow = -1;	//Символа в TBLetterAdd не записали
		}
		if (this->TBLetterAdd->Text->Length == 1){	//Если есть один символ, то
			LetterNow = this->TBLetterAdd->Text[0];//Запоминаем его
		}
		if (this->TBLetterAdd->Text->Length >= 2){	//Если ввели больше одного символа, то
			//В зависимости от значения LetterLast мы оставляем в TBLetterAdd первый или второй символ:
			if (this->TBLetterAdd->Text[0] == LetterLast){	//Если первый символ такой же как LetterLast, то
				this->TBLetterAdd->Text = this->TBLetterAdd->Text[1].ToString();	//Оставляем второй символ	
			}else{											//Если второй символ такой же как LetterLast, то
				this->TBLetterAdd->Text = this->TBLetterAdd->Text[0].ToString();	//Оставляем первый символ	
			}
			LetterNow = this->TBLetterAdd->Text[0];//Запоминаем тот новый символ, который мы оставили в TBLetterAdd
		}
		if ((LetterNow > -1 && LetterNow < 97) || LetterNow > 122){	//Если символ не является латинской буквой, то
			FlagTBLetterAddChanged = true;	//Показыаем, что эта функция уже выполнена, заново её выполнять уже не надо
			if (LetterLast > -1){	//Если предыдущий символ был, то
				this->TBLetterAdd->Text = SimbolsEnglish[LetterLast-97].ToString();	//Возвращаем всё как было
			}else{	//Если предыдущего символа было, то
				this->TBLetterAdd->Text = "";	//Удаляем всю запись
			}
		}else{	//Если символ является латинской буквой, то
			LetterLast = LetterNow;//Запоминаем в LetterLast символ, который вписали в TBLetterAdd
		}
	}
	FlagTBLetterAddChanged = false;	//Эту функцию выполнили, можно выполнять другую
}


	/*---------------------------------------------------------------------------------------------------*/
									//Добавление переменной в TBPole2//

private: System::Void ButtoLetterAdd_Click(System::Object^  sender, System::EventArgs^  e) {
	bool FlagMayAddVariable = false;	//Можно ли добавить переменную
	if ((this->TBLetterAdd->TextLength == 1) && (this->TBPole2->TextLength > 0)){	//Если переменная введена и в TBPole2 что-то уже написано
		if (this->TBPole2->Text[this->TBPole2->TextLength-1] != ')'){	//Если последний символ - не закр. скобка...
			FlagMayAddVariable = true;		//...можно добавить переменную
		}
	}
	else if(this->TBLetterAdd->TextLength == 1){	//Если переменная введена
		FlagMayAddVariable = true;		//Mожно добавить переменную
	}
	if (FlagMayAddVariable == true){	//Если можно добавить переменную
		if (!Variables->HaveLetter(Convert::ToChar(this->TBLetterAdd->Text))){		//Если такой переменной ещё не было
			NumOfLetters++;							//Увеличиваем показатель количества переменных
			Variables->Add(Convert::ToChar(this->TBLetterAdd->Text));	//Добавляем переменную в список переменных
		}else{
			Variables->ReWriteMaxPower(Convert::ToChar(this->TBLetterAdd->Text), 1);
		}
		this->TBPole2->Text += this->TBLetterAdd->Text;		//Добавляем переменную в TBPole2
		ReWriteDGVvariables (Variables, NumOfLetters);		//Переписать DGV
	}
	this->TBLetterAdd->Text = "";	//Очистить TBLetterAdd
}


	/*---------------------------------------------------------------------------------------------------*/
								//Добавление открывающейся скобки в TBPole2//

private: System::Void ButtonBracketOpen_Click(System::Object^  sender, System::EventArgs^  e) {
	if (this->TBPole2->TextLength > 0){	//←Если TBPole2 не пустое и ↓ в нём последний символ - операция, либо ↓ другая открывающаяся скобка, ....................... либо ↓ пробел, то...
		if ((SimbolsOperations->IndexOf(this->TBPole2->Text[this->TBPole2->TextLength-1]) > -1) || (this->TBPole2->Text[this->TBPole2->TextLength-1] == '(') || (this->TBPole2->Text[this->TBPole2->TextLength-1] == ' ') ){
			this->TBPole2->Text += "(";	//Можно добавить скобку
			NumOfBrackets++;	//Увеличиваем кол-во незакрытых фигурных скобок
		}
		if (this->TBPole2->Text[this->TBPole2->TextLength-1] == ','){	//Если стоит запятая...
			DeleteLastSimbol();										//...удаляем её
		}
		char C = this->TBPole2->Text[this->TBPole2->TextLength-1];
		//Если последний символ - это ↓ переменная, ↓ цифра или закрывающаяся  ↓ скобка       ↓         ,то...
		if (SimbolsEnglish->IndexOf(C) > -1 || SimbolsNumbers->IndexOf(C) > -1 || C == ']' || C == ')'){
			this->TBPole2->Text += "*(";	//...добавим умножение и скобку
			NumOfBrackets++;	//Увеличиваем кол-во незакрытых фигурных скобок
		}
	}else{	//Если TBPole2 пустое - можно добавить скобку
		this->TBPole2->Text += "(";
		NumOfBrackets++;	//Увеличиваем кол-во незакрытых фигурных скобок
	}
}


	/*---------------------------------------------------------------------------------------------------*/
								//Добавление закрывающейся скобки в TBPole2//

private: System::Void ButtonBracketClose_Click(System::Object^  sender, System::EventArgs^  e) {
	if (NumOfBrackets > 0){	//Если есть незакрытые скобки
		if (this->TBPole2->Text[this->TBPole2->TextLength-1] == '('){	//Сразу после открытой скобки нельзя ставить закрывающуюся
			this->TBPole2->Text += "0";	//Надо поставить ноль, а потом через 5 строк вниз закрыть
		}
		if (this->TBPole2->Text[this->TBPole2->TextLength-1] == ','){	//Запятая???
			DeleteLastSimbol();	//Долой её!
		}
		if (SimbolsOperations->IndexOf(this->TBPole2->Text[this->TBPole2->TextLength-1]) == -1){
			this->TBPole2->Text += ")";	//Закрыть скобку, если ↑ последний символ не операция
			NumOfBrackets--;	//На одну незакрытую скобку стало меньше:)
		}
	}
}


	/*---------------------------------------------------------------------------------------------------*/
									//Удалить моном в TBPole2//

private: System::Void ButtonMonomCancel_Click(System::Object^  sender, System::EventArgs^  e) {
	int I = this->TBPole2->TextLength-1;	//Показывает количество символов в TBPole2
	if (I > -1){	//←Если чё-то вписали и ↓ последний символ либо операция, ................................ ↓ либо открывающаяся скобка, ............................... ↓ либо закрывающаяся скобка, то...
		if ( (SimbolsOperations->IndexOf(this->TBPole2->Text[this->TBPole2->TextLength-1]) > -1) || (this->TBPole2->Text[this->TBPole2->TextLength-1] == '(') || (this->TBPole2->Text[this->TBPole2->TextLength-1] == ')') ){
			this->ButtonCancel_Click(ButtonCancel,e);	//...просто удаляем его
			I--;	//Количество символов в TBPole2 стало на одну меньше
		}else{	//Если последнее условие не выполнилось, значит перед нами МОНОМ!
			while (I > -1){	
				if (this->TBPole2->Text[this->TBPole2->TextLength-1] == '('){							//И мы его
					break;																				//будем удалять,
				}																						//пока не
				if (SimbolsOperations->IndexOf(this->TBPole2->Text[this->TBPole2->TextLength-1]) > -1){	//встретяться
					break;																				//скобка
				}																						//либо
				this->ButtonCancel_Click(ButtonCancel,e);												//какой-нибудь
				I = this->TBPole2->TextLength-1;														//символ
			}
		}
	}
}


	/*---------------------------------------------------------------------------------------------------*/
									//Удалить содержимое TBPole2//

private: System::Void ButtonCE_Click(System::Object^  sender, System::EventArgs^  e) {
	this->TBPole1->Text = "";	//Удаляем содержимое TBPole1
	this->TBPole2->Text = "";	//Удаляем содержимое TBPole2
}


	/*---------------------------------------------------------------------------------------------------*/
							 //Изменение таблицы инициализации переменных//

private: System::Void DGV_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	int Col = e->ColumnIndex;   //Номер активного столбца
	int Row = e->RowIndex;      //Номер активной строки
	int Val = 0;	//Новое значение переменной

	if ((Col > -1) && (Row > -1)){
		try{   //Попробуй конвертировать строку в число
			Val = Convert::ToInt32(this->DGV->Rows[Row]->Cells[Col]->Value);
		}
		catch(System::Exception ^e){   //Если произошла ошибка при конвертировании строки в число
			this->DGV->Rows[Row]->Cells[1]->Value = 0;
			Val = 0;
		}
		Variables->ReWriteValue (Row, Val);
	}
}


	/*---------------------------------------------------------------------------------------------------*/
							   //Добавление нового полинома в таблицу//

private: System::Void ButtonNew_Click(System::Object^  sender, System::EventArgs^  e) {
	NumOfPolynums++;
	this->DGV2->RowCount = NumOfPolynums;
	this->DGV2->Rows[NumOfPolynums-1]->Cells[0]->Value = "#" + (NumOfPolynums-1).ToString();
	this->DGV2->Rows[NumOfPolynums-1]->Cells[1]->Value = "0";
	this->Numeric->Maximum = NumOfPolynums-1;
}

	/*---------------------------------------------------------------------------------------------------*/
								//Использовать сохранённый полином//

private: System::Void ButtonUse_Click(System::Object^  sender, System::EventArgs^  e) {
	if (this->TBPole2->TextLength != 0){
		char LastSymbol = this->TBPole2->Text[this->TBPole2->TextLength-1];
		if (LastSymbol == ','){
			DeleteLastSimbol();
		}
		if ((SimbolsMonom->IndexOf(LastSymbol) > -1)||(LastSymbol == ')')){
			this->TBPole2->Text += "*";
		}
	}
	this->TBPole2->Text += "[#" + this->Numeric->Value + "]";
}


	/*---------------------------------------------------------------------------------------------------*/
								//Сохранить полином в ячейку таблицы//

private: System::Void ButtonEquate_Click(System::Object^  sender, System::EventArgs^  e) {
	if (this->TBPole1->TextLength != 0){
		this->TBPole1->Text = "";
		this->TBPole2->Text = "";
	}
	if (this->TBPole2->TextLength == 0){
		if (Convert::ToInt32(this->Numeric->Value) != 0){
			this->TBPole2->Text += "[#" + this->Numeric->Value + "]=";
			SavePolynom = Convert::ToInt32(this->Numeric->Value);
		}
	}
}


	/*---------------------------------------------------------------------------------------------------*/
							//******************************************//

private: System::Void ButtonExit_Click(System::Object^  sender, System::EventArgs^  e) {
	//Form;

	//char* C;
	//C = new char[this->TBPole2->TextLength-1];
	//C = StrToChar(this->TBPole2->Text);
	//for (int I = 0; I<7; I++){
	//	this->TBPole1->Text += Convert::ToChar(C[I]).ToString();

	//}

	//String ^S = this->TBPole2->Text;
	//int N = this->TBPole2->TextLength;
	//char *C = new char[this->TBPole2->TextLength];
	//C = StrToChar(S);
	//Monom *M = new Monom;
	//M->InitializeMonom(C, N, 1, Variables);
	//this->TBPole1->Text += M->Alpha.ToString() + " " + M->PowerNum.ToString();

	//this->TBPole1->Text += " " + Variables->GetMaxPower(this->TBPowerAdd->Text[0]-48);

	
	Variables->First					= new Link('a', 1,  4);
	Variables->First->Next				= new Link('b', 1,  4);
	//Variables->First->Next->Next		= new Link('d', 1,  6);
	//Variables->First->Next->Next->Next	= new Link('f', 1, 10);

	Polynom *Pol1 = new Polynom;
	Pol1->First = new Monom(1 , 1);
	Pol1->First->Next = new Monom(1, 5);
	//Pol1->First->Next->Next = new Monom(1, 10);

	Polynom *Pol2 = new Polynom;
	Pol2->First = new Monom(1 , 1);
	Pol2->First->Next = new Monom(-1,  5);
	//Pol2->First->Next->Next = new Monom(-1, 6);
	
	Polynom Pol3 = *Pol1 * *Pol2;
	int t;

}


	/*---------------------------------------------------------------------------------------------------*/
									//Выполнить подсчёт полинома//

private: System::Void ButtonCalc_Click(System::Object^  sender, System::EventArgs^  e) {
	this->TBPole1->Text = "";
	int I, J;
	String ^STR;	//Строка, с кот. будем работать
	char *C;
	int Len;
	int Start;
	int StartPosition;
	stack *PolynomStack = new stack;
	stack *PolynomStackReverce = new stack;
	stack *VirtualPolynomStack = new stack;
	stack *OperationStack = new stack;
	stack *Record = new stack;
	stack *RecordReverce = new stack;
	stack *Calc = new stack;
	Polynom *Pol1 = new Polynom;
	Polynom *Pol2 = new Polynom;
	stack *ListOfPowers;
	stack *ListOfPowersReverce;
	int Conv;
	int Power;
	int Sign;
	int Result = 0;

	//Создание вычисляемого выражения
	StartPosition = 0;
	if (this->TBPole2->Text->IndexOf('=') > -1){
		StartPosition = this->TBPole2->Text->IndexOf('=') + 1;
	}else{
		this->TBPole2->Text = "=" + this->TBPole2->Text;
	}
	for (I=StartPosition ; I<this->TBPole2->TextLength; I++){
		if ((this->TBPole2->Text[I] == '[') && ((SimbolsOperAndBracket->IndexOf(this->TBPole2->Text[I-1]) > -1) || (this->TBPole2->Text[I-1]) == '=')){
			if (this->TBPole2->Text[I-1] == '-'){
				STR += "(-1)*";
			}
			I = I + 2;
			Len = 1;
			Start = I;
			while (SimbolsEnglish->IndexOf(this->TBPole2->Text[I+1]) > -1){
				Len++;
				I++;
			}
			I = I + 1;
			J = Convert::ToInt32(this->TBPole2->Text->Substring(Start, Len));
			STR += "(" + this->DGV2->Rows[J]->Cells[1]->Value + ")";
		}else if ((this->TBPole2->Text[I] == '-') && (this->TBPole2->Text[I+1] == '(')){
			STR += "+(-1)*";
		}else{
			STR += this->TBPole2->Text[I];
		}
	}

	if ((STR->Length > 0) && (NumOfBrackets == 0) && (SimbolsOperations->IndexOf(STR[STR->Length - 1]) == -1)){

		if (STR[STR->Length - 1] == ','){
			 DeleteLastSimbol();
		}
		if (STR[0] == '-'){
			STR = DeleteFirstMines(STR);
			STR = "(-1)*" + STR;
		}
		STR = AddSpace(STR);

		//***(1) Получение польской записи и упорядоченного списка одномономных полиномов
		for (I=0; I<STR->Length; I++){
			if (SimbolsMonom->IndexOf(STR[I])>-1){
				if (I >= 1 && STR[I-1] == '-'){
					Sign = -1;
				}else{
					Sign = 1;
				}
				Len = 1;
				Start = I;
				while (I<STR->Length-1 && SimbolsMonom->IndexOf(STR[I+1])>-1){
					Len++;
					I++;
				} 
				C = new char[Len];
				C = StrToChar(STR->Substring(Start, Len));
				Pol1->First = new Monom;
				Pol1->First->InitializeMonom(C, Len, Sign, Variables);
				PolynomStackReverce->Put(Pol1);
				VirtualPolynomStack->Put(1);
			}
			else if ((STR[I] == '+') || (STR[I] == '-')){
				if (!OperationStack->IsEmpty() && OperationStack->SeeOp() == 3){
					while (VirtualPolynomStack->Quantity() != 0){
						RecordReverce->Put(1);
						VirtualPolynomStack->Delete();
					}
					while (!OperationStack->IsEmpty() && OperationStack->SeeOp() != 4){
						RecordReverce->Put(OperationStack->SeeOp());
						OperationStack->Delete();
					}
				}
				OperationStack->Put(2);
				if (((STR[I] == '-')&&(I==0)) || ((STR[I] == '-')&&(I>0)&&(STR[I-1]=='('))){
					OperationStack->Delete();
				}

			}
			else if (STR[I] == '*'){
				OperationStack->Put(3);
			}
			else if (STR[I] == '('){
				OperationStack->Put(4);
			}
			else if (STR[I] == ')'){
				while (!VirtualPolynomStack->IsEmpty()){
					RecordReverce->Put(1);
					VirtualPolynomStack->Delete();
				}
				while (OperationStack->SeeOp() != 4){
					RecordReverce->Put(OperationStack->SeeOp());
					OperationStack->Delete();
				}
				OperationStack->Delete();
			}
		}

		while (VirtualPolynomStack->Quantity() != 0){
			RecordReverce->Put(1);
			VirtualPolynomStack->Delete();
		}
		while (!OperationStack->IsEmpty()){
			RecordReverce->Put(OperationStack->SeeOp());
			OperationStack->Delete();
		}

		while(!RecordReverce->IsEmpty()){
			Record->Put(RecordReverce->SeeOp());
			RecordReverce->Delete();
		}
		while(!PolynomStackReverce->IsEmpty()){
			PolynomStack->Put(&PolynomStackReverce->SeePol());
			PolynomStackReverce->Delete();
		}

		//***(2) Вычисление полинома-результата
		while (!Record->IsEmpty()){
			if (Record->SeeOp() == 1){
				Calc->Put(&PolynomStack->SeePol());
				PolynomStack->Delete();
			}
			else if (Record->SeeOp() == 2){
				*Pol1 = Calc->SeePol();
				Calc->Delete();
				*Pol2 = Calc->SeePol();
				Calc->Delete();
				Calc->Put(&(*Pol1 + *Pol2));
			}
			else if (Record->SeeOp() == 3){
				*Pol1 = Calc->SeePol();
				Calc->Delete();
				*Pol2 = Calc->SeePol();
				Calc->Delete();
				Calc->Put(&(*Pol1 * *Pol2));
			}
			Record->Delete();
		}

		//***(3) Преобразование полинома-результата
		int R;
		while (Calc->First->Pol->First != NULL){
			R = 0;
			if((Calc->First->Pol->First->Alpha > 0) && (this->TBPole1->TextLength > 0)){
				this->TBPole1->Text += "+";
			}
			if (Calc->First->Pol->First->Alpha != 1){
				this->TBPole1->Text += Calc->First->Pol->First->Alpha.ToString();
			}
			R += Calc->First->Pol->First->Alpha;
			ListOfPowersReverce = new stack();
			ListOfPowers = new stack();
			Conv = Calc->First->Pol->First->PowerNum;
			for (I=0; I<NumOfLetters-1; I++){
				ListOfPowersReverce->Put(RestOfDiv(Conv, Variables->GetMaxPowerAll()+1));
				Conv = IntOfDiv(Conv, Variables->GetMaxPowerAll()+1);
			}ListOfPowersReverce->Put(Conv);
			
			while(!ListOfPowersReverce->IsEmpty()){
				ListOfPowers->Put(ListOfPowersReverce->SeeOp());
				ListOfPowersReverce->Delete();
			}
			
			for (I=0; I<NumOfLetters; I++){
				if (ListOfPowers->SeeOp() == 1){
					this->TBPole1->Text += (Convert::ToChar(Variables->GetLetter(I))).ToString();
					R = R * PowIntOnInt(Variables->GetValueByNumber(I), 1);
				}
				else if(ListOfPowers->SeeOp() > 1){
					this->TBPole1->Text += (Convert::ToChar(Variables->GetLetter(I))).ToString();
					this->TBPole1->Text += "[" + ListOfPowers->SeeOp().ToString() + "]";
					R = R * PowIntOnInt(Variables->GetValueByNumber(I), ListOfPowers->SeeOp());
				}
				ListOfPowers->Delete();
			}
			Result += R;
			Calc->First->Pol->First = Calc->First->Pol->First->Next;
		}
		bool FlagNoZero = false;
		for (J=0; J<NumOfLetters; J++){
			if(Variables->GetValueByNumber(J) != 0){
				FlagNoZero = true;
			}
		}
		this->DGV2->Rows[SavePolynom]->Cells[1]->Value = this->TBPole1->Text;	//Сохранить полином
		if (FlagNoZero){
			this->TBPole1->Text += " = " + Result.ToString();
		}
	}

	SavePolynom = 0;

}















};
}

