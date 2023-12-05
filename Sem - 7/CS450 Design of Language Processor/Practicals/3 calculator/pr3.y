%{
#include<ctype.h>
#include<stdio.h>
#define YYSTYPE double
%}
%token NUM
%left '+' '-'  
%left '*' '/'
%%
S : S E '\n' { printf("Answer: %g \nEnter:\n", $2); }
| S '\n'
|
| error '\n' { yyerror("Error: Enter once more\n"); yyerrok; }

;
E : E '+' E { $$ = $1 + $3; }
| E'-'E { $$=$1-$3;}
| E'*'E {$$=$1*$3;}
| E'/'E {$$=$1/$3;}
| NUM
;
%%
#include "lex.yy.c"
int main()
{
printf("Enter the expression: ");
yyparse();
}
yyerror (char * s)
{
printf ("% s \n", s);
exit (1);
}
