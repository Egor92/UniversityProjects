#pragma once
#include <vcclr.h>
#include <string>
#include <math.h>
#include "der.h"

namespace Tree {

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
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  Tkolv;

	private: System::Windows::Forms::Label^  label2;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::DataGridView^  matrix;

	private: System::Windows::Forms::Label^  label4;








	protected: 

	protected: 

	protected: 

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Tkolv = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->matrix = (gcnew System::Windows::Forms::DataGridView());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->matrix))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(151, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Введите количество вершин";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// Tkolv
			// 
			this->Tkolv->Location = System::Drawing::Point(60, 35);
			this->Tkolv->Name = L"Tkolv";
			this->Tkolv->Size = System::Drawing::Size(39, 20);
			this->Tkolv->TabIndex = 1;
			this->Tkolv->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 71);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(154, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Введите матрицу смежности";
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(15, 309);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Готово";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// matrix
			// 
			this->matrix->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCellsExceptHeader;
			this->matrix->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCellsExceptHeaders;
			this->matrix->BackgroundColor = System::Drawing::Color::Linen;
			this->matrix->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->matrix->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->matrix->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnKeystroke;
			this->matrix->GridColor = System::Drawing::Color::MistyRose;
			this->matrix->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->matrix->Location = System::Drawing::Point(15, 100);
			this->matrix->MultiSelect = false;
			this->matrix->Name = L"matrix";
			this->matrix->RowHeadersWidth = 10;
			this->matrix->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->matrix->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->matrix->Size = System::Drawing::Size(183, 183);
			this->matrix->TabIndex = 5;
			this->matrix->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::matrix_CellValueChanged);
			this->matrix->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::matrix_CellContentClick);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::Color::Red;
			this->label4->Location = System::Drawing::Point(12, 289);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(12, 17);
			this->label4->TabIndex = 7;
			this->label4->Text = L".";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Linen;
			this->ClientSize = System::Drawing::Size(502, 369);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->matrix);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->Tkolv);
			this->Controls->Add(this->label1);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->matrix))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		int kolv; // количество вершин
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 BitString der(kolv);
				 int *graph;
				 int *nom;
				 int i, j, k, s, z, d;
				 s=kolv*(kolv-1)/2;
				 z=0;
				 d=1;
				 graph = new int [s];
				 nom = new int [s];
				 this->label4-> Text = "";
		for (i=0; i<kolv; i++)
			if (d==0) this->label4-> Text = "Граф должен быть связен!";
			else
			{
				d=0;
			for (j=i+1; j<kolv; j++)
			{
					String ^str = this->matrix->Rows[i]->Cells[j]->Value->ToString();
					k = Convert::ToInt32(str);
					graph[z] = k;
					d=d+k;
					nom[z]=z;
					z++;
			}
			}
			for (i = s - 1; i > 0; i--)
			{
				for (j = 0; j < i; j++)
				{
					if (graph[j] > graph[j + 1])
					{
						z=graph[j]; graph[j]=graph[j+1]; graph[j+1]=z;
						z=nom[j]; nom[j]=nom[j+1]; nom[j+1]=z;
					}
				}
			}
			for (i=0; i<s; i++)
			{
				if (graph[i]!=0)
				{
				}
				else der.BitDown(nom[i]);
			 }
			 }
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
					String ^s = this->Tkolv->Text;
					int i;
		try{
			kolv=Convert::ToInt32(s);
			this->matrix->RowCount=kolv;
		    this->matrix->ColumnCount=kolv;
			for (i=0; i<kolv; i++)
			this->matrix->Rows[i]->Cells[i]->Value = 0;
		}catch(System::Exception ^e){}
				 double k, j, y;
				 double pi=3.14;
               	 Color ^col = gcnew Color();
				 Pen ^bPen = gcnew Pen (col->Black);
				 Graphics ^im = this->CreateGraphics();
				 im->Clear(col->Linen);
				 for (i=0; i<kolv; i++)
					  im->DrawEllipse( bPen, 350+140*cos(pi/2+i*pi*2/kolv), 150+140*sin(pi/2+i*pi*2/kolv), 10, 10 );
		 }

private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void matrix_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
{
		matrix->AutoGenerateColumns = false;
		matrix->AllowUserToResizeColumns = false;
		double pi=3.14;
		int x1, y1, x2, y2, i;
		Color ^col = gcnew Color();
		Graphics ^im = this->CreateGraphics();
	    int stl = e->ColumnIndex;   //Номер Столбца
		int str = e->RowIndex;      //Номер Строки
		String ^s = this->matrix->Rows[str]->Cells[stl]->Value->ToString();
		i=Convert::ToInt32(s);
		if ((str==stl)&(i!=0))
		{
			this->matrix->Rows[str]->Cells[stl]->Value = 0;
			this->label4-> Text = "Граф без петель!";
		}
		    else
		      {
			  try 
			    {   
				 this->matrix->Rows[stl]->Cells[str]->Value = this->matrix->Rows[str]->Cells[stl]->Value->ToString();
				 if (i!=0)
				 {
				 Pen ^bPen = gcnew Pen (col->Black);
				 x1=350+140*cos(pi/2+stl*pi*2/kolv);
				 y1=150+140*sin(pi/2+stl*pi*2/kolv);
				 x2=350+140*cos(pi/2+str*pi*2/kolv);
				 y2=150+140*sin(pi/2+str*pi*2/kolv);
				 im->DrawLine(bPen, x1+5, y1+5, x2+5, y2+5);
				 }
				 else 
				 {
				 Pen ^bPen = gcnew Pen (col->Linen);
				 x1=350+140*cos(pi/2+stl*pi*2/kolv);
				 y1=150+140*sin(pi/2+stl*pi*2/kolv);
				 x2=350+140*cos(pi/2+str*pi*2/kolv);
				 y2=150+140*sin(pi/2+str*pi*2/kolv);
				 im->DrawLine(bPen, x1+5, y1+5, x2+5, y2+5);
				 }
			    }
			  catch(System::Exception ^e)
			   {   
				this->matrix->Rows[stl]->Cells[str]->Value = 0;
			   }
		      }
}
private: System::Void matrix_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		 }

};
}

