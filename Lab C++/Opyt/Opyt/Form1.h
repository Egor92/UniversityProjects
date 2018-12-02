#pragma once
#include <math.h>
#include <conio.h>
#include <stdlib.h>

namespace Opyt {

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
	private: System::Windows::Forms::Button^  button;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox;
	private: System::Windows::Forms::Button^  Zvuk;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button = (gcnew System::Windows::Forms::Button());
			this->textBox = (gcnew System::Windows::Forms::TextBox());
			this->Zvuk = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button
			// 
			this->button->Location = System::Drawing::Point(7, 10);
			this->button->Name = L"button";
			this->button->Size = System::Drawing::Size(267, 25);
			this->button->TabIndex = 0;
			this->button->Text = L"button";
			this->button->UseVisualStyleBackColor = true;
			this->button->Click += gcnew System::EventHandler(this, &Form1::button_Click);
			// 
			// textBox
			// 
			this->textBox->Location = System::Drawing::Point(7, 41);
			this->textBox->Name = L"textBox";
			this->textBox->Size = System::Drawing::Size(266, 20);
			this->textBox->TabIndex = 1;
			// 
			// Zvuk
			// 
			this->Zvuk->Location = System::Drawing::Point(73, 163);
			this->Zvuk->Name = L"Zvuk";
			this->Zvuk->Size = System::Drawing::Size(107, 49);
			this->Zvuk->TabIndex = 2;
			this->Zvuk->Text = L"Звук";
			this->Zvuk->UseVisualStyleBackColor = true;
			this->Zvuk->Click += gcnew System::EventHandler(this, &Form1::Zvuk_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->Zvuk);
			this->Controls->Add(this->textBox);
			this->Controls->Add(this->button);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_Click(System::Object^  sender, System::EventArgs^  e) {
				int I,J;
				double G,H;

				/*--------Составление строки бит по числу--------*/
				//String ^s = this->textBox->Text;
				//I=Convert::ToInt32(s);
				//this->textBox->Text = this->textBox->Text + "   ";
				//for (int X=0; X<32; X++){
				//	J = I;
				//	J = J << (31 - X);	//Убираем лишнее слева
				//	J = J >> 31;		//Убираем лишнее справа
				//	this->textBox->Text = this->textBox->Text + J.ToString();
				//}

				/*------Составление числа по битовой строке------*/
				//int *K,X;
				//X=2;
				//K = new int[31];
				//K[0]=0;   K[10]=0;   K[20]=0;   K[30]=0;
				//K[1]=0;   K[11]=0;   K[21]=0;   K[31]=0;
				//K[2]=0;   K[12]=0;   K[22]=0;
				//K[3]=0;   K[13]=0;   K[23]=0;
				//K[4]=0;   K[14]=0;   K[24]=0;
				//K[5]=0;   K[15]=0;   K[25]=0;
				//K[6]=0;   K[16]=0;   K[26]=0;
				//K[7]=0;   K[17]=0;   K[27]=0;
				//K[8]=0;   K[18]=0;   K[28]=0;
				//K[9]=0;   K[19]=0;   K[29]=0;
				//I=0;

				//for (int N=0; N<32; N++)
				//	I = I | ((K[N] << N));

				//J = 1 << (X%32);
				//I = J | I;
				//this->textBox->Text = I.ToString();

				/*---------Тестирование оператора break---------*/
				//for (I=0; I<30; I++){
				//	if (I=10) {break;}
				//}
				//this->textBox->Text = I.ToString();

				/*-----------------Флаги......------------------*/
				//bool Flag;
				//Flag = false;
				//I = 1;
				//if (I==1) Flag = true;
				//if (Flag = true) this->textBox->Text = "OK";
			 
				//I = 32;
				//I = I/32;
				//this->textBox->Text = I.ToString();
			 
				//G = 3,9;
				//H = sin(G);
				//this->textBox->Text = (sin(G)).ToString();


				this->textBox->Text = "123456789";
				for (I=0;I<8;I++){
					this->textBox->Text += this->textBox->Text[I];
				}
	System::Media::SoundPlayer ^ f;
	f=gcnew System::Media::SoundPlayer("E:\\Егор\\Школа\\Университет\\Лабораторная C++\\NewYear2011\\Jingle_Bells.PCM");
	f->Play(); 


}



private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {

}



private: System::Void Zvuk_Click(System::Object^  sender, System::EventArgs^  e) {
	System::Media::SoundPlayer^ f;
	f=gcnew System::Media::SoundPlayer("E:\\Новогодняя.wav");
	f->Play();

}










};
}

