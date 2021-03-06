#pragma once
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "Heap.h"
#include "Tree.h"
#define MAX 1000000000


namespace AlgorithmOfDijkstra {

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
	private: System::Windows::Forms::RadioButton^  TreeIsSelect; 
	private: System::Windows::Forms::RadioButton^  HeapIsSelect; 
	private: System::Windows::Forms::Panel^  Panel; 
	private: System::Windows::Forms::DataGridView^  Matrix; 
	private: System::Windows::Forms::Button^  ButtonDone; 
	private: System::Windows::Forms::Button^  FillTheMatrix; 
	private: System::Windows::Forms::TextBox^  TextStartTop;
	private: System::Windows::Forms::Label^  label2; 
	private: System::Windows::Forms::TextBox^  TextNumOfTops;
	private: System::Windows::Forms::Label^  label1; 
	private: System::Windows::Forms::GroupBox^  InitTheMatrixBox; 
	private: System::Windows::Forms::GroupBox^  PanelBox; 
	private: System::Windows::Forms::GroupBox^  RoadsBox; 
	private: System::Windows::Forms::GroupBox^  CalcBox; 
	private: System::Windows::Forms::Button^  ButtonExit; 
	private: System::Windows::Forms::Label^  LabelHelp; 
	private: System::Windows::Forms::DataGridView^  DataRoads;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Путь;
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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->TreeIsSelect = (gcnew System::Windows::Forms::RadioButton());
			this->HeapIsSelect = (gcnew System::Windows::Forms::RadioButton());
			this->Panel = (gcnew System::Windows::Forms::Panel());
			this->Matrix = (gcnew System::Windows::Forms::DataGridView());
			this->ButtonDone = (gcnew System::Windows::Forms::Button());
			this->FillTheMatrix = (gcnew System::Windows::Forms::Button());
			this->TextStartTop = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->TextNumOfTops = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->InitTheMatrixBox = (gcnew System::Windows::Forms::GroupBox());
			this->PanelBox = (gcnew System::Windows::Forms::GroupBox());
			this->RoadsBox = (gcnew System::Windows::Forms::GroupBox());
			this->DataRoads = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Путь = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CalcBox = (gcnew System::Windows::Forms::GroupBox());
			this->ButtonExit = (gcnew System::Windows::Forms::Button());
			this->LabelHelp = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Matrix))->BeginInit();
			this->InitTheMatrixBox->SuspendLayout();
			this->PanelBox->SuspendLayout();
			this->RoadsBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DataRoads))->BeginInit();
			this->CalcBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// TreeIsSelect
			// 
			this->TreeIsSelect->AutoSize = true;
			this->TreeIsSelect->Location = System::Drawing::Point(6, 42);
			this->TreeIsSelect->Name = L"TreeIsSelect";
			this->TreeIsSelect->Size = System::Drawing::Size(227, 17);
			this->TreeIsSelect->TabIndex = 23;
			this->TreeIsSelect->TabStop = true;
			this->TreeIsSelect->Text = L"С использованием Поискового Дерева";
			this->TreeIsSelect->UseVisualStyleBackColor = true;
			this->TreeIsSelect->MouseLeave += gcnew System::EventHandler(this, &Form1::TreeIsSelect_MouseLeave);
			this->TreeIsSelect->MouseEnter += gcnew System::EventHandler(this, &Form1::TreeIsSelect_MouseEnter);
			this->TreeIsSelect->CheckedChanged += gcnew System::EventHandler(this, &Form1::TreeIsSelect_CheckedChanged);
			// 
			// HeapIsSelect
			// 
			this->HeapIsSelect->AutoSize = true;
			this->HeapIsSelect->Location = System::Drawing::Point(6, 19);
			this->HeapIsSelect->Name = L"HeapIsSelect";
			this->HeapIsSelect->Size = System::Drawing::Size(147, 17);
			this->HeapIsSelect->TabIndex = 22;
			this->HeapIsSelect->TabStop = true;
			this->HeapIsSelect->Text = L"С использованием Кучи";
			this->HeapIsSelect->UseVisualStyleBackColor = true;
			this->HeapIsSelect->MouseLeave += gcnew System::EventHandler(this, &Form1::HeapIsSelect_MouseLeave);
			this->HeapIsSelect->MouseEnter += gcnew System::EventHandler(this, &Form1::HeapIsSelect_MouseEnter);
			this->HeapIsSelect->CheckedChanged += gcnew System::EventHandler(this, &Form1::HeapIsSelect_CheckedChanged);
			// 
			// Panel
			// 
			this->Panel->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->Panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Panel->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			this->Panel->Location = System::Drawing::Point(11, 15);
			this->Panel->Name = L"Panel";
			this->Panel->Size = System::Drawing::Size(325, 325);
			this->Panel->TabIndex = 19;
			this->Panel->MouseLeave += gcnew System::EventHandler(this, &Form1::Panel_MouseLeave);
			this->Panel->MouseEnter += gcnew System::EventHandler(this, &Form1::Panel_MouseEnter);
			// 
			// Matrix
			// 
			this->Matrix->AllowUserToAddRows = false;
			this->Matrix->AllowUserToDeleteRows = false;
			this->Matrix->AllowUserToResizeColumns = false;
			this->Matrix->AllowUserToResizeRows = false;
			this->Matrix->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->Matrix->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->Matrix->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->Matrix->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->Matrix->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Matrix->ColumnHeadersVisible = false;
			this->Matrix->Location = System::Drawing::Point(10, 80);
			this->Matrix->Name = L"Matrix";
			this->Matrix->RowHeadersVisible = false;
			this->Matrix->Size = System::Drawing::Size(230, 230);
			this->Matrix->TabIndex = 18;
			this->Matrix->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::Matrix_CellValueChanged);
			this->Matrix->MouseLeave += gcnew System::EventHandler(this, &Form1::Matrix_MouseLeave);
			this->Matrix->MouseEnter += gcnew System::EventHandler(this, &Form1::Matrix_MouseEnter);
			// 
			// ButtonDone
			// 
			this->ButtonDone->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->ButtonDone->Location = System::Drawing::Point(6, 73);
			this->ButtonDone->Name = L"ButtonDone";
			this->ButtonDone->Size = System::Drawing::Size(227, 25);
			this->ButtonDone->TabIndex = 17;
			this->ButtonDone->Text = L"Вычислить";
			this->ButtonDone->UseVisualStyleBackColor = true;
			this->ButtonDone->MouseLeave += gcnew System::EventHandler(this, &Form1::ButtonDone_MouseLeave);
			this->ButtonDone->Click += gcnew System::EventHandler(this, &Form1::ButtonDone_Click);
			this->ButtonDone->MouseEnter += gcnew System::EventHandler(this, &Form1::ButtonDone_MouseEnter);
			// 
			// FillTheMatrix
			// 
			this->FillTheMatrix->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->FillTheMatrix->Location = System::Drawing::Point(10, 316);
			this->FillTheMatrix->Name = L"FillTheMatrix";
			this->FillTheMatrix->Size = System::Drawing::Size(230, 25);
			this->FillTheMatrix->TabIndex = 16;
			this->FillTheMatrix->Text = L"Случайная инициализация";
			this->FillTheMatrix->UseVisualStyleBackColor = true;
			this->FillTheMatrix->MouseLeave += gcnew System::EventHandler(this, &Form1::FillTheMatrix_MouseLeave);
			this->FillTheMatrix->Click += gcnew System::EventHandler(this, &Form1::FillTheMatrix_Click);
			this->FillTheMatrix->MouseEnter += gcnew System::EventHandler(this, &Form1::FillTheMatrix_MouseEnter);
			// 
			// TextStartTop
			// 
			this->TextStartTop->Location = System::Drawing::Point(142, 54);
			this->TextStartTop->Name = L"TextStartTop";
			this->TextStartTop->Size = System::Drawing::Size(98, 20);
			this->TextStartTop->TabIndex = 15;
			this->TextStartTop->Text = L"0";
			this->TextStartTop->TextChanged += gcnew System::EventHandler(this, &Form1::StartTop_TextChanged);
			this->TextStartTop->MouseLeave += gcnew System::EventHandler(this, &Form1::StartTop_MouseLeave);
			this->TextStartTop->MouseEnter += gcnew System::EventHandler(this, &Form1::StartTop_MouseEnter);
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(10, 54);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(126, 20);
			this->label2->TabIndex = 14;
			this->label2->Text = L"Стартовая вершина:";
			// 
			// TextNumOfTops
			// 
			this->TextNumOfTops->Location = System::Drawing::Point(142, 26);
			this->TextNumOfTops->Name = L"TextNumOfTops";
			this->TextNumOfTops->Size = System::Drawing::Size(98, 20);
			this->TextNumOfTops->TabIndex = 13;
			this->TextNumOfTops->Text = L"0";
			this->TextNumOfTops->TextChanged += gcnew System::EventHandler(this, &Form1::NumOfTops_TextChanged);
			this->TextNumOfTops->MouseLeave += gcnew System::EventHandler(this, &Form1::NumOfTops_MouseLeave);
			this->TextNumOfTops->MouseEnter += gcnew System::EventHandler(this, &Form1::NumOfTops_MouseEnter);
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(10, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(126, 20);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Число вершин:";
			// 
			// InitTheMatrixBox
			// 
			this->InitTheMatrixBox->Controls->Add(this->label1);
			this->InitTheMatrixBox->Controls->Add(this->TextNumOfTops);
			this->InitTheMatrixBox->Controls->Add(this->label2);
			this->InitTheMatrixBox->Controls->Add(this->TextStartTop);
			this->InitTheMatrixBox->Controls->Add(this->Matrix);
			this->InitTheMatrixBox->Controls->Add(this->FillTheMatrix);
			this->InitTheMatrixBox->Location = System::Drawing::Point(12, 11);
			this->InitTheMatrixBox->Name = L"InitTheMatrixBox";
			this->InitTheMatrixBox->Size = System::Drawing::Size(250, 350);
			this->InitTheMatrixBox->TabIndex = 24;
			this->InitTheMatrixBox->TabStop = false;
			this->InitTheMatrixBox->Text = L"Инициализировать матрицу:";
			// 
			// PanelBox
			// 
			this->PanelBox->Controls->Add(this->Panel);
			this->PanelBox->Location = System::Drawing::Point(514, 11);
			this->PanelBox->Name = L"PanelBox";
			this->PanelBox->Size = System::Drawing::Size(345, 350);
			this->PanelBox->TabIndex = 25;
			this->PanelBox->TabStop = false;
			this->PanelBox->Text = L"Граф:";
			// 
			// RoadsBox
			// 
			this->RoadsBox->Controls->Add(this->DataRoads);
			this->RoadsBox->Location = System::Drawing::Point(268, 11);
			this->RoadsBox->Name = L"RoadsBox";
			this->RoadsBox->Size = System::Drawing::Size(240, 236);
			this->RoadsBox->TabIndex = 26;
			this->RoadsBox->TabStop = false;
			this->RoadsBox->Text = L"Вычисленные пути:";
			// 
			// DataRoads
			// 
			this->DataRoads->AllowUserToAddRows = false;
			this->DataRoads->BackgroundColor = System::Drawing::SystemColors::Control;
			this->DataRoads->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->DataRoads->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DataRoads->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {this->dataGridViewTextBoxColumn1, 
				this->dataGridViewTextBoxColumn2, this->Путь});
			this->DataRoads->EnableHeadersVisualStyles = false;
			this->DataRoads->Location = System::Drawing::Point(6, 15);
			this->DataRoads->Name = L"DataRoads";
			this->DataRoads->RowHeadersVisible = false;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->DataRoads->RowsDefaultCellStyle = dataGridViewCellStyle1;
			this->DataRoads->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->DataRoads->Size = System::Drawing::Size(227, 215);
			this->DataRoads->TabIndex = 30;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ReadOnly = true;
			this->dataGridViewTextBoxColumn1->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridViewTextBoxColumn1->Width = 55;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Вес";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->ReadOnly = true;
			this->dataGridViewTextBoxColumn2->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridViewTextBoxColumn2->Width = 30;
			// 
			// Путь
			// 
			this->Путь->HeaderText = L"Путь";
			this->Путь->Name = L"Путь";
			this->Путь->Width = 120;
			// 
			// CalcBox
			// 
			this->CalcBox->Controls->Add(this->HeapIsSelect);
			this->CalcBox->Controls->Add(this->ButtonDone);
			this->CalcBox->Controls->Add(this->TreeIsSelect);
			this->CalcBox->Location = System::Drawing::Point(268, 253);
			this->CalcBox->Name = L"CalcBox";
			this->CalcBox->Size = System::Drawing::Size(240, 108);
			this->CalcBox->TabIndex = 27;
			this->CalcBox->TabStop = false;
			this->CalcBox->Text = L"Вычисление:";
			// 
			// ButtonExit
			// 
			this->ButtonExit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->ButtonExit->Location = System::Drawing::Point(12, 367);
			this->ButtonExit->Name = L"ButtonExit";
			this->ButtonExit->Size = System::Drawing::Size(125, 25);
			this->ButtonExit->TabIndex = 28;
			this->ButtonExit->Text = L"Выход";
			this->ButtonExit->UseVisualStyleBackColor = true;
			this->ButtonExit->MouseLeave += gcnew System::EventHandler(this, &Form1::ButtonExit_MouseLeave);
			this->ButtonExit->Click += gcnew System::EventHandler(this, &Form1::ButtonExit_Click);
			this->ButtonExit->MouseEnter += gcnew System::EventHandler(this, &Form1::ButtonExit_MouseEnter);
			// 
			// LabelHelp
			// 
			this->LabelHelp->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->LabelHelp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->LabelHelp->Location = System::Drawing::Point(144, 367);
			this->LabelHelp->Name = L"LabelHelp";
			this->LabelHelp->Size = System::Drawing::Size(715, 25);
			this->LabelHelp->TabIndex = 29;
			this->LabelHelp->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(867, 400);
			this->Controls->Add(this->LabelHelp);
			this->Controls->Add(this->ButtonExit);
			this->Controls->Add(this->CalcBox);
			this->Controls->Add(this->RoadsBox);
			this->Controls->Add(this->PanelBox);
			this->Controls->Add(this->InitTheMatrixBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Algorithm Of Dijkstra";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Matrix))->EndInit();
			this->InitTheMatrixBox->ResumeLayout(false);
			this->InitTheMatrixBox->PerformLayout();
			this->PanelBox->ResumeLayout(false);
			this->RoadsBox->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DataRoads))->EndInit();
			this->CalcBox->ResumeLayout(false);
			this->CalcBox->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	int NumOfTops; 
	int StartTop; 
	bool Flag;  

void Paint(){ 
	int I; 
	double X, Y; 
	double Pi; 
 	Pi = 3.141592653592l;  
	Color ^MyCol = gcnew Color();   
	Pen ^BlackPen = gcnew Pen(MyCol->Black);   
	Graphics ^Gr = this->Panel->CreateGraphics();   
	Gr->Clear(MyCol->White);   
	for (I = 0;  I<NumOfTops;  I++){ 
		X = 158+135*cos(Pi/2 - I*Pi*2/NumOfTops);  
		Y = 158+135*sin(-Pi/2 - I*Pi*2/NumOfTops);   
		Gr->DrawEllipse( BlackPen, X, Y, 7, 7 );  
	}
	for (I = 1; I<NumOfTops; I++){ 
		for (int J = 0; J<NumOfTops; J++){
			if (this->Matrix->Rows[I]->Cells[J]->Value->ToString() != "0"){
				X = 162 + 135*cos(Pi/2 - I*Pi*2/NumOfTops);   
				Y = 162 + 135*sin(-Pi/2 - I*Pi*2/NumOfTops);   
				Point T1(X, Y);   
				X = 162 + 135*cos(Pi/2 - J*Pi*2/NumOfTops);   
				Y = 162 + 135*sin(-Pi/2 - J*Pi*2/NumOfTops);   
				Point T2(X, Y);  
				Gr->DrawLine(BlackPen, T1, T2);  
			}
		}
	}
}

/*-----------------------------------------------------------------------------------------------*/
									//***** При загрузке *****//

private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		this->HeapIsSelect->Checked;
		Flag = true;
}

/*-----------------------------------------------------------------------------------------------*/
								//***** Mouse Move *****//

private: System::Void ButtonExit_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		this->LabelHelp->Text = "Выйти из приложения"; 
		ButtonExit->ForeColor = System::Drawing::Color::Red; 
}
private: System::Void ButtonExit_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		this->LabelHelp->Text = ""; 
		ButtonExit->ForeColor = System::Drawing::Color::Black; 
}

private: System::Void ButtonDone_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		this->LabelHelp->Text = "Выполнить поиск путей"; 
		ButtonDone->ForeColor = System::Drawing::Color::Red; 
}
private: System::Void ButtonDone_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		this->LabelHelp->Text = ""; 
		ButtonDone->ForeColor = System::Drawing::Color::Black; 
}

private: System::Void NumOfTops_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		this->LabelHelp->Text = "Задать количество вершин"; 
}
private: System::Void NumOfTops_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		this->LabelHelp->Text = ""; 
}

private: System::Void StartTop_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		this->LabelHelp->Text = "Задать стартовую вершину"; 
}
private: System::Void StartTop_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		this->LabelHelp->Text = ""; 
}

private: System::Void Matrix_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		this->LabelHelp->Text = "Матрица инициализации графа"; 
}
private: System::Void Matrix_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		this->LabelHelp->Text = ""; 
}

private: System::Void FillTheMatrix_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		this->LabelHelp->Text = "Проинициализировать матрицу случайными числами"; 
		FillTheMatrix->ForeColor = System::Drawing::Color::Red; 
}
private: System::Void FillTheMatrix_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		this->LabelHelp->Text = ""; 
		FillTheMatrix->ForeColor = System::Drawing::Color::Black; 
}

private: System::Void HeapIsSelect_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		this->LabelHelp->Text = "Выбрать использование ''Кучи''"; 
}
private: System::Void HeapIsSelect_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		this->LabelHelp->Text = ""; 
}

private: System::Void TreeIsSelect_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		this->LabelHelp->Text = "Выбрать использование ''Поискового дерева''"; 
}
private: System::Void TreeIsSelect_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		this->LabelHelp->Text = ""; 
}

private: System::Void Panel_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		this->LabelHelp->Text = "Граф"; 
}
private: System::Void Panel_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		this->LabelHelp->Text = ""; 
}


/*-----------------------------------------------------------------------------------------------*/
								//***** Ввод количества вершин *****//

private: System::Void NumOfTops_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		System::String^ S1 = this->TextNumOfTops->Text; 
		try{
			int tmp = Convert::ToInt32(S1); 
			this->Matrix->ColumnCount = tmp; 
			this->Matrix->RowCount = tmp; 
			NumOfTops = tmp; 
			for (int I = 0; I<NumOfTops; I++){
				for(int J = I; J<NumOfTops; J++){    
					this->Matrix->Rows[I]->Cells[J]->Value = 0; 
				}
			}
			Paint(); 
		}catch(System::Exception ^e){}; 
}

/*-----------------------------------------------------------------------------------------------*/
								//***** Ввод стартовой вершины *****//

private: System::Void StartTop_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		System::String^ S1 = this->TextStartTop->Text; 
		try{ 
			int tmp = Convert::ToInt32(S1); 
			StartTop = tmp; 
		}catch(System::Exception ^e){}; 
}

/*-----------------------------------------------------------------------------------------------*/
								//***** Заполнение матрицы *****//

private: System::Void Matrix_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		int Cell = e->ColumnIndex; 
		int Row = e->RowIndex; 

		try{ 
			int I = Convert::ToInt32(this->Matrix->Rows[Row]->Cells[Cell]->Value->ToString()); 
			if ((I < 0) || (Row == Cell)){
				this->Matrix->Rows[Row]->Cells[Cell]->Value = 0;  
			}
			this->Matrix->Rows[Cell]->Cells[Row]->Value = this->Matrix->Rows[Row]->Cells[Cell]->Value; 
		}catch(System::Exception ^e){
			this->Matrix->Rows[Row]->Cells[Cell]->Value = 0;  
		}; 
}

/*-----------------------------------------------------------------------------------------------*/
								//***** Случайная инициализация *****//

private: System::Void FillTheMatrix_Click(System::Object^  sender, System::EventArgs^  e) {
		int I, J; 
		srand(time(0)); 
		int MinOfRnd = 0;  
		int MaxOfRnd = 10; 
		for (int I = 0;  I<NumOfTops;  I++){ 
			for (int J = I+1;  J<NumOfTops;  J++){
				int temp = (double)rand()/(RAND_MAX + 1)*(MaxOfRnd - MinOfRnd)+MinOfRnd; 
				this->Matrix->Rows[I]->Cells[J]->Value = temp; 
			}
		}
		Paint(); 
}

/*-----------------------------------------------------------------------------------------------*/
								//***** Выполнить *****//

private: System::Void ButtonDone_Click(System::Object^  sender, System::EventArgs^  e) {
		int *Length =  new int [NumOfTops];  
		int *Ot = new int [NumOfTops];  

		for (int I = 0; I<NumOfTops; I++){
			Ot[I] = -1;  
		}
		for (int I = 0; I<NumOfTops; I++){
			Length[I] = MAX;  
		}

		if (Flag){ 
			Heap heap(NumOfTops);  
			int I, J, K, L; 
			for (I = 0; I<NumOfTops; I++){ 
				Field tmp;  
				tmp.Name = I;  
				if (I == StartTop){
					tmp.Value = 0;  
				}else{
					tmp.Value = MAX;  
				}
				heap.Add(tmp);  
			}
			Field tmp; 
			for (I = 0; I < NumOfTops - 1; I++){ 
				tmp = heap.Extract();  
				Length[tmp.Name] = tmp.Value;  
				for (J = 0; J < NumOfTops - I - 1; J++){ 
					K = tmp.Name;  
					L = heap.GetName(J);  
					int I1 = Convert::ToInt32(this->Matrix->Rows[K]->Cells[L]->Value->ToString());  
					if ((I1 != 0) && (tmp.Value + I1 < heap.GetValue(J))){
						heap.Init(J, tmp.Value + I1);  
						Ot[L] = K; 
					}
				}
			}
			tmp = heap.Extract();  
			Length[tmp.Name] = tmp.Value;  
		}else{
			Tree Derevo;  
			int St = StartTop;  
			int I, J, K, L; 
			int Size = NumOfTops;  
			bool *Otm = new bool[Size]; 
			for (I = 0; I < Size; I++){ 
				if (I == St){
					Derevo.Add(0, I); 
					Length[I] = 0; 
				}else{
					Derevo.Add(MAX, I); 
					Length[I] = MAX; 
				}
			Otm[I] = false;  
			}
			for (I = 0; I<Size - 1; I++){
				int tmp = Derevo.Extract();  
				int ss = -1;  
				Otm[tmp] = true;  
				for (J = 0; J < Size - I - 1; J++){ 
					K = tmp;  
					ss++; 
					while (Otm[ss]){
						ss++; 
					} 
					L = ss; 
					int I1 = Convert::ToInt32(this->Matrix->Rows[K]->Cells[L]->Value->ToString());  
					if ((I1 != 0) && (Length[tmp] + I1 < Length[L])){ 
						Derevo.Change(Length[L], L, Length[tmp] + I1);  
						Length[L] = Length[tmp] + I1;  
						Ot[L] = tmp;  
					}
				}
			}
		}
		this->DataRoads->RowCount = NumOfTops;
		for (int I = 0; I < NumOfTops; I++){
			this->DataRoads->Rows[I]->Cells[0]->Value = "S(" + Convert::ToString(StartTop) + ", " +Convert::ToString(I) + ")";
			if (abs(MAX-abs(Length[I])) <= 100){
				this->DataRoads->Rows[I]->Cells[1]->Value = "+Inf";
			}else{
				this->DataRoads->Rows[I]->Cells[1]->Value = Convert::ToString(Length[I]);
			}
			int tmp = Ot[I]; 
			if (tmp >= 0){
				this->DataRoads->Rows[I]->Cells[2]->Value = Convert::ToString(I);
				while (tmp >= 0){ 
					this->DataRoads->Rows[I]->Cells[2]->Value += "-" + Convert::ToString(tmp);
					tmp = Ot[tmp]; 
				}
			}else{ 
				this->DataRoads->Rows[I]->Cells[2]->Value = "Empty";
			}
		}
		delete [] Length;  
		Paint();  
	}

/*-----------------------------------------------------------------------------------------------*/
								//***** Выбор Кучи *****//

private: System::Void HeapIsSelect_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		Flag = true; 
}

/*-----------------------------------------------------------------------------------------------*/
								//***** Выбор Дерева *****//

private: System::Void TreeIsSelect_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		Flag = false; 
}

/*-----------------------------------------------------------------------------------------------*/
									//***** Выход *****//

private: System::Void ButtonExit_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close(); 
}


}; 
}

