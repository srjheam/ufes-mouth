#include <stdio.h>
#include <math.h>

int EhPrimo(int num) {
    if (num  <= 1) {
        return 0;
    }
    
    int i;
    for (i = 2; i < num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    
    return 1;
}

int MaiorDigitoPrimo(int num) {
    int maior = 0;

    int i;
    for (i = 1; i <= 10; i++) {
        int digito = (num % (int)pow(10, i)) / pow(10, i - 1);

        if (EhPrimo(digito) && digito > maior) {
            maior = digito;
        }
    }

    return maior;
}

int main(void) {
    int sum = 0;

    while (1) {
        int curr;
        char end;
        scanf("%d%c", &curr, &end);

        sum += MaiorDigitoPrimo(curr);

        if (end != ' ') {
            break;
        }
    }

    printf("SOMA:%d", sum);

    return 0;
}
