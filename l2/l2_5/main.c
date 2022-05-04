#include <stdio.h>
#include <math.h>

float piSummationByPrecision(int n) {
    if (!n)
    {
        return .0;
    }

    return 6.0/(n * n) + piSummationByPrecision(n - 1);
}

void main(void) {
    int n = 0, k = 1;

    scanf("%d", &n);

    float pi = sqrt(piSummationByPrecision(n));

    printf("%.6f", pi);
}
