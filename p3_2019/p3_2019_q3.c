#include <stdio.h>

#define CARRO_TIPO_MAX_CHARS 100
#define CONCESSIONARIA_MAX_CARROS 100

typedef struct
{
    int id;
    int pass;
    char tipo[CARRO_TIPO_MAX_CHARS + 1];
    int km;

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

void ListaCarrosConcessionaria(tConcessionaria concessionaria, int pass, int km) {
    int i;
    for (i = 0; i < concessionaria.n; i++) {
        tCarro curr = concessionaria.carros[i];

        int query = 1;
        if (pass != -1) {
            query = query && curr.pass == pass;
        }
        if (km != -1) {
            query = query && curr.km <= km;
        }
        
        if (query) {
            ImprimeCarro(curr);
        }
    }
}

int main() {
    tConcessionaria concessionaria;

    concessionaria = LeCarrosConcessionaria();

    int qtdPassageiros, km, i = 0;
    while(scanf("%d,%d", &qtdPassageiros, &km) == 2) {
        printf("Caso %d:\n", ++i);
        ListaCarrosConcessionaria(concessionaria, qtdPassageiros, km);
    }

    return 0;
}
