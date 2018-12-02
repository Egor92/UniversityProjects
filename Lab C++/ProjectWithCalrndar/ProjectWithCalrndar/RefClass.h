#pragma once
#include "StdAfx.h"

ref class RefClass
{
	System::String^ string;

public:
	RefClass(void){
		this->string = gcnew System::String("Я создан!");
	}

	property System::String^ String{
		void set(System::String^ str){
			this->string = str;
		}

		System::String^ get(void){
			return this->string;
		}
	}
		
private:
	~RefClass(void){
		delete this->string;
	}
};	
