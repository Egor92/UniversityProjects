#include "stdafx.h"
#include "GeorgeFunctions.h"
#include "Variable.h"
#include "stddef.h"

Link::Link(){
	Letter = NULL;
	Value = 0;
	MaxPower = 1;
	Next = NULL;
}

Link::Link(char Letter, double Value, int MaxPower){
	this->Letter = Letter;
	this->Value = Value;
	this->MaxPower = MaxPower;
	Next = NULL;
}

Variable::Variable(){
	First = NULL;
}

void Variable::Add (char Let){		//Добавить переменную
	Link *V1 = First;		//Указатель на конец списка
	Link *V2 = new Link;	//Звено с новой переменной
	V2->Letter = Let;		//Даём новой переменной имя (содержиться в Let)
	V2->Value = 0;			//Даём новой переменной значение (по стандарту)
	V2->MaxPower = 1;		//Переменная ещё не возведена нивкакую степень
	if (First == NULL){		//Если переменных ещё нет
		First = V2;			//Добавляем новую переменную
		First->Next = NULL;	//Показываем, что больше переменных нет
	}else{							//Если переменные уже есть
		while (V1->Next != NULL){	//Ищем конец списка
			V1 = V1->Next;
		}
		V1->Next = V2;				//Вставляем новую переменную в конец списка
		V2->Next = NULL;			//Показываем, что больше переменных нет
	}
}

void Variable::Delete (char Let){		//Удалить переменную
	Link *V1 = First;	//Звено после удаляемой переменной
	Link *V2 = V1;		//Звено перед удаляемой переменной
	if (First != NULL){		//Если переменные вообще есть
		while ((V1->Letter != Let) && (V1->Next != NULL)){		//Перебираем все переменные, пока не найдём переменную с именем Let либо не наткнёмся на конец списка
			V2 = V1;			//Сохраним указатель на предыдущее звено, чтобы его не потерять
			V1 = V1->Next;
		}
		if ((V1 == First) && (V1->Letter == Let)){	//Если переменная, кот. нам надо удалить стоит первой в списке, то...
			First = First->Next;	//...удаляем
		}
		else if (V1->Letter == Let){		//Нашли ли мы переменную с именем Let?
			V2->Next = V1->Next;	//Если нашли, то удаляем её
		}
	}
}

void Variable::DeleteAll (){	//Удалить все переменные
	First = NULL;
}

void Variable::ReWriteValue (int N, double Val){	//Переписать значение переменной
	Link *V1 = First;
	for (int I=0; I<N; I++){	//Доходим до переменной, находящейся на N-ном месте в списке
		V1 = V1->Next;
	}
	V1->Value = Val;
}

char Variable::GetLetter (int N){		//Получить имя переменной по номеру
	Link *V1 = First;
	for (int I=0; I<N; I++){	//Доходим до переменной, находящейся на N-ном месте в списке
		V1 = V1->Next;
	}
	return V1->Letter;
}

double Variable::GetValueOfLetter (char Let){		//Получить значение переменной
	Link *V1 = First;
	while (V1->Letter != Let){	//Перебираем все переменные, пока не найдём переменную с именем Let
		V1 = V1->Next;
	}
	return V1->Value;
}

double Variable::GetValueByNumber (int N){		//Получить значение переменной по номеру
	Link *V1 = First;
	for (int I=0; I<N; I++){	//Доходим до переменной, находящейся на N-ном месте в списке
		V1 = V1->Next;
	}
	return V1->Value;
}

int Variable::GetNumberOfLetter (char Let){		//Получить номер переменной в списке
	int I = 0;	//Положение переменной с именем Let в списке
	Link *V1 = First;
	while (V1->Letter != Let){
		V1 = V1->Next;
		I++;
	}
	return I;
}

int Variable::GetMaxPower (int N){		//Получить максимальную степень переменной
	Link *V1 = First;
	for (int I=0; I<N; I++){	//Доходим до переменной, находящейся на N-ном месте в списке
		V1 = V1->Next;
	}
	return V1->MaxPower;
}

int Variable::GetMaxPowerAll (){				//Получить максимальную степень среди всех переменных
	Link *V1 = First;
	int Power = 0;
	while (V1->Next != NULL){
		if (Power < V1->MaxPower){
			Power = V1->MaxPower;
		}
		V1 = V1->Next;
	}
	return Power;
}

void Variable::ReWriteMaxPower (char Let, int Power){	//Переписать максимальную степень переменной
	Link *V1 = First;
	while (V1->Letter != Let){
		V1 = V1->Next;
	}
	V1->MaxPower += Power;
}

bool Variable::HaveLetter(char Let){			//В наличии ли переменная
	Link *V1 = this->First;
	bool Have = false;
	if (V1 != NULL){
		while (V1 != NULL){
			if (V1->Letter == Let){
				Have = true;
			}
			V1 = V1->Next;
		}
	}
	return Have;
}