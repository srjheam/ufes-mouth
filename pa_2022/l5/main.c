#include <stdio.h>
#include <stdlib.h>

#define VISITADO 1
#define NAO_VISITADO 0

void fillArr(int l, int c, int arr[l][c], int val) {
    int i;
    for (i = 0; i < l; i++) {
        int j;
        for (j = 0; j < c; j++) {
            arr[i][j] = val;
        }
    }
}

void moveRoboH(int l, int c, int arr[l][c], int l0, int c0, int cf) {
    int deltaH = cf - c0;

    int i;
    for (i = c0; i != cf; i += deltaH / abs(deltaH)) {
        arr[l0][i] = VISITADO;
    }
    arr[l0][cf] = VISITADO;
}

void moveRoboV(int l, int c, int arr[l][c], int l0, int c0, int lf) {
    int deltaV = lf - l0;

    int i;
    for (i = l0; i != lf; i += deltaV / abs(deltaV)) {
        arr[i][c0] = VISITADO;
    }
    arr[lf][c0] = VISITADO;
}

void moveRobo(int l, int c, int arr[l][c], int l0, int c0, int lf, int cf) {
    int deltaH = cf - c0;
    int deltaV = lf - l0;

    if (abs(deltaV) < abs(deltaH)) {
        moveRoboV(l, c, arr, l0, c0, lf);
        l0 = lf;
        moveRoboH(l, c, arr, l0, c0, cf);
        c0 = cf;
    }
    else {
        moveRoboH(l, c, arr, l0, c0, cf);
        c0 = cf;
        moveRoboV(l, c, arr, l0, c0, lf);
        l0 = lf;
    }
}

void printArr(int l, int c, int arr[l][c]) {
    int i;
    for (i = 0; i < l; i++) {
        int j;
        for (j = 0; j < c; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void main(void) {
    int c, l;
    scanf("%d %d", &c, &l);

    int arr[l][c];
    fillArr(l, c, arr, NAO_VISITADO);

    int c0 = 0, l0 = 0;
    int cf, lf;
    while (scanf("%d %d", &cf, &lf) == 2) {
        moveRobo(l, c, arr, l0, c0, lf, cf);

        l0 = lf;
        c0 = cf;

        if (c0 == 0 && l0 == 0)
            break;
    }

    printArr(l, c, arr);
}
