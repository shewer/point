/*
 * point.c
 * Copyright (C) 2019 Shewer Lu <shewer@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include "point.h"
//#include <stdio.h>

const char *info[]={
	C_FF ,
	C_08 ,
	C_0A ,
	C_15 ,
	C_17 ,
	C_18 ,
	C_1A ,
	C_1C ,
	C_1D 
	
};

char string[6]="AbCdE";
char bit_str[]="00000000";
const char string1[6]="AbCdE";

/*
 *void printout(char *, char , char *);
 *int chk_ch(const char ch ,const char *str,const char* str1) ;
 *int chk_ptr(const char *p,const char *str,const char *str1); 
 *int chk_code(char c,const char *p,const char *str, const char *str1);
 *
 *void init(char *c,char ** p);
 *const char * info_str(int code);
 *char * bbit_str(int flag,char *str) ;
 *const char * info_str(int code);
 *
 */
void init(char *c,char ** p)
{
	*p=string ;
	*c='_';
	for( int i=0;  i < 5;i++){
		string[i]= string1[i]; 
	};
}
void printout(const char *str,const char ch,const char *ptr) {
	printf("------ %s ------\n",str );
	printf( "ch:'%c' ptr:%s ,string:%s\n",ch,ptr,string);
	printf("ptr:\t%p\nstring:\t%p\n\n",ptr,string);
	int ch_code =chk_ch(ch,string,string1);
	int p_code =chk_ptr(ptr,string,string1);
	int code= p_code | ch_code ;
	printf("code: 0x%02x  ch: 0x%02x | ptr: 0x%02x \n",code, ch_code,p_code);
	printf("info: %s\n",info_str(code) );

}

void print_status()
{
/*
	printout("After " #a,ch,ptr );
	printf("ch:  0x%02x \t", chk_ch(ch,string,string1) ); 
	printf("ptr: 0x%02x \t", chk_ptr(ptr,string,string1) );
	printf( "bit: %s \n", bbit_str( chk_ch(ch,string,string1) | chk_ptr(ptr,string,string1), bit_str) );
	ddprintf("info: %s\n", (b) ); 
*/
}

// ch flap  b1b0   3~0
int chk_ch(const char ch ,const char *str,const char* str1) 
{
	if (ch == *( str1 +0) ) 
		return 0; 
	else if ( ch == *( str1+1) )
		return 1;
	else if (ch == *( str + 0) ) 
		return 2;
	else if (ch == *( str + 1) )
		return 3;
	else return -1;
	

}
int chk_code(char c,const char *p,const char *str, const char *str1)
{
	return chk_ptr(p,str,str1) | chk_ch(c,str,str1);
}

int chk_ptr(const char *p,const char *str,const char *str1) 
{
	int pp=0;
	if ( p - str )  pp |=  1<<4;
	if (str[0] == str1[0]) pp|= 1<<2;
	if (str[1] == str1[1]) pp|= 1<<3;
	return pp;


}

char * bbit_str(int flag,char *str) 
{
	printf("flag: 0x%02x\n" ,flag);
	for(int i=0 ; i<8;i++) 
		str[8-1-i]=	(flag & 1<<i ) ?  '1' : '0';
    return str;

}
void _eval() {


}
const char * info_str(int code)
{
	switch (code) {
		case 0x08:  return  info[C_08_F];
		case 0x0A:  return  info[C_0A_F];
		case 0x15:  return  info[C_15_F];
		case 0x17:  return  info[C_17_F];
		case 0x18:  return  info[C_18_F];
		case 0x1A:  return  info[C_1A_F];
		case 0x1C:  return  info[C_1C_F];
		case 0x1D:  return  info[C_1D_F];
		default: 
					return info[C_FF_F];


	}
}

