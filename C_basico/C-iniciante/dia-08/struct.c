#include <stdio.h>
#include <string.h>

int main() {
    struct contato_t {
        char nome[31];
        char telefone[18]; // 
    } contato;

    strcpy(contato.nome, "Jose Almeida");
    strcpy(contato.telefone, "+55 54 98730-3749");

    printf("\n Contato : %s - (%s) \n", contato.nome, contato.telefone);
    
    return 0;
}