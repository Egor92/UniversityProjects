#pragma once
#include "player.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

ref class PlayerOnField{

	#pragma region Поля класса
		public:
		Control^ ParentObject;
		unsigned int ID;
		Point^ Position;
		Label^ Number;
		Label^ Name;
		Player^ ThisPlayer;
	#pragma endregion 

	#pragma region Конструктор
		PlayerOnField(Control^ ParentObject, unsigned int ID, Point^ Position, Player^ ThisPlayer){
			this->ParentObject = ParentObject;
			this->ID = ID;
			this->Position = Position;
			this->Number = gcnew Label();
			this->Number->Text = ThisPlayer->Number.ToString();
			this->Name = gcnew Label();
			this->Name->Text = ThisPlayer->Name;
		}
	#pragma endregion 
};
