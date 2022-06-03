#include <stdio.h>
#include <stdlib.h>

void printCoord(int x, int y) {
    printf("(%d,%d)", x, y);
}

int main(void) {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    int supEsqX = x1 < x2 ? x1 : x2;
    int supEsqY = y1 > y2 ? y1 : y2;
    
    int deltaX = abs(x1 - x2);
    int deltaY = abs(y1 - y2);

    printCoord(supEsqX, supEsqY);
    printCoord(supEsqX, supEsqY - deltaY);
    printCoord(supEsqX + deltaX, supEsqY - deltaY);
    printCoord(supEsqX + deltaX, supEsqY);
    printf("%c", '\n');
}
