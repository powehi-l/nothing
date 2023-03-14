%{
#include<stdio.h>
int key = 0;
int mark = 0;
%}

key if|else|int|double|return
digit [0-9]
alpha [a-zA-Z]
mark {alpha}({alpha}|{digit}|"_")*

%%

{key} {printf("KEY ");++key;}
{mark} {printf("MARK ");++mark;}
\n {printf("\n");}
.

%%

int main(){
	yylex();
	printf("key = %d, mark = %d\n", key, mark);
	return 0;
}

int yywrap(){
	return 1;
}
