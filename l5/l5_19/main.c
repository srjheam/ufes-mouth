#include <stdio.h>

#define LAND 0
#define WATER 1

int isInsideBounds(int l, int c, int x, int y) {
    if (x < 0 || x >= l || y < 0 || y >= c) {
        return 0;
    }
    
    return 1;
}

int isLand(int h, int w, int map[h][w], int x, int y) {
    if (!isInsideBounds(h, w, x, y) || map[x][y] == WATER) {
        return 0;
    }
    
    return 1;
}

int isWater(int h, int w, int map[h][w], int x, int y) {
    if (!isInsideBounds(h, w, x, y) || map[x][y] == LAND) {
        return 0;
    }
    
    return 1;
}

int isBorder(int h, int w, int map[h][w], int x, int y) {
    if (isWater(h, w, map, x, y)
        || isLand(h, w, map, x, y - 1)
        && isLand(h, w, map, x + 1, y)
        && isLand(h, w, map, x, y + 1)
        && isLand(h, w, map, x - 1, y)) {
        return 0;
    }
    
    return 1;
}

void simulTideAdvnc(int h, int w, int map[h][w], int newMap[h][w], int t) {
    if (t <= 0) {
        return;
    }

    int i;
    for (i = 0; i < h; i++) {
        int j;
        for (j = 0; j < w; j++) {
            if (isBorder(h, w, map, i, j)) {
                newMap[i][j] = WATER;
            }
            else {
                newMap[i][j] = map[i][j];
            }
        }
    }

    for (i = 0; i < h; i++) {
        int j;
        for (j = 0; j < w; j++) {
            map[i][j] = newMap[i][j];
        }
    }

    simulTideAdvnc(h, w, map, newMap, t - 1);
}

int getLandArea(int h, int w, int map[h][w]) {
    int result = 0;
    
    int i;
    for (i = 0; i < h; i++) {
        int j;
        for (j = 0; j < w; j++) {
            if (isLand(h, w, map, i, j)) {
                result++;
            }
        }
    }

    return result;
}

int ReadMap(int l, int c, int arr[l][c]) {
    int i;
    for (i = 0; i < l; i++) {
        int j;
        for (j = 0; j < c; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
}

void main(void) {
    int hours, w, h;
    scanf("%d %d %d", &hours, &w, &h);

    int map[h][w];
    ReadMap(h, w, map);

    int initialLand = getLandArea(h, w, map);

    int newMap[h][w];
    simulTideAdvnc(h, w, map, newMap, hours);

    int finalLand = getLandArea(h, w, newMap);

    printf("%d %d\n", initialLand, finalLand);
}
