#include <stdio.h>
#include <math.h>

void main(void) {
    int n = 0, m = 0;

    scanf("%d %d", &n, &m);

    int i;
    for (i = n + 1; i < m; i++)
    {
        /* Decompose number */
        int iCpy = i;

        int thousands = iCpy / 1000;
        iCpy -= thousands * 1000;

        int hundreds = iCpy / 100;
        iCpy -= hundreds * 100;

        int tens = iCpy / 10;
        iCpy -= tens * 10;

        int ones = iCpy;

        double iSqrt = sqrt(i);

        if (iSqrt == (int)iSqrt)
        {
            if ((thousands * 10 + hundreds) + (tens * 10 + ones) == iSqrt)
            {
                printf("%d\n", i);
            }
        }
    }
    
}
