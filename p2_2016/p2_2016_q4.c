#include <stdio.h>
#include <limits.h>

float FazOperacao(float num1, float num2, char op) {
    switch (op)
    {
    case '+':
        return num1 + num2;
        break;
    
    case '-':
        return num1 - num2;
        break;
    
    case '*':
        return num1 * num2;
        break;
    
    case '/':
        return num1 / num2;
        break;
    }
}

float ResolveExpressao() {
    float num1 = .0;

    scanf("%f", &num1);

    while (1) {
        float num2;
        char op, end;
        scanf("%f %c%c", &num2, &op, &end);

        num1 = FazOperacao(num1, num2, op);

        if (end == ')') {
            break;
        }
    }
    
    return num1;
}

void main(void) {
    float greatest = INT_MIN;
    while (1)
    {
        char curr;
        scanf("%c", &curr);

        if (curr == '(') {
            float result = ResolveExpressao();
            printf("%.2f", result);

            if (result > greatest) {
                greatest = result;
            }
        }
        else {
            printf("%c", curr);
        }

        if (curr == '.') {
            break;
        }
    }
    printf(" MAIOR:%.2f", greatest);
}
