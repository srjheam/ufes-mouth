#include <stdio.h>
#include <math.h>

int EhPalindromo(int num) {
    int numLength;
    for (numLength = 1; (int)(num / pow(10, numLength)); numLength++);
    
    int fstHalf = num % (int)pow(10, numLength / 2);
    int sndHalf = num / (int)pow(10, (numLength / 2) + (numLength % 2 ? 1 : 0));
    int i, acc = 0;
    for (i = 0; i < numLength / 2; i++) {
        acc += (int)((sndHalf % (int)pow(10, i + 1)) / pow(10, i)) * pow(10, numLength / 2 - 1 - i);
    }

    return fstHalf == acc;
}

void main(void) {
    char c;
    int i, num = 0;
    for (i = 0; scanf("%c", &c); i++) {
        if (c == '\n') {
            if (i == 0) {
                break;
            }
            
            printf("%c\n", EhPalindromo(num) ? 'S' : 'N');
            num = 0;
            i = -1;
        }
        else {
            num = num * 10 + (c - 48);
        }
    }
}
