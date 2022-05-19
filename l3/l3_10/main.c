#include <stdio.h>

int EhLetraMaiuscula(char c) {
    return c >= 'A' && c <= 'Z';
}

int EhLetraMinuscula(char c) {
    return c >= 'a' && c <= 'z';
}

int EhLetra(char c) {
    return EhLetraMaiuscula(c) || EhLetraMinuscula(c);
}

char Codifica(char letra, int n) {
    int aBase = EhLetraMaiuscula(letra) ? 'A' : 'a';
    int key = EhLetraMaiuscula(letra) ? 2 * n : n;
    return aBase + (letra - aBase + key) % 26;
}

char Decodifica(char letra, int n) {
    int zBase = EhLetraMaiuscula(letra) ? 'Z' : 'z';
    int key = EhLetraMaiuscula(letra) ? 2 * n : n;
    return zBase + (letra - zBase - key) % 26;
}

/* YES - Presentation differences */
void main(void) {
    int option = 0, n = 0;
    scanf("%d %d ", &option, &n);

    int i;
    char curr = '\0';
    switch (option) {
    case 1:
        while (curr != '.') {
            scanf("%c", &curr);
            if (EhLetra(curr)) {
                printf("%c", Codifica(curr, n));
            }
            else {
                printf("%c", curr);
            }
        }
        break;
    
    case 2:
        while (curr != '.') {
            scanf("%c", &curr);
            if (EhLetra(curr)) {
                printf("%c", Decodifica(curr, n));
            }
            else {
                printf("%c", curr);
            }
        }
        break;
    
    default:
        printf("%s", "Operacao invalida.");
        break;
    }
    printf("\n");
}
