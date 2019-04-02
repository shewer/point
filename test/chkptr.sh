#! /bin/sh
#
# chkptr.sh
# Copyright (C) 2019 Shewer Lu <shewer@gmail.com>
#
# Distributed under terms of the MIT license.
#

FILE=/tmp/chkptr.c

FLAG=$1

T1=$2
#// cat <<EOM >$FILE
src="

#include \"point.h\"

#define $FLAG

int main(int argc,char *argv[])
{
	char ch,*ptr;
	_Eval(T2,\"\");
	return 0;
}
"
print $src 
#printf $src > $FILE

