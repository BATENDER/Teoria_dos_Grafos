#include <stdio.h>

int main() {
    int dia = 2;

    switch(dia) {
        case 1: printf("Domingo!\n"); break;
        case 2: printf("Segunda!\n"); break;
        case 3: printf("Terça!\n"); break;
        case 4: printf("Quarta!\n"); break;
        case 5: printf("Quinta!\n"); break;
        case 6: printf("Sexta!\n"); break;
        case 7: printf("Sábado!\n"); break;
        default: printf("Dia da semana inexistente!\n");
    }


    char alternativa = 'A';

    switch(alternativa) {
        case 'a': case 'A': printf("ALternativa A selecionada\n"); break;
        case 'b': case 'B': printf("ALternativa B selecionada\n"); break;
        case 'c': case 'C': printf("ALternativa C selecionada\n"); break;
        case 'd': case 'D': printf("ALternativa D selecionada\n"); break;
        case 'e': case 'E': printf("ALternativa E selecionada\n"); break;
        default: printf("Alternativa inválida selecionada!\n");
    }
    
    return 0;
}