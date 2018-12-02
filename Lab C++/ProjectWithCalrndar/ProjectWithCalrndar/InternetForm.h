#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace ProjectWithCalrndar {

	public ref class InternetForm : public System::Windows::Forms::Form{

	public:
		InternetForm(System::String ^URL){
			InitializeComponent();
			this->URL = URL;
		}

	protected:
		~InternetForm(){
			if (components){
				delete components;
			}
		}

	private: System::Windows::Forms::WebBrowser^  webBrowser1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::LinkLabel^  GO;
	private: System::String ^URL;
	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->webBrowser1 = (gcnew System::Windows::Forms::WebBrowser());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->GO = (gcnew System::Windows::Forms::LinkLabel());
			this->SuspendLayout();
			// 
			// webBrowser1
			// 
			this->webBrowser1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->webBrowser1->Location = System::Drawing::Point(0, 21);
			this->webBrowser1->MinimumSize = System::Drawing::Size(20, 20);
			this->webBrowser1->Name = L"webBrowser1";
			this->webBrowser1->ScriptErrorsSuppressed = true;
			this->webBrowser1->Size = System::Drawing::Size(1120, 542);
			this->webBrowser1->TabIndex = 8;
			this->webBrowser1->Navigated += gcnew System::Windows::Forms::WebBrowserNavigatedEventHandler(this, &InternetForm::webBrowser1_Navigated);
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->Location = System::Drawing::Point(90, 0);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(1030, 20);
			this->textBox1->TabIndex = 9;
			this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &InternetForm::textBox1_KeyDown);
			// 
			// GO
			// 
			this->GO->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->GO->Location = System::Drawing::Point(1, 0);
			this->GO->Name = L"GO";
			this->GO->Size = System::Drawing::Size(84, 23);
			this->GO->TabIndex = 10;
			this->GO->TabStop = true;
			this->GO->Text = L"ѕерейти";
			this->GO->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &InternetForm::GO_LinkClicked);
			// 
			// InternetForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1119, 562);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->webBrowser1);
			this->Controls->Add(this->GO);
			this->Name = L"InternetForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"InternetForm";
			this->Load += gcnew System::EventHandler(this, &InternetForm::InternetForm_Load);
			this->SizeChanged += gcnew System::EventHandler(this, &InternetForm::InternetForm_SizeChanged);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


private: System::Void InternetForm_Load(System::Object^  sender, System::EventArgs^  e) {
		this->textBox1->Text = URL;
		this->webBrowser1->Navigate(URL);
}

private: System::Void GO_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
		this->webBrowser1->Navigate( this->textBox1->Text );
}

private: System::Void textBox1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		try{
			if ( e->KeyCode == System::Windows::Forms::Keys::Enter &&  !this->textBox1->Text->Equals( "" ) ){
				this->webBrowser1->Navigate( this->textBox1->Text );
			}
		}catch(Exception^ ex){

		}
}

private: System::Void InternetForm_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
		//this->textBox1->SetBounds(90, 0, this->Size.Width - 90, 20);
		//this->webBrowser1->SetBounds(0, 21, this->Size.Width - 15, this->Size.Height - 58);
}

private: System::Void webBrowser1_Navigated(System::Object^  sender, System::Windows::Forms::WebBrowserNavigatedEventArgs^  e) {
		this->textBox1->Text = this->webBrowser1->Url->ToString();
}


};
}
