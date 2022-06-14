#include <stdio.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} tPonto;

tPonto newPonto(int x, int y) {
    tPonto pnt;

    pnt.x = x;
    pnt.y = y;

    return pnt;
}

int getQuadrante(tPonto this) {
    if (this.x == 0 && this.y == 0) {
        return 0;
    }

    int rel = 0;
    if (this.x > 0) {
        rel += 1;
    }
    if (this.y > 0) {
        rel += 2;
    }
    
    switch (rel) {
    case 3:
        return 1;
        break;
    
    case 2:
        return 2;
        break;
    
    case 0:
        return 3;
        break;
    
    case 1:
        return 4;
        break;
    }
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

tReta readReta() {
    tReta reta;

    tPonto pi = readPonto();
    tPonto pf = readPonto();

    reta = newReta(pi, pf);

    return reta;
}

int main(void) {
    int n;
    scanf("%d", &n);

    int i;
    for (i = 0; i < n; i++) {
        tReta reta = readReta();
        
        if (getQuadrante(reta.pi) == getQuadrante(reta.pf)) {
            printf("MESMO");
        }
        else {
            printf("DIFERENTE");
        }

        printf("%c", '\n');
    }

    return 0;
}