#include <stdio.h>

void main(void) {
    int n = 0, m = 0;

    scanf("%d %d", &n, &m);

    int i;
    for (i = n + 1; i < m; i++)
    {
        if (!(i % 3) || !(i % 4) || !(i % 7))
        {
            printf("%d ", i);
        }
        
    }
    
}
