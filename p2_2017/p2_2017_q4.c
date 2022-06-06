#include <stdio.h>

int EhLetra(char c) {
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

int EhVogal(char c) {
    return c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U';
}

int ReconheceSimbolo(char c) {
    int result = 0;

    if (c != '*') {
        return 0;
    }
    
    char elem;
    scanf("%c", &elem);
    
    switch (elem)
    {
    case '1':
        result = 1;
        break;
        
    case '2':
        result = 2;
        break;
        
    case '3':
        result = 3;
        break;

    case '*':
        return -1;
        
    default:
        result = -1;
        break;
    }

    while (1) {
        char curr;
        scanf("%c", &curr);
        if (curr == '*') {
            break;
        }
        result = -1;
    }

    return result;
}

void main(void) {
    char curr, cLetra = 0, cVogal = 0, cConsoante = 0;
    while (scanf("%c", &curr) == 1) {
        if (EhLetra(curr) || curr == '.') {
            printf("%c", curr);
            
            if (EhVogal(curr)) {
                cVogal++;
            }
            else {
                cConsoante++;
            }
            cLetra++;
        }
        else if (curr == '*') {
            int simb = ReconheceSimbolo(curr);
            switch (simb) {
            case 1:
                printf("*L:%d V:%d C:%d*", cLetra, cVogal, cConsoante);
                cLetra = 0;
                cConsoante = 0;
                cVogal = 0;
                break;
            
            case 2:
                printf("*V:%d*", cVogal);
                cVogal = 0;
                break;

            case 3:
                printf("*C:%d*", cConsoante);
                cConsoante = 0;
                break;

            case -1:
                printf("*ERRO*");
                break;
            }
        }

        if (curr == '.') {
            break;
        }
    }
}
