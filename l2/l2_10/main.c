#include <stdio.h>

void main(void) {
    int n = 0, m = 0;

    scanf("%d %d", &n, &m);

    int i;
    for (i = n; i <= m; i++)
    {
        int j;
        for (j = 1; j <= 10; j++)
        {
            printf("%d x %d = %d\n", i, j, i * j);
        }
    }
    
}
