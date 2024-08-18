#include <stdio.h>

int main() {
    int array[2][2];

    array[0][0] = 2;
    array[0][1] = 3;
    array[1][0] = 6;
    array[1][1] = 67;
    
    for (int i = 0; i < 2; i++) {
        printf("[");
        for (int j = 0; j < 2; j++)
            printf(" %d ", array[i][j]);
        printf("]\n");
    }

    return 0;
}