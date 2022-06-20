#include <stdio.h>

void main(void) {
    int n;
    scanf("%d", &n);

    int num[n];
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    
    int a, b;
    scanf("%d %d", &a, &b);

    int count = 0;
    for (i = 0; i < n; i++) {
        int curr = num[i];
        if (curr >= a && curr <= b) {
            count++;
        }
    }
    
    printf("%d %d", count, n - count);
}
