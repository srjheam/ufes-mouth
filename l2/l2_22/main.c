#include <stdio.h>

void main(void) {
    char c;
    int sum = 0;
    while (scanf("%c", &c)) {
        if (c == '\n')
        {
            break;
        }

        sum += c - 48;
    }
    int r = sum % 9;
    printf("RESP:%d", r ? r : 9);
}
