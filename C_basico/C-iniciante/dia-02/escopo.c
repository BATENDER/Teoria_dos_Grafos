#include <stdio.h>

int var_global = 30;

int main() {
    int var_local = 10;

    {
        int var_bloco = 40;
        int var_local = 10;
        printf("Valor das variáveis dentro do bloco : \n");
        printf("Global = %d\n", var_global);
        printf("Local = %d\n", var_local);
        printf("Bloco = %d\n\n", var_bloco);
    }

    printf("Valor das variáveis fora do bloco : \n");
    printf("Global = %d\n", var_global);
    printf("Local = %d\n", var_local);
    // printf("Bloco = %d\n", var_bloco); // Variável não inicializada.
    
    return 0;
}