#include <stdio.h>

void fillArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void TrocaParEImpar(int vet[], int qtd) {
    int i;
    for (i = 1; i < qtd; i += 2) {
        int tmp = vet[i];
        vet[i] = vet[i - 1];
        vet[i - 1] = tmp;
    }
}

void ImprimeDadosDoVetor(int vet[], int qtd) {
    if (qtd == 0) {
        printf("{}");
        return;
    }
    
    printf("{");
    printf("%d", vet[0]);
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
    TrocaParEImpar(arr, n);
    ImprimeDadosDoVetor(arr, n);
}
