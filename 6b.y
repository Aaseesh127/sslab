%{
#include <stdio.h>
extern int yylex();
extern FILE *yyin;
int id=0,key=0,op=0;
%}

%token KEY ID OP

%%

input: ID input {id++;}
     | KEY input {key++;}
     | OP input {op++;}
     | ID {id++;}
     | KEY {key++;}
     | OP {op++;}
%%

void main()
{
		printf("Printing the content of input.c and no. of its keyword, operator and id\n");
		yyin = fopen("input.c","r");
		yyparse();
		fclose(yyin);
		printf("keyword=%d and operator=%d and id=%d\n",key,op,id);
}

int yyerror()
{
		printf("invalid");
		return 0;
}
