#include <stdio.h>
#include <string.h>
#include <math.h>

int verificaPrimo(int n) {
    if (n < 2) {
        return 0;
    }
    
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

    return sieve[n];
}

int transformaPrimo(int n) {
    int result = n;
    int i;
    for (i = (verificaNegativo(n) ? -n : n); i <= 32000; i++) {
        if (verificaPrimo(i)) {
            result = verificaNegativo(n) ? -i : i;
            break;
        }
    }
    return result;
}

int verificaNegativo(int n) {
    return n < 0;
}

void main(void) {
    int l = 0, c = 0;
    scanf("%d %d", &l, &c);

    int i;
    for (i = 0; i < l; i++) {
        int j;
        printf("\t");
        for (j = 0; j < c; j++) {
            int curr;
            scanf("%d", &curr);
            printf("%d ", transformaPrimo(curr));
        }
        printf("%c", '\n');
    }
    
}
