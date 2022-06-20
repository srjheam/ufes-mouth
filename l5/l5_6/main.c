#include <stdio.h>

void fillArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

int elementOf(int this, int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == this) {
            return 1;
        }
    }

    return 0;
}

void main(void) {
    int n1;
    scanf("%d", &n1);
    int a[n1];
    fillArray(a, n1);

    int n2;
    scanf("%d", &n2);
    int b[n2];
    fillArray(b, n2);

    int counter = 0;
    int i;
    for (i = 0; i < n2; i++) {
        if (elementOf(b[i], a, n1)) {
            counter++;

            if (counter == n1) {
                break;
            }
        }
    }

    if (counter == 0) {
        printf("NENHUM");
    }
    else if (counter >= n1) {
        printf("TODOS");
    }
    else {
        printf("PARCIAL");
    }
}
