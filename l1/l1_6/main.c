#include <stdio.h>

void main(void) {
    int grade1 = 0, grade2 = 0;

    scanf("%d %d", &grade1, &grade2);

    float averageGrade = (grade1 + grade2) / 2.0;

    char *str_status;
    if (averageGrade < 5) {
        str_status = "Reprovado";
    }
    else if (averageGrade < 7) {
        str_status = "De Recuperacao";
    }
    else {
        str_status = "Aprovado";
    }
    printf("%.1f - %s", averageGrade, str_status);
    
}
