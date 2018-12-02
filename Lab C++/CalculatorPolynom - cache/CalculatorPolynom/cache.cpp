#pragma once

#include "stdafx.h"
#include "GeorgeFunctions.h"
#include "cache.h"
#include <string>
using namespace std;

/*-----------------------------------------------------------------------------------------------*/
										//***** class Field *****//

Field::Field(){
	this->Name = -1;
	this->Value = "";
}

Field::Field(int Name, std::string Value){
	this->Name = Name;
	this->Value = Value;
}

void Field::Initialize(int Name, std::string Value){
	this->Name = Name;
	this->Value = Value;
}

/*-----------------------------------------------------------------------------------------------*/
									//***** class CircleBuffer *****//

CircleBuffer::CircleBuffer(Field *Memory, int Size){
	this->Memory = Memory;
	this->Size = Size;
	this->Begin = Size - 1;
	this->End = Size - 1;
}

int CircleBuffer::PlusOne(int A){
	return ( (A+1) % this->Size);
}

Field* CircleBuffer::Find(int Name){
	for (int I = this->Begin; I != this->End; I = this->PlusOne(I) ){
		if (this->Memory[I].Name == Name){
			return &(this->Memory[I]);
		}
		if (this->PlusOne(I) == this->End){
			if (this->Memory[this->End].Name == Name){
				return &(this->Memory[this->End]);
			}
		}
	}
	return NULL;
}

void CircleBuffer::Add(int Name, std::string Value){
	Field* Result = this->Find(Name);
	if (Result == NULL){
		if (this->PlusOne(this->End) == this->Begin){
			this->Begin = this->PlusOne(this->Begin);
		}
		this->End = this->PlusOne(this->End);
		this->Memory[this->End].Name = Name;
		this->Memory[this->End].Value = Value;
	}else{
		Result->Value = Value;
	}
}

/*-----------------------------------------------------------------------------------------------*/
										//***** class Cache *****//

Cache::Cache(int CountBuffers, int SizeGlobal, int SizeCache){
	this->CountBuffers = CountBuffers;
	this->SizeGlobal = SizeGlobal;
	this->SizeCache = SizeCache;
	this->MemGlobal = new Field[this->SizeGlobal];
	for(int I = 0; I < this->SizeGlobal; I++){
		this->MemGlobal[I].Initialize(I, "0");
	}
	this->MemCache = new Field[this->SizeCache];
	this->End = SizeGlobal - 1;
	int S = IntOfDiv(this->SizeCache, this->CountBuffers);
	this->Buffer = new CircleBuffer*[CountBuffers];
	for(int I = 0; I < this->CountBuffers; I++){
		this->Buffer[I] = new CircleBuffer(&this->MemCache[I * S], SizeOfBuffer(I));
	}
}

int Cache::SizeOfBuffer(int NumBuffer){
	int Result = -1;
	if (NumBuffer < this->CountBuffers - 1){
		Result = IntOfDiv(this->SizeCache, this->CountBuffers);
	}
	else if (NumBuffer == this->CountBuffers - 1){
		Result = IntOfDiv(this->SizeCache, this->CountBuffers) + (this->SizeCache % this->CountBuffers);
	}
	return Result;
}

int Cache::PlusOne(int A){
	return ( (A+1) % this->SizeCache);
}

Field* Cache::FindInCache(int Name){
	Field* FindedField = NULL;
	FindedField = this->Buffer[Name % this->CountBuffers]->Find(Name);
	return FindedField;
}

Field* Cache::FindInGlobal(int Name){
	for (int I = 0; I < this->SizeGlobal; I++){
		if (this->MemGlobal[I].Name == Name){
			return &(this->MemGlobal[I]);
		}
	}
	return NULL;
}

void Cache::Add(int Name, std::string Value){
	Field* FindedField = NULL;
	FindedField = this->FindInGlobal(Name);
	if (FindedField == NULL){
		this->MemGlobal[this->End].Name = Name;
		this->MemGlobal[this->End].Value = Value;
		this->End = this->PlusOne(this->End);
	}else{
		FindedField->Value = Value;
	}
	this->Buffer[Name % this->CountBuffers]->Add(Name, Value);
}


