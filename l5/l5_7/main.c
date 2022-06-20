#include <stdio.h>

void fillArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void main(void) {
    int n;
    scanf("%d", &n);

    if (n <= 1) {
        printf("NAO");
        return;
    }

    int arr[n];
    fillArray(arr, n);

    int r = arr[1] - arr[0];

    int i;
    for (i = 2; i < n; i++) {
        int currR = arr[i] - arr[i - 1];
        if (currR != r) {
            printf("NAO");
            return;
        }
    }
    
    printf("RESP:%d", r);
}
