#include <stdio.h>

int main() {
    int i, j, linha;

    printf("Digite a altura do triangulo : ");
    scanf("%d", &linha);

    printf("\n");

    for (i = 0; i <= linha; i++) {
        for (j = 0; j < i; j++)
            printf(" ");
        for (j = linha - i; j >= 1; j--)
            printf("*");
        printf("\n");
    }
    
    return 0;
}