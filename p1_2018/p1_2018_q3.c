#include <stdio.h>

int ehDigito(char c) {
    return c >= '0' && c <= '9';
}

int ehMinuscula(char c) {
    return c >= 'a' && c <= 'z';
}

int ehMaiuscula(char c) {
    return c >= 'A' && c <= 'Z';
}

int ehLetra(char c) {
    return ehMinuscula(c) || ehMaiuscula(c);
}

int ehValido(char c1, char c2, char c3) {
    return ehDigito(c1) && ehMinuscula(c2) && ehLetra(c3);
} 

char paraMinuscula(char c) {
    if (ehMinuscula(c)) {
        return c;
    }
    
    return c + 32;
}

void printComparacao(char c1, char c2) {
    if (c1 == c2) {
        printf("%c", 'I');
    }
    else if (paraMinuscula(c1) == paraMinuscula(c2)) {
        printf("%c", 'C');
    }
    else {
        printf("%c", 'D');
    }
}

int main(void) {
    char c1_1, c1_2, c1_3, c2_1, c2_2, c2_3;
    scanf("%c%c%c %c%c%c", &c1_1, &c1_2, &c1_3, &c2_1, &c2_2, &c2_3);

    if (!ehValido(c1_1, c1_2, c1_3) || !ehValido(c2_1, c2_2, c2_3)) {
        printf("Codigo invalido!");
        printf("%c", '\n');
        return 0;
    }
    
    printComparacao(c1_1, c2_1);
    printComparacao(c1_2, c2_2);
    printComparacao(c1_3, c2_3);
    printf("%c", '\n');
}
