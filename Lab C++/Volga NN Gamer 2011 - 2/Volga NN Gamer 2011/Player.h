#pragma once
#include "person.h"

ref class Player : public Person{
public:

	int Amplua;
	int Number;

	Player(String^ Name, String^ Surname, int Reputation, int Club, int Day, int Month, int Year, int FirstNation, int SecondNation,
			int Amplua, int Number) : Person(Name, Surname, Reputation, Club, Day, Month, Year, FirstNation, SecondNation){
		this->Amplua = Amplua;
		this->Number = Number;
	}
};
