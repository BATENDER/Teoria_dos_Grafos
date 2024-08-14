#include <stdio.h>

int main() {
    char  caractere;
    char  string[31];
    int   inteiro;
    float flutuante;

    printf("Entre com um caractere : ");
    int leuCerto = scanf("%c", &caractere);
    printf("\n%d\n\n", leuCerto);

    printf("Entre com uma string : ");
    leuCerto = scanf("%s", string);
    printf("\n%d\n\n", leuCerto);

    printf("Entre com um inteiro : ");
    leuCerto = scanf("%d", &inteiro);
    printf("\n%d\n\n", leuCerto);

    printf("Entre com um flutuantw : ");
    leuCerto = scanf("%f", &flutuante);
    printf("\n%d\n\n", leuCerto);

    while(getchar() != '\n');

    printf("Entre com uma string : ");
    leuCerto = scanf("%[^\n]", string);
    printf("\n%d\n\n", leuCerto);
    
    return 0;
}