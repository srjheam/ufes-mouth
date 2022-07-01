#include <stdio.h>

void LeMap(int l, int c, int map[l][c]) {
    int i;
    for (i = 0; i < l; i++) {
        int j;
        for (j = 0; j < c; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
}

void PrintSoldaCoodinates(int lPlaca, int cPlaca, int placa[lPlaca][cPlaca], int lImg, int cImg, int img[lImg][cImg]) {
    int i;
    for (i = 0; i <= lPlaca - lImg; i++) {
        int j;
        for (j = 0; j <= cPlaca - cImg; j++) {
            int isSolda = 1;

            int k;
            for (k = 0; k < lImg && isSolda; k++) {
                int l;
                for (l = 0; l < cImg && isSolda; l++) {
                    if (img[k][l] != placa[i + k][j + l]) {
                        isSolda = 0;
                    }
                }
            }

            if (isSolda) {
                printf("%d,%d\n", j, i);
            }
        }
    }
}

void main(void) {
    int lPlaca, cPlaca;
    scanf("%d %d", &lPlaca, &cPlaca);
    int placa[lPlaca][cPlaca];
    LeMap(lPlaca, cPlaca, placa);

    int lImg, cImg;
    scanf("%d %d", &lImg, &cImg);
    int img[lImg][cImg];
    LeMap(lImg, cImg, img);

    PrintSoldaCoodinates(lPlaca, cPlaca, placa, lImg, cImg, img);
}
