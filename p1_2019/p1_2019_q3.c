#include <stdio.h>

int ehLetra(char c) {
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

int ehNumero(char d) {
    return d >= '0' && d <= '9';
}

void printValidade(int validoLetra, int validoNumero) {
    if (validoLetra && validoNumero) {
        printf("Codigo valido!");
        return;
    }
    
    printf("Codigo invalido!Problema ");
    if (!validoLetra) {
        printf("nas letras");
        if (!validoNumero) {
            printf(" e ");
        }
    }
    if (!validoNumero) {
        printf("nos numeros");
    }
    printf("%c", '!');
}

void main(void) {
    int validoLetra = 1, validoNumero = 1;

    int i;
    for (i = 0; i < 3; i++) {
        char curr;
        scanf("%c", &curr);
        if (!ehLetra(curr)) {
            validoLetra = 0;
        }
    }
    scanf("%*c");
    for (i = 0; i < 4; i++) {
        char curr;
        scanf("%c", &curr);
        if (!ehNumero(curr)) {
            validoNumero = 0;
            break;
        }
    }
    printValidade(validoLetra, validoNumero);
}
