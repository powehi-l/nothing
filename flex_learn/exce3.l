%{
#include<stdio.h>
int status;
char name[10];

int int_value = 0;
double dou_value = 0;

%}

type int|double
digit [0-9]
alpha [a-zA-Z]
mark {alpha}({alpha}|{digit}|"_")*
integer [1-9]digit*|0
real {integer}\.[0-9]+

%%
{type} {
	if(yytext[0] == 'i') status = 0;
	else status = 1;
}

{mark} {strcpy(name, yytext, yyleng)}
{integer} {
	if(status == 0) sscanf(yytext, %d, &int_value);
	else sscanf(yytext, %lf, &dou_value);
}

{}

%%

int main(){
	yylex();
	printf("key = %d, mark = %d\n", key, mark);
	return 0;
}

int yywrap(){
	return 1;
}
