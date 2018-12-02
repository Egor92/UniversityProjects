// Volga NN Gamer 2011.cpp: главный файл проекта.

#include "stdafx.h"
#include "VideoForm.h"
#include "MenuForm.h"
#include "SquadForm.h"
#include "SelectTacticForm.h"

using namespace VolgaNNGamer2011;
using namespace System::Windows::Forms;
using namespace System::Drawing;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Включение визуальных эффектов Windows XP до создания каких-либо элементов управления
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Создание главного окна и его запуск
	Application::Run(gcnew VideoForm("Intro.wmv"));
	Application::Run(gcnew MenuForm());

	FormWithResult^ NextForm = gcnew SquadForm();
	while(true){
		Application::Run(NextForm);
		switch (NextForm->GetResultCode()){
			case 0:
				Application::Exit();
				break;
			case 1:
				NextForm = gcnew SquadForm();
				break;
			case 2:
				//NextForm = gcnew OfficeForm();
				break;
			default:
				System::Windows::Forms::MessageBox::Show("Накосячил. default-значение NextForm (" + NextForm->GetResultCode().ToString() + ")", "Ошибка!");
		}
	}

	return 0;
}
