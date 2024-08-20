#include <stdio.h>
#include <string.h>

int main() {
    struct endereco_t {
        char logradouro[31];
        char cep[10];
        char uf[3];
        int numero;
    } enderecos[2];

    strcpy(enderecos[0].logradouro, "Setor");
    strcpy(enderecos[0].cep, "12342-098");
    strcpy(enderecos[0].uf, "BA");
    enderecos[0].numero = 128;

    strcpy(enderecos[1].logradouro, "Cria");
    strcpy(enderecos[1].cep, "12354-098");
    strcpy(enderecos[1].uf, "RJ");
    enderecos[1].numero = 90;
    
    for (int i = 0; i < 2; i++) {
        printf("\n Endereco : %s, %ld - %s / %s", enderecos[i].logradouro, enderecos[i].numero, enderecos[i].cep, enderecos[i].uf);
    }

    return 0;
}