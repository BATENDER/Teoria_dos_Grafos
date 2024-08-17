#include <stdio.h>

int main() {
    int i = 0;
    while (i <= 5) {
        printf("%d ", i);
        i++;
    }

    printf("\n\n");

    char ch = getchar();
    while (ch != '\n') {
        getchar();
        ch = getchar();
    }

    printf("%d", i);
    printf("\n\n");

    i = 0;
    
    while (i <= 5) {
        int j = 0;
        while (j <= 5) {
            printf("(%d,%d) ", i, j);
            j++;
        }
        i++;
    }
    
    return 0;
}