#include <stdio.h>

void fillArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void InverteVetor(int vet[], int qtd) {
    int i;
    for (i = 0; i < qtd / 2; i++) {
        int tmp = vet[i];
        vet[i] = vet[qtd - i - 1];
        vet[qtd - i - 1] = tmp;
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
    InverteVetor(arr, n);
    ImprimeDadosDoVetor(arr, n);
}
