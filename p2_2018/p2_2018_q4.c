#include <stdio.h>

int ReduzInteiro(int n) {
    if (n == 0) {
        return 0;
    }

    int reduzido = n % 9;

    return reduzido ? reduzido : 9;
}

int MontaSenha(int senha, int dig) {
    return senha * 10 + dig;
}

int ReduzCodigo() {
    int result = 0;

    char curr, count = 0;
    while (scanf("%c", &curr) == 1) {
        if (curr == ')') {
            break;
        }
        
        result = ReduzInteiro(result + (curr - '0'));
        count++;
    }
    
    return count > 0 ? result : -1;
}

int main(void) {
    int senha = 0;
    while (1) {
        char curr;
        scanf("%c", &curr);

        if (curr == '(') {
            int digito = ReduzCodigo();
            
            if (digito == -1) {
                printf("[ERRO]");
            }
            else {
                printf("[%d]", digito);
                senha = MontaSenha(senha, digito);
            }
        }
        else {
            printf("%c", curr);
        }

        if (curr == '.') {
            break;
        }
    }

    printf(" SENHA:%d\n", senha);
    return 0;
}