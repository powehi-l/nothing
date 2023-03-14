%{
int ch = 0;
int word = 0;
int line_number = 0;
%}

WORD [a-zA-Z0-9]+

%%

{WORD} {
	++word;
	ch+=yyleng;
}

\n {line_number++;}
. {ch++;}


%%
int main(){
	yylex();
	printf("words = %d, chars = %d, lines = %d\n", word, ch, line_number);
	return 0;
}

int yywrap(){
	return 1;
}
