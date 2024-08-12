#include <stdio.h>
#include <float.h>
#include <limits.h>

int main() {
    printf("O signed char ocupa %lu bytes e vai do valor %d a %d!\n", sizeof(signed char), SCHAR_MIN, SCHAR_MAX);
    printf("O unsigned char ocupa %lu bytes e vai do valor %d a %d!\n\n", sizeof(unsigned char), 0, UCHAR_MAX);

    printf("O signed short int ocupa %lu bytes e vai do valor %d a %d!\n", sizeof(signed short int), SHRT_MIN, SHRT_MAX);
    printf("O unsigned short int ocupa %lu bytes e vai do valor %d a %d!\n\n", sizeof(unsigned short int), 0, USHRT_MAX);

    printf("O signed int ocupa %lu bytes e vai do valor %d a %d!\n", sizeof(signed int), INT_MIN, INT_MAX);
    printf("O unsigned int ocupa %lu bytes e vai do valor %d a %d!\n\n", sizeof(unsigned int), 0, UINT_MAX);

    printf("O signed long int ocupa %lu bytes e vai do valor %d a %d!\n", sizeof(signed long int), LONG_MIN, LONG_MAX);
    printf("O unsigned long int ocupa %lu bytes e vai do valor %d a %d!\n\n", sizeof(unsigned long int), 0, ULONG_MAX);

    printf("O long double ocupa %lu bytes e vai do valor %d a %d!\n\n", sizeof(long double), -LDBL_MAX, LDBL_MAX);
    
    return 0;
}