%{
	#include <stdio.h>
	extern int yylex();
%}

%token id
%left '+' '-'
%left '*' '/'

%%
exp:E{ printf("Result=%d\n",$1);}

E:E'+'E {$$=$1+$3;}
 |E'-'E {$$=$1-$3;}
 |E'*'E {$$=$1*$3;}
 |E'/'E {$$=$1/$3;}
 |'('E')' {$$=$2;}
 |id {$$=$1;}
%%
int main()
{
	printf("Enter expression:");
	yyparse();
    printf("\nValid Expression");
}

int yyerror()
{
printf("invalid");
return 0;
}
