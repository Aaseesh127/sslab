%{
#include <stdio.h>
int comment=0;
%}

%%

"/*"[a-zA-Z0-9' '\n\t]+"*/" { comment++;}
"//".* {comment++;}

%%

int main()
{
	yyin = fopen("input.c","r");
	yyout = fopen("output.c","w");
	yylex();
	printf("No. of comment lines is %d\n",comment);
}
