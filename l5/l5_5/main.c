#include <stdio.h>

int findIndex(int arr[], int n, int target) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }

    return n;
}

void main(void) {
    int x, n;
    scanf("%d %d", &x, &n);

    int seq[n];
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &seq[i]);
    }
    
    int indx = findIndex(seq, n, x);

    printf("RESP:%d", indx);
}
