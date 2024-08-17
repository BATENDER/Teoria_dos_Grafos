#include <stdio.h>

int main() {
    int i, j, linhas;

    printf("Digite a altura da piramide : ");
    scanf("%d", &linhas);
    printf("\n");

    for (i = 1; i <= linhas; i++) {
        for (j = linhas - i; j >= 1; j--)
            printf(" ");
        for (j = 1; j <= i; j++)
            printf("*");
        printf("\n");
    }
    
    return 0;
}