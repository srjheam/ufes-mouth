#include <stdio.h>

void main(void) {
    int n;
    scanf("%d", &n);

    int i, sum = 0;
    for (i = 0; i < n; i++) {
        int curr;
        scanf("%d", &curr);
        if (i % 2 == curr % 2) {
            sum += curr;
        }
    }

    printf("SOMA:%d", sum);
}
