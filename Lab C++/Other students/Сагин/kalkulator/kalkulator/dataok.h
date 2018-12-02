#include "stdafx.h"
#pragma once
#define OK 0 //код, говорящий что объект is valid
#define ERR -1 //код, говорящий что с объектом произошла ошибка
;
class dataok{
protected:
	int ErrCode; //естественно код ошибки, который могут изменять потомки
public:
	dataok(); //при создании объекта код ошибки нулевой
	int GetErrCode(); //получаем код ошибки и делаем его равным нулю
};
