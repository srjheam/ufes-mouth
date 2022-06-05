#include <stdio.h>

int EhFinalDaLista(int buraco) {
    return buraco == -1;
}

int EcontraMaiorBuraco() {
    int maior = 0;

    int curr;
    do {
        scanf("%d", &curr);
        maior = curr > maior ? curr : maior;
    } while (!EhFinalDaLista(curr));

    return maior;
}

int ContaEsferasGrandes(int maiorBuraco) {
    int counter = 0;

    int curr;
    do {
        scanf("%d", &curr);
        if (curr >= maiorBuraco) {
            counter++;
        }
        
    } while (!EhFinalDaLista(curr));

    return counter;
}

void main(void) {
    int maiorBuraco = EcontraMaiorBuraco();
    int esferasGrandes = ContaEsferasGrandes(maiorBuraco);

    printf("QTD:%d\n", esferasGrandes);
}
