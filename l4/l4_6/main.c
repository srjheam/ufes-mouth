#include <stdio.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} tPonto;

tPonto tPontoContructor(int x, int y) {
    tPonto pnt;

    pnt.x = x;
    pnt.y = y;

    return pnt;
}

float calcDistance(tPonto p1, tPonto p2) {
    int xDistance = p1.x - p2.x;
    int yDistance = p1.y - p2.y;

    return sqrt(pow(xDistance, 2) + pow(yDistance, 2));
}

tPonto readPonto() {
    tPonto ponto;

    scanf("%d %d", &ponto.x, &ponto.y);

    return ponto;
}

typedef struct {
    tPonto pi;
    tPonto pf;
} tReta;

tReta newReta(tPonto pi, tPonto pf) {
    tReta reta;

    reta.pi = pi;
    reta.pf = pf;

    return reta;
}

tPonto getPi(tReta reta) {
    return reta.pi;
}

tPonto getPf(tReta reta) {
    return reta.pf;
}

tReta moveReta(tReta reta, int deltaX, int deltaY) {
    return newReta(tPontoContructor(getPi(reta).x + deltaX, getPi(reta).y + deltaY), tPontoContructor(getPf(reta).x + deltaX, getPf(reta).y + deltaY));
}

float getSize(tReta reta) {
    int xDistance = getPi(reta).x - getPf(reta).x;
    int yDistance = getPi(reta).y - getPf(reta).y;

    return sqrt(pow(xDistance, 2) + pow(yDistance, 2));
}

void printReta(tReta reta) {
    printf("[(%d,%d),(%d,%d)]", getPi(reta).x, getPi(reta).y, getPf(reta).x, getPf(reta).y);
}

tReta readReta() {
    tReta reta;

    tPonto pi = readPonto();
    tPonto pf = readPonto();

    reta = newReta(pi, pf);

    return reta;
}

int getPosRel(tPonto p1, tReta reta) {
    int distancePi = calcDistance(p1, getPi(reta));
    int distancePf = calcDistance(p1, getPf(reta));

    if (distancePi == distancePf) {
        return 0;
    }
    else if (distancePi > distancePf) {
        return 1;
    }
    else {
        return -1;
    }
}

int main(void) {
    int n;
    scanf("%d", &n);

    int i;
    for (i = 0; i < n; i++) {
        tPonto pnt = readPonto();
        tReta reta = readReta();

        int prox = getPosRel(pnt, reta);

        switch (prox)
        {
        case -1:
            printf("INICIO");
            break;
        
        case 0:
            printf("EQUIDISTANTE");
            break;
        
        case 1:
            printf("FIM");
            break;
        }
        printf("%c", '\n');
    }

    return 0;
}