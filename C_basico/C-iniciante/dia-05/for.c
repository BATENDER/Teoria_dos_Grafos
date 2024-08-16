#include <stdio.h>

int main() {
    for (int i = 0; i < 10; i++) {
        printf("%d\n", i);
    }
    
    printf("\n");

    for (int i = 0; i < 10; i+=2) {
        printf("%d\n", i);
    }

    printf("\n");

    for (int i = 10; i > 0; i--) {
        printf("%d\n", i);
    }

    printf("\n");

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("(%d,%d)\n", i, j);
        }
    }

    return 0;
}