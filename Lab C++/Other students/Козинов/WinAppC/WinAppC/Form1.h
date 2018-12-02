#pragma once
#include <vcclr.h>
#include <string>


namespace WinAppC {

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
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Panel^  panel1;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(26, 383);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Кликни";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 34);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(268, 20);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(76, 22);
			this->label1->TabIndex = 2;
			this->label1->Text = L"label1";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 60);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 87);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"label2";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(13, 104);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(240, 273);
			this->dataGridView1->TabIndex = 5;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(178, 383);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 6;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel1->Location = System::Drawing::Point(379, 231);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(200, 100);
			this->panel1->TabIndex = 7;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panel1_Paint);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(651, 532);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Это мое первое виз прил";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 int j = 20;
				 
				 System::String ^str= j.ToString();

				 std::string s;

				 s = "Hello";

				 System::String ^str2 = gcnew System::String(s.c_str());

				 this->label1->Text = str + str2;
				 this->textBox1->Text = "Привет!";

				 pin_ptr<const wchar_t> wch = PtrToStringChars(this->textBox2->Text);
				 size_t convertedChars = 0;
				 size_t  sizeInBytes = ((this->button1->Text->Length + 1) * 2);
				 errno_t err = 0;
				 char    *ch = (char *)malloc(sizeInBytes);
				err = wcstombs_s(&convertedChars, ch, sizeInBytes, wch, sizeInBytes);
				  s = ch;
				 str2 = gcnew System::String(s.c_str());

				 this->label2->Text = str2;
				/* int  j = atoi(ch)
			     double f = atof(ct)*/

				 free(ch);
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->dataGridView1->RowCount = 10;
				 this->dataGridView1->ColumnCount = 5;

				 int i = 10;

				 this->dataGridView1->Rows[1]->Cells[2]->Value = i.ToString();
				 this->dataGridView1->Rows[1]->Cells[2]->Value->ToString();

				 System::Int32 j;

				 j = System::Convert::ToInt32(this->dataGridView1->Rows[1]->Cells[2]->Value->ToString());

				i = j;

			 }
private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 Graphics ^ g = e->Graphics;

			 Pen^ blackPen = gcnew Pen( Color::Aqua,3.0f );

			  // Create location and size of ellipse.
			  int x = 0;
			  int y = 0;
			  int width = 10;
			  int height = 10;

			  // Draw ellipse to screen.
			  g->DrawEllipse( blackPen, x, y, width, height );


			  g->DrawEllipse( blackPen, x, y, 100, 100 );
			  g->Clear;

		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {



		 }


};
}

