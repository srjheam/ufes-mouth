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
    int n1;
    scanf("%d", &n1);
    int a[n1];
    fillArray(a, n1);
    OrdenaCrescente(a, n1);

    int n2;
    scanf("%d", &n2);
    int b[n2];
    fillArray(b, n2);
    OrdenaCrescente(b, n2);

    int i = 0, j = 0;
    while (i + j < n1  + n2) {
        if (i == n1 || j < n2 && b[j] < a[i]) {
            j++;
            printf("B");
        }
        else {
            i++;
            printf("A");
        }
    }
}
