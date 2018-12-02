#pragma once
#include "StdAfx.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace VolgaNNGamer2011 {

	public ref class FormWithResult : public System::Windows::Forms::Form
	{
	public:
		FormWithResult(){
			InitializeComponent();
			ResultCode = 0;
		}

	protected:
		~FormWithResult(){
			if (components){
				delete components;
			}
		}

	public:
		int ResultCode;
	protected: System::Windows::Forms::MenuStrip^  MStrip;
	public: 

	public: 

	public: System::Windows::Forms::Label^  HelpLabel;

	public: 

	private: System::ComponentModel::Container ^components;


	#pragma region Windows Form Designer generated code
		void InitializeComponent(){
			this->MStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->HelpLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// MStrip
			// 
			this->MStrip->Location = System::Drawing::Point(0, 0);
			this->MStrip->Name = L"MStrip";
			this->MStrip->Size = System::Drawing::Size(994, 24);
			this->MStrip->TabIndex = 0;
			this->MStrip->Text = L"menuStrip1";
			// 
			// HelpLabel
			// 
			this->HelpLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->HelpLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->HelpLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->HelpLabel->Location = System::Drawing::Point(12, 544);
			this->HelpLabel->Name = L"HelpLabel";
			this->HelpLabel->Size = System::Drawing::Size(970, 21);
			this->HelpLabel->TabIndex = 1;
			this->HelpLabel->Text = L"HelpLabel";
			this->HelpLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// FormWithResult
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(994, 572);
			this->Controls->Add(this->HelpLabel);
			this->Controls->Add(this->MStrip);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->MStrip;
			this->MaximizeBox = false;
			this->Name = L"FormWithResult";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion

	#pragma region 
		public:
		void SetResultCode (int ResultCode){
			this->ResultCode = ResultCode;
		}
	#pragma endregion

	#pragma region 
		public:
		int GetResultCode (){
			return this->ResultCode;
		}
	#pragma endregion

	};
}
