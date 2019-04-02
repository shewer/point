/*
 * point.h
 * Copyright (C) 2019 Shewer Lu <shewer@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef POINT_H
#define POINT_H


#include <stdio.h>



#define C_08 "ch= *ptr ; *ptr +=1 ;"
#define C_0A "*ptr +=1; ch=*ptr ;"
#define C_15 "ptr++ ;  ch=*ptr ; *ptr+=1; "
#define C_17 "ch=*ptr ; *ptr+=1 ;ptr++ ;"
#define C_18 "ch=*ptr ; *ptr+=1 ;ptr++ ;"
#define C_1A "*ptr +=1; ch=*ptr ; ptr++ ;"
#define C_1C "ch= *ptr; ptr++;"
#define C_1D "ptr++ ; ch=*ptr ;"
#define C_FF "error code "

#define C_FF_F 0
#define C_08_F 1
#define C_15_F 2
#define C_17_F 3 
#define C_18_F 4 
#define C_0A_F 5 
#define C_1A_F 6 
#define C_1C_F 7 
#define C_1D_F 8



#if defined(__CHK0__)
	#define _Eval(a,b)  Chk_Eval(a,b)
#elif defined( __CHK1__ )
	#define _Eval(a,b) _Eval_(a,b)
#elif defined( __CHK2__ )
	#define _Eval(a,b) __Eval_(a)
#else 
    #define _Eval(a,b) __Eval_(a)
#endif

//#define _Eval(a,b)  _Eval_(a,b)
//#define _Eval(a,b)  __Eval_( a )
// #define _Eval(a,b)  Chk_Eval( a,b )

#define _init() {\
	ptr=string ;\
	ch='_';\
	for( int i=0;  i < 5;i++){\
		string[i]= string1[i]; \
	};\
}

// _Eval  inline init() ; a ; printout()
#define _Eval_(a,b) _init() ;\
	a;\
	printout("After " #a  "  : " #b ,ch,ptr )

// _Eval  inline init() ; a ; printout()
#define __Eval_( a ) \
	init(&ch,&ptr) ;\
	a;\
	printout("After " #a,ch,ptr )
// compare  _Eval(a,b)  __Eval(a)
#define Chk_Eval(a,b)  \
	printf("==== check eval start ======( " #a " )===\n");\
	_Eval_(a,b); \
	__Eval_(a); \
	printf("==== check eval end ======\n");

extern const char *info[];
extern char string[6];
extern char bit_str[];
extern const char string1[6];

extern void printout(const char *,const char ,const char *);
extern int chk_ch(const char ch ,const char *str,const char* str1) ;
extern int chk_ptr(const char *p,const char *str,const char *str1); 
extern int chk_code(char c,const char *p,const char *str, const char *str1);

extern void init(char *c,char ** p);
extern const char * info_str(int code);
extern char * bbit_str(int flag,char *str) ;

extern const char * info_str(int code);

#endif /* !POINT_H */
