#pragma once
#include <math.h>

ref class Lighting_Label : public System::Windows::Forms::Label
{
public:

	#pragma region Поля класса
		System::Windows::Forms::Form^ ThisForm;
		System::Windows::Forms::Label^ Flying_label;
		System::Drawing::Point^ Point_of_select;
		unsigned int ID;
		bool IsSelected;
	#pragma endregion 

	#pragma region Конструктор
		Lighting_Label::Lighting_Label(System::Windows::Forms::Form^ ThisForm, unsigned int ID, int X_position, int Y_position,
			System::String^ Text_of_label, System::Windows::Forms::ContextMenuStrip^ R_Context){
			this->ThisForm = ThisForm;

			this->IsSelected = false;
			this->Point_of_select = gcnew System::Drawing::Point(0, 0);
			this->ID = ID;

			this->AutoSize = true;
			this->Location = System::Drawing::Point(X_position, Y_position);
			this->Text = Text_of_label;
			this->BackColor = System::Drawing::Color::Transparent;
			this->ContextMenuStrip = R_Context;
			ThisForm->Controls->Add(this);

			this->Flying_label = gcnew System::Windows::Forms::Label();
			this->Flying_label->AutoSize = true;
			this->Flying_label->Visible = false;
			this->Flying_label->Text = this->Text;
			this->Flying_label->BackColor = System::Drawing::Color::Transparent;
			this->Flying_label->TabIndex = 555;
			this->ThisForm->Controls->Add(Flying_label);

			this->MouseEnter += gcnew System::EventHandler(this, &Lighting_Label::Action_MouseEnter);
			this->MouseLeave += gcnew System::EventHandler(this, &Lighting_Label::Action_MouseLeave);
			this->MouseDown  += gcnew System::Windows::Forms::MouseEventHandler(this, &Lighting_Label::Action_MouseDown);
			this->MouseUp    += gcnew System::Windows::Forms::MouseEventHandler(this, &Lighting_Label::Action_MouseUp);
			this->Click		 += gcnew System::EventHandler(this, &Lighting_Label::Action_Click);
			this->MouseMove  += gcnew System::Windows::Forms::MouseEventHandler(this, &Lighting_Label::Action_MouseMove);
		}
	#pragma endregion 

	#pragma region Диструктор
		Lighting_Label::~Lighting_Label(void){
			delete this->MouseEnter;
			delete this->MouseLeave;
		}
	#pragma endregion 

	#pragma region Действие: Вход мыши на объект (Action_MouseEnter)
		void Lighting_Label::Action_MouseEnter(System::Object^  sender, System::EventArgs^  e){
			this->ForeColor = System::Drawing::Color::Orange;
		}
	#pragma endregion 

	#pragma region Действие: Выход мыши за пределы объекта (Action_MouseLeave)
		void Lighting_Label::Action_MouseLeave(System::Object^  sender, System::EventArgs^  e){
			this->ForeColor = System::Drawing::Color::Black;
		}
	#pragma endregion 

	#pragma region Действие: Мышь нажата (Action_MouseDown)
		void Lighting_Label::Action_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e){
			IsSelected = true;
			Flying_label->Visible = true;
			this->Point_of_select = gcnew System::Drawing::Point(e->X, e->Y);
			if (e->Button == System::Windows::Forms::MouseButtons::Left){
				this->ForeColor = System::Drawing::Color::Red;
			}
			if (e->Button == System::Windows::Forms::MouseButtons::Right){
				this->ForeColor = System::Drawing::Color::Green;
			}
		}
	#pragma endregion 

	#pragma region Действие: Мышь отжата (Action_MouseUp)
		void Lighting_Label::Action_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e){
			IsSelected = false;
			Flying_label->Visible = false;
			this->ForeColor = System::Drawing::Color::Orange;
			this->Point_of_select = gcnew System::Drawing::Point(e->X + this->Location.X, e->Y + this->Location.Y);
			if (hypot(this->Location.X - Point_of_select->X, this->Location.Y - Point_of_select->Y) < 75){
				this->Text = "Его номер - " + this->ID.ToString();
			}
		}
	#pragma endregion 

	#pragma region Действие: Клик мыши по объекту (Action_Click)
		void Lighting_Label::Action_Click(System::Object^  sender, System::EventArgs^  e){
			//this->IsSelected = true;
		}
	#pragma endregion 

	#pragma region Действие: Движение мыши по форме (Action_MouseMove)
		void Lighting_Label::Action_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e){
			if (IsSelected){
				Flying_label->Visible = true;
				Flying_label->SetBounds(e->X + this->Location.X - this->Point_of_select->X,
										e->Y + this->Location.Y - this->Point_of_select->Y,
										Flying_label->Width,
										Flying_label->Height);
			}
			ThisForm->Text = (System::Convert::ToInt32(ThisForm->Text) + 1).ToString();
		}
	#pragma endregion 
};
