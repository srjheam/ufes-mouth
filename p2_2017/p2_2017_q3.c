#include <stdio.h>

int QtdDebitoPlaca(int presc) {
    int qtdDebt = 0;

    while (1) {
        char parenteses;
        scanf("%c", &parenteses);

        if (parenteses == '\n') {
            break;
        }

        int debt, ano;
        scanf("%d:%d)", &debt, &ano);
        if (ano <= presc) {
            qtdDebt += debt;
        }
    }
    
    return qtdDebt;
}

int MaiorDebitoCidade() {
    int p;
    scanf("%d%*c", &p);

    int maiorDebito = 0;
    char maiorDebito_c1, maiorDebito_c2, maiorDebito_c3;
    while (1) {
        char c1, c2, c3;
        scanf("%c%c%c", &c1, &c2, &c3);

        if (c1 == 'F' && c2 == 'I' && c3 == 'M') {
            break;
        }

        int debitoTotal = QtdDebitoPlaca(p);
        if (debitoTotal > maiorDebito) {
            maiorDebito_c1 = c1;
            maiorDebito_c2 = c2;
            maiorDebito_c3 = c3;
            maiorDebito = debitoTotal;
        }
    }

    if (maiorDebito == 0) {
        printf("SEM DEBITO!\n");
    }
    else {
        printf("PLACA:%c%c%c DEBITO:%d\n", maiorDebito_c1, maiorDebito_c2, maiorDebito_c3, maiorDebito);
    }
    return maiorDebito;
}

void main(void) {
    int n;
    scanf("%d", &n);

    int i, somaMaioresDebt = 0;
    for (i = 0; i < n; i++) {
        somaMaioresDebt += MaiorDebitoCidade();
    }

    printf("SOMA:%d\n", somaMaioresDebt);
}
