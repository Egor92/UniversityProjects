#pragma once
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "THeap.h"
#include "TTree.h"
#define MAX 1000000000


namespace graphs_lab_work {

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
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(83, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Число вершин:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(101, 6);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(35, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(142, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(110, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Стартовая вершина:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(258, 6);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(35, 20);
			this->textBox2->TabIndex = 3;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Form1::textBox2_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(311, 6);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(132, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"заполнить матрицу";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(15, 341);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(146, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"вычислить расстояния";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->ColumnHeadersVisible = false;
			this->dataGridView1->Location = System::Drawing::Point(15, 35);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(300, 300);
			this->dataGridView1->TabIndex = 6;
			this->dataGridView1->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::dataGridView1_CellValueChanged);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			this->panel1->Location = System::Drawing::Point(335, 35);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(300, 300);
			this->panel1->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(651, 35);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 13);
			this->label3->TabIndex = 8;
			this->label3->Click += gcnew System::EventHandler(this, &Form1::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(651, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(62, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Результат:";
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(205, 347);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(47, 17);
			this->radioButton1->TabIndex = 10;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"куча";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->Click += gcnew System::EventHandler(this, &Form1::radioButton1_Click);
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(267, 347);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(61, 17);
			this->radioButton2->TabIndex = 11;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"дерево";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->Click += gcnew System::EventHandler(this, &Form1::radioButton2_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(857, 374);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->Text = L"Лаба";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		int versh;
		int start;
		bool flag; 
	void Paint(){ 
		int i;
		double x,y;
		double Pi;
     	Pi = 3.141592653592l; 
		Color ^MyCol = gcnew Color();  
		Pen ^BlackPen = gcnew Pen (MyCol->Black);  
		Graphics ^Gr = this->panel1->CreateGraphics();  
		Gr->Clear(MyCol->White);  
		for (i=0; i<versh; i++){ 
			x = 145+135*cos(Pi/2-i*Pi*2/versh); 
			y = 145+135*sin(-Pi/2-i*Pi*2/versh);  
			Gr->DrawEllipse( BlackPen, x, y, 5, 5 ); 
		}
		for (i=1;i<versh;i++) 
			for (int j=0;j<versh;j++){
				if (this->dataGridView1->Rows[i]->Cells[j]->Value->ToString() != "0"){
					x = 147+135*cos(Pi/2-i*Pi*2/versh);  
					y = 147+135*sin(-Pi/2-i*Pi*2/versh);  
					Point t1(x,y);  
					x = 147+135*cos(Pi/2-j*Pi*2/versh);  
					y = 147+135*sin(-Pi/2-j*Pi*2/versh);  
					Point t2(x,y); 
					Gr->DrawLine( BlackPen, t1, t2); 
				}
			}

	}
	private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {

			 }
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			  System::String^ s=this->textBox1->Text;
				 try{
					 int tmp=Convert::ToInt32(s);
					 this->dataGridView1->ColumnCount=tmp;
					 this->dataGridView1->RowCount=tmp;
					 versh=tmp;
					 for (int i=0;i<versh;i++){
						for(int j=i;j<versh;j++){    
							this->dataGridView1->Rows[i]->Cells[j]->Value=0;
						}
					}
				 }catch(System::Exception ^e){};
		 }
private: System::Void dataGridView1_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
			 int stolbec = e->ColumnIndex;
			int stroka = e->RowIndex;
			String ^s;
			s=this->dataGridView1->Rows[stroka]->Cells[stolbec]->Value->ToString();
			if (s=="") {s="0";} 
			int i=Convert::ToInt32(s);
			if (i<0) {
				i=-i; 
				this->dataGridView1->Rows[stroka]->Cells[stolbec]->Value = i;
			}
			if ((stroka==stolbec)&&(i!=0)) {
				i=0;  
				this->dataGridView1->Rows[stroka]->Cells[stolbec]->Value = i; 
			}
			this->dataGridView1->Rows[stolbec]->Cells[stroka]->Value = this->dataGridView1->Rows[stroka]->Cells[stolbec]->Value;

		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			  int i,j;
			 srand(time(0));
			 int min=0; 
			 int max=10;
			 for (int i=0; i<versh; i++) 
				 for (int j=i+1; j<versh; j++) 
				 {
					 int temp=(double)rand()/(RAND_MAX + 1)*(max - min)+min;
					 if (temp>6){ 
						 temp=(double)rand()/(RAND_MAX + 1)*(max - min)+min; 
						 this->dataGridView1->Rows[i]->Cells[j]->Value=temp;
					 }else{
						 this->dataGridView1->Rows[i]->Cells[j]->Value=0;
					 }
				 }
			 Paint();
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->label3->Text="";
			 int *rasst= new int [versh]; 
			 int *ot=new int [versh]; 
			 for (int i=0;i<versh;i++){
				ot[i]=-1; 
			 }
			  for (int i=0;i<versh;i++){
				rasst[i]=MAX; 
			 }
			 if (flag){ 
				 kucha heap(versh); 
				 int i,j,k,l;
				 for (i=0;i<versh;i++){ 
					 Value tmp; 
					 tmp.Name=i; 
					 if (i==start) tmp.val=0; 
					 else tmp.val=MAX; 
					 heap.dobavit(tmp); 
				 }
				 Value tmp;
				 for (i=0;i<versh-1;i++){ 
					 tmp=heap.izvl(); 
					 rasst[tmp.Name]=tmp.val; 
					 for (j=0;j<versh-i-1;j++){ 
						k=tmp.Name; 
						l=heap.GetName(j); 
						int inttmp = Convert::ToInt32(this->dataGridView1->Rows[k]->Cells[l]->Value->ToString()); 
						if ((inttmp!=0)&&(tmp.val+inttmp<heap.GetVal(j))){
							heap.izmenit(j,tmp.val+inttmp); 
							ot[l]=k;
						}
					 }
					}
				 tmp=heap.izvl(); 
				 rasst[tmp.Name]=tmp.val; 
			 }else{
				 Tree Tr; 
				 int istart=start; 
				 int i,j,k,l;
				 int n=versh; 
				 bool *otm = new bool[n];
				 for (i=0;i<n;i++){ 
					 if (i==istart) {Tr.Insert(0,i); rasst[i]=0;} 
					 else {Tr.Insert(MAX,i); rasst[i]=MAX;} 
					 otm[i]=false; 
				 }
				 for (i=0;i<n-1;i++){
					 int tmp=Tr.DelMin(); 
					 int ss=-1; 
					 otm[tmp]=true; 
					 for (j=0;j<n-i-1;j++){ 
						k=tmp; 
						ss++; while (otm[ss]) {ss++;} 
						l=ss;
						int inttmp = Convert::ToInt32(this->dataGridView1->Rows[k]->Cells[l]->Value->ToString()); 
						if ((inttmp!=0)&&(rasst[tmp]+inttmp<rasst[l])){ 
							Tr.Change(rasst[l],l,rasst[tmp]+inttmp); 
							rasst[l]=rasst[tmp]+inttmp; 
							ot[l]=tmp; 
						}
					 }
			}
			 }
			  for (int i=0;i<versh;i++){
				 this->label3->Text+="("+Convert::ToString(i)+"-"+Convert::ToString(start)+") = "; 
				 if (abs(MAX-abs(rasst[i]))<=100){
					 this->label3->Text+=" - ";
				 }else{
					 this->label3->Text+=Convert::ToString(rasst[i]); 
				 }
				 this->label3->Text+="   "; 
				 int tmp=ot[i];
				 if (tmp>=0){
					 this->label3->Text+="  "+Convert::ToString(i);
					 while (tmp>=0){ 
						 this->label3->Text+="  -  "+Convert::ToString(tmp);
						 tmp=ot[tmp];
					 }
				 }else{ 
					 this->label3->Text+=" - ";
				 }
			 	 this->label3->Text+="\n"; 
			 }
			 delete [] rasst; 
			 Paint(); 
		 }
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 System::String^ s=this->textBox2->Text;
			 try{ 
				 int tmp=Convert::ToInt32(s);
				 start=tmp;
			 }catch(System::Exception ^e){};
		 }
private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void radioButton1_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->radioButton1->Checked=true;
			 this->radioButton2->Checked=false;
			 flag=true;
		 }
private: System::Void radioButton2_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->radioButton1->Checked=false;
			 this->radioButton2->Checked=true;
			 flag=false;
		 }
};
}

