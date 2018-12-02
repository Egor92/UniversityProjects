#pragma once
#include "LightingLabel.h"
#include "FileWork.h"
#include "LinesFormations.h"

#using "..\Bin\PresentationCore.dll"

#define _DEFENCE 0
#define _MIDDLEFIELD 1
#define _FORWARD 2
#define _SIZE 31
#define _HALF_SIZE (_SIZE + 1)/2

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

namespace VolgaNNGamer2011 {

	public ref class SelectTacticForm : public System::Windows::Forms::Form{

	#pragma region Конструктор
	public:
	SelectTacticForm(){
		InitializeComponent();
		Label_FormationOfForward = gcnew LightingLabel(this, 14.25f, Point(418, Label_CountOfForwards->Location.Y + 25) , Point(409, 28), Color::Orange, true, true);
		Label_FormationOfMiddlefield = gcnew LightingLabel(this, 14.25f, Point(418, Label_CountOfMiddlefieldes->Location.Y + 25), Point(409, 28), Color::Orange, true, true);
		Label_FormationOfDefence = gcnew LightingLabel(this, 14.25f, Point(418, Label_CountOfDefences->Location.Y + 25), Point(409, 28), Color::Orange, true, true);

	}
	#pragma endregion

	#pragma region Деструктор
	protected:
	~SelectTacticForm(){
		if (components){
			delete components;
		}
	}
	#pragma endregion


	#pragma region Глобальные переменные
	private:
	int CountOfTacticsFormation;
	cli::array<System::Windows::Media::Media3D::Point3D>^ AllTacticsFormation;
	int CurrentTacticsFormation;
	System::Windows::Media::Media3D::Point3D^ CurrentLinesFormation;
	cli::array<VNNG2011::LinesFormations^>^ DifferenceFormationsOfLines;
	System::Drawing::Graphics^ FieldGraphics;
	#pragma endregion

	#pragma region Объекты формы
		private: System::Windows::Forms::Label^ Label_FormationOfForward;
		private: System::Windows::Forms::Label^ Label_FormationOfMiddlefield;
		private: System::Windows::Forms::Label^ Label_FormationOfDefence;

		private: System::Windows::Forms::Button^  Button_PrevTactic;
		private: System::Windows::Forms::Button^  Button_NextTactic;
		private: System::Windows::Forms::Label^  Label_FormationTotal;
		private: System::Windows::Forms::Label^  Label_CountOfForwards;
		private: System::Windows::Forms::Label^  Label_CountOfMiddlefieldes;
		private: System::Windows::Forms::Label^  Label_CountOfDefences;
		private: System::ComponentModel::Container ^components;
		private: System::Windows::Forms::Panel^  Field;
		private: System::Windows::Forms::Button^  Button_SetAndExit;



	#pragma endregion

	#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->Button_PrevTactic = (gcnew System::Windows::Forms::Button());
			this->Button_NextTactic = (gcnew System::Windows::Forms::Button());
			this->Label_FormationTotal = (gcnew System::Windows::Forms::Label());
			this->Label_CountOfForwards = (gcnew System::Windows::Forms::Label());
			this->Label_CountOfMiddlefieldes = (gcnew System::Windows::Forms::Label());
			this->Label_CountOfDefences = (gcnew System::Windows::Forms::Label());
			this->Button_SetAndExit = (gcnew System::Windows::Forms::Button());
			this->Field = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// Button_PrevTactic
			// 
			this->Button_PrevTactic->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->Button_PrevTactic->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Button_PrevTactic->Location = System::Drawing::Point(330, 12);
			this->Button_PrevTactic->Name = L"Button_PrevTactic";
			this->Button_PrevTactic->Size = System::Drawing::Size(75, 75);
			this->Button_PrevTactic->TabIndex = 1;
			this->Button_PrevTactic->UseVisualStyleBackColor = true;
			this->Button_PrevTactic->Click += gcnew System::EventHandler(this, &SelectTacticForm::Button_PrevTactic_Click);
			// 
			// Button_NextTactic
			// 
			this->Button_NextTactic->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->Button_NextTactic->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Button_NextTactic->Location = System::Drawing::Point(752, 12);
			this->Button_NextTactic->Name = L"Button_NextTactic";
			this->Button_NextTactic->Size = System::Drawing::Size(75, 75);
			this->Button_NextTactic->TabIndex = 2;
			this->Button_NextTactic->UseVisualStyleBackColor = true;
			this->Button_NextTactic->Click += gcnew System::EventHandler(this, &SelectTacticForm::Button_NextTactic_Click);
			// 
			// Label_FormationTotal
			// 
			this->Label_FormationTotal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->Label_FormationTotal->Location = System::Drawing::Point(411, 29);
			this->Label_FormationTotal->Name = L"Label_FormationTotal";
			this->Label_FormationTotal->Size = System::Drawing::Size(335, 40);
			this->Label_FormationTotal->TabIndex = 3;
			this->Label_FormationTotal->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Label_CountOfForwards
			// 
			this->Label_CountOfForwards->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->Label_CountOfForwards->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->Label_CountOfForwards->Location = System::Drawing::Point(330, 102);
			this->Label_CountOfForwards->Name = L"Label_CountOfForwards";
			this->Label_CountOfForwards->Size = System::Drawing::Size(75, 75);
			this->Label_CountOfForwards->TabIndex = 4;
			this->Label_CountOfForwards->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Label_CountOfMiddlefieldes
			// 
			this->Label_CountOfMiddlefieldes->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->Label_CountOfMiddlefieldes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->Label_CountOfMiddlefieldes->Location = System::Drawing::Point(330, 190);
			this->Label_CountOfMiddlefieldes->Name = L"Label_CountOfMiddlefieldes";
			this->Label_CountOfMiddlefieldes->Size = System::Drawing::Size(75, 75);
			this->Label_CountOfMiddlefieldes->TabIndex = 5;
			this->Label_CountOfMiddlefieldes->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Label_CountOfDefences
			// 
			this->Label_CountOfDefences->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->Label_CountOfDefences->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->Label_CountOfDefences->Location = System::Drawing::Point(330, 278);
			this->Label_CountOfDefences->Name = L"Label_CountOfDefences";
			this->Label_CountOfDefences->Size = System::Drawing::Size(75, 75);
			this->Label_CountOfDefences->TabIndex = 6;
			this->Label_CountOfDefences->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Button_SetAndExit
			// 
			this->Button_SetAndExit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->Button_SetAndExit->Location = System::Drawing::Point(330, 366);
			this->Button_SetAndExit->Name = L"Button_SetAndExit";
			this->Button_SetAndExit->Size = System::Drawing::Size(497, 45);
			this->Button_SetAndExit->TabIndex = 8;
			this->Button_SetAndExit->Text = L"Установить";
			this->Button_SetAndExit->UseVisualStyleBackColor = true;
			// 
			// Field
			// 
			this->Field->Location = System::Drawing::Point(12, 12);
			this->Field->Name = L"Field";
			this->Field->Size = System::Drawing::Size(307, 399);
			this->Field->TabIndex = 9;
			this->Field->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &SelectTacticForm::Field_Paint);
			// 
			// SelectTacticForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(839, 423);
			this->Controls->Add(this->Field);
			this->Controls->Add(this->Button_SetAndExit);
			this->Controls->Add(this->Label_CountOfDefences);
			this->Controls->Add(this->Label_CountOfMiddlefieldes);
			this->Controls->Add(this->Label_CountOfForwards);
			this->Controls->Add(this->Label_FormationTotal);
			this->Controls->Add(this->Button_NextTactic);
			this->Controls->Add(this->Button_PrevTactic);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"SelectTacticForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"SelectTacticForm";
			this->Load += gcnew System::EventHandler(this, &SelectTacticForm::SelectTacticForm_Load);
			this->ResumeLayout(false);

		}
	#pragma endregion


	#pragma region Загрузка формы
	private:
	System::Void SelectTacticForm_Load(System::Object^  sender, System::EventArgs^  e) {
		try{
			this->Button_PrevTactic->BackgroundImage = gcnew System::Drawing::Bitmap("..//Data//Pictures//Arrow Left.png");
		}catch(Exception^ ex){ ex->ToString(); }
		try{
			this->Button_NextTactic->BackgroundImage = gcnew System::Drawing::Bitmap("..//Data//Pictures//Arrow Right.png");
		}catch(Exception^ ex){ ex->ToString(); }

		InitializeTotalFormations();
		InitializeFormationsOfLines();

		this->Label_FormationOfForward->Click += gcnew System::EventHandler(this, &SelectTacticForm::NextFormationOfForward);
		this->Label_FormationOfMiddlefield->Click += gcnew System::EventHandler(this, &SelectTacticForm::NextFormationOfMiddlefield);
		this->Label_FormationOfDefence->Click += gcnew System::EventHandler(this, &SelectTacticForm::NextFormationOfDefence);
		this->Label_FormationOfForward->DoubleClick += gcnew System::EventHandler(this, &SelectTacticForm::NextFormationOfForward);
		this->Label_FormationOfMiddlefield->DoubleClick += gcnew System::EventHandler(this, &SelectTacticForm::NextFormationOfMiddlefield);
		this->Label_FormationOfDefence->DoubleClick += gcnew System::EventHandler(this, &SelectTacticForm::NextFormationOfDefence);

		{	/********* Изменить! ********/
			CurrentTacticsFormation = 0;
			CurrentLinesFormation = gcnew System::Windows::Media::Media3D::Point3D(0, 0, 0);
		}	/****************************/

		//this->Field->OnPaint(gcnew System::Windows::Forms::PaintEventArgs(this->FieldGraphics, gcnew System::Drawing::Rectangle(0,0,0,0)));
		DisplayOptionsForCurrentTacticalFormation();

		DisplayRoundsOnField();
	}
	#pragma endregion


	#pragma region Рисовать графику на поле
	private:
	System::Void Field_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		FieldGraphics = e->Graphics;
		DisplayRoundsOnField();
	}
	#pragma endregion


	#pragma region Отобразить параметры для текущей тактической схемы
	private:
	System::Void DisplayOptionsForCurrentTacticalFormation() {
		this->Label_CountOfForwards->Text = (AllTacticsFormation[CurrentTacticsFormation].Z).ToString();
		this->Label_CountOfMiddlefieldes->Text = (AllTacticsFormation[CurrentTacticsFormation].Y).ToString();
		this->Label_CountOfDefences->Text = (AllTacticsFormation[CurrentTacticsFormation].X).ToString();

		this->Label_FormationTotal->Text = "<< " + 
									 AllTacticsFormation[CurrentTacticsFormation].X.ToString() + 
									 " - " +
									 AllTacticsFormation[CurrentTacticsFormation].Y.ToString() + 
									 " - " +
									 AllTacticsFormation[CurrentTacticsFormation].Z.ToString() + 
									 " >>";

		this->Label_FormationOfForward->Text = 
			this->DifferenceFormationsOfLines[_FORWARD][CountOfPlayersOnLine(_FORWARD)][cli::safe_cast<int>(CurrentLinesFormation->Z)]->Text;
		this->Label_FormationOfMiddlefield->Text =
			this->DifferenceFormationsOfLines[_MIDDLEFIELD][CountOfPlayersOnLine(_MIDDLEFIELD)][cli::safe_cast<int>(CurrentLinesFormation->Y)]->Text;
		this->Label_FormationOfDefence->Text = 
			this->DifferenceFormationsOfLines[_DEFENCE][CountOfPlayersOnLine(_DEFENCE)][cli::safe_cast<int>(CurrentLinesFormation->X)]->Text;

	}
	#pragma endregion

	#pragma region Отобразить поле и футболки, символизирующие расположение игроков на поле
		#pragma region Отобразить поле и футболки, символизирующие расположение игроков, на поле
		private:
		System::Void DisplayRoundsOnField() {
			this->FieldGraphics = this->Field->CreateGraphics();

			DisplayField();

			DisplayGoalkeeper();

			DisplayFieldPlayers();
		}
		#pragma endregion

		#pragma region Отобразить поле
		private:
		System::Void DisplayField() {
			this->FieldGraphics->DrawImage( gcnew System::Drawing::Bitmap("..//Data//Pictures//Field.GIF"), 0 , 0, this->Field->Width, this->Field->Height );
		}
		#pragma endregion

		#pragma region Отобразить вратаря
		private:
		System::Void DisplayGoalkeeper() {
			this->FieldGraphics->DrawImage( gcnew System::Drawing::Bitmap("..//Data//Graphics//Kits//Volga NN - 1.PNG"), 138, 321, 31, 31 );
		}
		#pragma endregion

		#pragma region Отобразить полевых игроков
		private:
		System::Void DisplayFieldPlayers() {
			for (int Line = 0; Line < 3; Line++){
				for (int Player=0; Player < (CountOfPlayersOnLine(Line) + 1); Player++){
					this->FieldGraphics->DrawImage( gcnew System::Drawing::Bitmap("..//Data//Graphics//Kits//Volga NN - 1.PNG"),
														this->DifferenceFormationsOfLines[Line]
															[CountOfPlayersOnLine(Line)]
															[GetCurrentLinesFormation(Line)]
															->Positions[Player]->X - _HALF_SIZE,
														this->DifferenceFormationsOfLines[Line]
															[CountOfPlayersOnLine(Line)]
															[GetCurrentLinesFormation(Line)]
															->Positions[Player]->Y - _HALF_SIZE,
														_SIZE, _SIZE );

					//this->FieldGraphics->DrawString("54",
					//								gcnew System::Drawing::Font(L"Microsoft Sans Serif",
					//															11,
					//															System::Drawing::FontStyle::Bold,
					//															System::Drawing::GraphicsUnit::Point),
					//								gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black),
					//									this->DifferenceFormationsOfLines[Line]
					//										[CountOfPlayersOnLine(Line)]
					//										[GetCurrentLinesFormation(Line)]
					//										->Positions[Player]->X - _HALF_SIZE,
					//									this->DifferenceFormationsOfLines[Line]
					//										[CountOfPlayersOnLine(Line)]
					//										[GetCurrentLinesFormation(Line)]
					//										->Positions[Player]->Y - _HALF_SIZE );
				}
			}
		}
		#pragma endregion
	#pragma endregion

	#pragma region Проинициализировать расстановки каждой из линий
		private:
		System::Void InitializeFormationsOfLines(){
			Egor::FileWork::FileReader* linesFormationRead = new Egor::FileWork::FileReader("..//Data//Original DataBase//Tactics//Tactics formation of lines.DAT");
			this->DifferenceFormationsOfLines = gcnew cli::array<VNNG2011::LinesFormations^> (3);
			this->DifferenceFormationsOfLines[_DEFENCE] = gcnew VNNG2011::LinesFormations();
			this->DifferenceFormationsOfLines[_MIDDLEFIELD] = gcnew VNNG2011::LinesFormations();
			this->DifferenceFormationsOfLines[_FORWARD] = gcnew VNNG2011::LinesFormations();

			if (linesFormationRead->IsOpenedSuccessfully()){
				for (int Line = 0; Line < 3; Line++){
					for (int CountOfPlayers = 0; CountOfPlayers < 5; CountOfPlayers++){
						int I1 = linesFormationRead->ReadInteger();	//Количество расстановок для данного количества игроков
						this->DifferenceFormationsOfLines[Line]->Formations[CountOfPlayers] = gcnew VNNG2011::LineFormations(I1);
						for (int NumOfFormation = 0; NumOfFormation < I1; NumOfFormation++){
							this->DifferenceFormationsOfLines[Line]->Formations[CountOfPlayers]->Formations[NumOfFormation] = gcnew VNNG2011::LineFormation(linesFormationRead->ReadString(),
																															CountOfPlayers + 1 );
							for (int NumOfPlayer = 0; NumOfPlayer < (CountOfPlayers + 1); NumOfPlayer++){
								this->DifferenceFormationsOfLines[Line][CountOfPlayers][NumOfFormation]->InitPlayerPosition(NumOfPlayer,
																											  linesFormationRead->ReadInteger() ,
																											  linesFormationRead->ReadInteger() );
							}
						}
					}
				}

			}else{
				System::Windows::Forms::Application::Exit();
			}
		}
	#pragma endregion

	#pragma region Проинициализировать общие расстановки
		private:
		System::Void InitializeTotalFormations(){
			Egor::FileWork::FileReader* tacticRead = new Egor::FileWork::FileReader("..//Data//Original DataBase//Tactics//Tactics total.DAT");
			CountOfTacticsFormation = tacticRead->ReadInteger();
			AllTacticsFormation = gcnew cli::array<System::Windows::Media::Media3D::Point3D> (CountOfTacticsFormation);
			if (tacticRead->IsOpenedSuccessfully()){
				for (int I=0; I < CountOfTacticsFormation; I++){
					AllTacticsFormation[I].X = tacticRead->ReadInteger() ;
					AllTacticsFormation[I].Y = tacticRead->ReadInteger() ;
					AllTacticsFormation[I].Z = tacticRead->ReadInteger() ;
				}
			}else{
				System::Windows::Forms::Application::Exit();
			}
		}
	#pragma endregion

	#pragma region Возвращает номер текущей расстаноки линии
	private:
	System::Int32 GetCurrentLinesFormation(int Line) {
		switch (Line){
			case _DEFENCE:
				return cli::safe_cast<int> (this->CurrentLinesFormation->X);
			case _MIDDLEFIELD:
				return cli::safe_cast<int> (this->CurrentLinesFormation->Y);
			case _FORWARD:
				return cli::safe_cast<int> (this->CurrentLinesFormation->Z);
			default:
				return (-1);
		}
	}
	#pragma endregion

	#pragma region Возвращает количество игроков на позиции
		private:
		System::Int32 CountOfPlayersOnLine(int Line){
			switch (Line){
				case _DEFENCE:
					return cli::safe_cast<int> (this->AllTacticsFormation[this->CurrentTacticsFormation].X - 1);
				case _MIDDLEFIELD:
					return cli::safe_cast<int>(this->AllTacticsFormation[this->CurrentTacticsFormation].Y - 1);
				case _FORWARD:
					return cli::safe_cast<int>(this->AllTacticsFormation[this->CurrentTacticsFormation].Z - 1);
				default:
					return (-1);
			}

		}
	#pragma endregion


	#pragma region Предыдущая тактика
		private:
		System::Void Button_PrevTactic_Click(System::Object^  sender, System::EventArgs^  e) {
			CurrentTacticsFormation = (CurrentTacticsFormation + CountOfTacticsFormation - 1) % CountOfTacticsFormation;
			CurrentLinesFormation = gcnew System::Windows::Media::Media3D::Point3D(0, 0, 0);
			DisplayOptionsForCurrentTacticalFormation();
			DisplayRoundsOnField();
		}
	#pragma endregion

	#pragma region Следующая тактика
		private:
		System::Void Button_NextTactic_Click(System::Object^  sender, System::EventArgs^  e) {
			CurrentTacticsFormation = ( ++CurrentTacticsFormation ) % CountOfTacticsFormation;
			CurrentLinesFormation = gcnew System::Windows::Media::Media3D::Point3D(0, 0, 0);
			DisplayOptionsForCurrentTacticalFormation();
			DisplayRoundsOnField();
		}
	#pragma endregion


	#pragma region Следующая расстановка нападения
	private:
	System::Void NextFormationOfForward(System::Object^  sender, System::EventArgs^  e) {
		if (this->DifferenceFormationsOfLines[_FORWARD][CountOfPlayersOnLine(_FORWARD)]->CountOfLineFormations != 0){
			CurrentLinesFormation->Z = cli::safe_cast <int> (CurrentLinesFormation->Z + 1) %
												this->DifferenceFormationsOfLines[_FORWARD][CountOfPlayersOnLine(_FORWARD)]->CountOfLineFormations;
		}
		DisplayOptionsForCurrentTacticalFormation();

		this->FieldGraphics = this->Field->CreateGraphics();
		DisplayRoundsOnField();
	}
	#pragma endregion

	#pragma region Следующая расстановка полузащиты
	private:
	System::Void NextFormationOfMiddlefield(System::Object^  sender, System::EventArgs^  e) {
		if (this->DifferenceFormationsOfLines[_MIDDLEFIELD][CountOfPlayersOnLine(_MIDDLEFIELD)]->CountOfLineFormations != 0){
			CurrentLinesFormation->Y = cli::safe_cast <int> (CurrentLinesFormation->Y + 1) %
												this->DifferenceFormationsOfLines[_MIDDLEFIELD][CountOfPlayersOnLine(_MIDDLEFIELD)]->CountOfLineFormations;
		}
		DisplayOptionsForCurrentTacticalFormation();

		this->FieldGraphics = this->Field->CreateGraphics();
		DisplayRoundsOnField();
	}
	#pragma endregion

	#pragma region Следующая расстановка защиты
	private:
	System::Void NextFormationOfDefence(System::Object^  sender, System::EventArgs^  e) {
		if (this->DifferenceFormationsOfLines[_DEFENCE][CountOfPlayersOnLine(_DEFENCE)]->CountOfLineFormations != 0){
			CurrentLinesFormation->X = cli::safe_cast <int> (CurrentLinesFormation->X + 1) %
												this->DifferenceFormationsOfLines[_DEFENCE][CountOfPlayersOnLine(_DEFENCE)]->CountOfLineFormations;
		}
		DisplayOptionsForCurrentTacticalFormation();

		this->FieldGraphics = this->Field->CreateGraphics();
		DisplayRoundsOnField();
	}
	#pragma endregion



};
}
