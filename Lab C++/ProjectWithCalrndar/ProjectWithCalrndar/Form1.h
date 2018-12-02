#pragma once
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "InternetForm.h"
#include <stdio.h>
#include <ctype.h>
#include <Vcclr.h>
#include <stdlib.h>
#include <string> 
#include <fstream>
#include "Array_of_Lighting_Labels.h"
#include "TList.h"
#include "RefClass.h"
//#include "DataBase.h"
#include "FormaProverka.h"

#define CodeOK 0
#define CodeError 1
#define CodeNoMem 2
#define CodeKoza 3

namespace ProjectWithCalrndar {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
    using namespace Runtime::InteropServices;  
	//using namespace DataBase;

	public ref class Form1 : public System::Windows::Forms::Form{

	public:
		Form1(void){
			InitializeComponent();
			DataString = "";
		}

	protected:
		~Form1(){
			if (components){
				delete components;
			}
		}

	#pragma region Глобальные переменные
	public:
		System::String ^DataString;
		//FILE *file;
		ifstream *file;
	#pragma endregion

	#pragma region Объекты формы
	private:
		System::Windows::Forms::PictureBox^  pictureBox1;
		System::Windows::Forms::RichTextBox^  richTextBox1;
		System::Windows::Forms::Button^  button1;
		System::Windows::Forms::ProgressBar^  progressBar1;
		System::Windows::Forms::Button^  button2;
		System::Windows::Forms::ToolTip^  toolTip1;
		System::Windows::Forms::TabControl^  tabControl1;
		System::Windows::Forms::TabPage^  tabPage1;
		System::Windows::Forms::TabPage^  tabPage2;
		System::Windows::Forms::TabPage^  tabPage3;
		System::Windows::Forms::Button^  Button_CreateNewConvertForm;
		System::Windows::Forms::MenuStrip^  menuStrip1;
		System::Windows::Forms::ToolStripMenuItem^  MenuItem_File;
		System::Windows::Forms::ToolStripMenuItem^  MenuItem_File_NewFile;
		System::Windows::Forms::ToolStripMenuItem^  MenuItem_File_OpenFile;
		System::Windows::Forms::ToolStripMenuItem^  MenuItem_File_SaveFile;
		System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
		System::Windows::Forms::ToolStripMenuItem^  MenuItem_File_SaveFileAs;
		System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
		System::Windows::Forms::ToolStripMenuItem^  MenuItem_File_Exit;
		System::Windows::Forms::Button^  Button_InitConvertForm;
		System::Windows::Forms::ContextMenuStrip^  R_Context;



		System::Windows::Forms::ToolStripMenuItem^  qwerToolStripMenuItem;
		cli::array<Lighting_Label^>^ Array_of_labels;
		System::Windows::Forms::Label^  LabelNum;





		System::ComponentModel::IContainer^  components;
	#pragma endregion

	#pragma region Дизайнер Windows-формы
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->R_Context = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->qwerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->Button_CreateNewConvertForm = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->MenuItem_File = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MenuItem_File_NewFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MenuItem_File_OpenFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->MenuItem_File_SaveFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MenuItem_File_SaveFileAs = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->MenuItem_File_Exit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Button_InitConvertForm = (gcnew System::Windows::Forms::Button());
			this->LabelNum = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->R_Context->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(729, 39);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(146, 194);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// richTextBox1
			// 
			this->richTextBox1->BulletIndent = 2;
			this->richTextBox1->ContextMenuStrip = this->R_Context;
			this->richTextBox1->Location = System::Drawing::Point(12, 39);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(345, 420);
			this->richTextBox1->TabIndex = 3;
			this->richTextBox1->Text = L"";
			// 
			// R_Context
			// 
			this->R_Context->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->qwerToolStripMenuItem});
			this->R_Context->Name = L"contextMenuStrip1";
			this->R_Context->Size = System::Drawing::Size(122, 26);
			// 
			// qwerToolStripMenuItem
			// 
			this->qwerToolStripMenuItem->Name = L"qwerToolStripMenuItem";
			this->qwerToolStripMenuItem->Size = System::Drawing::Size(121, 22);
			this->qwerToolStripMenuItem->Text = L"Выбрать";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(387, 404);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Интернет";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(93, 465);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(264, 23);
			this->progressBar1->TabIndex = 7;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 465);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Число ПИ";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Appearance = System::Windows::Forms::TabAppearance::Buttons;
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(364, 39);
			this->tabControl1->Multiline = true;
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(334, 194);
			this->tabControl1->TabIndex = 10;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::White;
			this->tabPage1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tabPage1.BackgroundImage")));
			this->tabPage1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->tabPage1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(326, 165);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"tabPage1";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::Color::White;
			this->tabPage2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tabPage2.BackgroundImage")));
			this->tabPage2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->tabPage2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(326, 165);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"tabPage2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// tabPage3
			// 
			this->tabPage3->BackColor = System::Drawing::Color::White;
			this->tabPage3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tabPage3.BackgroundImage")));
			this->tabPage3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->tabPage3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(326, 165);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"tabPage3";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// Button_CreateNewConvertForm
			// 
			this->Button_CreateNewConvertForm->Location = System::Drawing::Point(368, 239);
			this->Button_CreateNewConvertForm->Name = L"Button_CreateNewConvertForm";
			this->Button_CreateNewConvertForm->Size = System::Drawing::Size(326, 23);
			this->Button_CreateNewConvertForm->TabIndex = 11;
			this->Button_CreateNewConvertForm->Text = L"Button_CreateNewConvertForm";
			this->Button_CreateNewConvertForm->UseVisualStyleBackColor = true;
			this->Button_CreateNewConvertForm->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->MenuItem_File});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1026, 24);
			this->menuStrip1->TabIndex = 12;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// MenuItem_File
			// 
			this->MenuItem_File->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {this->MenuItem_File_NewFile, 
				this->MenuItem_File_OpenFile, this->toolStripSeparator1, this->MenuItem_File_SaveFile, this->MenuItem_File_SaveFileAs, this->toolStripSeparator2, 
				this->MenuItem_File_Exit});
			this->MenuItem_File->Name = L"MenuItem_File";
			this->MenuItem_File->Size = System::Drawing::Size(37, 20);
			this->MenuItem_File->Text = L"&File";
			// 
			// MenuItem_File_NewFile
			// 
			this->MenuItem_File_NewFile->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->MenuItem_File_NewFile->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"MenuItem_File_NewFile.Image")));
			this->MenuItem_File_NewFile->Name = L"MenuItem_File_NewFile";
			this->MenuItem_File_NewFile->ShortcutKeyDisplayString = L"Ctrl+N";
			this->MenuItem_File_NewFile->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			this->MenuItem_File_NewFile->Size = System::Drawing::Size(167, 22);
			this->MenuItem_File_NewFile->Text = L"&New File";
			this->MenuItem_File_NewFile->Click += gcnew System::EventHandler(this, &Form1::MenuItem_File_NewFile_Click);
			// 
			// MenuItem_File_OpenFile
			// 
			this->MenuItem_File_OpenFile->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"MenuItem_File_OpenFile.Image")));
			this->MenuItem_File_OpenFile->Name = L"MenuItem_File_OpenFile";
			this->MenuItem_File_OpenFile->ShortcutKeyDisplayString = L"Ctrl+O";
			this->MenuItem_File_OpenFile->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->MenuItem_File_OpenFile->Size = System::Drawing::Size(167, 22);
			this->MenuItem_File_OpenFile->Text = L"&Open File";
			this->MenuItem_File_OpenFile->Click += gcnew System::EventHandler(this, &Form1::MenuItem_File_OpenFile_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(164, 6);
			// 
			// MenuItem_File_SaveFile
			// 
			this->MenuItem_File_SaveFile->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"MenuItem_File_SaveFile.Image")));
			this->MenuItem_File_SaveFile->Name = L"MenuItem_File_SaveFile";
			this->MenuItem_File_SaveFile->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->MenuItem_File_SaveFile->Size = System::Drawing::Size(167, 22);
			this->MenuItem_File_SaveFile->Text = L"&Save File";
			this->MenuItem_File_SaveFile->Click += gcnew System::EventHandler(this, &Form1::MenuItem_File_SaveFile_Click);
			// 
			// MenuItem_File_SaveFileAs
			// 
			this->MenuItem_File_SaveFileAs->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"MenuItem_File_SaveFileAs.Image")));
			this->MenuItem_File_SaveFileAs->Name = L"MenuItem_File_SaveFileAs";
			this->MenuItem_File_SaveFileAs->Size = System::Drawing::Size(167, 22);
			this->MenuItem_File_SaveFileAs->Text = L"Save File as...";
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(164, 6);
			// 
			// MenuItem_File_Exit
			// 
			this->MenuItem_File_Exit->Name = L"MenuItem_File_Exit";
			this->MenuItem_File_Exit->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::E));
			this->MenuItem_File_Exit->Size = System::Drawing::Size(167, 22);
			this->MenuItem_File_Exit->Text = L"&Exit";
			this->MenuItem_File_Exit->Click += gcnew System::EventHandler(this, &Form1::MenuItem_File_Exit_Click);
			// 
			// Button_InitConvertForm
			// 
			this->Button_InitConvertForm->Location = System::Drawing::Point(368, 268);
			this->Button_InitConvertForm->Name = L"Button_InitConvertForm";
			this->Button_InitConvertForm->Size = System::Drawing::Size(326, 23);
			this->Button_InitConvertForm->TabIndex = 13;
			this->Button_InitConvertForm->Text = L"Button_InitConvertForm";
			this->Button_InitConvertForm->UseVisualStyleBackColor = true;
			this->Button_InitConvertForm->Click += gcnew System::EventHandler(this, &Form1::Button_InitConvertForm_Click);
			// 
			// LabelNum
			// 
			this->LabelNum->AutoEllipsis = true;
			this->LabelNum->BackColor = System::Drawing::Color::Transparent;
			this->LabelNum->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->LabelNum->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->LabelNum->Location = System::Drawing::Point(819, 322);
			this->LabelNum->Name = L"LabelNum";
			this->LabelNum->Size = System::Drawing::Size(150, 150);
			this->LabelNum->TabIndex = 0;
			this->LabelNum->Text = L"99";
			this->LabelNum->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->LabelNum->UseMnemonic = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1026, 500);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->LabelNum);
			this->Controls->Add(this->Button_InitConvertForm);
			this->Controls->Add(this->Button_CreateNewConvertForm);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"0";
			this->toolTip1->SetToolTip(this, L"Это форма");
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->R_Context->ResumeLayout(false);
			this->tabControl1->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion

	#pragma region Функции
		#pragma region Перевод "System::String^" в "const char*"
			const char* SysToChar(System::String^ SysStr){
				return (const char*) (Marshal::StringToHGlobalAnsi(SysStr)).ToPointer();
			}
		#pragma endregion

		#pragma region Перевод "System::String^" в "const wchar_t*"
			const wchar_t* SysToWchar_t(System::String^ SysStr){
				return (const wchar_t*) (Marshal::StringToHGlobalAnsi(SysStr)).ToPointer();
			}
		#pragma endregion

		#pragma region Перевод "const char*" в "System::String^"
			System::String^ CharToSys(const char* CharStr){
				return gcnew System::String(CharStr);
			}
		#pragma endregion

		#pragma region Перевод "System::String^" в адрес файла
			System::String^ SysStrToFileAddr(System::String^ SysStr){
				System::String^ FileAddr;
				for (int I=0; I<SysStr->Length; I++){
					if (SysStr[I] == '\\'){
						FileAddr += "\\";
					}
					FileAddr += SysStr[I];
				}
				return FileAddr;
			}
		#pragma endregion

	#pragma endregion

public:
	#pragma region Загрузка формы (Form1_Load)
		void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			TList<System::Object^> Spisok;
			Spisok.Add(this);
			Spisok.Add(this->tabPage1);
			Spisok.Add(this->tabPage2);
			Spisok.Add(this->tabPage3);
			Spisok.Delete(this);

			RefClass ^refclass = gcnew RefClass();
			//this->richTextBox1->Text = refclass->String;

			//CreatePersons(5);
			//InitializePersons(0, "Sergey", "Davydov", 34);
			//PrintAllPersons((System::Windows::Forms::TextBox^) this->richTextBox1);
		}
	#pragma endregion

	#pragma region button1_Click
		System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			System::String ^str = "E:\\Егор\\ФК Волга НН\\kit#1.jpg";
			pictureBox1->Load(str);

			ProjectWithCalrndar::InternetForm ^newform = gcnew ProjectWithCalrndar::InternetForm("http://fcvolgann.ru/addon/gbook/index/1");
			newform->Show();

		}
	#pragma endregion

	#pragma region button2_Click (Тестирование: Вычисление числа ПИ.)
		System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			int Radius;
			long Counter = 0;
			int Num_Of_Exps = 4;
			this->richTextBox1->Text = "Experiment #One:\n";
			for (int D = 1; D < Num_Of_Exps + 1; D++){
				Counter = 0;
				Radius = (int) (2 * pow(10.0, (int) D));
				this->progressBar1->Value = 0;
				this->progressBar1->Maximum = 2*Radius;
				this->richTextBox1->Text += "    " + D.ToString() + "). Radius = " + Radius.ToString() + ":" + "\n";
				for (int I = -Radius; I < Radius; I++){
					this->progressBar1->Value++;
					for (int J = -Radius; J < Radius + 1; J++){
						if (I*I + J*J <= Radius*Radius){
							Counter++;
						}
					}
				}
				float Ans = ((float) Counter) / (Radius * Radius);
				this->richTextBox1->Text += "        Result = " + Ans.ToString() + "\n";
			}
			this->richTextBox1->Text += "\n";

			this->richTextBox1->Text += "Experiment #Two:" + "\n";
			srand(time(0)); 
			Radius = 1000;
			Counter = 0;
			double X;
			double Y;
			int N = 1000000;
			this->progressBar1->Value = 0;
			this->progressBar1->Maximum = N;
			for (int I = 0; I < N; I++){
				this->progressBar1->Value++;
				X = (rand() * (2 * Radius) / (RAND_MAX + 1)) - (Radius);
				Y = (rand() * (2 * Radius) / (RAND_MAX + 1)) - (Radius);
				if (X*X + Y*Y <= Radius*Radius){
					Counter++;
				}
			}
			float Res = ((float) Counter) / N * 4;
			this->richTextBox1->Text += "    Result = " + Res.ToString() + '\n';

			this->progressBar1->Value = 0;
		}
	#pragma endregion

	#pragma region button3_Click (Считать данные из формы ConvertForm)
		System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			DataBase::Count = 5;

			ProjectWithCalrndar::FormaProverka^ newform = gcnew FormaProverka();
			newform->Show(this);

			//System::Media::SoundPlayer ^ f;
			//f = gcnew System::Media::SoundPlayer("E:\\Егор\\Школа\\Университет\\Лабораторная C++\\NewYear2011\\Media\\Start_Song.wav");
			//f->Play(); 
		}

		System::Void Button_InitConvertForm_Click(System::Object^  sender, System::EventArgs^  e) {
			//ProjectWithCalrndar::ConvertForm^ newform = gcnew ConvertForm();
			//newform->str = this->richTextBox1->Text;
			
			//this->sl = (gcnew Lighting_Label(this))[3];
			Array_of_Lighting_Labels^ Array_of_labels = gcnew Array_of_Lighting_Labels(this, 10, R_Context);

			//System::Drawing::Graphics^ MyGrahpic = this->LabelNum->CreateGraphics();
			//MyGrahpic->FillEllipse(gcnew System::Drawing::SolidBrush(System::Drawing::Color::Blue), 0, 0 , this->LabelNum->Width, this->LabelNum->Height);
			//MyGrahpic->FillEllipse(gcnew System::Drawing::SolidBrush(System::Drawing::Color::White), 5, 5 , this->LabelNum->Width - 10, this->LabelNum->Height - 10);
		}
	#pragma endregion

	#pragma region MenuItem_File_NewFile_Click (Создать новый файл)
		System::Void MenuItem_File_NewFile_Click(System::Object^  sender, System::EventArgs^  e) {
			//System::Windows::Forms::DialogResult Res = System::Windows::Forms::DialogResult::Yes;
			//if (file->is_open()){
			//	String^ message = "Вы уверены, что хотите создать новый файл?";
			//	String^ caption = "Создать новый файл?";
			//	MessageBoxButtons buttons = MessageBoxButtons::YesNo;
			//	System::Windows::Forms::MessageBoxIcon icon = MessageBoxIcon::Question;
			//	Res = MessageBox::Show( this, message, caption, buttons, icon );

			//	if ( Res == System::Windows::Forms::DialogResult::Yes ){
			//		this->richTextBox1->Text = "";
			//		fclose(file);
			//	}
			//}
			//if (Res == System::Windows::Forms::DialogResult::Yes){
			//	SaveFileDialog^ sFileDialog = gcnew SaveFileDialog();
			//	sFileDialog->Title = "Create new file";
			//	sFileDialog->Filter = "Text file (*.txt)|*.txt";
			//	sFileDialog->FilterIndex = 1;
			//	if (sFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK){
			//		file = fopen(SysToChar(sFileDialog->FileName), "w");
			//	}
			//}
			t = gcnew ToolTip();
            t->SetToolTip(this->LabelNum, "Показывать окно веверх всех окон");

		}
	#pragma endregion
ToolTip^ t;

	#pragma region MenuItem_File_OpenFile_Click (Открыть файл)
		System::Void MenuItem_File_OpenFile_Click(System::Object^  sender, System::EventArgs^  e) {
			OpenFileDialog^ oFileDialog = gcnew OpenFileDialog();
			oFileDialog->Title = "Open file";
			oFileDialog->Filter = "Text files (*.txt)|*.txt";
			oFileDialog->FilterIndex = 1;

			if (oFileDialog->ShowDialog(this) == System::Windows::Forms::DialogResult::OK){
				try{
					this->richTextBox1->Text = "";

					//file = fopen( SysToChar(oFileDialog->FileName), "r");
					//while (!feof(file)){
					//	int a;
					//	fscanf(file, "%d" ,&a);
					//	this->richTextBox1->Text += a.ToString() + " ";
					//}

					//pin_ptr<const wchar_t> name_of_file = PtrToStringChars(oFileDialog->FileName);
					////ifstream file;
					//file->open(oFileDialog->FileName);
					//file->unsetf(ios::skipws);
					//
					//if (file->fail()){
					//	this->richTextBox1->Text += "Error\n" + SysStrToFileAddr(oFileDialog->FileName);
					//}

					//while(&file){
					//	char d;
					//	//&file >> d;
					//	this->richTextBox1->Text += Convert::ToChar(d).ToString();
					//}
				}
				catch(Exception^ ex){
					MessageBox::Show( this, "Не удаётся считать данные с файла\n\n" + ex->ToString() , "Ошибка!",
										System::Windows::Forms::MessageBoxButtons::OK,
										System::Windows::Forms::MessageBoxIcon::Error );
				}
			}
		}
	#pragma endregion

	#pragma region Сохранить файл
		System::Void MenuItem_File_SaveFile_Click(System::Object^  sender, System::EventArgs^  e) {
			//while (this->richTextBox1->Text){
				int i;
				double d = 5.6;
				i = static_cast <int> (d);
				this->richTextBox1->Text = i.ToString();
			//}
		}
	#pragma endregion
	
	#pragma region Выход из приложения
		System::Void MenuItem_File_Exit_Click(System::Object^  sender, System::EventArgs^  e) {
			Application::Exit();
		}
	#pragma endregion
};
}

