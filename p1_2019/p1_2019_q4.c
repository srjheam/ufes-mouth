#include <stdio.h>

int getDV10Valido(int d1, int d2, int d3, int d4, int d5, int d6, int d7, int d8, int d9) {
    int soma = d1 * 10 + d2 * 9 + d3 * 8 + d4 * 7 + d5 * 6 + d6 * 5 + d7 * 4 + d8 * 3 + d9 * 2;
    int resto = soma % 11;

    if (resto < 2) {
        return 0;
    }
    else {
        return 11 - resto;
    }
}

int getDV11Valido(int d1, int d2, int d3, int d4, int d5, int d6, int d7, int d8, int d9) {
    int soma = d1 * 11 + d2 * 10 + d3 * 9 + d4 * 8 + d5 * 7 + d6 * 6 + d7 * 5 + d8 * 4 + d9 * 3 + getDV10Valido(d1, d2, d3, d4, d5, d6, d7, d8, d9) * 2;
    int resto = soma % 11;

    if (resto < 2) {
        return 0;
    }
    else {
        return 11 - resto;
    }
}

int validaDV10(int d1, int d2, int d3, int d4, int d5, int d6, int d7, int d8, int d9, int dv10) {
    return dv10 == getDV10Valido(d1, d2, d3, d4, d5, d6, d7, d8, d9);
}

int validaDV11(int d1, int d2, int d3, int d4, int d5, int d6, int d7, int d8, int d9, int dv11) {
    return dv11 == getDV11Valido(d1, d2, d3, d4, d5, d6, d7, d8, d9);
}

void main(void) {
    int d1, d2, d3, d4, d5, d6, d7, d8, d9, v10, v11;
    scanf("%1d%1d%1d.%1d%1d%1d.%1d%1d%1d-%1d%1d", &d1, &d2, &d3, &d4, &d5, &d6, &d7, &d8, &d9, &v10, &v11);

    if (d1 == d2 && d2 == d3 && d3 == d4 && d4 == d5 && d5 == d6 && d6 == d7 && d7 == d8 && d8 == d9) {
        printf("CPF invalido: digitos iguais!");
        return;
    }

    int ehV10Valido = validaDV10(d1, d2, d3, d4, d5, d6, d7, d8, d9, v10);
    int ehV11Valido = validaDV11(d1, d2, d3, d4, d5, d6, d7, d8, d9, v11);
    if (ehV10Valido && ehV11Valido) {
        printf("CPF valido!");
    }
    else if (!ehV10Valido && !ehV11Valido) {
        printf("CPF invalido: dois digitos!");
    }
    else if (!ehV10Valido) {
        printf("CPF invalido: primeiro digito!");
    }
    else if (!ehV11Valido) {
        printf("CPF invalido: segundo digito!");
    }
}
