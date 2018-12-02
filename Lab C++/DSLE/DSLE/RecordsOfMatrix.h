#pragma once

void PrintMatrix (double* A, double* B, int N);
void ManualInputMatrix (double* A, double* B, int N);
void RandomInputMatrix (double* A, double* B, int N);
void CopyMatrixA (double* A, double* B, int N);
void CopyMatrixB (double* A, double* B, int N);
void SearchTheMax (double* ACopy, int Column, int N, int& Index);
void ReplacementStrings (double* ACopy, double* BCopy, int Str1, int Str2, int* XIndex, int N);
void ReplacementColumn (double* ACopy, int Str1, int Str2, int N);
void ReplacementStringsKrammer (double* ACopy, double* BCopy, int Str1, int Str2, int N);
void CalcDetKrammer (double* ACopy, double* BCopy, double* Det, int Str1, int N);
void DivisionOfStringsDown (double* ACopy, double* BCopy, int N, int Str);
void DivisionOfStringsUp (double* ACopy, double* BCopy, int N, int Str);
void Gauss (double* A, double* B, double* ACopy, double* BCopy, double* X, double* XChanging, int* XIndex, int N);
void Kramer (double* A, double* B, double* ACopy, double* BCopy, double* X, int N);
