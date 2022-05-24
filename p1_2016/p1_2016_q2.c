#include <stdio.h>

void main(void) {
    int a = 0, b = 0;
    scanf("%d %d ", &a, &b);

    int count = 0;
    int i;
    for (i = 0; i < 3; i++) {
        int x = 0, y = 0;
        scanf("%d %d ", &x, &y);

        if (a * x + b == y)
            count++;
    }

    switch (count)
    {
    case 0:
        printf("%s", "Nenhum");
        break;

    case 1:
        printf("%s", "Um");
        break;

    case 2:
        printf("%s", "Dois");
        break;

    case 3:
        printf("%s", "Todos");
        break;
    }
}
