#include <stdio.h>

int ehMaiusculo(char ch) {
    return ch >= 'A' && ch <= 'Z';
}

int ehLetra(char ch) {
    return ehMaiusculo(ch) || ch >= 'a' && ch <= 'z';
}

int ehDigito(char ch) {
    return ch >= '0' && ch <= '9';
}

int ehVogal(char ch) {
    return ch == 'a'
        || ch == 'e'
        || ch == 'i'
        || ch == 'o'
        || ch == 'u'
        || ch == 'A'
        || ch == 'E'
        || ch == 'I'
        || ch == 'O'
        || ch == 'U';
}

int ehConsoanteMinuscula(char ch) {
    return ehLetra(ch) && !ehMaiusculo(ch) && !ehVogal(ch);
}

int paraMaiuscula(char ch) {
    if (ch < 'a' || ch > 'z') {
        return ch;
    }
    
    return ch - 32;
}

void main(void) {
    char fst, snd, trd, fth;
    scanf("%c%c%c%c", &fst, &snd, &trd, &fth);

    if (ehMaiusculo(fst) && ehDigito(snd) && ehVogal(trd) && ehConsoanteMinuscula(fth)) {
        printf("%c%c%c%c", fst, snd, paraMaiuscula(trd), paraMaiuscula(fth));
    }
    else {
        printf("%s", "Invalido");
    }
}
