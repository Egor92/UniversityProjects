#pragma once
#include "StdAfx.h"
#include "SelectTacticForm.h"
#include "FormWithResult.h"
#include "UnderliningLabel.h"
#include "SquadSystem.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace VolgaNNGamer2011 {

	public ref class SquadForm : public FormWithResult{
	public:
		SquadForm() : FormWithResult(){
			InitializeComponent();
		}

	protected:
		~SquadForm(){
			if (components){
				delete components;
			}
		}

	private: System::Windows::Forms::PictureBox^  PictureField;
	private: System::Windows::Forms::Panel^  Panel_For_PlayerInfo;
	private: System::Windows::Forms::Label^  FlyingLabel;


	private: System::ComponentModel::IContainer^  components;



	#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(SquadForm::typeid));
			this->PictureField = (gcnew System::Windows::Forms::PictureBox());
			this->Panel_For_PlayerInfo = (gcnew System::Windows::Forms::Panel());
			this->FlyingLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PictureField))->BeginInit();
			this->SuspendLayout();
			// 
			// PictureField
			// 
			this->PictureField->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"PictureField.Image")));
			this->PictureField->Location = System::Drawing::Point(12, 36);
			this->PictureField->Name = L"PictureField";
			this->PictureField->Size = System::Drawing::Size(340, 440);
			this->PictureField->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->PictureField->TabIndex = 1;
			this->PictureField->TabStop = false;
			// 
			// Panel_For_PlayerInfo
			// 
			this->Panel_For_PlayerInfo->AutoScroll = true;
			this->Panel_For_PlayerInfo->Location = System::Drawing::Point(358, 36);
			this->Panel_For_PlayerInfo->Name = L"Panel_For_PlayerInfo";
			this->Panel_For_PlayerInfo->Size = System::Drawing::Size(624, 505);
			this->Panel_For_PlayerInfo->TabIndex = 2;
			// 
			// FlyingLabel
			// 
			this->FlyingLabel->Location = System::Drawing::Point(12, 498);
			this->FlyingLabel->Name = L"FlyingLabel";
			this->FlyingLabel->Size = System::Drawing::Size(100, 23);
			this->FlyingLabel->TabIndex = 0;
			// 
			// SquadForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(994, 572);
			this->Controls->Add(this->FlyingLabel);
			this->Controls->Add(this->Panel_For_PlayerInfo);
			this->Controls->Add(this->PictureField);
			this->Name = L"SquadForm";
			this->Text = L"SquadForm";
			this->Load += gcnew System::EventHandler(this, &SquadForm::SquadForm_Load);
			this->Click += gcnew System::EventHandler(this, &SquadForm::SquadForm_Click);
			this->Controls->SetChildIndex(this->HelpLabel, 0);
			this->Controls->SetChildIndex(this->PictureField, 0);
			this->Controls->SetChildIndex(this->Panel_For_PlayerInfo, 0);
			this->Controls->SetChildIndex(this->FlyingLabel, 0);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PictureField))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion


	#pragma region Глобальные переменные
		private: ClassOf_SquadSystem^ SquadSystem;
	#pragma endregion



	#pragma region Инициализация FlyingLabel
		void Initialize_FlyingLabel(){
			this->FlyingLabel->AutoSize = true;
			this->FlyingLabel->Text = L"FlyingLabel";
		}
	#pragma endregion

	#pragma region Загрузка формы OfficeForm
		System::Void SquadForm_Load(System::Object^  sender, System::EventArgs^  e) {
			Initialize_FlyingLabel();
		}
	#pragma endregion


	System::Void SquadForm_Click(System::Object^  sender, System::EventArgs^  e) {
		SquadSystem = gcnew ClassOf_SquadSystem(this->Panel_For_PlayerInfo, 10, this->FlyingLabel, this->HelpLabel);
	}




	};
}
