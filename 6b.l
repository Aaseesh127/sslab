%{
#include <stdio.h>
#include "y.tab.h"

%}

%%

[+\-%/<>=]+ { printf("%s is a operator", yytext); return OP;}
[a-bA-Z_][a-zA-Z0-9]+ {return ID;}
"int"|"char"|"printf"|"scanf"|"while"|"do"|"switch"|"void"|"main" { printf("%s is a keyword \n",yytext); return KEY;}
[\t] ;

%%