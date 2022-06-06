#include <stdio.h>

double LeNotasECalculaMediaAluno () {
    int sum = 0, menor = __INT32_MAX__;

    int c;
    for (c = 0; 1; c++) {
        char end;
        scanf("%c", &end);

        if (end == ']') {
            scanf("%*c");
            break;
        }
        
        int curr;
        scanf("%d", &curr);

        sum += curr;
        if (curr < menor) {
            menor = curr;
        }
    }
    
    if (sum == menor) {
        return menor;
    }
    else {
        return (sum - menor) / (double)(c - 1);
    }
    
}

int ContaAlunosAprovadosTurma () {
    int result = 0;
    
    int a;
    scanf("%d%*c", &a);
    int j;
    for (j = 0; j < a; j++) {
        char c1, c2;
        scanf("%c%c", &c1, &c2);

        double media = LeNotasECalculaMediaAluno();

        if (media >= 70.0) {
            printf("%c\n", c1);
            result++;
        }
    }

    return result;
}

void main(void) {
    int n;
    scanf("%d", &n);

    int maxAprov_id = 1, maxAprov_qtd = 0;
    int minAprov_id = 1, minAprov_qtd = __INT32_MAX__;

    int i;
    for (i = 1; i <= n; i++) {
        printf("TURMA:%d\n", i);

        int qtdAprov = ContaAlunosAprovadosTurma();
        
        if (qtdAprov > maxAprov_qtd) {
            maxAprov_id = i;
            maxAprov_qtd = qtdAprov;
        }
        if (qtdAprov < minAprov_qtd) {
            minAprov_id = i;
            minAprov_qtd = qtdAprov;
        }
    }
    
    printf("MAIOR:TURMA %d MENOR:TURMA %d\n", maxAprov_id, minAprov_id);
}
