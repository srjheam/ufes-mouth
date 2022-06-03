#include <stdio.h>

void printSePlural(int qtd) {
    if (qtd > 1) {
        printf("%c", 's');
    }
}

int main(void) {
    int hh, mm, increment;
    scanf("%d:%d %d", &hh, &mm, &increment);

    int totalMinutes = hh * 60 + mm + increment;
    int newDays = (totalMinutes / 60) / 24;
    int newHH = (totalMinutes / 60) % 24;
    int newMM = totalMinutes % 60;

    if (newDays) {
        printf("(%d dia", newDays);
        printSePlural(newDays);
        printf("%c", ')');
    }
    if (newHH) {
        printf("(%d hora", newHH);
        printSePlural(newHH);
        printf("%c", ')');
    }
    if (newMM) {
        printf("(%d minuto", newMM);
        printSePlural(newMM);
        printf("%c", ')');
    }
    printf("%c", '\n');

    return 0;
}
