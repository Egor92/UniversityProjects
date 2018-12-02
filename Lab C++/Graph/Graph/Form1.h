#pragma once
#include <vcclr.h>
#include <string>
#include "BitString.h"
#include <math.h>


namespace Graph {

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

	protected: 
	private: System::Windows::Forms::Button^  ButtonVypolnit;
	private: System::Windows::Forms::GroupBox^  GBMatrix;
	private: System::Windows::Forms::DataGridView^  DGVMatrix;
	private: System::Windows::Forms::Label^  LabelKolichestvoVershin;
	private: System::Windows::Forms::TextBox^  TBKolichestvoVershin;
	private: System::Windows::Forms::TextBox^  TBSpisokReber;
	private: System::Windows::Forms::Label^  LabelSpisokReber;
	private: System::Windows::Forms::TextBox^  TBVesDereva;
	private: System::Windows::Forms::Label^  LabelVesDereva;
	private: System::Windows::Forms::Label^  LabelHelp;
	private: System::Windows::Forms::GroupBox^  GBGraph;
	private: System::Windows::Forms::GroupBox^  GBKarkas;
	private: System::Windows::Forms::Label^  LabelKoren;
	private: System::Windows::Forms::TextBox^  TBKoren;
	private: System::Windows::Forms::Panel^  PanelGraph;
	private: System::Windows::Forms::Panel^  PanelKarkas;
	private: System::Windows::Forms::Button^  ButtonAbout;
	private: System::Windows::Forms::Button^  ButtonTekhPodderzhka;


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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->ButtonVypolnit = (gcnew System::Windows::Forms::Button());
			this->GBMatrix = (gcnew System::Windows::Forms::GroupBox());
			this->TBKoren = (gcnew System::Windows::Forms::TextBox());
			this->LabelKoren = (gcnew System::Windows::Forms::Label());
			this->DGVMatrix = (gcnew System::Windows::Forms::DataGridView());
			this->LabelKolichestvoVershin = (gcnew System::Windows::Forms::Label());
			this->TBKolichestvoVershin = (gcnew System::Windows::Forms::TextBox());
			this->TBSpisokReber = (gcnew System::Windows::Forms::TextBox());
			this->LabelSpisokReber = (gcnew System::Windows::Forms::Label());
			this->TBVesDereva = (gcnew System::Windows::Forms::TextBox());
			this->LabelVesDereva = (gcnew System::Windows::Forms::Label());
			this->LabelHelp = (gcnew System::Windows::Forms::Label());
			this->GBGraph = (gcnew System::Windows::Forms::GroupBox());
			this->PanelGraph = (gcnew System::Windows::Forms::Panel());
			this->GBKarkas = (gcnew System::Windows::Forms::GroupBox());
			this->PanelKarkas = (gcnew System::Windows::Forms::Panel());
			this->ButtonAbout = (gcnew System::Windows::Forms::Button());
			this->ButtonTekhPodderzhka = (gcnew System::Windows::Forms::Button());
			this->GBMatrix->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DGVMatrix))->BeginInit();
			this->GBGraph->SuspendLayout();
			this->GBKarkas->SuspendLayout();
			this->SuspendLayout();
			// 
			// ButtonVypolnit
			// 
			this->ButtonVypolnit->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ButtonVypolnit->Cursor = System::Windows::Forms::Cursors::Cross;
			this->ButtonVypolnit->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->ButtonVypolnit->ForeColor = System::Drawing::Color::Black;
			this->ButtonVypolnit->Location = System::Drawing::Point(12, 670);
			this->ButtonVypolnit->Name = L"ButtonVypolnit";
			this->ButtonVypolnit->Size = System::Drawing::Size(101, 26);
			this->ButtonVypolnit->TabIndex = 15;
			this->ButtonVypolnit->Text = L"Выполнить";
			this->ButtonVypolnit->UseVisualStyleBackColor = true;
			this->ButtonVypolnit->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::ButtonVypolnit_MouseMove);
			this->ButtonVypolnit->Click += gcnew System::EventHandler(this, &Form1::ButtonVypolnit_Click);
			// 
			// GBMatrix
			// 
			this->GBMatrix->Controls->Add(this->TBKoren);
			this->GBMatrix->Controls->Add(this->LabelKoren);
			this->GBMatrix->Controls->Add(this->DGVMatrix);
			this->GBMatrix->Controls->Add(this->LabelKolichestvoVershin);
			this->GBMatrix->Controls->Add(this->TBKolichestvoVershin);
			this->GBMatrix->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->GBMatrix->ForeColor = System::Drawing::Color::Black;
			this->GBMatrix->Location = System::Drawing::Point(12, 11);
			this->GBMatrix->Name = L"GBMatrix";
			this->GBMatrix->Size = System::Drawing::Size(509, 396);
			this->GBMatrix->TabIndex = 14;
			this->GBMatrix->TabStop = false;
			this->GBMatrix->Text = L"Задать матрицу:";
			// 
			// TBKoren
			// 
			this->TBKoren->Location = System::Drawing::Point(153, 48);
			this->TBKoren->Name = L"TBKoren";
			this->TBKoren->Size = System::Drawing::Size(350, 22);
			this->TBKoren->TabIndex = 4;
			this->TBKoren->TextChanged += gcnew System::EventHandler(this, &Form1::TBKoren_TextChanged);
			this->TBKoren->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::TBKoren_MouseMove);
			// 
			// LabelKoren
			// 
			this->LabelKoren->AutoSize = true;
			this->LabelKoren->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->LabelKoren->Location = System::Drawing::Point(6, 51);
			this->LabelKoren->Name = L"LabelKoren";
			this->LabelKoren->Size = System::Drawing::Size(134, 16);
			this->LabelKoren->TabIndex = 3;
			this->LabelKoren->Text = L"Корневая вершина:";
			// 
			// DGVMatrix
			// 
			this->DGVMatrix->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DGVMatrix->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->DGVMatrix->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->DGVMatrix->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->DGVMatrix->ColumnHeadersHeight = 4;
			this->DGVMatrix->Location = System::Drawing::Point(6, 76);
			this->DGVMatrix->MultiSelect = false;
			this->DGVMatrix->Name = L"DGVMatrix";
			this->DGVMatrix->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->DGVMatrix->RowHeadersWidth = 4;
			dataGridViewCellStyle1->NullValue = L"0";
			this->DGVMatrix->RowsDefaultCellStyle = dataGridViewCellStyle1;
			this->DGVMatrix->Size = System::Drawing::Size(497, 314);
			this->DGVMatrix->TabIndex = 2;
			this->DGVMatrix->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::DGVMatrix_CellValueChanged);
			this->DGVMatrix->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::DGVMatrix_MouseMove);
			// 
			// LabelKolichestvoVershin
			// 
			this->LabelKolichestvoVershin->AccessibleRole = System::Windows::Forms::AccessibleRole::TitleBar;
			this->LabelKolichestvoVershin->AutoSize = true;
			this->LabelKolichestvoVershin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->LabelKolichestvoVershin->Location = System::Drawing::Point(6, 23);
			this->LabelKolichestvoVershin->Name = L"LabelKolichestvoVershin";
			this->LabelKolichestvoVershin->Size = System::Drawing::Size(141, 16);
			this->LabelKolichestvoVershin->TabIndex = 1;
			this->LabelKolichestvoVershin->Text = L"Количество вершин:";
			// 
			// TBKolichestvoVershin
			// 
			this->TBKolichestvoVershin->Location = System::Drawing::Point(153, 20);
			this->TBKolichestvoVershin->Name = L"TBKolichestvoVershin";
			this->TBKolichestvoVershin->Size = System::Drawing::Size(350, 22);
			this->TBKolichestvoVershin->TabIndex = 0;
			this->TBKolichestvoVershin->TextChanged += gcnew System::EventHandler(this, &Form1::TBKolichestvoVershin_TextChanged);
			this->TBKolichestvoVershin->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::TBKolichestvoVershin_MouseMove);
			// 
			// TBSpisokReber
			// 
			this->TBSpisokReber->BackColor = System::Drawing::Color::WhiteSmoke;
			this->TBSpisokReber->Location = System::Drawing::Point(119, 436);
			this->TBSpisokReber->Multiline = true;
			this->TBSpisokReber->Name = L"TBSpisokReber";
			this->TBSpisokReber->ReadOnly = true;
			this->TBSpisokReber->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->TBSpisokReber->Size = System::Drawing::Size(402, 226);
			this->TBSpisokReber->TabIndex = 13;
			this->TBSpisokReber->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::TBSpisokReber_MouseMove);
			// 
			// LabelSpisokReber
			// 
			this->LabelSpisokReber->AutoSize = true;
			this->LabelSpisokReber->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->LabelSpisokReber->ForeColor = System::Drawing::Color::Black;
			this->LabelSpisokReber->Location = System::Drawing::Point(12, 436);
			this->LabelSpisokReber->Name = L"LabelSpisokReber";
			this->LabelSpisokReber->Size = System::Drawing::Size(101, 16);
			this->LabelSpisokReber->TabIndex = 12;
			this->LabelSpisokReber->Text = L"Список рёбер:";
			// 
			// TBVesDereva
			// 
			this->TBVesDereva->BackColor = System::Drawing::Color::WhiteSmoke;
			this->TBVesDereva->Location = System::Drawing::Point(104, 410);
			this->TBVesDereva->Name = L"TBVesDereva";
			this->TBVesDereva->ReadOnly = true;
			this->TBVesDereva->Size = System::Drawing::Size(417, 20);
			this->TBVesDereva->TabIndex = 11;
			this->TBVesDereva->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::TBVesDereva_MouseMove);
			// 
			// LabelVesDereva
			// 
			this->LabelVesDereva->AutoSize = true;
			this->LabelVesDereva->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->LabelVesDereva->ForeColor = System::Drawing::Color::Black;
			this->LabelVesDereva->Location = System::Drawing::Point(12, 410);
			this->LabelVesDereva->Name = L"LabelVesDereva";
			this->LabelVesDereva->Size = System::Drawing::Size(86, 16);
			this->LabelVesDereva->TabIndex = 10;
			this->LabelVesDereva->Text = L"Вес дерева:";
			// 
			// LabelHelp
			// 
			this->LabelHelp->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->LabelHelp->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->LabelHelp->ForeColor = System::Drawing::Color::Black;
			this->LabelHelp->Location = System::Drawing::Point(119, 672);
			this->LabelHelp->Name = L"LabelHelp";
			this->LabelHelp->Size = System::Drawing::Size(733, 24);
			this->LabelHelp->TabIndex = 16;
			this->LabelHelp->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->LabelHelp->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::LabelHelp_MouseMove);
			// 
			// GBGraph
			// 
			this->GBGraph->Controls->Add(this->PanelGraph);
			this->GBGraph->ForeColor = System::Drawing::Color::Black;
			this->GBGraph->Location = System::Drawing::Point(540, 12);
			this->GBGraph->Name = L"GBGraph";
			this->GBGraph->Size = System::Drawing::Size(312, 325);
			this->GBGraph->TabIndex = 17;
			this->GBGraph->TabStop = false;
			this->GBGraph->Text = L"Исходный граф:";
			// 
			// PanelGraph
			// 
			this->PanelGraph->Location = System::Drawing::Point(6, 19);
			this->PanelGraph->Name = L"PanelGraph";
			this->PanelGraph->Size = System::Drawing::Size(300, 300);
			this->PanelGraph->TabIndex = 0;
			// 
			// GBKarkas
			// 
			this->GBKarkas->Controls->Add(this->PanelKarkas);
			this->GBKarkas->ForeColor = System::Drawing::Color::Black;
			this->GBKarkas->Location = System::Drawing::Point(540, 343);
			this->GBKarkas->Name = L"GBKarkas";
			this->GBKarkas->Size = System::Drawing::Size(312, 325);
			this->GBKarkas->TabIndex = 18;
			this->GBKarkas->TabStop = false;
			this->GBKarkas->Text = L"Соответствующий каркас:";
			// 
			// PanelKarkas
			// 
			this->PanelKarkas->Location = System::Drawing::Point(6, 19);
			this->PanelKarkas->Name = L"PanelKarkas";
			this->PanelKarkas->Size = System::Drawing::Size(300, 300);
			this->PanelKarkas->TabIndex = 0;
			// 
			// ButtonAbout
			// 
			this->ButtonAbout->Cursor = System::Windows::Forms::Cursors::Cross;
			this->ButtonAbout->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"ButtonAbout.Image")));
			this->ButtonAbout->ImageAlign = System::Drawing::ContentAlignment::BottomLeft;
			this->ButtonAbout->Location = System::Drawing::Point(12, 626);
			this->ButtonAbout->Name = L"ButtonAbout";
			this->ButtonAbout->Size = System::Drawing::Size(101, 28);
			this->ButtonAbout->TabIndex = 19;
			this->ButtonAbout->Text = L"О программе";
			this->ButtonAbout->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->ButtonAbout->UseVisualStyleBackColor = true;
			this->ButtonAbout->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::ButtonAbout_MouseMove);
			this->ButtonAbout->Click += gcnew System::EventHandler(this, &Form1::ButtonAbout_Click);
			// 
			// ButtonTekhPodderzhka
			// 
			this->ButtonTekhPodderzhka->Cursor = System::Windows::Forms::Cursors::Cross;
			this->ButtonTekhPodderzhka->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"ButtonTekhPodderzhka.Image")));
			this->ButtonTekhPodderzhka->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->ButtonTekhPodderzhka->Location = System::Drawing::Point(12, 468);
			this->ButtonTekhPodderzhka->Name = L"ButtonTekhPodderzhka";
			this->ButtonTekhPodderzhka->Size = System::Drawing::Size(101, 152);
			this->ButtonTekhPodderzhka->TabIndex = 20;
			this->ButtonTekhPodderzhka->Text = L"Тех. Поддержка";
			this->ButtonTekhPodderzhka->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->ButtonTekhPodderzhka->UseVisualStyleBackColor = true;
			this->ButtonTekhPodderzhka->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::ButtonTekhPodderzhka_MouseMove);
			this->ButtonTekhPodderzhka->Click += gcnew System::EventHandler(this, &Form1::ButtonTekhPodderzhka_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(862, 705);
			this->Controls->Add(this->ButtonTekhPodderzhka);
			this->Controls->Add(this->ButtonAbout);
			this->Controls->Add(this->GBMatrix);
			this->Controls->Add(this->GBKarkas);
			this->Controls->Add(this->GBGraph);
			this->Controls->Add(this->LabelHelp);
			this->Controls->Add(this->ButtonVypolnit);
			this->Controls->Add(this->TBSpisokReber);
			this->Controls->Add(this->LabelSpisokReber);
			this->Controls->Add(this->TBVesDereva);
			this->Controls->Add(this->LabelVesDereva);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->RightToLeftLayout = true;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Graph";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->GBMatrix->ResumeLayout(false);
			this->GBMatrix->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DGVMatrix))->EndInit();
			this->GBGraph->ResumeLayout(false);
			this->GBKarkas->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	//Глобальные переменные
		int KolichestvoVershin;
		int VesDereva;
        int Koren; 

/*------------------------------------------------------------------------------*/
								//MOUSEMOVE//
private: System::Void TBKolichestvoVershin_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		this->LabelHelp->Text="Задать количество вершин";
}

private: System::Void TBKoren_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		this->LabelHelp->Text="Задать корневую вершину";
}

private: System::Void DGVMatrix_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		this->LabelHelp->Text="Матрица смежности";
}

private: System::Void Form1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		this->LabelHelp->Text="";
		this->ButtonVypolnit->ForeColor = System::Drawing::Color::Black;
		this->ButtonTekhPodderzhka->ForeColor = System::Drawing::Color::Black;
		this->ButtonAbout->ForeColor = System::Drawing::Color::Black;
}

private: System::Void LabelHelp_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		this->LabelHelp->Text="Помощь";
}

private: System::Void ButtonVypolnit_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		this->LabelHelp->Text="Пошли работать!!!";
		this->ButtonVypolnit->ForeColor = System::Drawing::Color::Red;
}

private: System::Void TBVesDereva_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		this->LabelHelp->Text="Вес дерева";
}

private: System::Void TBSpisokReber_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		this->LabelHelp->Text="Список рёбер";
}

private: System::Void ButtonTekhPodderzhka_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		this->LabelHelp->Text="Техническая поддержка";
		this->ButtonTekhPodderzhka->ForeColor = System::Drawing::Color::Red;
}

private: System::Void ButtonAbout_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		this->LabelHelp->Text="Информация о производителе";
		this->ButtonAbout->ForeColor = System::Drawing::Color::Red;
}

/*------------------------------------------------------------------------------*/


private: System::Void ButtonAbout_Click(System::Object^  sender, System::EventArgs^  e) {
		this->TBSpisokReber->Text =								"===============================================================";
		this->TBSpisokReber->Text = this->TBSpisokReber->Text + "                             APPLICATION : Graph Project Overview   ";                                  
		this->TBSpisokReber->Text = this->TBSpisokReber->Text + "===============================================================";                                     
		this->TBSpisokReber->Text = this->TBSpisokReber->Text + "Версия 1.0.0.0							";
		this->TBSpisokReber->Text = this->TBSpisokReber->Text + "Производство ''The AFT Company''				";
		this->TBSpisokReber->Text = this->TBSpisokReber->Text + "Руководитель проекта:						     ";
		this->TBSpisokReber->Text = this->TBSpisokReber->Text + "Новиков Егор Александрович";
		this->TBSpisokReber->Text = this->TBSpisokReber->Text + "													";
		this->TBSpisokReber->Text = this->TBSpisokReber->Text + "Version 1.0.0.0							";
		this->TBSpisokReber->Text = this->TBSpisokReber->Text + "Production by ''The AFT Company''					";
		this->TBSpisokReber->Text = this->TBSpisokReber->Text + "The head of the project:						     ";
		this->TBSpisokReber->Text = this->TBSpisokReber->Text + "Novikov Egor Alexandrovich";
		this->TBSpisokReber->Text = this->TBSpisokReber->Text + "													";
		this->TBSpisokReber->Text = this->TBSpisokReber->Text + "25.09.2010";
}

private: System::Void ButtonTekhPodderzhka_Click(System::Object^  sender, System::EventArgs^  e) {
		this->TBSpisokReber->Text = "Техническая поддержка по телефону 89616362768 (звонок платный)";
}

private: System::Void TBKolichestvoVershin_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		//Вводим в TBKolichestvoVershin цифирь и запоминаем
		String ^s = this->TBKolichestvoVershin->Text;
		try{
			KolichestvoVershin = Convert::ToInt32(s);
			if (KolichestvoVershin > 0){  //Если она положительна только
				this->DGVMatrix->RowCount=KolichestvoVershin;
				this->DGVMatrix->ColumnCount=KolichestvoVershin;
			}
		}catch(System::Exception ^e){}
		// Рисуем вершины
		int I;
		double X,Y;
		double Pi;
     	Pi = 3.141592653592l;  //Число ПИ
		Color ^MyCol = gcnew Color();  //Сорздаём цвет
		Pen ^BlackPen = gcnew Pen (MyCol->Black);  //Создаём карандаш
		Graphics ^Gr = this->PanelGraph->CreateGraphics();  //Создаём графику
		Gr->Clear(MyCol->WhiteSmoke);  //Очищаем предыдущий рисунок
		for (I=0; I<KolichestvoVershin; I++){  //Для каждой вершины находим
			X = 145+135*cos(Pi/2-I*Pi*2/KolichestvoVershin);  //Координату "X"
			Y = 145+135*sin(-Pi/2-I*Pi*2/KolichestvoVershin);  //Координату "Y"
			Gr->DrawEllipse( BlackPen, X, Y, 10, 10 );  //И, наконец, рисуем её
		}

}

private: System::Void TBKoren_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		//Помни: Все вершины нумеруются с 1!
			String ^s = this->TBKoren->Text;
			try{
				Koren = Convert::ToInt32(s) - 1; //В вычислениях вершины нумеруются с 0!
				if ( ( Koren < 0 ) || ( Koren > (KolichestvoVershin-1) ) ){
					Koren = 0;
					this->TBKoren->Text = "1";
				}
			}catch(System::Exception ^e){}
}

private: System::Void DGVMatrix_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {

		int Col = e->ColumnIndex;   //Номер Столбца
		int Row = e->RowIndex;      //Номер Строки
		int I;

		//try{   //Все нормально? - копируй симметрично!								//Главная  //
			String ^s = this->DGVMatrix->Rows[Row]->Cells[Col]->Value->ToString();		//фигня -  //
		//}																				//не       //
		//catch(System::Exception ^e){   //Ввел фигню? - обнуляй!						//вводи    //
		//	String ^s = "0";															//в матрицу//
		//}																				//нули!!!  //

		if (Col==Row){   //Обнуление элементав на главной диагонали
			this->DGVMatrix->Rows[Col]->Cells[Row]->Value = 0;
		}
		else{
			try{   //Все нормально? - копируй симметрично!
				I=Convert::ToInt32(s);
				this->DGVMatrix->Rows[Col]->Cells[Row]->Value = 
				this->DGVMatrix->Rows[Row]->Cells[Col]->Value->ToString();
			}
			catch(System::Exception ^e){   //Ввел фигню? - обнуляй!
				this->DGVMatrix->Rows[Col]->Cells[Row]->Value = 0;
			}
		}

		//Графика это:
		double X,Y;                  //Где-то выше я писал комменты по поводу следующего десятка строк
		double Pi;					 //Но для ленивых я могу написать ещё раз:
		Pi = 3.141592653592l; //Число ПИ
		Color ^MyCol = gcnew Color();  //Сорздаём цвет
		Graphics ^Gr = this->PanelGraph->CreateGraphics();  //Создаём графику
		X = 150+135*cos(Pi/2-Col*Pi*2/KolichestvoVershin);  // Находим координату "X" для первой точки
		Y = 150+135*sin(-Pi/2-Col*Pi*2/KolichestvoVershin);  // Находим координату "Y" для первой точки
		Point Tochka1(X,Y);   //Первая точка
		X = 150+135*cos(Pi/2-Row*Pi*2/KolichestvoVershin);  // Находим координату "X" для второй точки
		Y = 150+135*sin(-Pi/2-Row*Pi*2/KolichestvoVershin);  // Находим координату "Y" для второй точки
		Point Tochka2(X,Y);   //Вторая точка
		if (this->DGVMatrix->Rows[Row]->Cells[Col]->Value->ToString() != "0"){
			Pen ^BlackPen1 = gcnew Pen (MyCol->Black);  //Создаём карандаш
			Gr->DrawLine( BlackPen1, Tochka1, Tochka2);  //Рисуем ребро
		}
		else{
			Pen ^BlackPen2 = gcnew Pen (MyCol->WhiteSmoke);  //Создаём карандаш
			Gr->DrawLine( BlackPen2, Tochka1, Tochka2);  //Очищаем ребро
			// Вершины после очистки ребра стали с "дырками", зарисуем их ещё раз, ну так сказать, для красоты
			Pen ^BlackPen3 = gcnew Pen (MyCol->Black);  //Создаём карандаш
			for (I=0; I<KolichestvoVershin; I++){  //Для каждой вершины находим
				X = 145+135*cos(Pi/2-I*Pi*2/KolichestvoVershin);  //Координату "X"
				Y = 145+135*sin(-Pi/2-I*Pi*2/KolichestvoVershin);  //Координату "Y"
				Gr->DrawEllipse( BlackPen3, X, Y, 10, 10 );  //И, наконец, рисуем её
			}
		}
		

}


private: System::Void ButtonVypolnit_Click(System::Object^  sender, System::EventArgs^  e) {
		BitString SostoyanieVershin(KolichestvoVershin);
		int *MatrixReber;
		int I,J,I1,J1,K,L;
		int SummaVesaReber;
		int Min;
		int MinLokal;
		bool Flag, FlagNashliRebro;
		//Это для графики:
		double X,Y;
		double Pi;
 		Pi = 3.141592653592l;  //Число ПИ
		Color ^MyCol = gcnew Color();  //Сорздаём цвет
		Pen ^BlackPen = gcnew Pen (MyCol->Black);  //Создаём карандаш
		Graphics ^Gr = this->PanelKarkas->CreateGraphics();  //Создаём графику
		
		MatrixReber = new int[KolichestvoVershin*KolichestvoVershin-1];  // Это - она, матрица элементов
																		 // Хоть и не оптимально задана, но.... и так сойдёт

		//Очистка предыдущих результатов
		this->TBSpisokReber->Text = "";
		this->TBVesDereva->Text = "";
		VesDereva = 0;  //Ах да, вот это я чуть не упустил
		Gr->Clear(MyCol->WhiteSmoke);  //Очищаем предыдущий рисунок
		
		//Матрица веса рёбер
		for (I=0; I<KolichestvoVershin; I++){
			for (J=0; J<KolichestvoVershin; J++){
				try{   //Здесь все нормально
					String ^str = this->DGVMatrix->Rows[I]->Cells[J]->Value->ToString();
					K = Convert::ToInt32(str);
					MatrixReber[I*KolichestvoVershin+J] = K;
				}
				catch(System::Exception ^e){   //А здесь - нет!.. Почему?
					MatrixReber[I*KolichestvoVershin+J] = 0;
				}
			}
		}

		//Проверим, есть ли изолированные вершины?
		Flag = false;  //false - нет, true - есть
		for (I=0; I<KolichestvoVershin; I++){
			K = 0;
			for (J=0; J<KolichestvoVershin; J++){
				K = K + MatrixReber[I*KolichestvoVershin+J];
			}
			if (K == 0) {
				Flag = true;
				break;
			}
		}

		if ( Flag == false ){
			// Рисуем вершины
			for (I=0; I<KolichestvoVershin; I++){  //Для каждой вершины находим
				X = 145+135*cos(Pi/2-I*Pi*2/KolichestvoVershin);  //Координату "X"
				Y = 145+135*sin(-Pi/2-I*Pi*2/KolichestvoVershin);  //Координату "Y"
				Gr->DrawEllipse( BlackPen, X, Y, 10, 10 );  //И, наконец, рисуем её
			}
		}


		//Щасъ основная часть работы:
		if (Flag == false){
			
			SostoyanieVershin.BitUp(Koren);
			SummaVesaReber = 0;  //Сумма всех элементов
			
			//Найдем вес ГРАФА
			for (I=0; I<KolichestvoVershin; I++){
				for (J=0; J<KolichestvoVershin; J++){
					SummaVesaReber = SummaVesaReber + MatrixReber[I*KolichestvoVershin+J];
				}
			}

			for (L=0; L<KolichestvoVershin-1; L++){
			Min = SummaVesaReber; // <- Пускай будет так
								  // Данное - пока идеально, т.к. ниже будем находить ребро реально миним. веса
				//Находим ребро минимальной длины
				for (I=0; I<KolichestvoVershin; I++){
					for (J=0; J<KolichestvoVershin; J++){
						if ( (MatrixReber[I*KolichestvoVershin+J]<Min) && (MatrixReber[I*KolichestvoVershin+J]!=0) ){
							Min = MatrixReber[I*KolichestvoVershin+J];
						}
					}
				}
				//this->TBVesDereva->Text = this->TBVesDereva->Text + " | " + Min.ToString() + "  ";

				FlagNashliRebro = false;   //Пока к.-л. ребро не найдено, то флаг опущен 
				MinLokal = Min;   //Локальный минимум - вес ребра
								  //Ищем ребро данного веса
								  //Если есть ребро, вес которого меньше, чем MinLokal, но оно соединяет две уже входящие (или две ещё не входящие) в текущий капкас вершины, то оно не может быть включено в текущий каркас, потому-что.....   Короче зад...ся я объяснять. Смотри код, который ниже, и ты короче сам всё поймешь!!!
				while (FlagNashliRebro == false){
					K = MinLokal;
					for (I=0; I<KolichestvoVershin; I++){
						for (J=0; J<KolichestvoVershin; J++){
							if ( (MatrixReber[I*KolichestvoVershin+J] == K ) ){
								if ( (SostoyanieVershin.BitGet(I) + SostoyanieVershin.BitGet(J)) == 1 ){
									//Добавим данное ребро в список
									if ( SostoyanieVershin.BitGet(I) > SostoyanieVershin.BitGet(J) ){  //Первым запишем ребро, уже вход. в каркас
										this->TBSpisokReber->Text = this->TBSpisokReber->Text + "(" + (I + 1).ToString() + "," + (J + 1).ToString() + ")  ";
									}else {
										this->TBSpisokReber->Text = this->TBSpisokReber->Text + "(" + (J + 1).ToString() + "," + (I + 1).ToString() + ")  ";
									}
									//Изменим состояние вершин I и J на "Включён в текущий каркас"
									SostoyanieVershin.BitUp(I);
									SostoyanieVershin.BitUp(J);
									//Ну и вес дерева увеличим...
									VesDereva = VesDereva + MatrixReber[I*KolichestvoVershin+J];
									//Эти рёбра нам больше не нужны
									MatrixReber[I*KolichestvoVershin+J] = 0;
									MatrixReber[J*KolichestvoVershin+I] = 0;
									//Рисуем рёбра
									X = 150+135*cos(Pi/2-I*Pi*2/KolichestvoVershin);  // Находим координату "X" для первой точки
									Y = 150+135*sin(-Pi/2-I*Pi*2/KolichestvoVershin);  // Находим координату "Y" для первой точки
									Point Tochka1(X,Y);   //Первая точка
									X = 150+135*cos(Pi/2-J*Pi*2/KolichestvoVershin);  // Находим координату "X" для второй точки
									Y = 150+135*sin(-Pi/2-J*Pi*2/KolichestvoVershin);  // Находим координату "Y" для второй точки
									Point Tochka2(X,Y);   //Вторая точка
									Gr->DrawLine( BlackPen, Tochka1, Tochka2);  //Рисуем ребро
									//Ребро найдено! Поиск завершить! А флаг поднять!
									FlagNashliRebro = true;
								}
							}						
							if (FlagNashliRebro == true) {break;} //Ребро нашли, бреакуй
						}
						if (FlagNashliRebro == true) {break;} //Ребро нашли, бреакуй
					}

					//Определяем новый локальный минимум
					MinLokal = SummaVesaReber;
					for (I1=0; I1<KolichestvoVershin; I1++){
						for (J1=0; J1<KolichestvoVershin; J1++){
							if ( (MatrixReber[I1*KolichestvoVershin+J1]<MinLokal) && (MatrixReber[I1*KolichestvoVershin+J1]!=0) && ( MatrixReber[I1*KolichestvoVershin+J1] > K ) ){
								MinLokal = MatrixReber[I1*KolichestvoVershin+J1];
							}
						}
					}

				}
			}

			this->TBVesDereva->Text = VesDereva.ToString();
		}
		else{
			this->TBVesDereva->Text = "Граф не связен";
		}
	
	//SostoyanieVershin.~BitString();

	/*------------------------------------------------------------
	-Ну чё, Егор Александрович, понял, как надо писать программы?
	-Да уж, спасибо. Ну ты и мудрая голова!
	-Да не за что. Если чё, звони 89616362768.
	-Ладно, до скорого!!!
	------------------------------------------------------------*/
}




private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}