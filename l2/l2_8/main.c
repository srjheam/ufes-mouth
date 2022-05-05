#include <stdio.h>
#include <string.h>
#include <math.h>

void main(void) {
    int n = 0, m = 0;

    scanf("%d %d", &n, &m);

    /* Sieve of Eratosthenes */
    
    int sieve[m + 1];
    memset(sieve, 1, (m + 1)*sizeof(int));
    /* Populate an Array, indexed from 2 to m, with true values */

    int i;
    for (i = 2; i <= sqrt(m); i++)
    {
        if (sieve[i])
        {
            int j;
            for (j = pow(i, 2); j <= m; j += i)
            {
                sieve[j] = 0;
            }
        }
    }

    printf("RESP:");
    for (i = n + 1; i < m; i++)
    {
        if (sieve[i])
        {
            printf("%d ", i);
        }
    }
}
