#include <stdio.h>
#include <string.h>

void main(void) {
    char str[100];

    scanf("%[^\n]", str);

    int i;
    for (i = 0; i < strlen(str); i++)
    {
        char curr = str[i];
        
        printf("%c", curr >= 97 && curr <= 122 ? curr - 32 : curr);
    }
}
