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

int main(void) {
    int n;
    scanf("%d", &n);

    tPonto last = readPonto();
    printf("-\n");

    while (n > 1) {
        tPonto curr = readPonto();

        printf("%.2f", calcDistance(curr, last));
        printf("%c", '\n');

        last = curr;
        n--;
    }

    return 0;
}