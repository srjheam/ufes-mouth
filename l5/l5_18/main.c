#include <stdio.h>

int EhMultiplicavel(int c1, int l2) {
    return c1 == l2;
}

void LeMatriz(int l, int c, int arr[l][c]) {
    int i;
    for (i = 0; i < l; i++) {
        int j;
        for (j = 0; j < c; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}

void MultMatriz(int l, int c, int kk, int r[l][c], int m1[l][kk], int m2[kk][c]) {
    int i;
    for (i = 0; i < l; i++) {
        int j;
        for (j = 0; j < c; j++) {
            int acc = 0;

            int k;
            for (k = 0; k < kk; k++) {
                acc += m1[i][k] * m2[k][j];
            }

            r[i][j] = acc;
        }
    }
}

void PrintMatriz(int l, int c, int arr[l][c]) {
    int i;
    for (i = 0; i < l; i++) {
        int j;
        for (j = 0; j < c; j++) {
            printf("%d", arr[i][j]);
            if (j < c - 1) {
                printf(" ");
            }
            
        }
        printf("\n");
    }
}

void main(void) {
    int n;
    scanf("%d", &n);

    int i;
    for (i = 0; i < n; i++) {
        int l1, c1;
        scanf("%d %d", &c1, &l1);

        int matriz1[l1][c1];
        LeMatriz(l1, c1, matriz1);

        int l2, c2;
        scanf("%d %d", &c2, &l2);

        int matriz2[l2][c2];
        LeMatriz(l2, c2, matriz2);

        if (!EhMultiplicavel(c1, l2)) {
            printf("IMPOSSIVEL\n");
        }
        else {
            int l3 = l1, c3 = c2, kk = c1;
            int result[l3][c3];
            MultMatriz(l3, c3, kk, result, matriz1, matriz2);
            PrintMatriz(l3, c3, result);
        }

        printf("\n");
    }
}
