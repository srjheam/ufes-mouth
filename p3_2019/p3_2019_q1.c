#include <stdio.h>

void leArr(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void zipArr(int arr1[], int n, int arr2[], int m) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d - %d\n", arr1[i], arr2[i % m]);
}

void main(void) {
    int n;
    scanf("%d", &n);
    int arr1[n];
    leArr(arr1, n);

    int m;
    scanf("%d", &m);
    int arr2[m];
    leArr(arr2, m);

    printf("PARES:\n");
    zipArr(arr1, n, arr2, m);
}
