#include <stdio.h>

void main(void) {
    char letter;

    scanf("%c", &letter);
    int decimal = (int)letter;

    if (decimal >= 'a' && decimal <= 'z')
    {
        int upperCase = decimal - 32;
        printf("%c(%d)", upperCase, upperCase);
    }
    else if (decimal >= 'A' && decimal <= 'Z')
    {
        printf("A letra deve ser minuscula!");
    }
    else
    {
        printf("Nao e letra!");
    }
}
