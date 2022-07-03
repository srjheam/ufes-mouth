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

int getErros(int lImg, int cImg, int img[lImg][cImg], int lTemp, int cTemp, int temp[lTemp][cTemp]) {
    int acc = 0;

    int i;
    for (i = 0; i <= lImg - lTemp; i++) {
        int j;
        for (j = 0; j <= cImg - cTemp; j++) {
            int isTemp = 1;

            int k;
            for (k = 0; k < lTemp && isTemp; k++) {
                int l;
                for (l = 0; l < cTemp && isTemp; l++) {
                    if (temp[k][l] != img[i + k][j + l]) {
                        isTemp = 0;
                        break;
                    }
                }
            }

            if (isTemp) {
                acc++;
            }
        }
    }

    return acc;
}

void main(void) {
    int lImg, cImg;
    scanf("%d %d", &lImg, &cImg);
    int img[lImg][cImg];
    LeMap(lImg, cImg, img);

    int lTemp, cTemp;
    scanf("%d %d", &lTemp, &cTemp);
    int temp[lTemp][cTemp];
    LeMap(lTemp, cTemp, temp);

    int erros = getErros(lImg, cImg, img, lTemp, cTemp, temp);

    printf("RESP:%d", erros);
}
