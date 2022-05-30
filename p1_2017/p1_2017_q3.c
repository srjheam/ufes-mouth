#include <stdio.h>

int ehNumero(char c) {
    return c >= '0' && c <= '9';
}

int ehLetra(char c) {
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

int ehValido(char c) {
    return ehNumero(c) || ehLetra(c);
}

char paraMaiuscula(char c) {
    if (c < 'a' || c > 'z') {
        return c;
    }
    
    return c - 32;
}

void main(void) {
    char c1, c2, c3, c4;
    scanf("%c%c %c%c", &c1, &c2, &c3, &c4);

    if (!ehValido(c1) || !ehValido(c2) || !ehValido(c3) || !ehValido(c4)) {
        printf("Invalido");
        return;
    }
    
    if (paraMaiuscula(c1) == paraMaiuscula(c3) && paraMaiuscula(c2) == paraMaiuscula(c4)) {
        printf("IGUAIS");
    }
    else {
        printf("DIFERENTES");
    }
}
