#include <stdio.h>

/*
5. Conversão de Temperatura (Médio)
Crie um programa que converta uma temperatura dada em graus Celsius para Fahrenheit e vice-versa, com base na escolha do usuário.

Fórmulas:

De Celsius para Fahrenheit: F = (C * 9/5) + 32
De Fahrenheit para Celsius: C = (F - 32) * 5/9
*/

int main() {
    char tempEscolha;
    float temperaturaEntrada, temperaturaSaida;

    printf("\nEscolha se desejaria fazer a transformacao da temperatura de graus Celsius para Fahrenheit ou vice-versa (C ou c - Celsius/ F ou f - fahrenheit) : ");
    scanf("%c", &tempEscolha);

    switch (tempEscolha) {
        case 'C':
        case 'c':
            printf("\nDigite a temperatura em oF : ");
            scanf("%f", &temperaturaEntrada);

            temperaturaSaida = (temperaturaEntrada - 32) * 5/9;

            printf("\nTemperatura %.2foF convertida eh : %.2foC \n", temperaturaEntrada, temperaturaSaida);
        
        break;
        
        
        case 'F':
        case 'f':
            printf("\nDigite a temperatura em oC : ");
            scanf("%f", &temperaturaEntrada);

            temperaturaSaida = (temperaturaEntrada * 9 / 5) + 32;

            printf("\nTemperatura %.2foC convertida eh : %.2foF \n", temperaturaEntrada, temperaturaSaida);

        break;

        default:
            printf("\nEntrada inválida!");

    }

    return 0;
}