#include <stdio.h>

int EhProduto(char prd) {
    if (prd >= 'A' && prd <= 'Z') {
        return 1;
    }
    return 0;
}

int AcabaramOsProdutos(char prd) {
    return prd == '0';
}

int QtdDoProdutoMaisComprado() {
    int maxQtd = 0;

    char lastProd = 0, currQtd = 1;
    while (1) {
        char currProd;
        scanf("%c", &currProd);

        if (AcabaramOsProdutos(currProd)) {
            break;
        }

        if (EhProduto(currProd)) {
            if (currProd == lastProd) {
                currQtd++;
            }
            else {
                lastProd = currProd;
                currQtd = 1;
            }
            if (currQtd > maxQtd) {
                maxQtd = currQtd;
            }
        }
        else {
            lastProd = 0;
            currQtd = 0;
        }
    }
    
    return maxQtd;
}

int main(void) {
    int guloso_id = 0, guloso_qtd = -1;

    while (1) {
        int id;
        scanf("%d%*c", &id);

        if (id == -1) {
            break;
        }
        
        int qtd = QtdDoProdutoMaisComprado();

        if (qtd > guloso_qtd) {
            guloso_id = id;
            guloso_qtd = qtd;
        }
    }

    printf("CLIENT:%d QTD:%d", guloso_id, guloso_qtd);
}
