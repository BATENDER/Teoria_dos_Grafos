#include <stdio.h>
#include <stdlib.h>

int main() {
    int i = 0;
    char string[] = "*"
                    "**"
                    "***"
                    "****"
                    "*****";

    printf("\nTamanho do vetor : %lu\n\n", sizeof(string));
    printf("Tamanho da string : %d\n\n", strlen(string));

    while (i <= strlen(string)) {
        printf("%c\n", string[i]);
    }
    
    return 0;
}