#include <stdio.h>
#include <math.h>

typedef struct
{
    int x;
    int y;
} tPonto;

tPonto tPontoContructor(int x, int y) {
    tPonto pnt;

    pnt.x = x;
    pnt.y = y;

    return pnt;
}

int getX(tPonto this) {
    return this.x;
}

tPonto setX(tPonto this, int x) {
    this.x = x;
    
    return this;
}

int getY(tPonto this) {
    return this.y;
}

tPonto setY(tPonto this, int y) {
    this.y = y;

    return this;
}

tPonto moveCoordinates(tPonto this, int deltaX, int deltaY) {
    this.x += deltaX;
    this.y += deltaY;

    return this;
}

float calcDistance(tPonto p1, tPonto p2) {
    int xDistance = p1.x - p2.x;
    int yDistance = p1.y - p2.y;

    return sqrt(pow(xDistance, 2) + pow(yDistance, 2));
}

int getQuadrante(tPonto this) {
    if (this.x == 0 || this.y == 0) {
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

tPonto getSimetrico(tPonto this) {
    this.x *= -1;
    this.y *= -1;

    return this;
}

void printPonto(tPonto this) {
    printf("(%d,%d)", this.x, this.y);
}

tPonto readPonto() {
    tPonto ponto;

    scanf("%d %d", &ponto.x, &ponto.y);

    return ponto;
}

void main(void) {
    int n;
    scanf("%d", &n);

    while (n > 0) {
        tPonto curr = readPonto();
        printPonto(curr);
        printf(" %d ", getQuadrante(curr));

        tPonto simetrico = getSimetrico(curr);
        printPonto(simetrico);
        printf(" %d", getQuadrante(simetrico));

        printf("%c", '\n');
        n--;
    }
}
