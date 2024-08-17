#include <stdio.h>

int main() {
    int i = 0;
    do {
        printf("%d ", i);
        i++;
    } while (i <= 5);

    printf("\n\n");

    char ch = getchar();
    do {
        getchar();
        ch = getchar();
    } while (ch != '\n');

    i = 0;
    do {
        int j = 0;
        
        do {
            printf("(%d,%d) ", i, j);
            j++;
        } while (j <= 5);

        i++;
    } while (i <= 5);
    
    return 0;
}