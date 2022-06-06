#include <stdio.h>
#include <math.h>

int EhIgual(int a, int b) {
    return a == b;
}

int MaiorDigito(int num) {
    int i, maior = 0;
    for (i = 1; i <= 10; i++) {
        int curr = (num % (int)pow(10, i)) / pow(10, i - 1);
        if (curr > maior) {
            maior = curr;
            if (maior == 9) {
                break;
            }
        }
    }
    return maior;
}

void main(void) {
    int a, b, count = 0;
    while (scanf("(%d,%d)", &a, &b) == 2) {
        int maiorA = MaiorDigito(a);
        int maiorB = MaiorDigito(b);

        if (EhIgual(maiorA, maiorB)) {
            count++;
        }
    }

    printf("COUNT:%d", count);
}
