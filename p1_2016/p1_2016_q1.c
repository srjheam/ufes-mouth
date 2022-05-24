#include <stdio.h>

void main(void) {
    int weekDay = 0;
    scanf("%d", &weekDay);
    
    switch (weekDay) {
    case 1:
        printf("%s", "Domingo");
        break;
    case 2:
        printf("%s", "Segunda");
        break;
    case 3:
        printf("%s", "Terca");
        break;
    case 4:
        printf("%s", "Quarta");
        break;
    case 5:
        printf("%s", "Quinta");
        break;
    case 6:
        printf("%s", "Sexta");
        break;
    case 7:
        printf("%s", "Sabado");
        break;
    default:
        printf("%s", "Invalido");
        break;
    };
}
