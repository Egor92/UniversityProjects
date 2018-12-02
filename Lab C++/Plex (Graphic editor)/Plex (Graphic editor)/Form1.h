#pragma once
#include "stdafx.h"
#include <stddef.h>
#include "math.h"
#include "Фигуры.h"
#include "Функции (для плекса).h"

namespace PlexGraphiceditor {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form1
	///
	/// Внимание! При изменении имени этого класса необходимо также изменить
	///          свойство имени файла ресурсов ("Resource File Name") для средства компиляции управляемого ресурса,
	///          связанного со всеми файлами с расширением .resx, от которых зависит данный класс. В противном случае,
	///          конструкторы не смогут правильно работать с локализованными
	///          ресурсами, сопоставленными данной форме.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Panel^  GraphicPanelPicture;
	protected: 

	protected: 

	protected: 

	protected: 
	private: System::Windows::Forms::Button^  ButtonExit;
	private: System::Windows::Forms::Label^  LabelHelp;
	private: System::Windows::Forms::Label^  LabelNewTPoint;
	private: System::Windows::Forms::Label^  LabelNewTLine;
	private: System::Windows::Forms::Label^  LabelNewTRect;
	private: System::Windows::Forms::Label^  LabelNewTCircle;
	private: System::Windows::Forms::Button^  CreateNewObject;
	private: System::Windows::Forms::Label^  PointFirstLabelTPoint;
	private: System::Windows::Forms::TextBox^  TextTPointY;
	private: System::Windows::Forms::Label^  PointSecondLabelTPoint;
	private: System::Windows::Forms::TextBox^  TextTPointX;
	private: System::Windows::Forms::CheckBox^  ObjectIsNotVisible;
	private: System::Windows::Forms::Panel^  BoxNewTLine;
	private: System::Windows::Forms::Label^  Label;
	private: System::Windows::Forms::Panel^  BoxNewTPoint;
	private: System::Windows::Forms::TextBox^  PointFirstName;
	private: System::Windows::Forms::TextBox^  PointSecondName;
	private: System::Windows::Forms::Label^  PointFirstLabelTLine;
	private: System::Windows::Forms::Label^  PointSecondLabelTLine;
	private: System::Windows::Forms::Label^  LabelShowName;
	private: System::Windows::Forms::Label^  LabelInstruction;
	private: System::Windows::Forms::Button^  DeleteTheObject;

	protected: 
	protected: 
	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->GraphicPanelPicture = (gcnew System::Windows::Forms::Panel());
			this->LabelShowName = (gcnew System::Windows::Forms::Label());
			this->ButtonExit = (gcnew System::Windows::Forms::Button());
			this->LabelHelp = (gcnew System::Windows::Forms::Label());
			this->LabelNewTPoint = (gcnew System::Windows::Forms::Label());
			this->ObjectIsNotVisible = (gcnew System::Windows::Forms::CheckBox());
			this->TextTPointY = (gcnew System::Windows::Forms::TextBox());
			this->PointSecondLabelTPoint = (gcnew System::Windows::Forms::Label());
			this->TextTPointX = (gcnew System::Windows::Forms::TextBox());
			this->PointFirstLabelTPoint = (gcnew System::Windows::Forms::Label());
			this->LabelNewTLine = (gcnew System::Windows::Forms::Label());
			this->LabelNewTRect = (gcnew System::Windows::Forms::Label());
			this->LabelNewTCircle = (gcnew System::Windows::Forms::Label());
			this->CreateNewObject = (gcnew System::Windows::Forms::Button());
			this->BoxNewTLine = (gcnew System::Windows::Forms::Panel());
			this->DeleteTheObject = (gcnew System::Windows::Forms::Button());
			this->Label = (gcnew System::Windows::Forms::Label());
			this->BoxNewTPoint = (gcnew System::Windows::Forms::Panel());
			this->PointFirstName = (gcnew System::Windows::Forms::TextBox());
			this->PointSecondName = (gcnew System::Windows::Forms::TextBox());
			this->PointFirstLabelTLine = (gcnew System::Windows::Forms::Label());
			this->PointSecondLabelTLine = (gcnew System::Windows::Forms::Label());
			this->LabelInstruction = (gcnew System::Windows::Forms::Label());
			this->GraphicPanelPicture->SuspendLayout();
			this->BoxNewTLine->SuspendLayout();
			this->BoxNewTPoint->SuspendLayout();
			this->SuspendLayout();
			// 
			// GraphicPanelPicture
			// 
			this->GraphicPanelPicture->BackColor = System::Drawing::Color::White;
			this->GraphicPanelPicture->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->GraphicPanelPicture->Controls->Add(this->LabelShowName);
			this->GraphicPanelPicture->Cursor = System::Windows::Forms::Cursors::Default;
			this->GraphicPanelPicture->Location = System::Drawing::Point(10, 10);
			this->GraphicPanelPicture->Name = L"GraphicPanelPicture";
			this->GraphicPanelPicture->Size = System::Drawing::Size(500, 500);
			this->GraphicPanelPicture->TabIndex = 0;
			this->GraphicPanelPicture->MouseLeave += gcnew System::EventHandler(this, &Form1::GraphicPanelPicture_MouseLeave);
			this->GraphicPanelPicture->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::GraphicPanelPicture_Paint);
			this->GraphicPanelPicture->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::GraphicPanelPicture_MouseMove);
			this->GraphicPanelPicture->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::GraphicPanelPicture_MouseDown);
			this->GraphicPanelPicture->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::GraphicPanelPicture_MouseUp);
			this->GraphicPanelPicture->MouseEnter += gcnew System::EventHandler(this, &Form1::GraphicPanelPicture_MouseEnter);
			// 
			// LabelShowName
			// 
			this->LabelShowName->AutoSize = true;
			this->LabelShowName->BackColor = System::Drawing::Color::Transparent;
			this->LabelShowName->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->LabelShowName->ForeColor = System::Drawing::Color::Black;
			this->LabelShowName->Location = System::Drawing::Point(54, 72);
			this->LabelShowName->Name = L"LabelShowName";
			this->LabelShowName->Size = System::Drawing::Size(80, 32);
			this->LabelShowName->TabIndex = 0;
			this->LabelShowName->Text = L"Name";
			// 
			// ButtonExit
			// 
			this->ButtonExit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ButtonExit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->ButtonExit->Location = System::Drawing::Point(10, 517);
			this->ButtonExit->Name = L"ButtonExit";
			this->ButtonExit->Size = System::Drawing::Size(125, 25);
			this->ButtonExit->TabIndex = 1;
			this->ButtonExit->Text = L"Выход";
			this->ButtonExit->UseVisualStyleBackColor = true;
			this->ButtonExit->MouseLeave += gcnew System::EventHandler(this, &Form1::ButtonExit_MouseLeave);
			this->ButtonExit->Click += gcnew System::EventHandler(this, &Form1::ButtonExit_Click);
			this->ButtonExit->MouseEnter += gcnew System::EventHandler(this, &Form1::ButtonExit_MouseEnter);
			// 
			// LabelHelp
			// 
			this->LabelHelp->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->LabelHelp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->LabelHelp->Location = System::Drawing::Point(141, 517);
			this->LabelHelp->Name = L"LabelHelp";
			this->LabelHelp->Size = System::Drawing::Size(691, 25);
			this->LabelHelp->TabIndex = 2;
			this->LabelHelp->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// LabelNewTPoint
			// 
			this->LabelNewTPoint->BackColor = System::Drawing::Color::RoyalBlue;
			this->LabelNewTPoint->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->LabelNewTPoint->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->LabelNewTPoint->Location = System::Drawing::Point(516, 10);
			this->LabelNewTPoint->Name = L"LabelNewTPoint";
			this->LabelNewTPoint->Size = System::Drawing::Size(110, 50);
			this->LabelNewTPoint->TabIndex = 4;
			this->LabelNewTPoint->Text = L"Точка";
			this->LabelNewTPoint->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->LabelNewTPoint->MouseLeave += gcnew System::EventHandler(this, &Form1::LabelNewTPoint_MouseLeave);
			this->LabelNewTPoint->Click += gcnew System::EventHandler(this, &Form1::LabelNewTPoint_Click);
			this->LabelNewTPoint->MouseEnter += gcnew System::EventHandler(this, &Form1::LabelNewTPoint_MouseEnter);
			// 
			// ObjectIsNotVisible
			// 
			this->ObjectIsNotVisible->AutoSize = true;
			this->ObjectIsNotVisible->BackColor = System::Drawing::Color::Transparent;
			this->ObjectIsNotVisible->Location = System::Drawing::Point(3, 129);
			this->ObjectIsNotVisible->Name = L"ObjectIsNotVisible";
			this->ObjectIsNotVisible->Size = System::Drawing::Size(103, 17);
			this->ObjectIsNotVisible->TabIndex = 8;
			this->ObjectIsNotVisible->Text = L"Не отображать";
			this->ObjectIsNotVisible->UseVisualStyleBackColor = false;
			this->ObjectIsNotVisible->MouseLeave += gcnew System::EventHandler(this, &Form1::ObjectIsNotVisible_MouseLeave);
			this->ObjectIsNotVisible->CheckedChanged += gcnew System::EventHandler(this, &Form1::ObjectIsNotVisible_CheckedChanged);
			this->ObjectIsNotVisible->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::ObjectIsNotVisible_MouseMove);
			// 
			// TextTPointY
			// 
			this->TextTPointY->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 20.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->TextTPointY->Location = System::Drawing::Point(133, 82);
			this->TextTPointY->MaxLength = 500;
			this->TextTPointY->Multiline = true;
			this->TextTPointY->Name = L"TextTPointY";
			this->TextTPointY->Size = System::Drawing::Size(66, 40);
			this->TextTPointY->TabIndex = 7;
			this->TextTPointY->Text = L"0";
			this->TextTPointY->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->TextTPointY->TextChanged += gcnew System::EventHandler(this, &Form1::InputOfCoordinates);
			// 
			// PointSecondLabelTPoint
			// 
			this->PointSecondLabelTPoint->BackColor = System::Drawing::Color::Transparent;
			this->PointSecondLabelTPoint->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->PointSecondLabelTPoint->Location = System::Drawing::Point(3, 90);
			this->PointSecondLabelTPoint->Name = L"PointSecondLabelTPoint";
			this->PointSecondLabelTPoint->Size = System::Drawing::Size(196, 20);
			this->PointSecondLabelTPoint->TabIndex = 5;
			this->PointSecondLabelTPoint->Text = L"Координата Y:";
			this->PointSecondLabelTPoint->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// TextTPointX
			// 
			this->TextTPointX->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 20.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->TextTPointX->Location = System::Drawing::Point(133, 36);
			this->TextTPointX->MaxLength = 500;
			this->TextTPointX->Multiline = true;
			this->TextTPointX->Name = L"TextTPointX";
			this->TextTPointX->Size = System::Drawing::Size(66, 40);
			this->TextTPointX->TabIndex = 2;
			this->TextTPointX->Text = L"0";
			this->TextTPointX->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->TextTPointX->TextChanged += gcnew System::EventHandler(this, &Form1::InputOfCoordinates);
			// 
			// PointFirstLabelTPoint
			// 
			this->PointFirstLabelTPoint->BackColor = System::Drawing::Color::Transparent;
			this->PointFirstLabelTPoint->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->PointFirstLabelTPoint->Location = System::Drawing::Point(3, 45);
			this->PointFirstLabelTPoint->Name = L"PointFirstLabelTPoint";
			this->PointFirstLabelTPoint->Size = System::Drawing::Size(196, 20);
			this->PointFirstLabelTPoint->TabIndex = 0;
			this->PointFirstLabelTPoint->Text = L"Координата X:";
			this->PointFirstLabelTPoint->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// LabelNewTLine
			// 
			this->LabelNewTLine->BackColor = System::Drawing::Color::WhiteSmoke;
			this->LabelNewTLine->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->LabelNewTLine->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->LabelNewTLine->Location = System::Drawing::Point(516, 62);
			this->LabelNewTLine->Name = L"LabelNewTLine";
			this->LabelNewTLine->Size = System::Drawing::Size(102, 50);
			this->LabelNewTLine->TabIndex = 8;
			this->LabelNewTLine->Text = L"Линия";
			this->LabelNewTLine->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->LabelNewTLine->MouseLeave += gcnew System::EventHandler(this, &Form1::LabelNewTLine_MouseLeave);
			this->LabelNewTLine->Click += gcnew System::EventHandler(this, &Form1::LabelNewTLine_Click);
			this->LabelNewTLine->MouseEnter += gcnew System::EventHandler(this, &Form1::LabelNewTLine_MouseEnter);
			// 
			// LabelNewTRect
			// 
			this->LabelNewTRect->BackColor = System::Drawing::Color::WhiteSmoke;
			this->LabelNewTRect->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->LabelNewTRect->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->LabelNewTRect->Location = System::Drawing::Point(516, 166);
			this->LabelNewTRect->Name = L"LabelNewTRect";
			this->LabelNewTRect->Size = System::Drawing::Size(102, 50);
			this->LabelNewTRect->TabIndex = 9;
			this->LabelNewTRect->Text = L"Прямоугольник";
			this->LabelNewTRect->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->LabelNewTRect->MouseLeave += gcnew System::EventHandler(this, &Form1::LabelNewTRect_MouseLeave);
			this->LabelNewTRect->Click += gcnew System::EventHandler(this, &Form1::LabelNewTRect_Click);
			this->LabelNewTRect->MouseEnter += gcnew System::EventHandler(this, &Form1::LabelNewTRect_MouseEnter);
			// 
			// LabelNewTCircle
			// 
			this->LabelNewTCircle->BackColor = System::Drawing::Color::WhiteSmoke;
			this->LabelNewTCircle->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->LabelNewTCircle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->LabelNewTCircle->Location = System::Drawing::Point(516, 114);
			this->LabelNewTCircle->Name = L"LabelNewTCircle";
			this->LabelNewTCircle->Size = System::Drawing::Size(102, 50);
			this->LabelNewTCircle->TabIndex = 10;
			this->LabelNewTCircle->Text = L"Окружность";
			this->LabelNewTCircle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->LabelNewTCircle->MouseLeave += gcnew System::EventHandler(this, &Form1::LabelNewTCircle_MouseLeave);
			this->LabelNewTCircle->Click += gcnew System::EventHandler(this, &Form1::LabelNewTCircle_Click);
			this->LabelNewTCircle->MouseEnter += gcnew System::EventHandler(this, &Form1::LabelNewTCircle_MouseEnter);
			// 
			// CreateNewObject
			// 
			this->CreateNewObject->Cursor = System::Windows::Forms::Cursors::Hand;
			this->CreateNewObject->Location = System::Drawing::Point(3, 152);
			this->CreateNewObject->Name = L"CreateNewObject";
			this->CreateNewObject->Size = System::Drawing::Size(202, 25);
			this->CreateNewObject->TabIndex = 11;
			this->CreateNewObject->Text = L"Создать новый объект";
			this->CreateNewObject->UseVisualStyleBackColor = true;
			this->CreateNewObject->MouseLeave += gcnew System::EventHandler(this, &Form1::CreateNewObject_MouseLeave);
			this->CreateNewObject->Click += gcnew System::EventHandler(this, &Form1::CreateNewObject_Click);
			this->CreateNewObject->MouseEnter += gcnew System::EventHandler(this, &Form1::CreateNewObject_MouseEnter);
			// 
			// BoxNewTLine
			// 
			this->BoxNewTLine->BackColor = System::Drawing::Color::RoyalBlue;
			this->BoxNewTLine->Controls->Add(this->BoxNewTPoint);
			this->BoxNewTLine->Controls->Add(this->DeleteTheObject);
			this->BoxNewTLine->Controls->Add(this->Label);
			this->BoxNewTLine->Controls->Add(this->TextTPointX);
			this->BoxNewTLine->Controls->Add(this->TextTPointY);
			this->BoxNewTLine->Controls->Add(this->PointFirstLabelTPoint);
			this->BoxNewTLine->Controls->Add(this->CreateNewObject);
			this->BoxNewTLine->Controls->Add(this->ObjectIsNotVisible);
			this->BoxNewTLine->Controls->Add(this->PointSecondLabelTPoint);
			this->BoxNewTLine->Location = System::Drawing::Point(624, 10);
			this->BoxNewTLine->Name = L"BoxNewTLine";
			this->BoxNewTLine->Size = System::Drawing::Size(208, 206);
			this->BoxNewTLine->TabIndex = 12;
			// 
			// DeleteTheObject
			// 
			this->DeleteTheObject->Cursor = System::Windows::Forms::Cursors::Hand;
			this->DeleteTheObject->Location = System::Drawing::Point(3, 178);
			this->DeleteTheObject->Name = L"DeleteTheObject";
			this->DeleteTheObject->Size = System::Drawing::Size(202, 25);
			this->DeleteTheObject->TabIndex = 13;
			this->DeleteTheObject->Text = L"Удалить объект";
			this->DeleteTheObject->UseVisualStyleBackColor = true;
			this->DeleteTheObject->MouseLeave += gcnew System::EventHandler(this, &Form1::DeleteTheObject_MouseLeave);
			this->DeleteTheObject->Click += gcnew System::EventHandler(this, &Form1::DeleteTheObject_Click);
			this->DeleteTheObject->MouseEnter += gcnew System::EventHandler(this, &Form1::DeleteTheObject_MouseEnter);
			// 
			// Label
			// 
			this->Label->BackColor = System::Drawing::Color::Transparent;
			this->Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->Label->Location = System::Drawing::Point(3, 4);
			this->Label->Name = L"Label";
			this->Label->Size = System::Drawing::Size(196, 20);
			this->Label->TabIndex = 12;
			this->Label->Text = L"Добавить новый объект:";
			this->Label->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// BoxNewTPoint
			// 
			this->BoxNewTPoint->BackColor = System::Drawing::Color::RoyalBlue;
			this->BoxNewTPoint->Controls->Add(this->PointFirstName);
			this->BoxNewTPoint->Controls->Add(this->PointSecondName);
			this->BoxNewTPoint->Controls->Add(this->PointFirstLabelTLine);
			this->BoxNewTPoint->Controls->Add(this->PointSecondLabelTLine);
			this->BoxNewTPoint->Location = System::Drawing::Point(0, 33);
			this->BoxNewTPoint->Name = L"BoxNewTPoint";
			this->BoxNewTPoint->Size = System::Drawing::Size(208, 94);
			this->BoxNewTPoint->TabIndex = 13;
			// 
			// PointFirstName
			// 
			this->PointFirstName->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 20.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->PointFirstName->Location = System::Drawing::Point(159, 3);
			this->PointFirstName->MaxLength = 1;
			this->PointFirstName->Multiline = true;
			this->PointFirstName->Name = L"PointFirstName";
			this->PointFirstName->Size = System::Drawing::Size(40, 40);
			this->PointFirstName->TabIndex = 2;
			this->PointFirstName->Text = L"A";
			this->PointFirstName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->PointFirstName->TextChanged += gcnew System::EventHandler(this, &Form1::InputOfCoordinates);
			// 
			// PointSecondName
			// 
			this->PointSecondName->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 20.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->PointSecondName->Location = System::Drawing::Point(159, 49);
			this->PointSecondName->MaxLength = 1;
			this->PointSecondName->Multiline = true;
			this->PointSecondName->Name = L"PointSecondName";
			this->PointSecondName->Size = System::Drawing::Size(40, 40);
			this->PointSecondName->TabIndex = 7;
			this->PointSecondName->Text = L"B";
			this->PointSecondName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->PointSecondName->TextChanged += gcnew System::EventHandler(this, &Form1::InputOfCoordinates);
			// 
			// PointFirstLabelTLine
			// 
			this->PointFirstLabelTLine->BackColor = System::Drawing::Color::Transparent;
			this->PointFirstLabelTLine->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->PointFirstLabelTLine->Location = System::Drawing::Point(3, 12);
			this->PointFirstLabelTLine->Name = L"PointFirstLabelTLine";
			this->PointFirstLabelTLine->Size = System::Drawing::Size(196, 20);
			this->PointFirstLabelTLine->TabIndex = 0;
			this->PointFirstLabelTLine->Text = L"PointFirstLabelTLine";
			this->PointFirstLabelTLine->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// PointSecondLabelTLine
			// 
			this->PointSecondLabelTLine->BackColor = System::Drawing::Color::Transparent;
			this->PointSecondLabelTLine->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->PointSecondLabelTLine->Location = System::Drawing::Point(3, 57);
			this->PointSecondLabelTLine->Name = L"PointSecondLabelTLine";
			this->PointSecondLabelTLine->Size = System::Drawing::Size(196, 20);
			this->PointSecondLabelTLine->TabIndex = 5;
			this->PointSecondLabelTLine->Text = L"PointSecondLabelTLine";
			this->PointSecondLabelTLine->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// LabelInstruction
			// 
			this->LabelInstruction->BackColor = System::Drawing::Color::Transparent;
			this->LabelInstruction->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->LabelInstruction->Location = System::Drawing::Point(516, 230);
			this->LabelInstruction->Name = L"LabelInstruction";
			this->LabelInstruction->Size = System::Drawing::Size(316, 280);
			this->LabelInstruction->TabIndex = 13;
			this->LabelInstruction->MouseLeave += gcnew System::EventHandler(this, &Form1::LabelInstruction_MouseLeave);
			this->LabelInstruction->MouseEnter += gcnew System::EventHandler(this, &Form1::LabelInstruction_MouseEnter);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(844, 552);
			this->Controls->Add(this->LabelInstruction);
			this->Controls->Add(this->BoxNewTLine);
			this->Controls->Add(this->LabelNewTRect);
			this->Controls->Add(this->LabelNewTCircle);
			this->Controls->Add(this->LabelNewTLine);
			this->Controls->Add(this->LabelHelp);
			this->Controls->Add(this->ButtonExit);
			this->Controls->Add(this->LabelNewTPoint);
			this->Controls->Add(this->GraphicPanelPicture);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Plex (Graphic editor)";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->GraphicPanelPicture->ResumeLayout(false);
			this->GraphicPanelPicture->PerformLayout();
			this->BoxNewTLine->ResumeLayout(false);
			this->BoxNewTLine->PerformLayout();
			this->BoxNewTPoint->ResumeLayout(false);
			this->BoxNewTPoint->PerformLayout();
			this->ResumeLayout(false);

		}


#pragma endregion

/*-----------------------------------------------------------------------------------------------*/
							   //***** Глобальные переменные *****//

int WhatObjectIsSelect;		//Какой объект выбран для создания (или удаления)
bool DisplaySelectedObject;
int NumberOfTPoint;
TPoint *ObjectPoints;
TPlex *Plex;
int TPointSelect;	//Номер выбранной на панели вершины
bool IsMouseDown;	//0 - нет
					//1 - левая кнопка нажата
int WhatTPointIsPressed;
bool IsPaintOver;	//Нужно ли закрашивать красные линии чёрным?
int *QuickBuild;	//Массив номеров из пары точек для быстрого создания объектов
int LastSelectedTPoint;
TLine *NewL1;
TCircle *NewC1;
TRect *NewR1;

/*-----------------------------------------------------------------------------------------------*/
									//***** Функции *****//

		//Отобразить все точки
void PaintAllTPoints(){
	for (int I=0; I<NumberOfTPoint; I++){
		ObjectPoints[I].Show(this->GraphicPanelPicture->CreateGraphics(), TPointSelect);
	}
}

		//Возврат состояния кнопок выбора типа объекта при создании
void ClearSelectOfObject(){
	if (WhatObjectIsSelect != 0){
		LabelNewTPoint->BackColor = System::Drawing::Color::WhiteSmoke;
		LabelNewTPoint->SetBounds(516, 10, 102, 50);
	}
	if (WhatObjectIsSelect != 1){
		LabelNewTLine->BackColor = System::Drawing::Color::WhiteSmoke;
		LabelNewTLine->SetBounds(516, 62, 102, 50);
	}
	if (WhatObjectIsSelect != 2){
		LabelNewTCircle->BackColor = System::Drawing::Color::WhiteSmoke;
		LabelNewTCircle->SetBounds(516, 114, 102, 50);
	}
	if (WhatObjectIsSelect != 3){
		LabelNewTRect->BackColor = System::Drawing::Color::WhiteSmoke;
		LabelNewTRect->SetBounds(516, 166, 102, 50);
	}
}


		//Создание объекта TPoint
void CreateTPoint(int X, int Y){
	if (NumberOfTPoint < 26){
		NumberOfTPoint++;
		ObjectPoints[NumberOfTPoint-1].Initialize(X, Y);
		TLine* L1 = new TLine(&ObjectPoints[NumberOfTPoint-1], &ObjectPoints[NumberOfTPoint-2], false);

		TLine *L2 = Plex->SearchTLineForAdd(&ObjectPoints[NumberOfTPoint-2]);
		if (L2 != NULL){
			if ( Plex->SideOfTLineForAdd(L2, &ObjectPoints[NumberOfTPoint-2])){
				L2->P1 = L1;
			}else{
				L2->P2 = L1;
			}
		}

	}
}

		//Создание объекта TLine
void CreateTLine(int Pi1, int Pi2, bool DisplaySelectedObject){
	TLine *L1 = new TLine(&(ObjectPoints[Pi1]),
						  &(ObjectPoints[Pi2]),
						  DisplaySelectedObject );
	Plex->Create(L1);
}

		//Создание объекта TCircle
void CreateTCircle(int Pi1, int Pi2, bool DisplaySelectedObject){
	TCircle *C1 = new TCircle(&(ObjectPoints[Pi1]),
						  &(ObjectPoints[Pi2]),
						  DisplaySelectedObject );
	Plex->Create(C1);
}

		//Создание объекта TRect
void CreateTRect(int Pi1, int Pi2, bool DisplaySelectedObject){
	TRect *R1 = new TRect(&(ObjectPoints[Pi1]),
						  &(ObjectPoints[Pi2]),
						  DisplaySelectedObject );
	Plex->Create(R1);
}

		//Даёт указания по удалению объекта
void DeleteObject(int Pi1, int Pi2, int WhatObjectIsSelect){
	Plex->Delete(Pi1, Pi2, WhatObjectIsSelect);
}

/*-----------------------------------------------------------------------------------------------*/
								//***** При загрузке *****//

private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		WhatObjectIsSelect = 0;
		DisplaySelectedObject = true;
		NumberOfTPoint = 2;
		ObjectPoints = new TPoint[26];
		for (int I=0; I<26; I++){
			ObjectPoints[I].Initialize(100, 100, I);
		}
		ObjectPoints[0].Initialize(100, 200);
		ObjectPoints[1].Initialize(200, 300);
		BoxNewTPoint->Visible = false;
		ObjectIsNotVisible->Enabled = false;
		LabelShowName->Text = "";
		IsMouseDown = false;
		TPointSelect = -1;
		IsPaintOver = false;
		QuickBuild = new int[2];
		QuickBuild[0] = -1;
		QuickBuild[1] = -1;
		LastSelectedTPoint = -1;

		LabelInstruction->Text += "                          Plex (Graphic Editor) Application\n\n";
		LabelInstruction->Text += "Изготовитель:\n";
		LabelInstruction->Text += "       Новиков Егор Александрович\n\n";
		LabelInstruction->Text += "Инструкция:\n";
		LabelInstruction->Text += "1). Программа предоставляет возможность создавать объекты четырёх типов: точку, линию, окружность, прямоугольник.\n";
		LabelInstruction->Text += "2). Выбор желаемого объекта осуществляется нажатием на панельку с соответствующей объекту надписью.\n";
		LabelInstruction->Text += "3). Левая клавиша мыши позволяет передвигать точки по графической панели.\n";
		LabelInstruction->Text += "4). Клик правой клавиши мыши по графической панели - создание новой точки.\n";
		LabelInstruction->Text += "5). ''Натягивание'' одной точки на другую роликом мыши позволяет быстро создавать выбранные объекты.\n";
		LabelInstruction->Text += "6). При наведении курсора мыши на точку программа подсвечивает красным цветом те объекты, которые изменяться при перетаскивании данной точки.\n";

		TLine *L1 = new TLine(&(ObjectPoints[0]), &(ObjectPoints[1]), false);
		Plex = new TPlex(L1);

}

 /*-----------------------------------------------------------------------------------------------*/
									//***** Создание графики *****//

private: System::Void GraphicPanelPicture_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		Plex->PaintPlex(e->Graphics, TPointSelect);
}

/*-----------------------------------------------------------------------------------------------*/
									//***** MOUSE MOVE *****//


private: System::Void ObjectIsNotVisible_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (DisplaySelectedObject){
			LabelHelp->Text = "Не отображать объект на панели после его создания";
		}else{
			LabelHelp->Text = "Разрешить отобразить объект на панели после его создания";
		}
}
private: System::Void ObjectIsNotVisible_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
			LabelHelp->Text = "";
}

private: System::Void ButtonExit_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		LabelHelp->Text = "Закончить работу с приложением";
		ButtonExit->ForeColor = System::Drawing::Color::Red;
}
private: System::Void ButtonExit_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		LabelHelp->Text = "";
		ButtonExit->ForeColor = System::Drawing::Color::Black;
}

private: System::Void DataTPoint_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		LabelHelp->Text = "Список Точек";
}
private: System::Void DataTPoint_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		LabelHelp->Text = "";
}

private: System::Void DataTObject_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		LabelHelp->Text = "Список Объектов";
}
private: System::Void DataTObject_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		LabelHelp->Text = "";
}

private: System::Void LabelNewTPoint_Click(System::Object^  sender, System::EventArgs^  e) {
		WhatObjectIsSelect = 0;
		ClearSelectOfObject();
		LabelNewTPoint->BackColor = System::Drawing::Color::RoyalBlue;
		BoxNewTPoint->Visible = false;
		ObjectIsNotVisible->Enabled = false;
		LabelNewTPoint->SetBounds(516, 10, 110, 50);
}
private: System::Void LabelNewTPoint_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		this->LabelHelp->Text = "Создать новый объект ''Точка''";
		if (WhatObjectIsSelect != 0)
			LabelNewTPoint->BackColor = System::Drawing::Color::CornflowerBlue;	
}	 
private: System::Void LabelNewTPoint_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		this->LabelHelp->Text = "";
		if (WhatObjectIsSelect != 0)
			LabelNewTPoint->BackColor = System::Drawing::Color::WhiteSmoke;
}

private: System::Void LabelNewTLine_Click(System::Object^  sender, System::EventArgs^  e) {
		WhatObjectIsSelect = 1;
		ClearSelectOfObject();
		LabelNewTLine->BackColor = System::Drawing::Color::RoyalBlue;
		BoxNewTPoint->Visible = true;
		ObjectIsNotVisible->Enabled = true;
		LabelNewTLine->SetBounds(516, 62, 110, 50);
		PointFirstLabelTLine->Text = "Первая точка:";
		PointSecondLabelTLine->Text = "Вторая точка:";
}
private: System::Void LabelNewTLine_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		LabelHelp->Text = "Создать новый объект ''Линия''";
		if (WhatObjectIsSelect != 1)
			LabelNewTLine->BackColor = System::Drawing::Color::CornflowerBlue;
}
private: System::Void LabelNewTLine_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		this->LabelHelp->Text = "";
		if (WhatObjectIsSelect != 1)
			LabelNewTLine->BackColor = System::Drawing::Color::WhiteSmoke;
}

private: System::Void LabelNewTCircle_Click(System::Object^  sender, System::EventArgs^  e) {
		WhatObjectIsSelect = 2;
		ClearSelectOfObject();
		LabelNewTCircle->BackColor = System::Drawing::Color::RoyalBlue;
		BoxNewTPoint->Visible = true;
		ObjectIsNotVisible->Enabled = true;
		LabelNewTCircle->SetBounds(516, 114, 110, 50);
		PointFirstLabelTLine->Text = "Центр эллипса:";
		PointSecondLabelTLine->Text = "Точка на окружности:";
}
private: System::Void LabelNewTCircle_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		LabelHelp->Text = "Создать новый объект ''Окружность''";
		if (WhatObjectIsSelect != 2)
			LabelNewTCircle->BackColor = System::Drawing::Color::CornflowerBlue;
}
private: System::Void LabelNewTCircle_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		this->LabelHelp->Text = "";
		if (WhatObjectIsSelect != 2)
			LabelNewTCircle->BackColor = System::Drawing::Color::WhiteSmoke;
}

private: System::Void LabelNewTRect_Click(System::Object^  sender, System::EventArgs^  e) {
		WhatObjectIsSelect = 3;
		ClearSelectOfObject();
		LabelNewTRect->BackColor = System::Drawing::Color::RoyalBlue;
		BoxNewTPoint->Visible = true;
		ObjectIsNotVisible->Enabled = true;
		LabelNewTRect->SetBounds(516, 166, 110, 50);
		PointFirstLabelTLine->Text = "Первая вершина:";
		PointSecondLabelTLine->Text = "Противоположная вершина:";
}
private: System::Void LabelNewTRect_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		LabelHelp->Text = "Создать новый объект ''Прямоугольник''";
		if (WhatObjectIsSelect != 3)
			LabelNewTRect->BackColor = System::Drawing::Color::CornflowerBlue;
}
private: System::Void LabelNewTRect_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		this->LabelHelp->Text = "";
		if (WhatObjectIsSelect != 3)
			LabelNewTRect->BackColor = System::Drawing::Color::WhiteSmoke;
}

private: System::Void CreateNewObject_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		if (WhatObjectIsSelect == 0){
			LabelHelp->Text = "Создать новый объект ''Точка''";
		}
		if (WhatObjectIsSelect == 1){
			LabelHelp->Text = "Создать новый объект ''Линия''";
		}
		if (WhatObjectIsSelect == 2){
			LabelHelp->Text = "Создать новый объект ''Окружность''";
		}
		if (WhatObjectIsSelect == 3){
			LabelHelp->Text = "Создать новый объект ''Прямоугольник''";
		}
		CreateNewObject->ForeColor = System::Drawing::Color::Red;
}
private: System::Void CreateNewObject_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		LabelHelp->Text = "";
		CreateNewObject->ForeColor = System::Drawing::Color::Black;
}

private: System::Void GraphicPanelPicture_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		LabelHelp->Text = "Графическая панель";
}
private: System::Void GraphicPanelPicture_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		LabelHelp->Text = "";
}

private: System::Void LabelInstruction_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		LabelHelp->Text = "Инструкция";
}
private: System::Void LabelInstruction_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		LabelHelp->Text = "";
}

private: System::Void DeleteTheObject_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		LabelHelp->Text = "Удалить заданный объект";
}
private: System::Void DeleteTheObject_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		LabelHelp->Text = "";
}

/*-----------------------------------------------------------------------------------------------*/
					//***** Передвижение и создание новых точек на панели *****//

private: System::Void GraphicPanelPicture_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		int I;
		TPointSelect = -1;
		for (I=0; I<NumberOfTPoint; I++){
			if (hypot(e->X - ObjectPoints[I].GetX(), e->Y - ObjectPoints[I].GetY()) <= 4){
				LabelShowName->Text = (Convert::ToChar(I + 65)).ToString();
				LabelShowName->SetBounds(e->X+15, e->Y-15, 0, 0);
				IsPaintOver = true;
				TPointSelect = I;
				if (LastSelectedTPoint != I){
					Plex->PaintPlex(this->GraphicPanelPicture->CreateGraphics(), TPointSelect);
					LastSelectedTPoint = I;
				}
			}
		}
		if (TPointSelect == -1){
			LabelShowName->Text = "";
			if (IsPaintOver){
				IsPaintOver = false;
				LastSelectedTPoint = -1;
				Plex->PaintPlex(this->GraphicPanelPicture->CreateGraphics(), TPointSelect);
			}
		}

		if (IsMouseDown){
			ObjectPoints[WhatTPointIsPressed].Initialize(e->X, e->Y);
			if (ObjectPoints[WhatTPointIsPressed].X < 0)
					ObjectPoints[WhatTPointIsPressed].Initialize(0, e->Y);
			if (ObjectPoints[WhatTPointIsPressed].X > this->GraphicPanelPicture->Size.Width)
					ObjectPoints[WhatTPointIsPressed].Initialize(500, e->Y);
			if (ObjectPoints[WhatTPointIsPressed].Y < 0)
					ObjectPoints[WhatTPointIsPressed].Initialize(e->X, 0);
			if (ObjectPoints[WhatTPointIsPressed].Y > this->GraphicPanelPicture->Size.Height)
					ObjectPoints[WhatTPointIsPressed].Initialize(e->X, 500);
			Plex->PaintPlex(this->GraphicPanelPicture->CreateGraphics(), TPointSelect);
		}

}
private: System::Void GraphicPanelPicture_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left){
			for (int I=0; I<NumberOfTPoint; I++){
				if (hypot(e->X - ObjectPoints[I].GetX(), e->Y - ObjectPoints[I].GetY()) <= 4){
					IsMouseDown = true;
					WhatTPointIsPressed = I;
				}
			}
		}
		if (e->Button == System::Windows::Forms::MouseButtons::Right){
			CreateTPoint(e->X, e->Y);
			Plex->PaintPlex(this->GraphicPanelPicture->CreateGraphics(), TPointSelect);
		}
		if (e->Button == System::Windows::Forms::MouseButtons::Middle){
			for (int I=0; I<NumberOfTPoint; I++){
				if (hypot(e->X - ObjectPoints[I].GetX(), e->Y - ObjectPoints[I].GetY()) <= 4){
					QuickBuild[0] = I;
				}
			}
		}
}
private: System::Void GraphicPanelPicture_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		IsMouseDown = false;

		for (int I=0; I<NumberOfTPoint; I++){
			if (hypot(e->X - ObjectPoints[I].GetX(), e->Y - ObjectPoints[I].GetY()) <= 7){
				QuickBuild[1] = I;
			}
		}

		if ((QuickBuild[0] > -1) && (QuickBuild[1] > -1) && 
												(QuickBuild[0] != QuickBuild[1])){
			if (WhatObjectIsSelect == 1){
				CreateTLine(QuickBuild[0], QuickBuild[1], DisplaySelectedObject);
			}
			if (WhatObjectIsSelect == 2){
				CreateTCircle(QuickBuild[0], QuickBuild[1], DisplaySelectedObject);
			}
			if (WhatObjectIsSelect == 3){
				CreateTRect(QuickBuild[0], QuickBuild[1], DisplaySelectedObject);
			}
		}
		for (int I=0; I<2; I++) 
			QuickBuild[I] = -1;

		Plex->PaintPlex(this->GraphicPanelPicture->CreateGraphics(), TPointSelect);
}

/*-----------------------------------------------------------------------------------------------*/
								//***** Ввод имён точек *****//

private: System::Void InputOfCoordinates(System::Object^  sender, System::EventArgs^  e) {
		PointFirstName->Text = PointFirstName->Text->ToUpper();
		PointSecondName->Text = PointSecondName->Text->ToUpper();
}

/*-----------------------------------------------------------------------------------------------*/
						//***** Ввод видимости созданного объекта *****//

private: System::Void ObjectIsNotVisible_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		DisplaySelectedObject = !DisplaySelectedObject;
}

/*-----------------------------------------------------------------------------------------------*/
								//***** Создание нового объекта *****//

private: System::Void CreateNewObject_Click(System::Object^  sender, System::EventArgs^  e) {
		if (WhatObjectIsSelect == 0){
			CreateTPoint(Convert::ToInt32(TextTPointX->Text),
						 Convert::ToInt32(TextTPointY->Text));
		}

		int Pi1 = Convert::ToInt32(Convert::ToChar(PointFirstName->Text)) - 65;
		int Pi2 = Convert::ToInt32(Convert::ToChar(PointSecondName->Text)) - 65;
			 
		if ((Pi1 >= 0) && (Pi1 < NumberOfTPoint) && (Pi2 >= 0) && (Pi2 < NumberOfTPoint)){
			if (WhatObjectIsSelect == 1){
				CreateTLine(Pi1, Pi2, DisplaySelectedObject);
			}else if (WhatObjectIsSelect == 2){
				CreateTCircle(Pi1, Pi2, DisplaySelectedObject);
			}else if (WhatObjectIsSelect == 3){
				CreateTRect(Pi1, Pi2, DisplaySelectedObject);
			}
			Plex->PaintPlex(this->GraphicPanelPicture->CreateGraphics(), TPointSelect);
		}

}

/*-----------------------------------------------------------------------------------------------*/
								//***** Удаление объекта *****//

private: System::Void DeleteTheObject_Click(System::Object^  sender, System::EventArgs^  e) {
		DeleteObject(Convert::ToInt32(Convert::ToChar(PointFirstName->Text)) - 65,
					 Convert::ToInt32(Convert::ToChar(PointSecondName->Text)) - 65,
					 WhatObjectIsSelect);
		Plex->PaintPlex(this->GraphicPanelPicture->CreateGraphics(), TPointSelect);
}

/*-----------------------------------------------------------------------------------------------*/
									//***** Выход *****//

private: System::Void ButtonExit_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
}





};
}

