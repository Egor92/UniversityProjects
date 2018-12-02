#pragma once
#include <math.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

ref class UnderliningLabel : public System::Windows::Forms::Label
{
public:

	#pragma region Поля класса
		Control^ ParentObject;
		unsigned int ID;
	#pragma endregion 

	#pragma region Конструктор
		UnderliningLabel::UnderliningLabel(Control^ ParentObject, unsigned int ID, int X_position, int Y_position,
									 System::String^ Text_of_label){

			this->ParentObject = ParentObject;
			this->ID = ID;

			this->AutoSize = true;
			this->Location = System::Drawing::Point(X_position, Y_position);
			this->Text = Text_of_label;
			this->BackColor = System::Drawing::Color::Transparent;
			ParentObject->Controls->Add(this);

			this->MouseEnter += gcnew System::EventHandler(this, &UnderliningLabel::Action_MouseEnter);
			this->MouseLeave += gcnew System::EventHandler(this, &UnderliningLabel::Action_MouseLeave);
			this->MouseDown  += gcnew System::Windows::Forms::MouseEventHandler(this, &UnderliningLabel::Action_MouseDown);
			this->MouseUp    += gcnew System::Windows::Forms::MouseEventHandler(this, &UnderliningLabel::Action_MouseUp);
		}
	#pragma endregion 

	#pragma region Диструктор
		UnderliningLabel::~UnderliningLabel(void){
			delete this->MouseEnter;
			delete this->MouseLeave;
			delete this->MouseDown;
			delete this->MouseUp;
		}
	#pragma endregion 

	#pragma region Вход мыши на лейбл - подчеркнуть
		void UnderliningLabel::Action_MouseEnter(System::Object^  sender, System::EventArgs^  e){
			this->Font = gcnew System::Drawing::Font(this->Font->FontFamily, this->Font->Size, System::Drawing::FontStyle::Underline);
		}
	#pragma endregion 

	#pragma region Выход мыши за пределы лейбла - убрать подчёркивание
		void UnderliningLabel::Action_MouseLeave(System::Object^  sender, System::EventArgs^  e){
			this->Font = gcnew System::Drawing::Font(this->Font->FontFamily, this->Font->Size);
		}
	#pragma endregion 

	#pragma region Мышь нажата
		void UnderliningLabel::Action_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e){
			if (e->Button == System::Windows::Forms::MouseButtons::Left){
				this->ForeColor = Color::Red;
			}
		}
	#pragma endregion 

	#pragma region Мышь отжата
		void UnderliningLabel::Action_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e){
			this->ForeColor = Color::Black;
		}
	#pragma endregion 

	#pragma region Мышь отжата
		void UnderliningLabel::Action_Click(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e){
			this->ForeColor = Color::Black;
		}
	#pragma endregion 
		
};
