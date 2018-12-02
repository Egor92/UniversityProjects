#pragma once
#include "drob.h"


namespace Simplex {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form1
	///
	/// Внимание! При изменении имени этого класса необходимо также изменить
	///          свойство имени файла ресурсов ("Resource File Name") для средства компиляции управляемого ресурса,
	///          связанного со всеми файлами с расширением .resx, от которых зависит данный класс. В противном случае,
	///          конструкторы не смогут правильно работать с локализованными
	///          ресурсами, сопоставленными данной форме.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  Chislo;
	protected: 
	private: System::Windows::Forms::Label^  Otvet;
	private: System::Windows::Forms::Button^  Mult;
	private: System::Windows::Forms::Label^  Otvet2;
	private: System::Windows::Forms::Button^  Podelit;
	private: System::Windows::Forms::TextBox^  Delitel;

	private: System::Windows::Forms::TextBox^  Znam;


	protected: 
	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Chislo = (gcnew System::Windows::Forms::TextBox());
			this->Otvet = (gcnew System::Windows::Forms::Label());
			this->Mult = (gcnew System::Windows::Forms::Button());
			this->Otvet2 = (gcnew System::Windows::Forms::Label());
			this->Podelit = (gcnew System::Windows::Forms::Button());
			this->Delitel = (gcnew System::Windows::Forms::TextBox());
			this->Znam = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// Chislo
			// 
			this->Chislo->Location = System::Drawing::Point(12, 207);
			this->Chislo->Multiline = true;
			this->Chislo->Name = L"Chislo";
			this->Chislo->Size = System::Drawing::Size(95, 24);
			this->Chislo->TabIndex = 0;
			this->Chislo->Text = L"1";
			// 
			// Otvet
			// 
			this->Otvet->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->Otvet->Location = System::Drawing::Point(9, 9);
			this->Otvet->Name = L"Otvet";
			this->Otvet->Size = System::Drawing::Size(202, 195);
			this->Otvet->TabIndex = 1;
			// 
			// Mult
			// 
			this->Mult->Location = System::Drawing::Point(12, 237);
			this->Mult->Name = L"Mult";
			this->Mult->Size = System::Drawing::Size(199, 29);
			this->Mult->TabIndex = 2;
			this->Mult->Text = L"Умножить на число";
			this->Mult->UseVisualStyleBackColor = true;
			this->Mult->Click += gcnew System::EventHandler(this, &Form1::Mult_Click);
			// 
			// Otvet2
			// 
			this->Otvet2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->Otvet2->Location = System::Drawing::Point(217, 9);
			this->Otvet2->Name = L"Otvet2";
			this->Otvet2->Size = System::Drawing::Size(197, 195);
			this->Otvet2->TabIndex = 3;
			// 
			// Podelit
			// 
			this->Podelit->Location = System::Drawing::Point(217, 237);
			this->Podelit->Name = L"Podelit";
			this->Podelit->Size = System::Drawing::Size(199, 29);
			this->Podelit->TabIndex = 5;
			this->Podelit->Text = L"Поделить на дробь №__";
			this->Podelit->UseVisualStyleBackColor = true;
			this->Podelit->Click += gcnew System::EventHandler(this, &Form1::Podelit_Click);
			// 
			// Delitel
			// 
			this->Delitel->Location = System::Drawing::Point(217, 207);
			this->Delitel->Multiline = true;
			this->Delitel->Name = L"Delitel";
			this->Delitel->Size = System::Drawing::Size(199, 24);
			this->Delitel->TabIndex = 4;
			this->Delitel->Text = L"0";
			// 
			// Znam
			// 
			this->Znam->Location = System::Drawing::Point(113, 207);
			this->Znam->Multiline = true;
			this->Znam->Name = L"Znam";
			this->Znam->Size = System::Drawing::Size(98, 24);
			this->Znam->TabIndex = 11;
			this->Znam->Text = L"1";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(427, 276);
			this->Controls->Add(this->Znam);
			this->Controls->Add(this->Podelit);
			this->Controls->Add(this->Delitel);
			this->Controls->Add(this->Otvet2);
			this->Controls->Add(this->Mult);
			this->Controls->Add(this->Otvet);
			this->Controls->Add(this->Chislo);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Симплекс";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


drob *rezult;
int razmer;

private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
	razmer = 9;		//Задать число столбцов
	rezult = new drob[razmer];
	int veduschiy = 3;	//Задать столбец, в кот. находится ведущий элемент

	drob *mass1 = new drob[razmer];
	drob *mass2 = new drob[razmer];
	drob *m0 = new drob[razmer];
	drob *m1 = new drob[razmer];
	drob *m2 = new drob[razmer];
	drob *m3 = new drob[razmer];
	drob *m4 = new drob[razmer];
	drob *m5 = new drob[razmer];
	mass1 = m5;
	mass2 = m4;

	//***(0) Cтрока
	  m0[0].initialize(-1	, 1		);
	  m0[1].initialize(10	, 1		);
	  m0[2].initialize(0	, 1		);
	  m0[3].initialize(4	, 1		);
	  m0[4].initialize(0	, 1		);
	  m0[5].initialize(-1	, 1		);
	  m0[6].initialize(0	, 1		);
	  m0[7].initialize(0	, 1		);
	  m0[8].initialize(0	, 1		);

	//***(1) Cтрока
	  m1[0].initialize(8	, 1		);
	  m1[1].initialize(20	, 1		);
	  m1[2].initialize(0	, 1		);
	  m1[3].initialize(-3	, 1		);
	  m1[4].initialize(-3	, 1		);
	  m1[5].initialize(-1	, 1		);
	  m1[6].initialize(0	, 1		);
	  m1[7].initialize(0	, 1		);
	  m1[8].initialize(0	, 1		);

	//***(2) Cтрока
	  m2[0].initialize(-1	, 1		);
	  m2[1].initialize(5	, 1		);
	  m2[2].initialize(-3	, 1		);
	  m2[3].initialize(0	, 1		);
	  m2[4].initialize(0	, 1		);
	  m2[5].initialize(-1	, 1		);
	  m2[6].initialize(0	, 1		);
	  m2[7].initialize(0	, 1		);
	  m2[8].initialize(0	, 1		);

	//***(3) Cтрока
	  m3[0].initialize(11	, 1		);
	  m3[1].initialize(-1	, 1		);
	  m3[2].initialize(0	, 1		);
	  m3[3].initialize(-3	, 1		);
	  m3[4].initialize(0	, 1		);
	  m3[5].initialize(2	, 1		);
	  m3[6].initialize(-3	, 1		);
	  m3[7].initialize(0	, 1		);
	  m3[8].initialize(0	, 1		);

	 //***(4) Cтрока
	  m4[0].initialize(10	, 1		);
	  m4[1].initialize(7	, 1		);
	  m4[2].initialize(0	, 1		);
	  m4[3].initialize(9	, 1		);
	  m4[4].initialize(0	, 1		);
	  m4[5].initialize(-2	, 1		);
	  m4[6].initialize(0	, 1		);
	  m4[7].initialize(3	, 1		);
	  m4[8].initialize(0	, 1		);

	//***(5) Cтрока
	  m5[0].initialize(16	, 1		);
	  m5[1].initialize(-11	, 1		);
	  m5[2].initialize(0	, 1		);
	  m5[3].initialize(-15	, 1		);
	  m5[4].initialize(0	, 1		);
	  m5[5].initialize(4	, 1		);
	  m5[6].initialize(0	, 1		);
	  m5[7].initialize(0	, 1		);
	  m5[8].initialize(3	, 1		);


	//Выполнение программы:
	drob a1;
		a1.chisl = mass1[veduschiy].chisl;
		a1.znam = mass1[veduschiy].znam;
	drob a2;
		a2.chisl = mass2[veduschiy].chisl;
		a2.znam = mass2[veduschiy].znam;
	
	drob n,m;
	for (int b=0; b<razmer; b++){
		n = delit(mass1[b], a1);
		m = delit(mass2[b], a2);
		rezult[b] = umnozhit(minus(n, m), a1);
	}

	this->Otvet2->Text = "";
	for (int b=0; b<razmer; b++){
		this->Otvet->Text += "("+(b+1).ToString()+ ").  ";
		if (rezult[b].chisl != 0){
			this->Otvet->Text += (rezult[b].chisl).ToString();
			if(rezult[b].znam != 1){
				this->Otvet->Text += "/" + (rezult[b].znam).ToString();
			}
		}else{
			this->Otvet->Text += "0";
		}
		this->Otvet->Text += "\n";
	}
}




private: System::Void Mult_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Otvet2->Text = "";
	drob *otvet = new drob[razmer];
	int g = Convert::ToInt32(this->Chislo->Text);
	int h = Convert::ToInt32(this->Znam->Text);
	for (int i=0; i<razmer; i++){
		otvet[i].chisl = rezult[i].chisl*g;
		otvet[i].znam = rezult[i].znam*h;
		otvet[i].sokratit();
	}
	for (int i=0; i<razmer; i++){
		this->Otvet2->Text += "("+(i+1).ToString()+ ").  ";
		if (otvet[i].chisl != 0){
			this->Otvet2->Text += (otvet[i].chisl).ToString();
			if(otvet[i].znam != 1){
				this->Otvet2->Text += "/" + (otvet[i].znam).ToString();
			}
		}else{
			this->Otvet2->Text += "0";
		}
		this->Otvet2->Text += "\n";
	}
}

private: System::Void Podelit_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Otvet2->Text = "";
	int nomer = Convert::ToInt32(this->Delitel->Text);
	drob delitel;
	if (nomer == 0){
		delitel.chisl = 1;
	}else{
		delitel.chisl = rezult[nomer-1].chisl;
		delitel.znam = rezult[nomer-1].znam;
	}
	for(int i=0; i<razmer; i++){
		rezult[i] = delit(rezult[i], delitel);
		this->Otvet2->Text += "("+(i+1).ToString()+ ").  ";
		if (rezult[i].chisl != 0){
			this->Otvet2->Text += (rezult[i].chisl).ToString();
			if(rezult[i].znam != 1){
				this->Otvet2->Text += "/" + (rezult[i].znam).ToString();
			}
		}else{
			this->Otvet2->Text += "0";
		}
		this->Otvet2->Text += "\n";
	}

}




};
}

