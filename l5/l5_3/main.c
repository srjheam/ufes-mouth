#include <stdio.h>
#include <stdlib.h>

void main(void) {
    int n;
    scanf("%d", &n);

    int heights[n], maxDiff = 0;
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &heights[i]);

        if (i > 0) {
            int currDiff = abs(heights[i] - heights[i - 1]);
            if (currDiff > maxDiff) {
                maxDiff = currDiff;
            }
        }
        
    }

    if (n <= 1) {
        printf("IMPOSSIVEL");
        return;
    }

    for (i = 1; i < n; i++) {
        if (abs(heights[i] - heights[i - 1]) == maxDiff) {
            printf(" (%d %d)", i - 1, i);
        }
    }
}
