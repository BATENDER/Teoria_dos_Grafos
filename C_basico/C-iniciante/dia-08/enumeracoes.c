#include <stdio.h>

int main() {
    enum dias_da_semana {
        mon,
        tue,
        wed,
        thu,
        fri,
        sat,
        sun
    } semana;

    switch (semana) {
        case mon:   case tue:
        case wed:   case thu:
        case fri: printf("Dia util! \n"); break;
        case sat:
        case sun: printf("Dia nao util! \n"); break;
    }
    
    return 0;
}