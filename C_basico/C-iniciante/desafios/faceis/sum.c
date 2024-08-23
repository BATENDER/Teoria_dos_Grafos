#include <stdio.h>

/*
2. Soma de Dois Números (Fácil)
Escreva um programa que solicite ao usuário dois números inteiros e imprima a soma deles.

Dica: Use as funções scanf() e printf().
*/

int main() {
    int num1, num2;

    printf("Digite 2 numeros (num1 num2) : ");
    scanf("%d %d", &num1, &num2);

    printf("\n A soma dos numeros %d + %d = %d \n", num1, num2, num1+num2);
    
    return 0;
}