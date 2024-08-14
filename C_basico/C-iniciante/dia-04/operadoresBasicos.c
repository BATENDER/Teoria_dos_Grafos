#include <stdio.h>

int main() {
    int x = 5;
    int y = 12;

    // Operações básicas

        printf("x + y = %d\n\n", x + y);
        printf("x - y = %d\n\n", x - y);
        printf("y - x = %d\n\n", y - x);
        printf("x * y = %d\n\n", x * y);
        printf("x / y = %d\n\n", x / y); // Divisão de inteiro em C dá um inteiro
        printf("x / y = %f\n\n", (x * 1.0) / y);
        printf("y %% x = %d\n\n", y % x);


    // Operações de incremento e decremento

        printf("++x = %d\n", ++x);
        printf("x++ = %d\n", x++);
        printf("--y = %d\n", --y);
        printf("y-- = %d\n", y--);
    
    return 0;
}