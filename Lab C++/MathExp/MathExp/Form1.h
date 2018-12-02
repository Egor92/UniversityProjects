#pragma once
#include "stack.h"

namespace MathExp {

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
	private: System::Windows::Forms::TextBox^  TBVvod;
	private: System::Windows::Forms::TextBox^  TBVyrazhenie;

	protected: 

	private: System::Windows::Forms::Label^  LabelVvod;
	private: System::Windows::Forms::Label^  LabelVyrazhenie;
	private: System::Windows::Forms::Button^  ButtonDo;
	private: System::Windows::Forms::Label^  LabelHelp;
	private: System::Windows::Forms::Label^  LabelVSkobkakh;
	private: System::Windows::Forms::TextBox^  TBVSkobkakh;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;


	void PrintNuStack (stack NuStack, String ^STR, bool TB){
		double *DA;
		DA = new double[STR->Length];
		stack DStack(STR->Length,DA);
		while (!NuStack.IsEmpty()){
			DStack.Put( NuStack.Get() );
		}
		while (!DStack.IsEmpty()){
			if (TB == true){
				this->TBVyrazhenie->Text += DStack.Get().ToString() + " ";
			}else{
				this->TBVSkobkakh->Text += DStack.Get().ToString() + " ";
			}
		}
	}

	void CalcResult(bool FlagExp){
		String ^SimbolAll = "0123456789+-*/(){}, ";
		String ^SimbolNumber = "0123456789,";
		String ^SimbolOperation = "+-*/(){}";
		String ^STR = "";

		int J,I,Len;
		double DS1, DS2;

		if (FlagExp == true){
			STR = this->TBVyrazhenie->Text + "  ";
		}else{
			STR = this->TBVSkobkakh->Text + "  ";
		}

		double *DA;
		DA = new double[STR->Length];
		stack DStack(STR->Length,DA);

		for (I=0;I<STR->Length;I++){
			if (SimbolNumber->IndexOf(STR[I])>-1){
				Len = 1;
				J = I;
				while (I<STR->Length-1 && SimbolNumber->IndexOf(STR[I+1])>-1){
					Len++;
					I++;
				} 
				DStack.Put(Convert::ToDouble(STR->Substring(J,Len)));
			}
			if (STR[I]==' '){}
			if (STR[I]=='+'){
				DS1 = DStack.Get();
				DS2 = DStack.Get();
				DStack.Put(DS2 + DS1);
			}
			if (STR[I]=='-'){
				DS1 = DStack.Get();
				DS2 = DStack.Get();
				DStack.Put(DS2 - DS1);
			}
			if (STR[I]=='*'){
				DS1 = DStack.Get();
				DS2 = DStack.Get();
				DStack.Put(DS2 * DS1);
			}
			if (STR[I]=='/'){
				DS1 = DStack.Get();
				DS2 = DStack.Get();
				DStack.Put(DS2 / DS1);
			}
		}

		if (FlagExp == true){
			this->TBVyrazhenie->Text += "= " + DStack.Get().ToString();
		}else{
			this->TBVSkobkakh->Text += "= " + DStack.Get().ToString();
		}

	}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->TBVvod = (gcnew System::Windows::Forms::TextBox());
			this->TBVyrazhenie = (gcnew System::Windows::Forms::TextBox());
			this->LabelVvod = (gcnew System::Windows::Forms::Label());
			this->LabelVyrazhenie = (gcnew System::Windows::Forms::Label());
			this->ButtonDo = (gcnew System::Windows::Forms::Button());
			this->LabelHelp = (gcnew System::Windows::Forms::Label());
			this->LabelVSkobkakh = (gcnew System::Windows::Forms::Label());
			this->TBVSkobkakh = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// TBVvod
			// 
			resources->ApplyResources(this->TBVvod, L"TBVvod");
			this->TBVvod->Name = L"TBVvod";
			this->TBVvod->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::TBVvod_MouseMove);
			// 
			// TBVyrazhenie
			// 
			resources->ApplyResources(this->TBVyrazhenie, L"TBVyrazhenie");
			this->TBVyrazhenie->Name = L"TBVyrazhenie";
			this->TBVyrazhenie->ReadOnly = true;
			this->TBVyrazhenie->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::TBVyrazhenie_MouseMove);
			// 
			// LabelVvod
			// 
			resources->ApplyResources(this->LabelVvod, L"LabelVvod");
			this->LabelVvod->Name = L"LabelVvod";
			// 
			// LabelVyrazhenie
			// 
			resources->ApplyResources(this->LabelVyrazhenie, L"LabelVyrazhenie");
			this->LabelVyrazhenie->Name = L"LabelVyrazhenie";
			// 
			// ButtonDo
			// 
			this->ButtonDo->Cursor = System::Windows::Forms::Cursors::UpArrow;
			this->ButtonDo->ForeColor = System::Drawing::SystemColors::ControlText;
			resources->ApplyResources(this->ButtonDo, L"ButtonDo");
			this->ButtonDo->Name = L"ButtonDo";
			this->ButtonDo->UseVisualStyleBackColor = true;
			this->ButtonDo->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::ButtonDo_MouseMove);
			this->ButtonDo->Click += gcnew System::EventHandler(this, &Form1::ButtonDo_Click);
			// 
			// LabelHelp
			// 
			this->LabelHelp->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->LabelHelp->Cursor = System::Windows::Forms::Cursors::Arrow;
			resources->ApplyResources(this->LabelHelp, L"LabelHelp");
			this->LabelHelp->Name = L"LabelHelp";
			this->LabelHelp->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::LabelHelp_MouseMove);
			// 
			// LabelVSkobkakh
			// 
			resources->ApplyResources(this->LabelVSkobkakh, L"LabelVSkobkakh");
			this->LabelVSkobkakh->Name = L"LabelVSkobkakh";
			// 
			// TBVSkobkakh
			// 
			resources->ApplyResources(this->TBVSkobkakh, L"TBVSkobkakh");
			this->TBVSkobkakh->Name = L"TBVSkobkakh";
			this->TBVSkobkakh->ReadOnly = true;
			this->TBVSkobkakh->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::TBVSkobkakh_MouseMove);
			// 
			// Form1
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->LabelVSkobkakh);
			this->Controls->Add(this->TBVSkobkakh);
			this->Controls->Add(this->LabelHelp);
			this->Controls->Add(this->ButtonDo);
			this->Controls->Add(this->LabelVyrazhenie);
			this->Controls->Add(this->LabelVvod);
			this->Controls->Add(this->TBVyrazhenie);
			this->Controls->Add(this->TBVvod);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

/*------------------------------------------------------------------------------*/
								//MOUSEMOVE//
private: System::Void ButtonDo_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->ButtonDo->ForeColor = System::Drawing::Color::Red;
	this->LabelHelp->Text = "Выполнить перевод и подсчёт исходного выражения";
}
private: System::Void LabelHelp_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->LabelHelp->Text = "Помощь";
}
private: System::Void TBVSkobkakh_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->LabelHelp->Text = "Окно для вывода результата перевода выражения в скобках";
}
private: System::Void TBVyrazhenie_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->LabelHelp->Text = "Окно для вывода результата перевода исходного выражения";
}
private: System::Void TBVvod_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->LabelHelp->Text = "Окно для ввода исходного выражения";
}
private: System::Void Form1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->LabelHelp->Text = "";
	this->ButtonDo->ForeColor = System::Drawing::Color::Black;
}

/*------------------------------------------------------------------------------*/



private: System::Void ButtonDo_Click(System::Object^  sender, System::EventArgs^  e) {
	String ^STR  = this->TBVvod->Text;
	String ^SimbolAll = "0123456789+-*/(){}, ";
	String ^SimbolNumber = "0123456789,";
	String ^SimbolOperation = "+-*/(){}";
	String ^SimbolOp = "+-*/";

	int H,J,I,Len;
	double K;
	bool FlagAllRightSimbol = true;
	bool FlagAllRightDrob = true;
	bool FlagAllRightSkobka1 = true;
	bool FlagAllRightSkobka2 = true;
	bool FlagAllRightSkobka  = true;
	bool FlagAllRightNuOp = true;

	double *OpA;
	double *NuA;
	double *Sk1A;
	double *Sk2A;
	double *NuOpA;
	OpA  = new double [STR->Length];
	NuA  = new double [STR->Length];
	Sk1A = new double [STR->Length];
	Sk2A = new double [STR->Length];
	NuOpA  = new double [STR->Length];
	stack OpStack(STR->Length,OpA);
	stack NuStack(STR->Length,NuA);
	stack Sk1Stack(STR->Length,Sk1A);
	stack Sk2Stack(STR->Length,Sk2A);
	stack NuOpStack(STR->Length,NuOpA);

	int *Start,*Finish;
	Start   = new int [STR->Length];
	Finish  = new int [STR->Length];
	double *S3A;
	S3A = new double [STR->Length];
	stack S3Stack(STR->Length,S3A);
	String ^SubSTR;
	int Counter = 0;
	double R;

	//Очистка экранов
	this->TBVyrazhenie->Text = "";
	this->TBVSkobkakh->Text = "";

	//Проверка на корректность исходного выражения
	for (I=0;I<STR->Length;I++){
		if (SimbolAll->IndexOf(STR[I]) == -1){
			this->TBVSkobkakh->Text += STR[I] + " ";
			FlagAllRightSimbol = false;
		}
		if (STR[I]==',' && (I==0 || I==STR->Length-1 || SimbolNumber->IndexOf(STR[I-1])==-1 || SimbolNumber->IndexOf(STR[I+1])==-1 )){
			FlagAllRightDrob = false;
		}
		if (STR[I] == '('){ Sk1Stack.Put(1); }
		if (STR[I] == ')' &&  Sk1Stack.IsEmpty() ){ FlagAllRightSkobka1=false; }
		if (STR[I] == ')' && !Sk1Stack.IsEmpty() ){ K = Sk1Stack.Get(); }
	}
	for (I=0;I<STR->Length;I++){
		if (STR[I] == '('){
			Sk2Stack.Put(1);
		}
		if (STR[I] == '{'){
			Sk2Stack.Put(2);
		}
		if (STR[I] == ')'){
			if (Sk2Stack.See() == 1){
				K = Sk2Stack.Get();
			}else{
				FlagAllRightSkobka = false;
			}
		}
		if (STR[I] == '}'){
			if (Sk2Stack.See() == 2){
				K = Sk2Stack.Get();
			}else{												
				FlagAllRightSkobka = false;
			}
		}
	}if (!Sk2Stack.IsEmpty()){
		FlagAllRightSkobka = false;
	}
	
	
	
	//Проверка на очерёдность чисел и операций
	for (I=0;I<STR->Length;I++){
		if (NuOpStack.IsEmpty() && SimbolOp->IndexOf(STR[I])>-1){
			FlagAllRightNuOp = false;
		}
		if (SimbolNumber->IndexOf(STR[I])>-1){
			if(NuOpStack.See() != 1){
				NuOpStack.Put(1);
				if(I < STR->Length-1){
					while (SimbolNumber->IndexOf(STR[I+1])>-1){
						I++;
						if (I == STR->Length){
							break;
						}
					}
				}
			}else{
				FlagAllRightNuOp = false;
			}
		}
		if (SimbolOp->IndexOf(STR[I])>-1){
			if(NuOpStack.See() == 2){
				FlagAllRightNuOp = false;
			}
			if(NuOpStack.See() == 1){
				NuOpStack.Put(2);
			}
		}
	}
	if (NuOpStack.See() == 2){
		FlagAllRightNuOp = false;
	}
	if (NuOpStack.IsEmpty()){
		FlagAllRightNuOp = true;
	}
	

	
	
	//Выдача ошибок
	if (FlagAllRightSimbol == false){
		this->TBVSkobkakh->Text += "- ошибка при вводе исходного выражения.  ";
	}
	if (FlagAllRightDrob == false){
		this->TBVSkobkakh->Text += "Ошибка при вводе дробного числа";
	}
	if (FlagAllRightSkobka == false){
		this->TBVSkobkakh->Text += "В исходном выражении неверно расставлены скобки.  ";
	}
	//if (FlagAllRightSkobka1 == false){
	//	this->TBVSkobkakh->Text += "В исходном выражении не хватает открывающейся скобки.  ";
	//}
	//if (!Sk1Stack.IsEmpty() ){
	//	this->TBVSkobkakh->Text += "В исходном выражении не хватает закрывающейся скобки.  ";
	//	FlagAllRightSkobka1 = false;
	//}
	if (FlagAllRightNuOp == false){
		this->TBVSkobkakh->Text += "В исходном выражении неверно расставлена очерёдность чисел и операций";
	}



	if (FlagAllRightSimbol == true && FlagAllRightSkobka1 == true && FlagAllRightDrob == true && FlagAllRightSkobka == true && FlagAllRightNuOp == true){
		//Вычислить всё выражение
		for (I=0;I<STR->Length;I++){
			if (SimbolNumber->IndexOf(STR[I])>-1){
				Len=1;
				J=I;
				while (I<STR->Length-1 && SimbolNumber->IndexOf(STR[I+1])>-1){
					Len++;
					I++;
				} 
				NuStack.Put(Convert::ToDouble(STR->Substring(J,Len)));
			}
			if (STR[I]==' '){}
			if (STR[I]=='+'){
				if (OpStack.See() < 4){
					PrintNuStack(NuStack, STR, true);
					NuStack.DeleteAll();
					while (!OpStack.IsEmpty() && OpStack.See() != 4){
						this->TBVyrazhenie->Text += SimbolOperation[OpStack.Get()].ToString() + " ";	
					}
				}
				OpStack.Put(0);
			}
			if (STR[I]=='-'){
				if (OpStack.See() < 4){
					PrintNuStack(NuStack, STR, true);
					NuStack.DeleteAll();
					while (!OpStack.IsEmpty() && OpStack.See() != 4){
						this->TBVyrazhenie->Text += SimbolOperation[OpStack.Get()].ToString() + " ";				
					}
				}
				OpStack.Put(1);
			}
			if (STR[I]=='*'){
				if (OpStack.See() > 1 && OpStack.See() < 4){
					PrintNuStack(NuStack, STR, true);
					NuStack.DeleteAll();
					while (!OpStack.IsEmpty() && ((OpStack.See() != 4) && (OpStack.See() != 0) && (OpStack.See() != 1))){
						this->TBVyrazhenie->Text += SimbolOperation[OpStack.Get()].ToString() + " ";				
					}
				}
				OpStack.Put(2);
			}
			if (STR[I]=='/'){
				if (OpStack.See() > 1 && OpStack.See() < 4){
					PrintNuStack(NuStack, STR, true);
					NuStack.DeleteAll();
					while (!OpStack.IsEmpty() && ((OpStack.See() != 4) && (OpStack.See() != 0) && (OpStack.See() != 1))){
						this->TBVyrazhenie->Text += SimbolOperation[OpStack.Get()].ToString() + " ";				
					}
				}
				OpStack.Put(3);
			}
			if (STR[I]=='(' || STR[I]=='{'){
				OpStack.Put(4);
			}
			if (STR[I]==')' || STR[I]=='}'){
				PrintNuStack(NuStack, STR, true);
				NuStack.DeleteAll();
				while (OpStack.See() != 4){
					this->TBVyrazhenie->Text += SimbolOperation[OpStack.Get()].ToString() + " ";				
				}
				OpStack.Dim--;
			}
		}

		PrintNuStack(NuStack, STR, true);
		NuStack.DeleteAll();
		while (!OpStack.IsEmpty()){
			this->TBVyrazhenie->Text += SimbolOperation[OpStack.Get()].ToString() + " ";				
		}
		CalcResult(true);


		//Вычислить {выражение}

		for (I=0;I<STR->Length;I++){
			if (STR[I] == '{'){
				Start[Counter] = I;
				S3Stack.Put(Counter);
				Counter++;
			}
			if (STR[I] == '}'){
				Finish[S3Stack.GetInt()] = I;
			}
		}

		for (H=0;H<Counter;H++){
			NuOpStack.DeleteAll();
			SubSTR = STR->Substring(Start[H]+1,Finish[H]-Start[H]-1);
			for (I=0;I<SubSTR->Length;I++){
				if (NuOpStack.IsEmpty() && SimbolOp->IndexOf(SubSTR[I])>-1){
					FlagAllRightNuOp = false;
				}
				if (SimbolNumber->IndexOf(SubSTR[I])>-1){
					if((NuOpStack.See() == 2)||(NuOpStack.See() == 0)){
						NuOpStack.Put(1);
						if(I < SubSTR->Length-1){
							while (SimbolNumber->IndexOf(SubSTR[I+1])>-1){
								I++;
								if (I == SubSTR->Length){
									break;
								}
							}
						}
					}else{
						FlagAllRightNuOp = false;
					}
				}
				if (SimbolOp->IndexOf(SubSTR[I])>-1){
					if(NuOpStack.See() == 2){
						FlagAllRightNuOp = false;
					}
					if(NuOpStack.See() == 1){
						NuOpStack.Put(2);
					}
				}
			}
			if (NuOpStack.See() == 2){
				FlagAllRightNuOp = false;
			}
			if (NuOpStack.IsEmpty()){
				FlagAllRightNuOp = true;
			}


			if (FlagAllRightNuOp == false){
				this->TBVSkobkakh->Text += "В выражении в фигурных скобках неверно расставлена очерёдность чисел и операций";				
			}

			if (FlagAllRightNuOp == true){
				for (I=0;I<SubSTR->Length;I++){
					if (SimbolNumber->IndexOf(SubSTR[I])>-1){
						Len=1;
						J=I;
						while (I<SubSTR->Length-1 && SimbolNumber->IndexOf(SubSTR[I+1])>-1){
							Len++;
							I++;
						} 
						NuStack.Put(Convert::ToDouble(SubSTR->Substring(J,Len)));
					}
					if (SubSTR[I]==' '){}
					if (SubSTR[I]=='+'){
						if (OpStack.See() < 4){
							PrintNuStack(NuStack, STR, false);
							NuStack.DeleteAll();
							while (!OpStack.IsEmpty() && OpStack.See() != 4){
								this->TBVSkobkakh->Text += SimbolOperation[OpStack.Get()].ToString() + " ";	
							}
						}
						OpStack.Put(0);
					}
					if (SubSTR[I]=='-'){
						if (OpStack.See() < 4){
							PrintNuStack(NuStack, STR, false);
							NuStack.DeleteAll();
							while (!OpStack.IsEmpty() && OpStack.See() != 4){
								this->TBVSkobkakh->Text += SimbolOperation[OpStack.Get()].ToString() + " ";				
							}
						}
						OpStack.Put(1);
					}
					if (SubSTR[I]=='*'){
						if (OpStack.See() > 1 && OpStack.See() < 4){
							PrintNuStack(NuStack, STR, false);
							NuStack.DeleteAll();
							while (!OpStack.IsEmpty() && ((OpStack.See() != 4) && (OpStack.See() != 0) && (OpStack.See() != 1))){
								this->TBVSkobkakh->Text += SimbolOperation[OpStack.Get()].ToString() + " ";				
							}
						}
						OpStack.Put(2);
					}
					if (SubSTR[I]=='/'){
						if (OpStack.See() > 1 && OpStack.See() < 4){
							PrintNuStack(NuStack, STR, false);
							NuStack.DeleteAll();
							while (!OpStack.IsEmpty() && ((OpStack.See() != 4) && (OpStack.See() != 0) && (OpStack.See() != 1))){
								this->TBVSkobkakh->Text += SimbolOperation[OpStack.Get()].ToString() + " ";				
							}
						}
						OpStack.Put(3);
					}
					if (SubSTR[I]=='(' || SubSTR[I]=='{'){
						OpStack.Put(4);
					}
					if (SubSTR[I]==')' || SubSTR[I]=='}'){
						PrintNuStack(NuStack, SubSTR, false);
						NuStack.DeleteAll();
						while (OpStack.See() != 4){
							this->TBVSkobkakh->Text += SimbolOperation[OpStack.Get()].ToString() + " ";				
						}
						OpStack.Dim--;
					}
				}

				PrintNuStack(NuStack, SubSTR, false);
				NuStack.DeleteAll();
				while (!OpStack.IsEmpty()){
					this->TBVSkobkakh->Text += SimbolOperation[OpStack.Get()].ToString() + " ";				
				}
				
				CalcResult(false);
				this->TBVSkobkakh->Text += ";     ";
			}
		}




	}

}




};
		 

