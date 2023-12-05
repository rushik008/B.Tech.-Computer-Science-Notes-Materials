#include <stdio.h>
#include <stdbool.h>
#include <string.h>


bool isKeyword(char* str)
{
    if (!strcmp(str, "if") || !strcmp(str, "else") ||
        !strcmp(str, "while") || !strcmp(str, "do") ||
        !strcmp(str, "break") ||
         !strcmp(str, "continue") || !strcmp(str, "int")
        || !strcmp(str, "double") || !strcmp(str, "float")
        || !strcmp(str, "return") || !strcmp(str, "char")
        || !strcmp(str, "case") || !strcmp(str, "char")
        || !strcmp(str, "sizeof") || !strcmp(str, "long")
        || !strcmp(str, "short") || !strcmp(str, "typedef")
        || !strcmp(str, "switch") || !strcmp(str, "unsigned")
        || !strcmp(str, "void") || !strcmp(str, "static")
        || !strcmp(str, "struct") || !strcmp(str, "goto"))
        return (true);
    return (false);
}

bool isAlphabet(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '_');
}

bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}

int main() {
    char input[1000];
    printf("Enter input text: ");
    fgets(input, sizeof(input), stdin);

    char token[100];
    int tokenIndex = 0;

    printf("Keywords and Identifiers:\n");

    for (int i = 0; i < strlen(input); i++) {
        char currentChar = input[i];
        if (isAlphabet(currentChar) || isDigit(currentChar)) {
            token[tokenIndex++] = currentChar;
        } else {
            if (tokenIndex > 0) {
                token[tokenIndex] = '\0'; // Null-terminate the token
                if (isKeyword(token)) {
                    printf("Keyword: %s\n", token);
                } else {
                    printf("Identifier: %s\n", token);
                }
                tokenIndex = 0; // Reset the token index
            }
        }
    }

    return 0;
}
