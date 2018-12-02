#pragma once
#include "StdAfx.h"
#include "SquadForm.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace VolgaNNGamer2011 {

	public ref class OfficeForm : public FormWithResult
	{
	public:
		OfficeForm(){
			InitializeComponent();
		}

	protected:
		~OfficeForm(){
			if (components){
				delete components;
			}
		}



	private: System::ComponentModel::Container ^components;


	#pragma region Windows Form Designer generated code
			void InitializeComponent(){
				this->SuspendLayout();
				// 
				// OfficeForm
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(500, 500);
				this->Name = L"OfficeForm";
				this->Text = L"OfficeForm";
				this->ResumeLayout(false);

			}
	#pragma endregion


};
}
