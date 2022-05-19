#include <stdio.h>

void main(void) {
    printf("%s", "RESP:");

    char c;
    int bracketsCount = 0;
    while (scanf("%c", &c)) {
        if (c == '.' && !bracketsCount)
            break;

        if (c == ')') {
            bracketsCount--;
        }

        if (bracketsCount > 0)
        {
            printf("%c", c);
        }

        if (c == '(') {
            bracketsCount++;
        }
    }
}
