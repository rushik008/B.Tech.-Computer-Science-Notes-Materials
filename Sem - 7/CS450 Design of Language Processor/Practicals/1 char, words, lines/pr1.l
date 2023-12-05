%{
#include <stdio.h>
int lc = 0, wc = 0, cc = 0;
%}

%%
\n      { lc++; }
[ \t]+  { }
.       { wc++; }
%%

int main(int argc, char* argv[]) {
    printf("Enter the input:\n");
    yylex();
    printf("The number of lines = %d\n", lc);
    printf("The number of words = %d\n", wc);
    printf("The number of characters = %d\n", wc + lc);  // Including line breaks in characters count
    return 0;
}

int yywrap() {
    return 1;
}
