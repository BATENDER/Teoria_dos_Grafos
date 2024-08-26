#include <stdio.h>

/*
7. Verificação de Número Primo (Difícil)
Crie um programa que verifique se um número inteiro positivo fornecido pelo usuário é primo.

Dica: Um número primo é divisível apenas por 1 e por ele mesmo. Use um loop para verificar as divisões.
*/

int main() {
    int numPrimo, numIgualUm, numIgualNum, i;

    printf("\n Digite um inteiro para descobrir se ele eh primo : ");
    scanf("%d", &numPrimo);

    if ((numPrimo == 0) || (numPrimo == 1)) {
        printf("\nNao sao numeros primos!\n");
    } else {
        for (i = 1; i <= numPrimo; i++) {
            if (((numPrimo / i) == numPrimo) && ((numPrimo / i) == 1))
                
        }
    }

    return 0;
}