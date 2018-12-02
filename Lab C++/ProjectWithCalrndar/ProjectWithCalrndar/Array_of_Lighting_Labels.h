#pragma once
#include "Lighting_Label.h"

ref class Array_of_Lighting_Labels
{
public:
	System::Windows::Forms::Form^ ThisForm;
	cli::array<Lighting_Label^>^ Array;
	unsigned int Number_of_selected_label;

	Array_of_Lighting_Labels::Array_of_Lighting_Labels(System::Windows::Forms::Form^ ThisForm,
										int Count, System::Windows::Forms::ContextMenuStrip^ R_Context)
	{
		this->ThisForm = ThisForm;

		Array = gcnew cli::array<Lighting_Label^> (Count);
		for (int I=0; I<Count; I++){
			Array[I] = gcnew Lighting_Label(ThisForm, I, 900, 50 + I*20, "Это Лейбел номер " + I.ToString(), R_Context);
		}

		Number_of_selected_label = -1;
	}

	Array_of_Lighting_Labels::~Array_of_Lighting_Labels(void){
		delete Array;
	}
};
