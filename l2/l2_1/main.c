#include <stdio.h>

void main(void) {
    int n = 0, m = 0;

    scanf("%d %d", &n, &m);

    printf("RESP:");
    int i = n;
    for (i += (n % 2 != 0) ? 1 : 2; i < m; i += 2) {
        printf("%d ", i);
    }
}
