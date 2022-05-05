#include <stdio.h>

void main(void) {
    char str[100];

    scanf("%[^\n]", str);

    printf("RESP:");
    int i;
    for (i = 0; 1; i++)
    {
        char curr = str[i];
        
        if (curr == ' ')
        {
            printf("_");
        }
        else
        {
            printf("%c", curr);
        }
        
        if (curr == '.' || curr == '!' || curr == '?')
        {
            break;
        }
    }
}
