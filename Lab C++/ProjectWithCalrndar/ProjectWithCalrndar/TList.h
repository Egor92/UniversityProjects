#pragma once
#include "StdAfx.h"

template <class TValue>
ref class TLink
{
public:
	TLink ^Next;
	TValue val;
	System::String^ STR;
	System::Drawing::Color^ color;

	TLink(void){
		this->Next = nullptr;
		this->val = nullptr;
		STR = "Был вызван конструктор по умолчанию TLink(void)";
		color = System::Drawing::Color::Transparent;
	}

	TLink(TValue val){
		this->Next = nullptr;
		this->val = val;
		STR = "Был вызван конструктор TLink(TValue val)";
		color = System::Drawing::Color::Black;
	}
};

template <class TValue>
ref class TList
{
public:
	TLink<TValue> ^First;

	TList(void){
		this->First = nullptr;
	}

	~TList(void){

	}

	void Add(TValue val){
		TLink<TValue> ^L1 = gcnew TLink<TValue>(val);
		if (this->First == nullptr){
			this->First = L1;
		}else{
			L1->Next = this->First;
		}
		this->First = L1;
		delete L1;
	}

	void Delete(TValue val){
		TLink<TValue> ^L1 = this->First;
		if (L1 != nullptr){
			while (L1->Next != nullptr){
				if (L1->Next->val == val){
					L1->Next = L1->Next->Next;
				}else{
					L1 = L1->Next;
				}
			}
			if (this->First->val == val){
				this->First = this->First->Next;
			}
		}
	}
};