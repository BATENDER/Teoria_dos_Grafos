#include <stdio.h>

int main() {
    int i, j, linhas;

    printf("Digite o tamanho do triangulo : ");
    scanf("%d", &linhas);
    printf("\n");

    for (i = 1; i <= linhas; i++) {
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}