#include <stdio.h>

void main(void) {
    int month = 0;

    scanf("%d", &month);

    char *months[12] = { "Jan.", "Fev.", "Mar.",
                    "Abr.", "Mai.", "Jun.",
                    "Jul.", "Ago.", "Set.",
                    "Out.", "Nov.", "Dez." };
    
    if (month - 1 < 0 || month - 1 > 11)
    {
        printf("Invalido.");
    }
    else
    {
        printf("%s", months[month - 1]);
    }
}
