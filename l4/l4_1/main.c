#include <stdio.h>

typedef struct {
    int codigo;
    float preco;
    int qtdEstoque;
} tProduto;

tProduto LeProduto() {
    int cod, qtd;
    float pre;
    scanf("%d;%f;%d", &cod, &pre, &qtd);

    tProduto result;
    result.codigo = cod;
    result.preco = pre;
    result.qtdEstoque = qtd;

    return result;
}

int EhProduto1MaiorQ2(tProduto p1, tProduto p2) {
    return p1.preco > p2.preco;
}

int EhProduto1MenorQ2(tProduto p1, tProduto p2) {
    return p1.preco < p2.preco;
}

int TemProdutoEmEstoque(tProduto p) {
    return p.qtdEstoque != 0;
}

void ImprimeProduto(tProduto p) {
    printf("COD %d, PRE %.2f, QTD %d", p.codigo, p.preco, p.qtdEstoque);
}

void main(void) {
    int n;
    scanf("%d", &n);

    tProduto caro;
    caro.preco = -1;
    tProduto barato;
    barato.preco = __FLT_MAX__;

    int i;
    for (i = 0; i < n; i++) {
        tProduto curr = LeProduto();

        if (!TemProdutoEmEstoque(curr)) {
            printf("FALTA:");
            ImprimeProduto(curr);
            printf("%c", '\n');
        }

        if (EhProduto1MaiorQ2(curr, caro)) {
            caro = curr;
        }
        if (EhProduto1MenorQ2(curr, barato)) {
            barato = curr;
        }
    }

    printf("MAIOR:");
    ImprimeProduto(caro);
    printf("%c", '\n');
    printf("MENOR:");
    ImprimeProduto(barato);
    printf("%c", '\n');
}
