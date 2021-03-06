#include "stdafx.h"
#include "Variable.h"
#include "GeorgeFunctions.h"
#include "Polynom.h"
#include "stddef.h"

Monom::Monom(){
	Alpha = 0;
	PowerNum = 0;
	Next = NULL;
}

Monom::Monom(double Alpha, int PowerNum){
	this->Alpha = Alpha;
	this->PowerNum = PowerNum;
	Next = NULL;
}

void Monom::InitializeMonom(char* C, int N, int Sign, Variable* Variables){	//Инициализировать моном и добавить его в начало списка мономов в полиноме
	this->Alpha = 0;
	this->PowerNum = 0;
	this->Next = NULL;
	int Start;		//Индекс начала числа
	int Len = 1;	//Длина числа
	int J, K;
	char Let;		//Переменная в мономе
	char* H = new char[N];	//Массив ЧАРОВ, в кот. будет записано вырезанное char* C из число
	int Comma = -1;			//местоположение запятой в числе
	for (int I=0; I<N; I++){	//Проходим по всем символам
		if (C[0]<48 || C[0]>57){
			Alpha = 1;
		}
		if (C[I]>47 && C[I]<58){	//Символ - это цифра?
			Len = 1;		//Длина цифры равна единице
			Start = I;		//Запоминаем, где начало числа
			Comma = -1;		//В цифре запятых нет
			while ((C[I+1]>47 && C[I+1]<58) || (C[I+1] == 44)){	//Начинаем искать число, следующий символ - это цифра, а может запятая?
				Len++;		//Если следующий символ входит в число, то увеличиваем длину числа
				I++;		//Этот символ уже был просмотрен, берём следующий
			}
			K = 0;		//Показывает в какой индекс из Н записать след. символ из С
			for (J=0; J<Len; J++){		//Копируем число
				if (C[Start+J] != 44){		//Если символ - не запятая
					H[K] = C[Start+J];	//Копируем
					K++;			//Сюда записали, следующий символ запишем в следующий индекс из Н
				}else{				//Если символ - запятая
					Comma = K - 1;	//Определив положение запятой в числе, укажем в каком индексе нулевой разряд числа
				}
			}
			Len = K;		//Новая длина числа(без запятой)
			if (Comma == -1){		//Если мы так и не нашли запятую в числе, то...
				Comma = Len - 1;	//...нулевой разряд имеет последняя цифра
			}
			for (J=0; J<Len; J++){	//Подсчитываем коэффициэнт
				Alpha += (H[J] - 48) * PowIntOnInt(10, Comma - J);
			}
			I++;				//Число уже вырезано, перейдём с следующему индексу
		}

		if (C[I]>96 && C[I]<123){	//Символ - это буква?
			Let = C[I];			//Запоминаем эту переменную
			if (C[I+1] == '['){		//Если эта переменная возведена в степень
				I = I + 2;		//"Перепрыгиваем" через скобку (показатель степени)
				Start = I;		//Сохраняем положение начала числа
				Len = 1;		//Длина числа
				while (C[I+1] != ']'){		//Пока не встретим конец показателя степени
					Len++;		//Увеличиваем длину числа
					I++;		//Переходим на следующую цифру
				}
				K = 0;		//Сюда будем записывать число, обозначающее степень
				for (J=0; J<Len; J++){	//По-очереди... 
					H[J] = C[Start+J];
					K += (H[J] - 48) * PowIntOnInt(10, Len - J - 1);	//...прибавляем к "К" все разряды 
				}
				I++;		//"Перепрыгиваем" на следующий символ	
			}else{		//Если показателя, в какую степень возводим переменную нет, то...
				K = 1;		//...считаем, что переменная в возведена в первую степень
			}			//Прибавляем к свёртке число по алгаритму, данным Козиновым ↓
			PowerNum += K * PowIntOnInt(Variables->GetMaxPowerAll()+1, Variables->GetNumberOfLetter(Let));
		}
	}
	Alpha = Alpha * Sign;		//Не забываем про знак коэффициента
}

Polynom::Polynom(){
	this->First = NULL;
	this->Next = NULL;
}


Polynom::Polynom(char* C, int N, int Sign, Variable* Variables){
	Monom *M1 = new Monom;
	M1->InitializeMonom(C, N, Sign, Variables);
	First = M1;
	this->Next = NULL;
}


Polynom::Polynom(const Polynom & P){
	if(P.First != NULL){
		this->Next = NULL;
		this->First = new Monom(P.First->Alpha, P.First->PowerNum);
		Monom *IndexAnswer = this->First;		//Указатель на последний моном в this
		Monom *IndexP = P.First;			//Указатель для P
		while (IndexP->Next != NULL){		//Пока следующий моном существует...
			IndexAnswer->Next = new Monom(IndexP->Next->Alpha, IndexP->Next->PowerNum);		//..добавляем его
			IndexP = IndexP->Next;		//Переносим указатель
			IndexAnswer = IndexAnswer->Next;	//Переносим указатель
		}
	}
}

Polynom Polynom::operator+ (const Polynom &P){
	Polynom *Answer = new Polynom;	//Будующий ответ
	Monom *IndexAnswer;		//Указатель на последний моном в Answer (но изначально он указывает вникуда)
	Monom *IndexThis = this->First;		//Указатель на моном для this
	Monom *IndexP = P.First;			//Указатель на моном для P
	while ((IndexThis != NULL) && (IndexP != NULL)){	//Пока один из полиномов не кончится
		if (IndexThis->PowerNum < IndexP->PowerNum){	//(1) Если в первом полиноме первый моном меньше, чем во втором
			if (Answer->First == NULL){		//Если в Answer ещё нет мономов
				Answer->First = new Monom(IndexThis->Alpha, IndexThis->PowerNum);	//Добавить моном
				IndexAnswer = Answer->First;
				IndexThis = IndexThis->Next;
			}else{					//Если в Answer есть мономы
				IndexAnswer->Next = new Monom(IndexThis->Alpha, IndexThis->PowerNum);	//Добавить моном
				IndexAnswer = IndexAnswer->Next;
				IndexThis = IndexThis->Next;
			}
		}
		else if (IndexThis->PowerNum > IndexP->PowerNum){	//(2) Если во втором полиноме первый моном меньше, чем в первом
			if (Answer->First == NULL){		//Если в Answer ещё нет мономов
				Answer->First = new Monom(IndexP->Alpha, IndexP->PowerNum);	//Добавить моном
				IndexAnswer = Answer->First;
				IndexP = IndexP->Next;
			}else{					//Если в Answer есть мономы
				IndexAnswer->Next = new Monom(IndexP->Alpha, IndexP->PowerNum);	//Добавить моном
				IndexAnswer = IndexAnswer->Next;
				IndexP = IndexP->Next;
			}
		}
		else if (IndexThis->PowerNum == IndexP->PowerNum){	//(3) Если первые мономы обоих полиномов равны
			if (Answer->First == NULL){		//Если в Answer ещё нет мономов
				if(IndexThis->Alpha + IndexP->Alpha != 0){	//Если после сложения мономов должен остаться результат
					Answer->First = new Monom(IndexThis->Alpha + IndexP->Alpha, IndexThis->PowerNum);	//Добавить моном
					IndexAnswer = Answer->First;
				}
			}else{				//Если в Answer есть мономы
				if(IndexThis->Alpha + IndexP->Alpha != 0){	//Если после сложения мономов должен остаться результат
					IndexAnswer->Next = new Monom(IndexThis->Alpha + IndexP->Alpha, IndexThis->PowerNum);	//Добавить моном
					IndexAnswer = IndexAnswer->Next;
				}
			}
			IndexThis = IndexThis->Next;
			IndexP = IndexP->Next;
		}
	}
	//Когда один из полиномов закончился, скопируем другой:
	while (IndexThis != NULL){	//Если закончился полином "P", то копируем полином "This"
		IndexAnswer->Next = new Monom(IndexThis->Alpha, IndexThis->PowerNum);	//Добавить моном
		IndexAnswer = IndexAnswer->Next;
		IndexThis = IndexThis->Next;
	}
	while (IndexP != NULL){		//Если закончился полином "This", то копируем полином "P"
		IndexAnswer->Next = new Monom(IndexP->Alpha, IndexP->PowerNum);	//Добавить моном
		IndexAnswer = IndexAnswer->Next;
		IndexP = IndexP->Next;
	}

	return *Answer;
}

Polynom Polynom::operator* (const Polynom &P){
	//***(1) Перемножаем полиномы
	Polynom *Answer = new Polynom;	//Промежуточный ответ
	Monom *IndexAnswer;		//Указатель на последний моном в Answer (но изначально он указывает вникуда)
	Monom *IndexThis = this->First;		//Указатель на моном для this
	Monom *IndexP = P.First;			//Указатель на моном для P
	while (IndexThis != NULL){
		IndexP = P.First;
		while (IndexP != NULL){
			if (Answer->First == NULL){
				Answer->First = new Monom(IndexThis->Alpha*IndexP->Alpha, IndexThis->PowerNum+IndexP->PowerNum);
				IndexAnswer = Answer->First;
			}else{
				IndexAnswer->Next = new Monom(IndexThis->Alpha*IndexP->Alpha, IndexThis->PowerNum+IndexP->PowerNum);
				IndexAnswer = IndexAnswer->Next;
			}
			IndexP = IndexP->Next;
		}
		IndexThis = IndexThis->Next;
	}

	//***(2) Сортируем полином
	Polynom *Sort = new Polynom;	//Будующий (отсортированный) ответ
	Monom *IndexSort;				//Указатель для Sort
	Monom *IndexSortLast;	//Предыдущий от IndexSort
	IndexAnswer = Answer->First;
	Monom *NewMonom;
	while (IndexAnswer != NULL){
		if (Sort->First == NULL){
			Sort->First = new Monom(Answer->First->Alpha, Answer->First->PowerNum);
		}else{
			while (IndexSort != NULL){
				if (IndexSort->PowerNum < IndexAnswer->PowerNum){
					IndexSortLast = IndexSort;
					IndexSort = IndexSort->Next;
				}else if(IndexSort->PowerNum > IndexAnswer->PowerNum){
					NewMonom = new Monom(IndexAnswer->Alpha, IndexAnswer->PowerNum);
					if (IndexSortLast == NULL){
						Sort->First = NewMonom;
						NewMonom->Next = IndexSort;
					}else{
						IndexSortLast->Next = NewMonom;
						NewMonom->Next = IndexSort;
					}
					break;
				}else if(IndexSort->PowerNum == IndexAnswer->PowerNum){
					if (IndexSort->Alpha + IndexAnswer->Alpha == 0){
						if (IndexSortLast == NULL){
							Sort->First = IndexSort->Next;
						}else{
							IndexSortLast->Next = IndexSort->Next;
						}
					}else{
						IndexSort->Alpha += IndexAnswer->Alpha;
					}
					break;
				}
			}
			if ((IndexSortLast != NULL) && (IndexSort == NULL)){
				NewMonom = new Monom(IndexAnswer->Alpha, IndexAnswer->PowerNum);
				IndexSortLast->Next = NewMonom;
			}
		}
		IndexSort = Sort->First;
		IndexSortLast = NULL;
		IndexAnswer = IndexAnswer->Next;
	}
	return *Sort;
}

Polynom Polynom::operator= (const Polynom &P){
	this->First = P.First;
	return *this;
}

