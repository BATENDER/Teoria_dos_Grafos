#include <stdio.h>

int main() {
    int idade = 19;

    idade <= 18 ? printf("Voce eh menor idade!\n\n") : printf("Voce eh maior de idade!\n\n");

    
    idade = 60;

    idade <= 25 ? printf("Voce eh um jovem!\n") : idade <= 59 ? printf("Voce eh adulto!\n") : printf("Voce faz parte da melhor idade!\n");
    
    return 0;
}