#include <stdio.h>
#include <limits.h>

int main(void) {
    int i, last = INT_MIN, decrescente = 0;
    for (i = 0; i < 3; i++) {
        int curr;
        scanf("%d", &curr);

        if (decrescente) {
            if (curr >= last) {
                printf("TUDO DOIDO");
                return 0;
            }
        }
        else if (curr <= last) {
            decrescente = 1;
        }

        last = curr;
    }

    if (decrescente) {
        printf("DECRESCENTE");
    }
    else {
        printf("CRESCENTE");
    }

    return 0;
}
