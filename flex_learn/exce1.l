%{
#include<stdio.h>

%}

digit [0-9]
number {digit}+
sign [+\-*/]
real {digit}"."{number}
%%

{real} {printf("REAL ");}
{number} {printf("NUM ");}
{sign} {printf("SIGN ");}
\( {printf("LPA ");}
\) {printf("RPA ");}

%%
int main(){
	yylex();
	return 0;
}

int yywrap(){
	return 1;
}