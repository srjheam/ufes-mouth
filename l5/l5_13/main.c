#include <stdio.h>
#include <stdlib.h>

int ComparaString(char *str1, char *str2);

int main() {
    char str1[1000];
    char str2[1000];
    
    while (scanf("%s", &str1) == 1 && scanf("%s", &str2) == 1) {
        if (ComparaString(str1, str2))
            printf("IGUAL\n");
        else
            printf("DIFERENTE\n");
    }

    return 0;
}

int ComparaString(char *str1, char *str2) {
    int i;
    for (i = 0; str1[i] || str2[i]; i++) {
        if (str1[i] != str2[i]) {
            return 0;
        }
    }
    
    return 1;
}
