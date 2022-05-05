#include <stdio.h>
#include <math.h>

double calcS1(int numerator, int denominator) {
    if (!denominator)
    {
        return 0;
    }

    return (double)numerator / denominator + calcS1(numerator - 2, denominator - 1);
}

double calcS2(int n, int denominator) {
    if (!n)
    {
        return 0;
    }

    return pow(2, n) / denominator + calcS2(n -1, denominator + 1);
}

double calcS3(int numerator) {
    if (!numerator)
    {
        return 0;
    }

    return numerator / pow(numerator, 2) + calcS3(numerator - 1);
}

void main(void) {
    int option = 0;

    scanf("%d", &option);

    double result = .0;

    switch (option)
    {
    case 1:
        result = calcS1(99, 50);
        break;
    
    case 2:
        result = calcS2(50, 1);
        break;

    case 3:
        result = calcS3(10);
        break;
    }

    printf("%.6f", result);
}
