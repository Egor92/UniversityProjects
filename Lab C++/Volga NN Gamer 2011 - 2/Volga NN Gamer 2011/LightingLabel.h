#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

namespace System{

	namespace Windows{

		namespace Forms{

			#pragma region LightingLabel
			ref class LightingLabel : public System::Windows::Forms::Label
			{

				#pragma region Поля
				public:
					Color BackColorOnClick;
					bool ToHideText;
				#pragma endregion

				#pragma region Конструктор
				public:
				LightingLabel::LightingLabel(Control^ ParentObject, float SizeOfText, Point LocationOfLabel, Point SizeOfLabel, Color BackColorOnClick, bool VisibleAtStart, bool ToHideText){
					this->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
					this->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", SizeOfText, System::Drawing::FontStyle::Bold);
					this->Location = LocationOfLabel;
					this->Size = System::Drawing::Size(SizeOfLabel);
					this->ForeColor = Color::Black;
					this->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
					this->Visible = VisibleAtStart;

					this->Parent = ParentObject;
					this->Parent->Controls->Add(this);
					this->BackColorOnClick = BackColorOnClick;
					this->ToHideText = ToHideText;

					this->MouseEnter += gcnew System::EventHandler(this, &LightingLabel::Action_MouseEnter);
					this->MouseLeave += gcnew System::EventHandler(this, &LightingLabel::Action_MouseLeave);
					this->MouseDown  += gcnew System::Windows::Forms::MouseEventHandler(this, &LightingLabel::Action_MouseDown);
					this->MouseUp    += gcnew System::Windows::Forms::MouseEventHandler(this, &LightingLabel::Action_MouseUp);
				}
				#pragma endregion

				#pragma region Деструктор
				protected:
				LightingLabel::~LightingLabel(){

				}
				#pragma endregion

				#pragma region Мышь отжата - отобразить текст
				public:
					void LightingLabel::SetText(System::String^ TheText){
					this->Text = TheText;
				}
				#pragma endregion 

				#pragma region Вход мыши на лейбл - закрасить оранжевым фон лейбла
				void LightingLabel::Action_MouseEnter(System::Object^  sender, System::EventArgs^  e){
					this->BackColor = this->BackColorOnClick;
				}
				#pragma endregion 

				#pragma region Выход мыши за пределы лейбла - закрасить серым фон лейбла
				void LightingLabel::Action_MouseLeave(System::Object^  sender, System::EventArgs^  e){
					this->BackColor = SystemColors::Control;
				}
				#pragma endregion 

				#pragma region Мышь нажата - скрыть текст
				void LightingLabel::Action_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e){
					if (this->ToHideText && e->Button == System::Windows::Forms::MouseButtons::Left){
						this->ForeColor = this->BackColor;
					}
				}
				#pragma endregion 

				#pragma region Мышь отжата - отобразить текст
				void LightingLabel::Action_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e){
					this->ForeColor = Color::Black;
				}
				#pragma endregion 

			};
			#pragma endregion 

		}
	}
}