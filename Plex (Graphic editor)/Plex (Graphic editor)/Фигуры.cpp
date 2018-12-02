#pragma once
#include "stdafx.h"
#include <stddef.h>
#include "Фигуры.h"
#include "Функции (для плекса).h"

/*-----------------------------------------------------------------------------------------------*/
										//***** class TObject *****//
TObject::TObject(){
	
}

bool TObject::IsPoint(){
	return false;
}

/*-----------------------------------------------------------------------------------------------*/
										//***** class TPoint *****//
TPoint::TPoint(){
	this->X = 0;
	this->Y = 0;
	this->Number = 999;
}

TPoint::TPoint(int X, int Y, int Number){
	this->X = X;
	this->Y = Y;
	this->Number = Number;
}

void TPoint::Initialize(int X, int Y){
	this->X = X;
	this->Y = Y;
}

void TPoint::Initialize(int X, int Y, int Number){
	this->X = X;
	this->Y = Y;
	this->Number = Number;
}

int TPoint::GetX(){
	return this->X;
}

int TPoint::GetY(){
	return this->Y;
}

TObject* TPoint::Show(System::Drawing::Graphics ^GraphicPanel, int RedNumber){
	bool IsRed;
	if (this->Number == RedNumber){
		IsRed = true;
	}else{
		IsRed = false;
	}
	DrawPoint(X, Y, GraphicPanel, IsRed);
	return this;
}

bool TPoint::IsPoint(){
	return true;
}

/*-----------------------------------------------------------------------------------------------*/
										//***** class TLine *****//
TLine::TLine(TObject *P1, TObject *P2){
	this->P1 = P1;
	this->P2 = P2;
	IsVisible = true;
}

TLine::TLine(TObject *P1, TObject *P2, bool IsVisible){
	this->P1 = P1;
	this->P2 = P2;
	this->IsVisible = IsVisible;
}

void TLine::Delete(){
	this->IsVisible = false;
}

TObject* TLine::Show(System::Drawing::Graphics ^GraphicPanel, int RedNumber){
	bool IsRed;
	TPoint *Left;
	TPoint *Right;
	Left  = (TPoint*) P1->Show(GraphicPanel, RedNumber);
	Right = (TPoint*) P2->Show(GraphicPanel, RedNumber);
	if ((Left->Number == RedNumber) || (Right->Number == RedNumber)){
		IsRed = true;
	}else{
		IsRed = false;
	}
	DrawLine(Left, Right, GraphicPanel, IsVisible, IsRed);
	return Right;
}

bool TLine::IsTLine(){
	return true;
}

bool TLine::IsTCircle(){
	return false;
}

bool TLine::IsTRect(){
	return false;
}

/*-----------------------------------------------------------------------------------------------*/
										//***** class TCircle *****//

TObject* TCircle::Show(System::Drawing::Graphics ^GraphicPanel, int RedNumber){
	bool IsRed;
	TPoint *Left;
	TPoint *Right;
	Left  = (TPoint*) P1->Show(GraphicPanel, RedNumber);
	Right = (TPoint*) P2->Show(GraphicPanel, RedNumber);
	if ((Left->Number == RedNumber) || (Right->Number == RedNumber)){
		IsRed = true;
	}else{
		IsRed = false;
	}
	DrawCircle(Left, Right, GraphicPanel, IsVisible, IsRed);
	return Right;
}

bool TCircle::IsTLine(){
	return false;
}

bool TCircle::IsTCircle(){
	return true;
}

/*-----------------------------------------------------------------------------------------------*/
										//***** class TRect *****//

TObject* TRect::Show(System::Drawing::Graphics ^GraphicPanel, int RedNumber){
	bool IsRed;
	TPoint *Left;
	TPoint *Right;
	Left  = (TPoint*) P1->Show(GraphicPanel, RedNumber);
	Right = (TPoint*) P2->Show(GraphicPanel, RedNumber);
	if ((Left->Number == RedNumber) || (Right->Number == RedNumber)){
		IsRed = true;
	}else{
		IsRed = false;
	}
	DrawRect(Left, Right, GraphicPanel, IsVisible, IsRed);
	return Right;
}

bool TRect::IsTLine(){
	return false;
}

bool TRect::IsTRect(){
	return true;
}

/*-----------------------------------------------------------------------------------------------*/
										//***** class TPlex *****//

TPlex::TPlex(){
	this->Head = NULL;
}

TPlex::TPlex(TLine *L1){
	this->Head = L1;
}


TObject* TPlex::GetHead(){
	return this->Head;
}

void TPlex::Create(TLine *L1){
	if (L1 != NULL){
		TLine *L2 = SearchTLineForAdd((TPoint*) L1->P2);
		if (this->Head == NULL){
			this->Head = L1;
		}else{
			if (SideOfTLineForAdd(L2, (TPoint*) L1->P2)){
				L2->P1 = L1;
			}else{
				L2->P2 = L1;
			}
		}
	}
}

void TPlex::PaintPlex(System::Drawing::Graphics ^GraphicPanel, int RedNumber){
	GraphicPanel->Clear(System::Drawing::Color::White);
	if (this->GetHead() != NULL){
		this->Head->Show(GraphicPanel, RedNumber);
	}
}

TLine* TPlex::SearchTLineForAdd(TPoint *Psearch){
	TLine *O1 = NULL;
	O1 = SearchTLineForAddRecursion(this->Head, Psearch);
	if (O1 != NULL){
		return O1;
	}
	return NULL;

}

bool TPlex::SideOfTLineForAdd(TLine *L1, TPoint *Psearch){
	// TRUE - левый потомок
	// FALSE  - правый потомок
	if (L1 != NULL){
		if ( L1->P1 == Psearch)
			return (true);
		if ( L1->P2 == Psearch)
			return (false);
	}
	return NULL;
}

void TPlex::Delete(int Pi1, int Pi2, int WhatObjectIsSelect){
	if (this->GetHead() != NULL){
		DeleteRecursion(this->Head, Pi1, Pi2, WhatObjectIsSelect);
	}

}



