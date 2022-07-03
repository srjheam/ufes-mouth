#include <stdio.h>

#define TERRA 0
#define AGUA 1


int estaDentroLimite(int h, int w, int i, int j) {
    if (i < 0 || i >= h || j < 0 || j >= w) {
        return 0;
    }
    
    return 1;
}

int ehTerra(int h, int w, int mapa[h][w], int i, int j) {
    if (!estaDentroLimite(h, w, i, j) || mapa[i][j] == AGUA) {
        return 0;
    }
    
    return 1;
}

int ehAgua(int h, int w, int mapa[h][w], int i, int j) {
    if (!estaDentroLimite(h, w, i, j) || mapa[i][j] == TERRA) {
        return 0;
    }
    
    return 1;
}

int ehBorda(int h, int w, int mapa[h][w], int i, int j) {
    if (ehAgua(h, w, mapa, i, j)
        || ehTerra(h, w, mapa, i - 1, j)
        && ehTerra(h, w, mapa, i - 1, j + 1)
        && ehTerra(h, w, mapa, i, j + 1)
        && ehTerra(h, w, mapa, i + 1, j + 1)
        && ehTerra(h, w, mapa, i + 1, j)
        && ehTerra(h, w, mapa, i + 1, j - 1)
        && ehTerra(h, w, mapa, i, j - 1)
        && ehTerra(h, w, mapa, i - 1, j - 1)) {
        return 0;
    }
    
    return 1;
}

int getPerimetro(int h, int w, int mapa[h][w]) {
    int acc = 0;
    
    int i;
    for (i = 0; i < h; i++) {
        int j;
        for (j = 0; j < w; j++)
            if (ehBorda(h, w, mapa, i, j))
                acc++;

    }

    return acc;
}

int leMapa(int h, int w, int mapa[h][w]) {
    int i;
    for (i = 0; i < h; i++) {
        int j;
        for (j = 0; j < w; j++) {
            scanf("%1d", &mapa[i][j]);
        }
    }
}

void main(void) {
    int w, h;
    scanf("%d %d", &w, &h);

    int mapa[h][w];
    leMapa(h, w, mapa);

    int perimetro = getPerimetro(h, w, mapa);

    printf("%d\n", perimetro);
}
