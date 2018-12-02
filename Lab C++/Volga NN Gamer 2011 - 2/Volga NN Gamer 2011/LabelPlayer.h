#pragma once
#include <math.h>
#include "UnderliningLabel.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

#pragma region ref class LabelPlayer
ref class LabelPlayer : public UnderliningLabel
{

	#pragma region Поля класса
		public:
		Point^ Point_Of_Select;
		Label^ FlyingLabel;
		bool IsSelected;
		Label^ HelpLabel;
	#pragma endregion 

	#pragma region Конструктор
		public:
		LabelPlayer::LabelPlayer(Control^ ParentObject, unsigned int ID, int X_position, int Y_position,
									 Label^ FlyingLabel, System::String^ Text_of_label, Label^ HelpLabel)
									 : UnderliningLabel(ParentObject, ID, X_position, Y_position, Text_of_label){

			this->ParentObject = ParentObject;
			this->FlyingLabel = FlyingLabel;

			this->IsSelected = false;
			this->Point_Of_Select = gcnew System::Drawing::Point(0, 0);
			this->ID = ID;

			this->AutoSize = true;
			this->Location = System::Drawing::Point(X_position, Y_position);
			this->Text = Text_of_label;
			this->BackColor = System::Drawing::Color::Transparent;

			this->ParentObject->Controls->Add(this);

			this->HelpLabel = HelpLabel;

			this->MouseEnter += gcnew System::EventHandler(this, &LabelPlayer::Action_MouseEnter);
			this->MouseLeave += gcnew System::EventHandler(this, &LabelPlayer::Action_MouseLeave);
			this->MouseDown  += gcnew System::Windows::Forms::MouseEventHandler(this, &LabelPlayer::Action_MouseDown);
			this->MouseUp    += gcnew System::Windows::Forms::MouseEventHandler(this, &LabelPlayer::Action_MouseUp);
			this->Click		 += gcnew System::EventHandler(this, &LabelPlayer::Action_Click);
			this->MouseMove  += gcnew System::Windows::Forms::MouseEventHandler(this, &LabelPlayer::Action_MouseMove);
		}
	#pragma endregion 

	#pragma region Диструктор
		public:
		LabelPlayer::~LabelPlayer(void){
			delete this->MouseEnter;
			delete this->MouseLeave;
			delete this->MouseDown;
			delete this->MouseUp;
			delete this->Click;
			delete this->MouseMove;
		}
	#pragma endregion 

	#pragma region Вход мыши на лейбл - отобразить имя игрока в HelpLabel
		private:
		void LabelPlayer::Action_MouseEnter(System::Object^  sender, System::EventArgs^  e){
			this->HelpLabel->Text = this->Text + " Help!";	//Исправить!!!
		}
	#pragma endregion 

	#pragma region Выход мыши за пределы лейбла - очистить HelpLabel
		private:
		void LabelPlayer::Action_MouseLeave(System::Object^  sender, System::EventArgs^  e){
			this->HelpLabel->ResetText();
		}
	#pragma endregion 

	#pragma region Мышь нажата
		private:
		void LabelPlayer::Action_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e){
			IsSelected = true;
			FlyingLabel->Visible = true;
			FlyingLabel->Text = this->Text;
			this->Point_Of_Select = gcnew System::Drawing::Point(e->X, e->Y);
		}
	#pragma endregion 

	#pragma region Мышь отжата
		private:
		void LabelPlayer::Action_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e){
			IsSelected = false;
			FlyingLabel->Visible = false;
			this->Point_Of_Select = gcnew System::Drawing::Point(e->X + this->Location.X, e->Y + this->Location.Y);
			if (_hypot(this->Location.X - Point_Of_Select->X, this->Location.Y - Point_Of_Select->Y) < 75){
				this->Text = "Его номер - " + this->ID.ToString();
			}
		}
	#pragma endregion 

	#pragma region Действие: Клик мыши по объекту (Action_Click)
		private:
		void LabelPlayer::Action_Click(System::Object^  sender, System::EventArgs^  e){
			//this->IsSelected = true;
		}
	#pragma endregion 

	#pragma region Действие: Движение мыши по форме (Action_MouseMove)
		private:
		void LabelPlayer::Action_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e){
			if (IsSelected){
				FlyingLabel->Visible = true;
				FlyingLabel->SetBounds(e->X + this->Location.X - this->Point_Of_Select->X,
										e->Y + this->Location.Y - this->Point_Of_Select->Y,
										FlyingLabel->Width,
										FlyingLabel->Height);
			}
		}
	#pragma endregion 
};
#pragma endregion 

/*-------------------------------------------------------------------------------*/

#pragma region ref class SquadSys_PlayerInfo
ref class SquadSys_PlayerInfo
{
	#pragma region Поля класса
		public:
		Label^ NumberOfPlayer;
		LabelPlayer^ NameOfPayer;
	#pragma endregion 

	#pragma region Конструктор
		public:
		SquadSys_PlayerInfo::SquadSys_PlayerInfo(){

		}
	#pragma endregion 

	#pragma region Диструктор
		public:
		SquadSys_PlayerInfo::~SquadSys_PlayerInfo(){

		}
	#pragma endregion 

};
#pragma endregion 
