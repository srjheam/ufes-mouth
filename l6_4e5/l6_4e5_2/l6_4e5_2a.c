#include <stdio.h>

#define CARTELA_MAX_LENGTH 6

typedef struct {
    int id;
    int length;
    int map[CARTELA_MAX_LENGTH][CARTELA_MAX_LENGTH];
} tCartela;

tCartela LeCartela() {
    int id, length;
    scanf("%d %d", &id, &length);

    tCartela cartela = { id, length };

    int j;
    for (j = 0; j < length; j++) {
        int i;
        for (i = 0; i < length; i++) {
            scanf("%d", &cartela.map[i][j]);
        }
    }

    return cartela;
}

void ImprimeCartela(tCartela cartela) {
    printf("ID:%d\n", cartela.id);

    int i;
    for (i = 0; i < cartela.length; i++) {
        int j;
        for (j = 0; j < cartela.length; j++) {
            printf("%03d", cartela.map[i][j]);
            if (j < cartela.length - 1) {
                printf("|");
            }
        }
        printf("\n");
    }
}

int main() {
    tCartela cartela;

    cartela = LeCartela();

    ImprimeCartela(cartela);

    return 0;
}
