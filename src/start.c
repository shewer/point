/*
 * start.c
 * Copyright (C) 2019 Shewer Lu <shewer@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */
#define __CHK0__ 
#include "point.h"


void start() 
{
	char ch,*ptr;

	_Eval(ch= ++*++ptr,"ch=*ptr ; *ptr+=1 ;ptr++ ;" );

	_Eval(ch= (*(ptr++))++  ,"ch=*ptr ; *ptr+=1 ;ptr++ ;" );
	_Eval(ch= (*ptr++)++  ,"ch=*ptr ; *ptr+=1 ;ptr++ ;" );
}
