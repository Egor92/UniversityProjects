#pragma once
#include "LabelPlayer.h"
#include "PlayerOnField.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

ref class ClassOf_SquadSystem
{
	#pragma region Поля класса
		public:
		Control^ ParentObject;
		int Count_Of_Players;
		cli::array<LabelPlayer^>^ Array_Of_LabelPlayer;
		Label^ FlyingLabel;
		Label^ HelpLabel;
	#pragma endregion 



	#pragma region Конструктор
		public:
		ClassOf_SquadSystem::ClassOf_SquadSystem(Control^ ParentObject, unsigned int Count_Of_Players, Label^ FlyingLabel, Label^ HelpLabel){

			this->HelpLabel = HelpLabel;

			this->ParentObject = ParentObject;
			this->Count_Of_Players = Count_Of_Players;
			Initialize_Array_Of_LabelForStaff();
			Initialize_FlyingLabel(FlyingLabel);
			Set_FlyingLabel_For_Every_Object_From_Array_Of_LabelForStaff(FlyingLabel);
			Add_All_Objects_To_Form(ParentObject);

		}
	#pragma endregion 

	#pragma region Диструктор
		public:
		ClassOf_SquadSystem::~ClassOf_SquadSystem(){

		}
	#pragma endregion 



	#pragma region Инициализация Array_Of_LabelPlayer
		private:
		void Initialize_Array_Of_LabelForStaff(){
			this->Array_Of_LabelPlayer = gcnew cli::array<LabelPlayer^> (this->Count_Of_Players);
			for (int I=0; I<this->Count_Of_Players; I++){
				this->Array_Of_LabelPlayer[I] = gcnew LabelPlayer(this->ParentObject, I, 20,  20 + 20*I,
																		this->FlyingLabel, "Label #" + I.ToString(), this->HelpLabel);
			}
		}
	#pragma endregion 

	#pragma region Установить значение FlyingLabel для каждого объекта из Array_Of_LabelPlayer
		private:
		void Set_FlyingLabel_For_Every_Object_From_Array_Of_LabelForStaff(Label^ FlyingLabel){
			for (int I=0; I<this->Count_Of_Players; I++){
				this->Array_Of_LabelPlayer[I]->FlyingLabel = this->FlyingLabel;
			}
		}
	#pragma endregion 

	#pragma region Инициализация FlyingLabel
		private:
		void Initialize_FlyingLabel(Label^ FlyingLabel){
			this->FlyingLabel = FlyingLabel;
			this->FlyingLabel->AutoSize = true;
			this->FlyingLabel->BackColor = System::Drawing::Color::AliceBlue;
			this->FlyingLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->FlyingLabel->Visible = false;
			this->FlyingLabel->Text = L"label1";
		}
	#pragma endregion 

	#pragma region Добавление всех объектов на форму
		private:
		void Add_All_Objects_To_Form(Control^ ParentObject){
			this->ParentObject->Controls->Add(this->FlyingLabel);
			for (int I=0; I<this->Count_Of_Players; I++){
				this->ParentObject->Controls->Add(this->Array_Of_LabelPlayer[I]);
			}
		}
	#pragma endregion 
};
