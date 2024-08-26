#include <stdio.h>

/*
6. Fatorial de um Número (Médio)
Escreva um programa que calcule e exiba o fatorial de um número inteiro fornecido pelo usuário.

Dica: Use um loop for ou while para realizar a multiplicação sucessiva.
*/

int main() {
    int num, i;
    int numFatorial = 1;

    printf("\nDigite um inteiro para saber seu fatorial : ");
    scanf("%d", &num);

    for (i = 1; i <= num; i++) {
        numFatorial *= i;
    }
    
    printf("\nO valor de %d! = %d", num, numFatorial);

    return 0;
}