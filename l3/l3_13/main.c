#include <stdio.h>

int CalculaValorPalavra() {
    char c = '\0';
    int acc = 0;
    while (scanf("%c", &c)) {
        if (c >= 'a' && c <= 'z') {
            acc += c - 'a' + 1;
        }
        else if (c >= 'A' && c <= 'Z') {
            acc += c - 'A' + 27;
        }
        else {
            break;
        }
    }
    return acc;
}

int EhPrimo(int n) {
    if (n == 1) {
        return 0;
    }

    int i;
    for (i = n - 1; i > 1; i--) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int ProximoPrimo(int n) {
    int i;
    for (i = n + 1; i <= __INT_MAX__; i++) {
        if (EhPrimo(i)) {
            return i;
        }
    }
}

void main(void) {
    int valorPalavra = 0;
    while (1) {
        valorPalavra = CalculaValorPalavra();

        if (valorPalavra == -1 || valorPalavra == 0)
            break;

        int ehPrimo = EhPrimo(valorPalavra);
        if (ehPrimo) {
            printf("%s", "E primo\n");
        }
        else {
            int proximoPrimo = ProximoPrimo(valorPalavra);
            printf("Nao e primo %d\n", proximoPrimo);
        }
    };
}
