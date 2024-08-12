#include <stdio.h>
#include <limits.h> // Define valores mínimos e máximos para o inteiro
#include <float.h> // Define valores mínimos e máximos para o ponto flutuante

int main() {
    // Tamanho e intervalo de um tipo char
    printf("O char ocupa %lu byte(s) e vai de %d a %d!\n", sizeof(char), CHAR_MIN, CHAR_MAX);

    // Tamanho e intervado de um tipo inteiro
    printf("O inteiro ocupa %lu bytes e vai de %d a %d!\n", sizeof(int), INT_MIN, INT_MAX);

    // Tamanho e intervalo de um tipo ponto flutuante
    printf("O ponto flutuante ocupa %lu bytes e vai de %E a %E!\n", sizeof(float), -FLT_MAX, FLT_MAX);

    // Tamanho e intervado do tipo double
    printf("O double ocupa %lu bytes e vai de %E a %E!\n", sizeof(double), -DBL_MAX, DBL_MAX);

    //Tamanho e intervalo de um tipo void
    printf("O void ocupa %lu byte(s)!\n", sizeof(void));

    return 0;
}