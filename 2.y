%{
	#include <stdio.h>
	extern int yylex();
%}

%token A B

%%
	str:S'\n' {printf("Accepted\n");return 0;}
	S:A T B
	T: A T
	|;
%%

void main()
{
	printf("Enter the string:");
	yyparse();
}

int yyerror()
{
	printf("invalid\n");
	return 0;
}









