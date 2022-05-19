#include <stdio.h>

int Propriedade(int num) {
    int thousands = num / 1000;
    int hundreds = (num / 100) % 10;
    int tens = (num / 10) % 10;
    int ones = num % 10;

    int ef = thousands * 10 + hundreds + tens * 10 + ones;
    return (ef * ef) == num;
}

void main(void) {
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);

    int i;
    for (i = n + 1; i < m; i++) {
        if (Propriedade(i)) {
            printf("%d\n", i);
        }
    }
}
