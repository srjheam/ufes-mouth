#include <stdio.h>

void main(void) {
    int menor_n = 0, menor_val = 10;

    int i;
    for (i = 1; i <= 3; i++) {
        int curr = 0;
        scanf("%d", &curr);

        int cent = (curr / 100) % 10;
        if (cent && cent < menor_val) {
            menor_n = i;
            menor_val = cent;
        }
    }
    
    if (menor_n == 0) {
        printf("%s", "Nenhum");
    }
    else {
        printf("N%d", menor_n);
    }
}
