#include <stdio.h>
#include <math.h>

int EhIgual(int a, int b) {
    return a == b;
}

int InverteNumero(int num) {
    int result = 0;

    int length;
    for (length = 0; length <= 10; length++) {
        if (num / (int)pow(10, length) == 0) {
            break;
        }
    }
    
    int i;
    for (i = 1; i <= length; i++) {
        result *= 10;
        result += (num % (int)pow(10, i)) / (int)pow(10, i - 1);
    }
    
    return result;
}

void main(void) {
    int curr, cPalindromos = 0;
    while (scanf("%d%*c", &curr) == 1) {
        int invertido = InverteNumero(curr);
        int ehPalindromo = EhIgual(curr, invertido);

        if (ehPalindromo) {
            cPalindromos++;
        }        
    }
    
    printf("COUNT:%d", cPalindromos);
}
