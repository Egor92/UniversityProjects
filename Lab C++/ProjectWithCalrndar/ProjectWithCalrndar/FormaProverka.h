#pragma once
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <Vcclr.h>
#include <stdlib.h>
#include <string> 
#include <fstream>
#include "Array_of_Lighting_Labels.h"
#include "TList.h"
#include "RefClass.h"
#include "DataBase.h"

using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;
using namespace Runtime::InteropServices;  
using namespace DataBase;


namespace ProjectWithCalrndar {

	public ref class FormaProverka : public System::Windows::Forms::Form
	{
	public:
		FormaProverka(void)
		{
			InitializeComponent();
		}

	protected:
		~FormaProverka()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(80, 82);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(96, 59);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FormaProverka::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(260, 20);
			this->textBox1->TabIndex = 1;
			// 
			// FormaProverka
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"FormaProverka";
			this->Text = L"FormaProverka";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->textBox1->Text = DataBase::Count.ToString();
			 }
	};
}
