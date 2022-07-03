#include <stdio.h>

void leArr(int l, int c, char arr[l][c]) {
    int i;
    for (i = 0; i < l; i++) {
        int j;
        for (j = 0; j < c; j++)
            scanf("%c", &arr[i][j]);

        scanf("%*c");
    }
}

int countVPatX(int l, int c, char arr[l][c], int qty) {
    const char TARGET = 'X';
    int acc = 0;

    int i;
    for (i = 0; i <= l - qty; i++) {
        int j;
        for (j = 0; j < c; j++) {
            int pattern = 1;

            int k;
            for (k = 0; k < qty; k++) {
                if (arr[i + k][j] != TARGET) {
                    pattern = 0;
                    break;
                }
                
            }

            if (pattern) {
                acc++;
            }
        }
    }

    return acc;
}

int countHPatX(int l, int c, char arr[l][c], int qty) {
   const char TARGET = 'X';
    int acc = 0;

    int i;
    for (i = 0; i < l; i++) {
        int j;
        for (j = 0; j <= c - qty; j++) {
            int pattern = 1;

            int k;
            for (k = 0; k < qty; k++) {
                if (arr[i][j + k] != TARGET) {
                    pattern = 0;
                    break;
                }
                
            }

            if (pattern) {
                acc++;
            }
        }
    }

    return acc;
}

void main(void) {
    int larg;
    char orient;
    scanf("%d%c", &larg, &orient);

    int l, c;
    scanf("%d %d%*c", &l, &c);
    char arr[l][c];
    leArr(l, c, arr);

    int cont;
    switch (orient) {
    case 'V':
        cont = countVPatX(l, c, arr, larg);
        break;

    case 'H':
        cont = countHPatX(l, c, arr, larg);
        break;
    }

    printf("CONT: %c %d\n", orient, cont);
}
