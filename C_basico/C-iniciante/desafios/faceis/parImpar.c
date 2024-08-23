#include <stdio.h>

/*
3. Verificação de Par ou Ímpar (Fácil)
Crie um programa que leia um número inteiro e verifique se ele é par ou ímpar, exibindo a mensagem correspondente.

Dica: Use o operador % para verificar o resto da divisão por 2.
*/

int main() {
    int num;

    printf("\n Digite o inteiro a ser verificado : ");
    scanf("%d", &num);

    if ((num % 2) == 0)
        printf("\n\n O numero %d eh PAR! \n", num);
    else
        printf("\n\n O numero %d eh IMPAR! \n", num);
        

    return 0;
}