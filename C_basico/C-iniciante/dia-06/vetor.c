#include <stdio.h>

int main() {
    int vetor[5];
    int i = 0;

    vetor[0] = 0;
    vetor[1] = 45;
    vetor[2] = 4;
    vetor[3] = 46;
    vetor[4] = 434;

    while (i < 5) {
        printf("%d ", vetor[i]);
        i++;
    }
    
    return 0;
}