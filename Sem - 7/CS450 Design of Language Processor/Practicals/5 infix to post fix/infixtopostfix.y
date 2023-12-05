%{
/*** Auxiliary declarations section ***/
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include <ctype.h>  

int yylex(void);
int yyerror(const char* s);
/* Custom function to print an operator*/ void print_operator(char op);
/* Variable to keep track of the position of the number in the input */ int pos=0;
char p;
%}
/*** YACC Declarations section ***/
%token NUM
%left '+'
%left '*'
%%
/*** Rules Section ***/
start : expr '\n' {exit(1);}
;
expr: expr '+' expr {print_operator('+');}
| expr '*' expr {print_operator('*');}
| '(' expr ')'
| NUM {printf("%c ",p);}
;
%%

/*** Auxiliary functions section ***/

void print_operator(char c){ switch(c){
case '+' : printf("+ "); break;
case '*' : printf("* "); break;
}
return;
}
int yyerror(char const *s)
{
printf("yyerror %s",s);
return 0;
}
int yylex(){ char c;
c = getchar(); p=c; if(isdigit(c)){
pos++; return NUM;
}
else if(c == ' '){
yylex(); /*This is to ignore whitespaces in the input*/
}
else {
return c;
}
}

int main()
{
yyparse(); return 1;
}