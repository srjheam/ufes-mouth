#include <stdio.h>

int getSort(int arr[], int n) {
    #define desordenado -1
    #define decres 0
    #define cres 1
    #define cres_decres 2

    /* -1: desordenado
     *  0: decres
     *  1: cres
     *  2: cres_decres
     */
    int sort = 2;

    int i;
    for (i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            if (sort == cres_decres) {
                sort = cres;
            }
            else if (sort != cres) {
                return desordenado;
            }
        }
        else if (arr[i] < arr[i - 1]) {
            if (sort == cres_decres) {
                sort = decres;
            }
            else if (sort != decres) {
                return desordenado;
            }
        }
    }

    return sort;
}

void main(void) {
    int n;
    scanf("%d", &n);

    int grades[n];
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &grades[i]);
    }
    
    int sort = getSort(grades, n);
    
    switch (sort)
    {
    case -1:
        printf("DESORDENADO");
        break;

    case 0:
        printf("DECRESCENTE");
        break;

    case 1:
        printf("CRESCENTE");
        break;

    case 2:
        printf("CRESCENTE&DECRESCENTE");
        break;
    }
}
