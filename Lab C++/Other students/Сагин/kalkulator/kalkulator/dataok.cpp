#pragma once
#include "stdafx.h"
#include "dataok.h"

dataok::dataok(){
	ErrCode=0; //при создании объекта код ошибки нулевой
}
int dataok::GetErrCode(){ 
		int tmp=ErrCode; ErrCode=OK; 
		return tmp; //получаем код ошибки и делаем его равным нулю
}

;