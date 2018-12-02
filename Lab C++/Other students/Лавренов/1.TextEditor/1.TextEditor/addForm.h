#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace My1TextEditor {

	public ref class addForm : public System::Windows::Forms::Form
	{
	public:
		addForm(void)
		{
			InitializeComponent();
			record = nullptr;
		}

	protected:
		~addForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::ComponentModel::Container ^components;
	private: String^ record;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(82, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Enter the name:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(128, 24);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(90, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &addForm::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button1->Location = System::Drawing::Point(29, 59);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(79, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Cancel";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(128, 59);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(90, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"OK";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// addForm
			// 
			this->AcceptButton = this->button2;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(229, 101);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"addForm";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Add Node";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 record = textBox1->Text;
				 button2->Enabled = Convert::ToBoolean(record->Length);
			 }
	public:
		property String^ recordName
		{
			String^ get(void)
			{
				return record;
			}
		}
	};
}
