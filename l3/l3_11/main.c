#include <stdio.h>

int EhPar (int x) {
    return !(x % 2);
}

void PrintaPares (int N) {
    int i, val = 2;
    for (i = 0; i < N; i++)
    {
        printf("%d ", val);
        val += 2;
    }
}

void PrintaImpares (int N) {
    int i, val = 1;
    for (i = 0; i < N; i++)
    {
        printf("%d ", val);
        val += 2;
    }
}

void main(void) {
    int type = 0, n = 0;
    scanf("%d %d", &type, &n);

    if (type == 0)
        PrintaPares(n);
    else if (type == 1)
        PrintaImpares(n);
}
