%{
    #include <stdio.h>
    int operand = 0, operator = 0, bracket = 0;
%}

%%
[A-Za-z0-9] {operand++;}
[+]         {operator++;}
[*]         {operator++;}
[(]         {bracket++;}
[)]         {bracket--;}
.           ;
%%

int main() {
    printf("enter the expression : ");
    yylex();
    if(operator >= operand || bracket != 0 || operand==1) 
        printf("invalid expression");

    else 
        printf("The expression is valid\n");

    printf("The no. of operators:%d\n",operator);
    printf("The no. of operand:%d\n",operand);
           
  
}
