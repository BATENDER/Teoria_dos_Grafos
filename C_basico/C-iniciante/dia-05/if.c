#include <stdio.h>

int main() {
    int idade = 48;

    if (idade >= 18) {
        printf("Parabens, você eh maior de idade!\n\n");
    }


    idade = 15;

    if (idade >= 18) {
        printf("Voce eh maior de idade!\n");
    } 
    else {
        printf("Voce eh menor de idade!\n");
    } 


    idade = 60;

    if (idade < 25) {
        printf("Voce eh jovem!\n");
    } 
    else if (idade < 59) {
        printf("Voce eh adulto!\n");
    }
    else {
        printf("Voce faz parte da melhor idade!\n");
    }

    return 0;
}