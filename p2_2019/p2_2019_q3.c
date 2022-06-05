#include <stdio.h>

int EhDigito(char c) {
    return c >= '0' && c <= '9';
}

char LeProxChar(char terminador) {
    char c;

    if (scanf("%c", &c) != 1 || c == terminador) {
        return 0;
    }
    
    return c;
}

void ImprimePorExtenso(char digito) {
    switch (digito)
    {
    case '0':
        printf("zero");
        break;
    
    case '1':
        printf("um");
        break;
    
    case '2':
        printf("dois");
        break;
    
    case '3':
        printf("tres");
        break;
    
    case '4':
        printf("quatro");
        break;
    
    case '5':
        printf("cinco");
        break;
    
    case '6':
        printf("seis");
        break;
    
    case '7':
        printf("sete");
        break;
    
    case '8':
        printf("oito");
        break;
    
    case '9':
        printf("nove");
        break;
    }
}

void main(void) {
    char d;
    scanf("%c%*c", &d);

    char curr, last = -1;
    int counter = 0;
    do {
        curr = LeProxChar(d);

        if (!EhDigito(curr)) {
            if (EhDigito(last) && counter == 1) {
                ImprimePorExtenso(last);
            }

            counter = 0;
        }
        else {
            if (counter == 1) {
                printf("%c", last);
            }
            counter++;
        }

        if (curr != 0 && counter != 1) {
            printf("%c", curr);
        }
        
        last = curr;
    } while (curr != 0);
}
