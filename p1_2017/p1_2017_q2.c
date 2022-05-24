#include <stdio.h>

int ehValido(int n) {
    return n >= 1 && n <= 10;
}

int ehHomem(int n) {
    return n >= 1 && n <= 5;
}

int ehMulher(int n) {
    return n >= 6 && n <= 10;
}

void main(void) {
    int a = 0, b = 0;
    scanf("%d %d", &a, &b);

    if (!ehValido(a) || !ehValido(b)) {
        printf("%s", "Invalido");
    }
    else {
        if (ehHomem(a) && ehMulher(b) || ehHomem(b) && ehMulher(a)) {
            printf("%s", "Um casal");
        }
        else if (ehHomem(a)) {
            if (a != b) {
                printf("%s", "Par de homens");
            }
            else {
                printf("%s", "Um homem");
            }
        }
        else {
            if (a != b) {
                printf("%s", "Par de mulheres");
            }
            else {
                printf("%s", "Uma mulher");
            }
        }
    }
}
