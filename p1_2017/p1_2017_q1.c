#include <stdio.h>

void main(void) {
    int a = 0, b = 0;
    char op;
    scanf("%d %d %c", &a, &b, &op);

    switch (op)
    {
    case '+':
        printf("RESP:%d", a + b);
        break;
    
    case '-':
        printf("RESP:%d", a - b);
        break;

    case '*':
        printf("RESP:%d", a * b);
        break;

    case '/':
        printf("RESP:%d", a / b);
        break;
    default:
        printf("%s", "Invalido");
        break;
    }
}
