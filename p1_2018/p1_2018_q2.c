#include <stdio.h>

int main(void) {
    int troco1, troco2;
    scanf("%d %d", &troco1, &troco2);

    int t1_nota5 = troco1 / 5;
    int t2_nota5 = troco2 / 5;

    int t1_nota1 = troco1 % 5;
    int t2_nota1 = troco2 % 5;

    int t1_sum = t1_nota5 + t1_nota1;
    int t2_sum = t2_nota5 + t2_nota1;

    if (t1_sum == t2_sum) {
        printf("Iguais!");
    }
    else if (t1_sum > t2_sum) {
        printf("QTD troco 1 eh maior!");
    }
    else {
        printf("QTD troco 2 eh maior!");
    }
}
