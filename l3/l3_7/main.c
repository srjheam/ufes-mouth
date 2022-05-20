#include <stdio.h>
#include <stdlib.h>

void main(void) {
    int x1l, y1l, x1r, y1r, x2l, y2l, x2r, y2r;
    scanf("%d %d %d %d %d %d %d %d", &x1l, &y1l, &x1r, &y1r, &x2l, &y2l, &x2r, &y2r);

    int b1 = abs(x1l - x1r);
    int h1 = abs(y1l - y1r);
    int a1 = b1 * h1;

    int b2 = abs(x2l - x2r);
    int h2 = abs(y2l - y2r);
    int a2 = b2 * h2;

    int b1_b2 = 0, h1_h2 = 0;
    if (x2l >= x1l && x2l < x1r) {
        b1_b2 = abs(x2l - x1r);
    }
    else if (x2r > x1l && x2r <= x1r) {
        b1_b2 = abs(x1l - x2r);
    }
    if (y2l >= y1l && y2l < y1r) {
        h1_h2 = abs(y2l - y1r);
    }
    else if (y2r > y1l && y2r <= y1r) {
        h1_h2 = abs(y1l - y2r);
    }
    
    int a1_a2 = b1_b2 * h1_h2;

    int at = a1 + a2 - a1_a2;

    printf("RESP:%d", at);
}
