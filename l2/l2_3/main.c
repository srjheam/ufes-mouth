#include <stdio.h>

void main(void) {
    int n = 0, max = 0, min = __INT_MAX__, evens = 0, odds = 0;
    float average = 0;

    scanf("%d", &n);

    int i;
    for (i = 0; i < n; i++) {
        int curr = 0;
        scanf("%d", &curr);

        max = curr > max ? curr : max;
        min = curr < min ? curr : min;
        if (curr % 2 == 0) {
            evens++;
        }
        else {
            odds++;
        }
        average += (float)curr / n;
    }

    printf("%d %d %d %d %.6f", max, min, evens, odds, average);
}
