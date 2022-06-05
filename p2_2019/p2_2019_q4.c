#include <stdio.h>

int EhLetraMaiuscula(char c) {
    return c >= 'A' && c <= 'Z';
}

int EhLetraMinuscula(char c) {
    return c >= 'a' && c <= 'z';
}

int EhNumero(char c) {
    return c >= '0' && c <= '9';
}

int AnalisaSenha() {
    scanf("%*c");

    int chCount = 0, haMaiusc = 0, haMinusc = 0, haNumero = 0, haNaoAlfaNum = 0;
    char curr;
    while (scanf("%c", &curr) == 1) {
        if (curr == ')') {
            break;
        }
        

        chCount++;
        if (EhLetraMaiuscula(curr)) {
            haMaiusc = 1;
        }
        else if (EhLetraMinuscula(curr)) {
            haMinusc = 1;
        }
        else if (EhNumero(curr)) {
            haNumero = 1;
        }
        else {
            haNaoAlfaNum = 1;
        }
    }

    if (chCount < 6)
    {
        return 0;
    }
    else if (haMaiusc && haMinusc && haNumero && haNaoAlfaNum) {
        return 2;
    }
    else {
        return 1;
    }
}

void main(void) {
    int n;
    scanf("%d", &n);

    int maxInv_id = 1, maxInv_qtd = -1;
    int maxFrac_id = 1, maxFrac_qtd = -1;
    int maxFort_id = 1, maxFort_qtd = -1;

    int i;
    for (i = 1; i <= n; i++) {
        printf("GRUPO %d\n", i);

        int qtdInv = 0, qtdFrac = 0, qtdFort = 0;
        while (1) {
            int codigo;
            scanf("%d", &codigo);
            if (codigo == -1) {
                break;
            }
            
            switch (AnalisaSenha()) {
            case 0:
                qtdInv++;
                printf("INVALIDA");
                break;

            case 1:
                qtdFrac++;
                printf("FRACA");
                break;

            case 2:
                qtdFort++;
                printf("FORTE");
                break;
            }
            printf("%c", '\n');
        }

        if (qtdInv > maxInv_qtd) {
            maxInv_id = i;
            maxInv_qtd = qtdInv;
        }
        if (qtdFrac > maxFrac_qtd) {
            maxFrac_id = i;
            maxFrac_qtd = qtdFrac;
        }
        if (qtdFort > maxFort_qtd) {
            maxFort_id = i;
            maxFort_qtd = qtdFort;
        }

        printf("%c", '\n');
    }
    
    printf("FORTES: GRUPO(%d) QTD(%d)\n", maxFort_id, maxFort_qtd);
    printf("FRACAS: GRUPO(%d) QTD(%d)\n", maxFrac_id, maxFrac_qtd);
    printf("INVALIDAS: GRUPO(%d) QTD(%d)\n", maxInv_id, maxInv_qtd);
}
