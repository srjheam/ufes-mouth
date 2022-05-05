#include <stdio.h>
#include <string.h>
#include <math.h>

void main(void) {
    int n = 0;

    scanf("%d", &n);

    /* Sieve of Eratosthenes */
    
    int sieve[n + 1];
    memset(sieve, 1, (n + 1)*sizeof(int));
    /* Populate an Array, indexed from 2 to n, with true values */

    int i;
    for (i = 2; i <= sqrt(n); i++)
    {
        if (sieve[i])
        {
            int j;
            for (j = pow(i, 2); j <= n; j += i)
            {
                sieve[j] = 0;
            }
        }
    }
    
    printf("%s", sieve[n] ? "Primo" : "Nao primo");
}
