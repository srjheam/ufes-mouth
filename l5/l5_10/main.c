#include <stdio.h>

void fillArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void OrdenaCrescente(int vet[], int qtd) {
    int i;
    for (i = 1; i < qtd; i++) {
        if (vet[i] < vet[i - 1]) {
            int tmp = vet[i];
            vet[i] = vet[i - 1];
            vet[i - 1] = tmp;
            i = 0;
        }
    }
}

void ImprimeDadosDoVetor(int vet[], int qtd) {
    if (qtd == 0) {
        printf("{}");
        return;
    }
    
    printf("{%d", vet[0]);
    int i;
    for (i = 1; i < qtd; i++) {
        printf(", %d", vet[i]);
    }
    printf("}");
}

void main(void) {
    int n;
    scanf("%d", &n);

    int arr[n];
    fillArray(arr, n);
    OrdenaCrescente(arr, n);
    ImprimeDadosDoVetor(arr, n);
}
