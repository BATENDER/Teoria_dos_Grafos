#include <stdio.h>

/*
%c       : caractere
%s       : string
%d ou %i : inteiro com sinal
%f       : ponto flutuante
*/

int main() {
    char caractere = 'a';
    char string[31] = "Uma cadeia de caracteres!";
    int inteiro = 100;
    float flutuante = 3.943F;
    
    printf("Imprimindo formatando com printf : \n");
    printf("%c\n", caractere);
    printf("%d\n", caractere);
    printf("%s\n", string);
    printf("%30s\n", string);
    printf("%-30s\n", string);
    printf("%d\n", inteiro);
    printf("%5d\n", inteiro);
    printf("%f\n", flutuante);
    printf("%6.2f\n", flutuante);
    printf("%.f\n\n", flutuante);

    return 0;
}