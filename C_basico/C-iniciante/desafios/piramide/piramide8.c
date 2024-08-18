#include <stdio.h>

int main() {
    int i, j, linha;

    printf("Digite a altura do triangulo : ");
    scanf("%d", &linha);

    printf("\n");

    for (i = 1; i <= linha; i++) {
        for (j = linha - i; j >= 1; j--)
            printf(" ");
        for (j = 1; j <= i; j++)
            printf("*");
        
        printf(" ");

        for (j = 1; j <= i; j++)
            printf("*");
        for (j = linha - i; j >= 1; j--)
            printf(" ");

        printf("\n");
    }
    
    return 0;
}