#include <stdio.h>
#include <string.h>

void main(void) {
    char str[100];

    scanf("%[^\n]", str);

    printf("RESP:");
    int i;
    for (i = 0; i < strlen(str); i++)
    {
        char curr = str[i];

        if (curr != ' ')
        {
            printf("%c", curr);
        }
    }
}
