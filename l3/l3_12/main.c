#include <stdio.h>

int somadosdigitos(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n = n / 10;
    }
    return sum;
}

void parImpar(int n) {
    printf("%s", n % 2 == 0 ? "Par" : "Impar");
}

void valorPrimo(int n) {
    if (n == 1) {
        printf("%s", "Nao e primo");
        return;
    }

    int i;
    for (i = n - 1; i > 1; i--) {
        if (n % i == 0) {
            printf("%s", "Nao e primo");
            return;
        }
    }
    printf("%s", "Primo");
}

void main(void) {
    int num = 0;
    scanf("%d", &num);
    
    int sum;
    do {
        sum = somadosdigitos(num);

        printf("%d ", sum);
        parImpar(sum);
        printf(" ");
        valorPrimo(sum);
        printf("\n");

        num = sum;
    } while (sum >= 10);
}
