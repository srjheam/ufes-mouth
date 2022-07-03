#include <stdio.h>

#define CARRO_TIPO_MAX_CHARS 100
#define CONCESSIONARIA_MAX_CARROS 100

typedef struct
{
    int id;
    int pass;
    char tipo[CARRO_TIPO_MAX_CHARS + 1];
    int km;
    int cliente;
} tCarro;

tCarro LeCarro() {
    tCarro carro;

    scanf("%d %d ", &carro.id, &carro.pass);
    
    char curr;
    int i;
    for (i = 0; scanf("%c", &curr) == 1 && curr != ' '; i++)
        carro.tipo[i] = curr;

    carro.tipo[i] = '\0';

    scanf("%d", &carro.km);

    carro.cliente = -1;

    return carro;
}

void ImprimeCarro(tCarro carro) {
    printf("CARRO (%d): %s de %d passageiros e com %d km\n", carro.id, carro.tipo, carro.pass, carro.km);
}

int ObtemNumPassageirosCarro(tCarro carro) {
    return carro.pass;
}

int ObtemKmCarro(tCarro carro) {
    return carro.km;
}

int ObtemClienteAlugouCarro(tCarro carro) {
    return carro.cliente;
}

int EstaDisponivelCarro(tCarro carro) {
    return carro.cliente == -1;
}

tCarro AlugaCarro(tCarro carro, int cliente) {
    carro.cliente = cliente;
    
    return carro;
}

tCarro DevolveCarro(tCarro carro) {
    carro.cliente = -1;

    return carro;
}

typedef struct
{
    int n;
    tCarro carros[CONCESSIONARIA_MAX_CARROS];
} tConcessionaria;

tConcessionaria LeCarrosConcessionaria() {
    int n;
    scanf("%d", &n);

    tConcessionaria concessionaria = { n };

    int i;
    for (i = 0; i < n; i++)
        concessionaria.carros[i] = LeCarro();
    

    return concessionaria;
}

tConcessionaria AlugaCarroConcessionaria(tConcessionaria concessionaria, int cliente, int pass, int km) {
    int i;
    for (i = 0; i < concessionaria.n; i++) {
        tCarro curr = concessionaria.carros[i];

        int query = EstaDisponivelCarro(curr);
        if (pass != -1) {
            query = query && curr.pass == pass;
        }
        if (km != -1) {
            query = query && curr.km <= km;
        }
        
        if (query) {
            concessionaria.carros[i] = AlugaCarro(curr, cliente);
            printf("Alugado (cliente %d) -> ", cliente);
            ImprimeCarro(curr);
            return concessionaria;
        }
    }

    printf("Carro Indisponivel\n");
    return concessionaria;
}

tConcessionaria DevolveCarroConcessionaria(tConcessionaria concessionaria, int cliente) {
    int i;
    for (i = 0; i < concessionaria.n; i++) {
        tCarro curr = concessionaria.carros[i];
        if (ObtemClienteAlugouCarro(curr) == cliente) {
            concessionaria.carros[i] = DevolveCarro(curr);
            printf("Devolvido (cliente %d) -> ", cliente);
            ImprimeCarro(curr);
        }
    }

    return concessionaria;
}

int main() {
    tConcessionaria concessionaria;

    concessionaria = LeCarrosConcessionaria();

    int cliente;
    char evento;
    while(scanf("%d,%c", &cliente, &evento) == 2) {
        switch (evento) {
        case 'A':;
            int qtdPass, km;
            scanf("%d,%d", &qtdPass, &km);
            concessionaria = AlugaCarroConcessionaria(concessionaria, cliente, qtdPass, km);
            break;

        case 'D':
            concessionaria = DevolveCarroConcessionaria(concessionaria, cliente);
            break;
        }
    }

    return 0;
}
