/*
 * chk_point.c
 * Copyright (C) 2019 Shewer Lu <shewer@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */
#define __CHK2__ 

#include "point.h"

int main(int argc, char *argv[])
{

	char ch,*ptr;
	/*
	// tert  ch=++*ptr  ==> *ptr+=1 ; ch=*ptr ; --(4);
	init();
	ch= ++*ptr;
	printout("after ch=++*ptr",ch,ptr);

	// tert  ch=++*ptr++  ==> *ptr+=1 ; ch=*ptr ; --(4);
	init();
	ch= ++*ptr++;
	printout("after ch=++*ptr++ ",ch,ptr);
	// tert  ch=++*ptr  ==> *ptr+=1 ; ch=*ptr ; --(4);
	init();
	ch= ++*ptr; ptr++;
	printout("after ch=++*ptr;ptr++ ",ch,ptr);

	// tert  ch=++(*ptr)++)  ==> *ptr+=1 ; ch=*ptr ; --(4);
	init();
	ch= ++(*ptr++);// ptr++;   
	printout("after ch=++(*ptr++) ",ch,ptr);

	// tert  ch=++(*ptr)++)  ==> *ptr+=1 ; ch=*ptr ; --(4);
	init();
	ch= (*++ptr)++;// ptr++;   
	printout("after ch=(*++ptr)++ ",ch,ptr);

	init();
	ch=(*ptr++);
	printout("after ch=(*ptr++) ",ch,ptr);
	init();
	ch=(*ptr++)++;
	printout("after ch=(*ptr++)++ ",ch,ptr);
	*/
	printf("-------======== macro eval \n");
	_init();
	printout("init ch ptr ", ch,ptr);


	_Eval(ch = *ptr++ , "ch= *ptr; ptr++;" );
	_Eval(ch = (*ptr++ ),"");
	_Eval(ch = (*(ptr)++),"" );
	_Eval(ch = *(ptr++),"" );

	_Eval(ch = (*ptr)++,"ch= *ptr ; *ptr +=1;"  );
	/*_Eval(ch = (*ptr)++ +10,"" );*/

	_Eval(ch = *++ptr,"ptr++ ; ch=*ptr; " );
	_Eval(ch = *(++ptr),"" );
	_Eval(ch = *++(ptr) ,"");

	_Eval(ch = ++*ptr ,"*ptr +=1; ch=*ptr;");
	_Eval(ch = ++(*ptr),"" );
	_Eval(ch = ++*(ptr) ,"");
	printf("------=== test ++*ptr++ \n");
	_Eval(ch = ++*ptr++ ,"*ptr +=1; ch=*ptr ; ptr++; ") ;
	_Eval(ch = ++(*ptr++) ,"") ;
	_Eval(ch = ++*(ptr++) ,"");
	// expression is not assignable   _Eval(ch = (++*ptr)++) );
	// expression is not assignable   _Eval(ch = ++(*ptr)++);
	
	_Eval(ch= (*++ptr)++ ,"ptr++ ;  ch=*ptr ; *ptr+=1; ");
	_Eval(ch= (*(++ptr))++  ,"" );
	_Eval(ch= (*(ptr++))++  ,"ch=*ptr ; *ptr+=1 ;ptr++ ;" );
	// expression is not assignable	_Eval(ch=   *++ptr++ )
	// expression is not assignable _Eval(ch= *(++ptr)++ )
	// expression is not assignable _Eval(ch= *++(ptr)++ )
	
	// expression is not assignable _Eval(ch= *++++ptr );
	// expression is not assignable _Eval(ch= *++(++ptr) );

	_Eval(ch= ++*++ptr,"ch=*ptr ; *ptr+=1 ;ptr++ ;" );
	_Eval(ch= ++*(++ptr),"" );
	_Eval(ch= ++(*++ptr) ,"");
	_Eval(ch= ++(*(++ptr)),"" );

	_Eval(ch= (*(ptr++))++  ,"ch=*ptr ; *ptr+=1 ;ptr++ ;" );
	_Eval(ch= (*(ptr++))++  , "" );
	_Eval(ch= (*ptr++)++  ,"ch=*ptr ; *ptr+=1 ;ptr++ ;" );
    /*printf("  --- chack ch:%d\n ",chk_ch(ch,string,string1));*/

//	__Eval_(ch= (*(ptr++))++   );
//	Chk_Eval(ch= ++*++ptr,"ch=*ptr ; *ptr+=1 ;ptr++ ;" );
//	Chk_Eval(ch= (*(ptr++))++  ,"ch=*ptr ; *ptr+=1 ;ptr++ ;" );
	return 0;
}



