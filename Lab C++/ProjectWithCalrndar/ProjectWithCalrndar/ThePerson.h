#pragma once

ref class ThePerson{
	public:
		System::String^ Name;
		System::String^ Surname;
		int Age;

		ThePerson(){
			this->Name = "";
			this->Surname = "";
			this->Age = 0;
		}

		ThePerson(System::String^ Name, System::String^ Surname){
			this->Name = Name;
			this->Surname = Surname;
			System::Random^ A = gcnew System::Random();
			this->Age = A->Next(15, 60);
		}

		ThePerson(System::String^ Name, System::String^ Surname, int Age){
			this->Name = Name;
			this->Surname = Surname;
			this->Age = Age;
		}
};