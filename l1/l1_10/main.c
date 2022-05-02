#include <stdio.h>

void main(void) {
    int val = 0;

    scanf("%d", &val);

    if (val % 2 == 0) {
        printf("Par");
    }
    else {
        printf("Impar");
    }
}
