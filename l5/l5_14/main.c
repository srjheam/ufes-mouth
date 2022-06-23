#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codigo;
    char sobrenome[21];
    char nome[21];
    int nota;
    int idade;
} tCandidato;

tCandidato LeCandidato();
void ImprimeCandidato(tCandidato candidato);

int ComparaString(char *str1, char *str2);

int main() {
    int qtdCand, i = 0;

    scanf("%d", &qtdCand);
    tCandidato candidatos[qtdCand];

    for (i = 0; i < qtdCand; i++) {
        candidatos[i] = LeCandidato();
    }

    for (i = 0; i < qtdCand; i++) {
        tCandidato curr = candidatos[i];
        if (curr.codigo == NULL) {
            continue;
        }

        int j, candPrinted = 0;
        for (j = i + 1; j < qtdCand; j++) {
            tCandidato comparer = candidatos[j];
            if (ComparaString(curr.sobrenome, comparer.sobrenome)) {
                if (!candPrinted)
                {
                    ImprimeCandidato(curr);
                    candidatos[i].codigo = NULL;
                    candPrinted = 1;
                }
                
                ImprimeCandidato(comparer);
                candidatos[j].codigo = NULL;
            }
        }
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
    printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n", candidato.codigo, candidato.nome, candidato.sobrenome, candidato.nota, candidato.idade);
}

int ComparaString(char *str1, char *str2) {
    int i;
    for (i = 0; str1[i] || str2[i]; i++) {
        if (str1[i] != str2[i]) {
            return 0;
        }
    }
    
    return 1;
}
