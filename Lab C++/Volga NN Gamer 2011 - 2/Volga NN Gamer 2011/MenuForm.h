#pragma once
#include "StdAfx.h"
#using "..\Bin\Microsoft.DirectX.AudioVideoPlayback.dll"
#include "LightingLabel.h"

#define NULL 0
#define _VERY_EASY 0
#define _EASY 1
#define _NORMAL 2
#define _HARD 3
#define _VERY_HARD 4

using namespace System::Windows::Forms;
using namespace System::Drawing;


namespace VolgaNNGamer2011 {

	public ref class MenuForm : public System::Windows::Forms::Form {

	#pragma region Конструктор
	public:
	MenuForm(){
		InitializeComponent();
	}
	#pragma endregion

	#pragma region Деструктор
	protected:
	~MenuForm(){
		if (components){
			delete components;
		}
	}
	#pragma endregion


	#pragma region Глобальные переменные
	private:
		int T;
		cli::array <System::Windows::Forms::Control^ >^ ArrayOfControls;
	#pragma endregion
		
	#pragma region Объекты формы
		private: System::Windows::Forms::Label^ Label_NewGame;
		private: System::Windows::Forms::Label^ Label_LoadGame;
		private: System::Windows::Forms::Label^ Label_Options;
		private: System::Windows::Forms::Label^ Label_Produser;
		private: System::Windows::Forms::Label^ Label_Exit;
		private: Video^ VIDEO;

		private: System::Windows::Forms::Timer^  Timer_Emersion;
		private: System::ComponentModel::IContainer^  components;

	#pragma endregion


	#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->Timer_Emersion = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// Timer_Emersion
			// 
			this->Timer_Emersion->Interval = 75;
			this->Timer_Emersion->Tick += gcnew System::EventHandler(this, &MenuForm::Timer_Emersion_Tick);
			// 
			// MenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(994, 572);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MenuForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MenuForm";
			this->Load += gcnew System::EventHandler(this, &MenuForm::MenuForm_Load);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MenuForm::Exit);
			this->ResumeLayout(false);

		}
	#pragma endregion


	#pragma region Загрузка формы
	System::Void MenuForm_Load(System::Object^  sender, System::EventArgs^  e) {
		this->T = 0;

		PlayVideo();

		CreateButtonsOnMenu();
	}
	#pragma endregion

	#pragma region Создать кнопки Меню
	System::Void CreateButtonsOnMenu() {
		this->Label_NewGame  = gcnew LightingLabel(this, 10.0f, Point(12, 406), Point(250, 26), Color::Orange, true, true);
		this->Label_NewGame->Text  = "Новая игра";
		this->Label_NewGame->Click        += gcnew System::EventHandler(this, &MenuForm::Label_NewGame_Click);
		this->Label_NewGame->DoubleClick  += gcnew System::EventHandler(this, &MenuForm::Label_NewGame_Click);

		this->Label_LoadGame = gcnew LightingLabel(this, 10.0f, Point(12, 438), Point(250, 26), Color::Orange, true, true);
		this->Label_LoadGame->Text = "Загрузить игру";
		this->Label_LoadGame->Click       += gcnew System::EventHandler(this, &MenuForm::Label_LoadGame_Click);
		this->Label_LoadGame->DoubleClick += gcnew System::EventHandler(this, &MenuForm::Label_LoadGame_Click);

		this->Label_Options  = gcnew LightingLabel(this, 10.0f, Point(12, 470), Point(250, 26), Color::Orange, true, true);
		this->Label_Options->Text  = "Настройки";
		this->Label_Options->Click        += gcnew System::EventHandler(this, &MenuForm::Label_Options_Click);
		this->Label_Options->DoubleClick  += gcnew System::EventHandler(this, &MenuForm::Label_Options_Click);

		this->Label_Produser = gcnew LightingLabel(this, 10.0f, Point(12, 502), Point(250, 26), Color::Orange, true, true);
		this->Label_Produser->Text = "Производители";
		this->Label_Produser->Click       += gcnew System::EventHandler(this, &MenuForm::Label_Produser_Click);
		this->Label_Produser->DoubleClick += gcnew System::EventHandler(this, &MenuForm::Label_Produser_Click);

		this->Label_Exit     = gcnew LightingLabel(this, 10.0f, Point(12, 534), Point(250, 26), Color::Orange, true, true);
		this->Label_Exit->Text     = "Выход";
		this->Label_Exit->Click           += gcnew System::EventHandler(this, &MenuForm::Label_Exit_Click);
		this->Label_Exit->DoubleClick     += gcnew System::EventHandler(this, &MenuForm::Label_Exit_Click);
	}
	#pragma endregion


	#pragma region Проигрывать видео
	System::Void PlayVideo() {
		try{
			this->VIDEO = gcnew Video("..\\Data\\Video\\" + "Main Menu.avi");
			this->VIDEO->Ending += gcnew System::EventHandler(this, &MenuForm::VIDEO_Ending);
			this->VIDEO->Owner = this;
			this->VIDEO->Size = System::Drawing::Size(1000, 600);
			this->Size = System::Drawing::Size(1000, 600);
			this->VIDEO->Play();
		}catch(Exception^ ex){
			ex->ToString();
		}
	}
	#pragma endregion

	#pragma region Воспроизведение закончено - начать заново
	System::Void VIDEO_Ending(System::Object^  sender, System::EventArgs^  e) {
		try{
			this->VIDEO->CurrentPosition = 0;
			this->VIDEO->Play();
		}catch(Exception^ ex){
			ex->ToString();
		}
	}
	#pragma endregion


	#pragma region Нажата кнопка "Новая игра"
		#pragma region "Новая игра"
		System::Void MenuForm::Label_NewGame_Click(System::Object^  sender, System::EventArgs^  e) {
			if (this->T == 0){
				DeleteTheArrayOfControls();

				this->ArrayOfControls = gcnew cli::array <System::Windows::Forms::Control^ > (5);
				this->ArrayOfControls[0] = gcnew LightingLabel(this, 7.0f, Point(270, 406), Point(200, 20), Color::Green, false, true);
				this->ArrayOfControls[0]->Text = "Очень Легко";
				this->ArrayOfControls[0]->Click += gcnew System::EventHandler(this, &MenuForm::Label_NewGame_VeryEasy_Click);

				this->ArrayOfControls[1] = gcnew LightingLabel(this, 7.0f, Point(270, 430), Point(200, 20), Color::Lime, false, true);
				this->ArrayOfControls[1]->Text = "Легко";
				this->ArrayOfControls[1]->Click += gcnew System::EventHandler(this, &MenuForm::Label_NewGame_Easy_Click);

				this->ArrayOfControls[2] = gcnew LightingLabel(this, 7.0f, Point(270, 454), Point(200, 20), Color::Yellow, false, true);
				this->ArrayOfControls[2]->Text = "Нормально";
				this->ArrayOfControls[2]->Click += gcnew System::EventHandler(this, &MenuForm::Label_NewGame_Normal_Click);

				this->ArrayOfControls[3] = gcnew LightingLabel(this, 7.0f, Point(270, 478), Point(200, 20), Color::OrangeRed, false, true);
				this->ArrayOfControls[3]->Text = "Сложно";
				this->ArrayOfControls[3]->Click += gcnew System::EventHandler(this, &MenuForm::Label_NewGame_Hard_Click);

				this->ArrayOfControls[4] = gcnew LightingLabel(this, 7.0f, Point(270, 502), Point(200, 20), Color::Red, false, true);
				this->ArrayOfControls[4]->Text = "Очень Сложно";
				this->ArrayOfControls[4]->Click += gcnew System::EventHandler(this, &MenuForm::Label_NewGame_VeryHard_Click);

				this->Timer_Emersion->Start();
			}
		}
		#pragma endregion

		#pragma region "Новая игра" -> "Очень легко"
		System::Void MenuForm::Label_NewGame_VeryEasy_Click(System::Object^  sender, System::EventArgs^  e) {
			if (this->T == 0){
				DeleteTheArrayOfControls();

				GenerateDataBase( _VERY_EASY );

				this->Timer_Emersion->Start();
			}
		}
		#pragma endregion

		#pragma region "Новая игра" -> "Легко"
		System::Void MenuForm::Label_NewGame_Easy_Click(System::Object^  sender, System::EventArgs^  e) {
			if (this->T == 0){
				DeleteTheArrayOfControls();

				GenerateDataBase( _EASY );

				this->Timer_Emersion->Start();
			}
		}
		#pragma endregion

		#pragma region "Новая игра" -> "Нормально"
		System::Void MenuForm::Label_NewGame_Normal_Click(System::Object^  sender, System::EventArgs^  e) {
			if (this->T == 0){
				DeleteTheArrayOfControls();

				GenerateDataBase( _NORMAL );

				this->Timer_Emersion->Start();
			}
		}
		#pragma endregion

		#pragma region "Новая игра" -> "Сложно"
		System::Void MenuForm::Label_NewGame_Hard_Click(System::Object^  sender, System::EventArgs^  e) {
			if (this->T == 0){
				DeleteTheArrayOfControls();

				GenerateDataBase( _HARD );

				this->Timer_Emersion->Start();
			}
		}
		#pragma endregion

		#pragma region "Новая игра" -> "Очень сложно"
		System::Void MenuForm::Label_NewGame_VeryHard_Click(System::Object^  sender, System::EventArgs^  e) {
			if (this->T == 0){
				DeleteTheArrayOfControls();

				GenerateDataBase( _VERY_HARD );

				this->Timer_Emersion->Start();
			}
		}
		#pragma endregion
	#pragma endregion

	#pragma region Нажата кнопка "Загрузить игру"
		#pragma region "Загрузить игру"
		System::Void MenuForm::Label_LoadGame_Click(System::Object^  sender, System::EventArgs^  e) {
			if (this->T == 0){
				DeleteTheArrayOfControls();

				OpenFileDialog^ OFD = gcnew OpenFileDialog();
				OFD->Title = "Загрузить игру";
				OFD->Filter = "Файлы (*.accdb)|*.accdb";
				OFD->FilterIndex = 1;

				if (OFD->ShowDialog(this) == System::Windows::Forms::DialogResult::OK){
					try{
						LoadDataBase(OFD->FileName);

					}
					catch(Exception^ ex){
						MessageBox::Show( this, "Не удаётся считать данные с файла\n\n" + ex->ToString() , "Ошибка!",
											System::Windows::Forms::MessageBoxButtons::OK,
											System::Windows::Forms::MessageBoxIcon::Error );
					}
				}
			}
		}
		#pragma endregion
	#pragma endregion

	#pragma region Нажата кнопка "Настройки"
		#pragma region "Настройки"
		System::Void MenuForm::Label_Options_Click(System::Object^  sender, System::EventArgs^  e) {
			if (this->T == 0){
				DeleteTheArrayOfControls();

				//this->ArrayOfControls = gcnew cli::array <System::Windows::Forms::Control^ > (0);

				this->Timer_Emersion->Start();
			}
		}
		#pragma endregion
	#pragma endregion

	#pragma region Нажата кнопка "Производители"
		#pragma region "Производители"
		System::Void MenuForm::Label_Produser_Click(System::Object^  sender, System::EventArgs^  e) {
			if (this->T == 0){
				DeleteTheArrayOfControls();

				this->ArrayOfControls = gcnew cli::array <System::Windows::Forms::Control^ > (2);
				this->ArrayOfControls[0] = gcnew LightingLabel(this, 7.0f, Point(270, 406), Point(200, 20), SystemColors::Control, false, false);
				this->ArrayOfControls[0]->Text = "Новиков Егор";

				this->ArrayOfControls[1] = gcnew LightingLabel(this, 7.0f, Point(270, 430), Point(200, 20), SystemColors::Control, false, false);
				this->ArrayOfControls[1]->Text = "Курсаков Евгений";

				this->Timer_Emersion->Start();
			}
		}
		#pragma endregion
	#pragma endregion

	#pragma region Нажата кнопка "Выход"
		#pragma region "Выход"
		System::Void MenuForm::Label_Exit_Click(System::Object^  sender, System::EventArgs^  e) {
			if (this->T == 0){
				DeleteTheArrayOfControls();

				this->ArrayOfControls = gcnew cli::array <System::Windows::Forms::Control^ > (2);
				this->ArrayOfControls[0] = gcnew LightingLabel(this, 7.0f, Point(270, 406), Point(200, 20), Color::Red, false, true);
				this->ArrayOfControls[0]->Text = "Да";
				this->ArrayOfControls[0]->Click       += gcnew System::EventHandler(this, &MenuForm::Label_Exit_Yes_Click);
				this->ArrayOfControls[0]->DoubleClick += gcnew System::EventHandler(this, &MenuForm::Label_Exit_Yes_Click);

				this->ArrayOfControls[1] = gcnew LightingLabel(this, 7.0f, Point(270, 430), Point(200, 20), Color::Lime, false, true);
				this->ArrayOfControls[1]->Text = "Нет";
				this->ArrayOfControls[1]->Click       += gcnew System::EventHandler(this, &MenuForm::Label_Exit_No_Click);
				this->ArrayOfControls[1]->DoubleClick += gcnew System::EventHandler(this, &MenuForm::Label_Exit_No_Click);

				this->Timer_Emersion->Start();
			}
		}
		#pragma endregion

		#pragma region "Выход" -> "Да"
		System::Void MenuForm::Label_Exit_Yes_Click(System::Object^  sender, System::EventArgs^  e) {
			this->OnFormClosing(gcnew FormClosingEventArgs(System::Windows::Forms::CloseReason(), false));
		}
		#pragma endregion

		#pragma region "Выход" -> "Нет"
		System::Void MenuForm::Label_Exit_No_Click(System::Object^  sender, System::EventArgs^  e) {
			DeleteTheArrayOfControls();
		}
		#pragma endregion

	#pragma endregion


	#pragma region Удаляет элементы ArrayOfControls
	private:
	System::Void DeleteTheArrayOfControls() {
		if (this->ArrayOfControls){
			for (int I = 0; I < (this->ArrayOfControls->Length); I++){
				delete this->ArrayOfControls[I];
			}
		}
	}
	#pragma endregion

	#pragma region Тик секундомера Timer_Emersion
	private:
	System::Void Timer_Emersion_Tick(System::Object^  sender, System::EventArgs^  e) {
		if (this->ArrayOfControls){
			this->ArrayOfControls[this->T]->Visible = true;
			this->T++;
			if (this->ArrayOfControls->Length == this->T){
				this->T = 0;
				this->Timer_Emersion->Stop();
			}
		}
	}
	#pragma endregion


	#pragma region Создание базы данных
		#pragma region Генерировать новую базу данных
		private:
		System::Void GenerateDataBase(int DifficultLevel){

		}
		#pragma endregion

		#pragma region Загрузить базу данных
		private:
			System::Void LoadDataBase(System::String^ FileName){

		}
		#pragma endregion
	#pragma endregion


	#pragma region Закончить приложение
	private:
	System::Void MenuForm::Exit(System::Object^  sender, FormClosingEventArgs^ e){
		this->VIDEO->Stop();
		Application::Exit();
	}
	#pragma endregion

};
}
