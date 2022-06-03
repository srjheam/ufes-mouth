#include <stdio.h>

void printSoma(int a, int b) {
    int res = a + b;
    printf("SOMA:%d", res);
}

void printSub(int a, int b) {
    int res = a - b;
    printf("SUB:%d", res);
}

void printMult(int a, int b) {
    int res = a * b;
    printf("MULT:%d", res);
}

void printDiv(int a, int b) {
    int div = a / b;
    printf("DIV:%d", div);

    int resto = a % b;
    if (resto) {
        printf(", RESTO:%d", resto);
    }
}

int main(void) {
    int a, b;
    char op;
    scanf("%d %c %d", &a, &op, &b);

    switch (op)
    {
    case '+':
        printSoma(a, b);
        break;

    case '-':
        printSub(a, b);
        break;

    case '*':
        printMult(a, b);
        break;

    case '/':
        printDiv(a, b);
        break;
    }

    return 0;
}
