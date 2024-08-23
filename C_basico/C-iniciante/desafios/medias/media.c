#include <stdio.h>

/*
4. Cálculo de Média Aritmética (Médio)
Escreva um programa que solicite ao usuário três notas (números reais) e calcule a média aritmética delas, exibindo o resultado.

Dica: Use float para lidar com números decimais.
*/

int main() {
    float nota1, nota2, nota3, media;

    printf("\nDigite suas 3 notas (nota1 nota2 nota3) : ");
    scanf("%f %f %f", &nota1, &nota2, &nota3);

    media = (nota1 + nota2 + nota3) / 3;

    printf("\nA media das notas %.2f, %.2f e %.2f do seu semestre foi : %.2f \n", nota1, nota2, nota3, media);

    return 0;
}