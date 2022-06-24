#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int codigo;
    char sobrenome[21];
    char nome[21];
    int nota;
    int idade;
} tCandidato;

tCandidato LeCandidato();
void ImprimeCandidato(tCandidato candidato);

int CompareTo(tCandidato this, tCandidato obj);
void OrdenaDecrescente(tCandidato *vet, int qtd);

int main() {
    int qtdCand, i = 0, j;

    scanf("%d", &qtdCand);
    tCandidato candidatos[qtdCand];

    for (i = 0; i < qtdCand; i++) {
        candidatos[i] = LeCandidato();
    }

    OrdenaDecrescente(candidatos, qtdCand);

    for (i = 0; i < qtdCand; i++) {
        ImprimeCandidato(candidatos[i]);
    }

    return 0;
}

tCandidato LeCandidato() {
    tCandidato candidato;
    scanf("%*[^{]");
    scanf("%*[{ ]");
    scanf("%d", &candidato.codigo);
    scanf("%*[, ]");
    scanf("%[^,],", candidato.sobrenome);
    scanf("%*[ ]");
    scanf("%[^,],", candidato.nome);
    scanf("%d", &candidato.nota);
    scanf("%*[, ]");
    scanf("%d", &candidato.idade);
    scanf("%*[^\n]\n");
    return candidato;
}

void ImprimeCandidato(tCandidato candidato) {
    printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n",
           candidato.codigo, candidato.nome,
           candidato.sobrenome, candidato.nota, candidato.idade);
}

int CompareTo(tCandidato this, tCandidato obj) {
    int result = 0;

    if (this.nota > obj.nota) {
        return 1;
    }
    else if (this.nota == obj.nota) {
        if (this.idade < obj.idade) {
            return 1;
        }
        else if (this.idade == obj.idade) {
            if (this.codigo < obj.codigo) {
                return 1;
            }
            else if (this.codigo == obj.codigo) {
                return 0;
            }
        }
    }
    
    return -1;
}

void OrdenaDecrescente(tCandidato *vet, int qtd) {
    int i;
    for (i = 1; i < qtd; i++) {
        if (CompareTo(vet[i], vet[i - 1]) > 0) {
            tCandidato tmp = vet[i];
            vet[i] = vet[i - 1];
            vet[i - 1] = tmp;
            i = 0;
        }
    }
}
