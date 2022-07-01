#include <stdio.h>

int ehLetra(char c) {
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

int ehVogal(char c) {
    return c == 'a' || c == 'A'
        || c == 'e' || c == 'E'
        || c == 'i' || c == 'I'
        || c == 'o' || c == 'O'
        || c == 'u' || c == 'U';
}

int ehConsoante(char c) {
    return ehLetra(c) && !ehVogal(c);
}

int CountVogal(char str[]) {
    int acc = 0;
    
    int i;
    for (i = 0; str[i]; i++) {
        if (ehVogal(str[i])) {
            acc++;
        }
    }

    return acc;
}

int CountConsoante(char str[]) {
    int acc = 0;
    
    int i;
    for (i = 0; str[i]; i++) {
        if (ehConsoante(str[i])) {
            acc++;
        }
    }

    return acc;
}

void PrintVogal(char str[]) {
    int i;
    for (i = 0; str[i]; i++) {
        if (ehVogal(str[i])) {
            printf("%c", str[i]);
        }
    }
}

void PrintConsoante(char str[]) {
    int i;
    for (i = 0; str[i]; i++) {
        if (ehConsoante(str[i])) {
            printf("%c", str[i]);
        }
    }
}

void main(void) {
    char palavra[1024];
    while (scanf("%s", palavra) == 1) {

        int vogais = CountVogal(palavra);
        int consoantes = CountConsoante(palavra);

        if (consoantes > vogais) {
            PrintConsoante(palavra);
        }
        else if (vogais > consoantes) {
            PrintVogal(palavra);
        }
        else {
            printf("%s", palavra);
        }
        printf("\n");
    }
}
