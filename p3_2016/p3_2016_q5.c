#include <stdio.h>

#define PALAVRA_MAX_CHARS 400

char normalizaChar(char c) {
    if (c < 'A' || c > 'Z') {
        return c;
    }
    
    return c + 32;
}

int estaContido(char *str1, char *str2) {
    int i, j = 0;
    for (i = 0; str2[i]; i++) {
        if (normalizaChar(str1[j]) == normalizaChar(str2[i])) {
            j++;

            if (str1[j] == '\0') {
                return 1;
            }
        }
    }
    
    return 0;
}

void main(void) {
    int c;
    scanf("%d", &c);

    while (c--) {
        char alvo[PALAVRA_MAX_CHARS], palavra[PALAVRA_MAX_CHARS];
        scanf("%s %s", alvo, palavra);

        int contido = estaContido(alvo, palavra);

        if (contido) {
            printf("PODE!\n");
        }
        else {
            printf("NAO PODE!\n");
        }
    }
}
