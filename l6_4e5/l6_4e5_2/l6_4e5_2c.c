#include <stdio.h>

#define CARTELA_MAX_LENGTH 6
#define PARTIDA_MAX_CARTELAS 100

typedef struct {
    int id;
    int length;
    int marked;
    int map[CARTELA_MAX_LENGTH][CARTELA_MAX_LENGTH];
} tCartela;

tCartela LeCartela() {
    int id, length;
    scanf("%d %d", &id, &length);

    tCartela cartela = { id, length, 0 };

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

tCartela MarcaCartela(tCartela cartela, int num) {
    int i;
    for (i = 0; i < cartela.length; i++) {
        int j;
        for (j = 0; j < cartela.length; j++) {
            if (cartela.map[i][j] == num) {
                cartela.marked++;
                break;
            }
        }
    }
    
    return cartela;
}

int VenceuCartela(tCartela cartela) {
    return cartela.marked == (cartela.length * cartela.length);
}

tCartela ResetaCartela(tCartela cartela) {
    cartela.marked = 0;

    return cartela;
}

typedef struct {
    int n;
    tCartela cartelas[PARTIDA_MAX_CARTELAS];
} tPartida;

tPartida LeCartelasPartida() {
    tPartida partida;

    int n;
    scanf("%d", &partida.n);

    int i;
    for (i = 0; i < partida.n; i++) {
        partida.cartelas[i] = LeCartela();
    }
    
    return partida;
}

void ImprimeInvCartelasPartida(tPartida partida) {
    while (partida.n--)
        ImprimeCartela(partida.cartelas[partida.n]);
}

tPartida ResetaPartida(tPartida partida) {
    int i;
    for (i = 0; i < partida.n; i++) {
        partida.cartelas[i] = ResetaCartela(partida.cartelas[i]);
    }

    return partida;
}

void JogaPartida(tPartida partida) {
    int hasWinner = 0;

    int m;
    while (scanf("%d", &m) == 1) {
        if (m == -1)
            break;

        if (!hasWinner) {
            int i;
            for (i = 0; i < partida.n; i++) {
                partida.cartelas[i] = MarcaCartela(partida.cartelas[i], m);
                if (VenceuCartela(partida.cartelas[i])) {
                    hasWinner = 1;
                }
            }
        }
    }

    if (!hasWinner) {
        printf("SEM VENCEDOR\n");
        return;
    }
    
    printf("COM VENCEDOR\n");

    int i;
    for (i = 0; i < partida.n; i++)
        if (VenceuCartela(partida.cartelas[i]))
            ImprimeCartela(partida.cartelas[i]);
            
}

int main() {
    tPartida partida;
    int qtdPartidas, i;

    partida = LeCartelasPartida();

    scanf("%d", &qtdPartidas);
    for (i = 0; i < qtdPartidas; i++) {
        if (i!=0) printf("\n");
        printf("PARTIDA %d\n", i+1);
        partida = ResetaPartida(partida);
        JogaPartida(partida);
    }

    return 0;
}
