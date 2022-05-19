#include <stdio.h>

float Soma(float num1, float num2) {
    return num1 + num2;
}

float Subtracao(float num1, float num2) {
    return num1 - num2;
}

float Divisao(float num1, float num2) {
    return num1 / num2;
}

float Multiplicacao(float num1, float num2) {
    return num1 * num2;
}

int main()
{
    float operand1 = .0, operand2 = .0;
    char operator;
    scanf("%f", &operand1);
    while (scanf("%f %c ", &operand2, &operator) == 2)
    {
        switch (operator) {
        case '+':
            operand1 = Soma(operand1, operand2);
            break;
        
        case '-':
            operand1 = Subtracao(operand1, operand2);
            break;
        
        case '/':
            operand1 = Divisao(operand1, operand2);
            break;
        
        case '*':
            operand1 = Multiplicacao(operand1, operand2);
            break;
        }
    }
    printf("%.2f", operand1);
    return 0;
}
