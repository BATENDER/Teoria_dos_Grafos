#include <stdio.h>
#include <string.h>

int main() {
    char s1[81];
    char s2[81];

    strcpy(s1, "Uma cadeia de caracteres! ");
    printf("%sQue possui %ld caracteres!\n", s1, strlen(s1));

    strcpy(s2, s1);
    printf("As strings sao iguais? %d (1 - Sim/ 0 - Nao)\n", strcmp(s2, s1));

    printf("Concatenando s1 e s2: %s", strcat(s1, s2));
    
    return 0;
}