#include <stdio.h>

void main(void) {
    int n;
    scanf("%d", &n);
    
    if (n == 0) {
        return;
    }
    
    int i, min = __INT32_MAX__, minIdx = 0;
    for (i = 1; i <= n; i++) {
        int curr;
        scanf("%d", &curr);

        if (curr < min) {
            min = curr;
            minIdx = i;
        }
    }
    printf("POS:%d", minIdx);
}
