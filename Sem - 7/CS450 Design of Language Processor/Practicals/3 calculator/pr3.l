DIGIT [0-9]
%option noyywrap
%%
{DIGIT} { yylval=atof(yytext); return NUM;}
\n|. {return yytext[0];}
