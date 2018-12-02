#pragma once

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

ref class Person{
public:
	String^ Name;
	String^ Surname;
	int Reputation;
	int Club;
	System::DateTime^ DateOfBirthday;
	int FirstNation;
	int SecondNation;

	Person::Person(String^ Name, String^ Surname, int Reputation, int Club, int Day, int Month, int Year, int FirstNation, int SecondNation){
		this->Name = Name;
		this->Surname = Surname;
		this->Reputation = Reputation;
		this->Club =  Club;
		DateOfBirthday = gcnew System::DateTime(Year, Month, Day);
		this->FirstNation = FirstNation;
		this->SecondNation = SecondNation;
	}

	Person::~Person(){
		delete DateOfBirthday;
	}
};
