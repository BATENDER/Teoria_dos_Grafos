#include <stdio.h>

int main() {
    // Conversão implícita
    char caractere = 'A';
    int inteiro = caractere;
    float flutuante = inteiro;
    double duplo = flutuante;

    printf("CARACTERE : %c\n", caractere);
    printf("CARACTERE %c após ser convertido para INTEIRO : %d\n", caractere, inteiro);
    printf("INTEIRO %d após ser convertido para FLUTUANTE : %f\n", inteiro, flutuante);
    printf("FLUTUANTE %f após ser convertido para DUPLO : %Lf\n", flutuante, duplo);


    // Conversão explícita
    duplo = 123.567849;
    flutuante = (float)duplo;
    inteiro = (int)flutuante;
    caractere = (char)inteiro;

    printf("DUPLO : %f\n", duplo);
    printf("DOUBLE %Lf após ser convertido para FLUTUANTE : %f\n", duplo, flutuante);
    printf("FLUTUANTE %f após ser convertido para INTEIRO : %d\n", flutuante, inteiro);
    printf("INTEIRO %d após ser convertido para CARACTERE : %d\n", inteiro, caractere);

    return 0;
}