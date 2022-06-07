#include <stdio.h>
#include <math.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int fst;
    scanf("%d", &fst);
    int resto = fabs(fst % 2);

    int counter = 1;
    int i;
    for (i = 1; i < n; i++) {
        int curr;
        scanf("%d", &curr);
        if (fabs(curr % 2) == resto) {
            counter++;
        }
    }

    printf("QTD ");
    if (resto == 0) {
        printf("PARES");
    }
    else {
        printf("IMPARES");
    }
    printf(":%d", counter);

    return 0;
}