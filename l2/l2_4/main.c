#include <stdio.h>

void main(void) {
    int n = 1, curr = 0, max = 0;
    float average = .0;
    do {
        scanf("%d", &curr);

        if (curr == 0)
        {
            break;
        }

        max = curr > max ? curr : max;
        average = (average * (n - 1) + curr) / n;

        printf("%d %.6f\n", max, average);

        n++;
    } while (1);
}
