#include <stdio.h>
#include <math.h>
#include <string.h>

int EhPrimo(int num) {
    /* Sieve of Eratosthenes */
    
    int sieve[num + 1];
    memset(sieve, 1, (num + 1)*sizeof(int));
    /* Populate an Array, indexed from 2 to n, with true values */

    int i;
    for (i = 2; i <= sqrt(num); i++)
    {
        if (sieve[i])
        {
            int j;
            for (j = pow(i, 2); j <= num; j += i)
            {
                sieve[j] = 0;
            }
        }
    }

    return sieve[num];
}

void ImprimeMultiplos(int num, int max) {
    int i;
    for (i = 2; i * num < max; i++)
    {
        printf("%d ", i * num);
    }

    if (i == 2) {
        printf("*");
    }

    printf("\n");
}

void main(void) {
    int min = 0, max = 0;
    scanf("%d %d", &min, &max);

    int i;
    for (i = min + 1; i < max; i++)
    {
        if (EhPrimo(i))
        {
            printf("%d\n", i);
            ImprimeMultiplos(i, max);
        }
    }
}
