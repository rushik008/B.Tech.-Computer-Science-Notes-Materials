bin (0|1)+
char [A-Za-z]+
digit [0-9]
oct [0-7]
dec [0-9]*
float {digit}+("."{digit}+)
exp {digit}+("."{digit}+)?("E"("+"|"-")?{digit}+)?
hex [0-9a-fA-F]+

%%
{bin} {printf("\n %s= it is a binary number",yytext);}
{char} {printf("\n %s=it is a char",yytext);}
{oct} {printf("\n %s=it is a octal number",yytext);}
{digit} {printf("\n %s=it is a digit",yytext);}
{dec} {printf("\n %s=it is a decimal",yytext);}
{float} {printf("\n %s=it is a float",yytext);}
{exp} {printf("\n %s=it is a exp",yytext);}
{hex} {printf("\n %s=it is a hex",yytext);}
%%
int yywrap()
{
  return 1;
}
int main()
{
  printf("Enter the number=");
  yylex();
  return 0;
}
