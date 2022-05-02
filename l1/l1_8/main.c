#include <stdio.h>
#include <ctype.h>

void main(void) {
    char letter;

    scanf("%c", &letter);
    letter = tolower(letter);

    if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
    {
        printf("Vogal");
    }
    else {
        printf("Nao vogal");
    }    
}
