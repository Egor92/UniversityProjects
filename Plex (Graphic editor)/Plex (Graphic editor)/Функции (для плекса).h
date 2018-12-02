void DrawPoint(int X, int Y, System::Drawing::Graphics ^GraphicPanel, bool IsRed);
void DrawLine(TPoint *P1, TPoint *P2, System::Drawing::Graphics ^GraphicPanel, bool IsVisible, bool IsRed);
void DrawCircle(TPoint *P1, TPoint *P2, System::Drawing::Graphics ^GraphicPanel, bool IsVisible, bool IsRed);
void DrawRect(TPoint *P1, TPoint *P2, System::Drawing::Graphics ^GraphicPanel, bool IsVisible, bool IsRed);
TLine* SearchTLineForAddRecursion(TLine *Obj, TPoint *Psearch);
TPoint* DeleteRecursion(TLine *Obj, int Pi1, int Pi2, int WhatObjectIsSelect);
