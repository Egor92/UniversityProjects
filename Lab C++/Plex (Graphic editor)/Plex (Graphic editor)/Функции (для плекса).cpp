#pragma once
#include "stdafx.h"
#include <stddef.h>
#include "Фигуры.h"
#include "Функции (для плекса).h"
#include "math.h"

void DrawPoint(int X, int Y, System::Drawing::Graphics ^GraphicPanel, bool IsRed){
	System::Drawing::Color ^MyCol = gcnew System::Drawing::Color();  //Сорздаём цвет
	System::Drawing::Pen ^BlackPen = gcnew System::Drawing::Pen (MyCol->Black);  //Создаём карандаш
	GraphicPanel->DrawEllipse( BlackPen, X-4, Y-4, 7, 7 );
	System::Drawing::Brush ^BlueBrush = gcnew System::Drawing::SolidBrush(MyCol->RoyalBlue);
	System::Drawing::Brush ^RedBrush = gcnew System::Drawing::SolidBrush(MyCol->Red);
	if (IsRed){
		GraphicPanel->FillEllipse(RedBrush, X-4, Y-4, 7, 7 ); 
	}else{
		GraphicPanel->FillEllipse(BlueBrush, X-4, Y-4, 7, 7 ); 
	}
}

void DrawLine(TPoint *P1, TPoint *P2, System::Drawing::Graphics ^GraphicPanel, bool IsVisible, bool IsRed){
	if (IsVisible){
		System::Drawing::Color ^MyCol = gcnew System::Drawing::Color();  //Сорздаём цвет
		System::Drawing::Pen ^BlackPen = gcnew System::Drawing::Pen (MyCol->Black);  //Создаём карандаш
		System::Drawing::Pen ^RedPen = gcnew System::Drawing::Pen (MyCol->Red);  //Создаём карандаш
		if (IsRed){
			GraphicPanel->DrawLine( RedPen, P1->GetX(), P1->GetY(), P2->GetX(), P2->GetY());
		}else{
			GraphicPanel->DrawLine( BlackPen, P1->GetX(), P1->GetY(), P2->GetX(), P2->GetY());
		}
	}
}

void DrawCircle(TPoint *P1, TPoint *P2, System::Drawing::Graphics ^GraphicPanel, bool IsVisible, bool IsRed){
	if (IsVisible){
		System::Drawing::Color ^MyCol = gcnew System::Drawing::Color();  //Сорздаём цвет
		System::Drawing::Pen ^BlackPen = gcnew System::Drawing::Pen (MyCol->Black);  //Создаём карандаш
		System::Drawing::Pen ^RedPen = gcnew System::Drawing::Pen (MyCol->Red);  //Создаём карандаш
		int Radius = hypot( P2->GetX() - P1->GetX(), P2->GetY() - P1->GetY() );
		if (IsRed){
			GraphicPanel->DrawEllipse(  RedPen,
										P1->GetX() - Radius,
										P1->GetY() - Radius,
										2 * Radius,
										2 * Radius );
		}else{
			GraphicPanel->DrawEllipse(  BlackPen,
										P1->GetX() - Radius,
										P1->GetY() - Radius,
										2 * Radius,
										2 * Radius );
		}
	}
}

void DrawRect(TPoint *P1, TPoint *P2, System::Drawing::Graphics ^GraphicPanel, bool IsVisible, bool IsRed){
	if (IsVisible){
		System::Drawing::Color ^MyCol = gcnew System::Drawing::Color();  //Сорздаём цвет
		System::Drawing::Pen ^BlackPen = gcnew System::Drawing::Pen (MyCol->Black);  //Создаём карандаш
		System::Drawing::Pen ^RedPen = gcnew System::Drawing::Pen (MyCol->Red);  //Создаём карандаш
		if (IsRed){
			GraphicPanel->DrawLine( RedPen, P1->GetX(), P1->GetY(), P1->GetX(), P2->GetY());
			GraphicPanel->DrawLine( RedPen, P1->GetX(), P2->GetY(), P2->GetX(), P2->GetY());
			GraphicPanel->DrawLine( RedPen, P2->GetX(), P2->GetY(), P2->GetX(), P1->GetY());
			GraphicPanel->DrawLine( RedPen, P2->GetX(), P1->GetY(), P1->GetX(), P1->GetY());
		}else{
			GraphicPanel->DrawLine( BlackPen, P1->GetX(), P1->GetY(), P1->GetX(), P2->GetY());
			GraphicPanel->DrawLine( BlackPen, P1->GetX(), P2->GetY(), P2->GetX(), P2->GetY());
			GraphicPanel->DrawLine( BlackPen, P2->GetX(), P2->GetY(), P2->GetX(), P1->GetY());
			GraphicPanel->DrawLine( BlackPen, P2->GetX(), P1->GetY(), P1->GetX(), P1->GetY());
		}
	}
}

TLine* SearchTLineForAddRecursion(TLine *Obj, TPoint *Psearch){
	TLine *O1 = NULL;
	TLine *O2 = NULL;
	if (Obj->P1->IsPoint()){
		if (Obj->P1 == Psearch)
			return Obj;
	}else{
		O1 = SearchTLineForAddRecursion( (TLine*) Obj->P1, Psearch);
	}

	if (Obj->P2->IsPoint()){
		if (Obj->P2 == Psearch)
			return Obj;
	}else{
		O2 = SearchTLineForAddRecursion( (TLine*) Obj->P2, Psearch);
	}

	if (O1 != NULL){
		return O1;
	}
	if (O2 != NULL){
		return O2;
	}
	return NULL;

}

TPoint* DeleteRecursion(TLine *Obj, int Pi1, int Pi2, int WhatObjectIsSelect){
	TPoint *Left;
	TPoint *Right;
	if (Obj->P1->IsPoint()){
		Left = (TPoint*) Obj->P1;
	}else{
		Left = DeleteRecursion( (TLine*) Obj->P1, Pi1, Pi2, WhatObjectIsSelect);
	}
	if (Obj->P2->IsPoint()){
		Right = (TPoint*) Obj->P2;
	}else{
		Right = DeleteRecursion( (TLine*) Obj->P2, Pi1, Pi2, WhatObjectIsSelect);
	}

	if ((WhatObjectIsSelect == 1) && (Obj->IsTLine())){
		if ( ((Left->Number == Pi1) && (Right->Number == Pi2)) || ((Left->Number == Pi2) && (Right->Number == Pi1)) ){
			Obj->Delete();
		}
	}

	if ((WhatObjectIsSelect == 2) && (Obj->IsTCircle())){
		if ((Left->Number == Pi1) && (Right->Number == Pi2)){
			Obj->Delete();
		}
	}

	if ((WhatObjectIsSelect == 3) && (Obj->IsTRect())){
		if ( ((Left->Number == Pi1) && (Right->Number == Pi2)) || ((Left->Number == Pi2) && (Right->Number == Pi1)) ){
			Obj->Delete();
		}
	}

	return Right;

}

