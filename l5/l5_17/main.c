#include <stdio.h>

#define __SIZEOF_TEXT__ 500
#define __SIZEOF_WORD__ 500

int isLetter(char c) {
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

void printWord(char str[__SIZEOF_WORD__]) {
    int i;
    for (i = 0; i < __SIZEOF_WORD__; i++) {
        if (str[i] == '\0') {
            break;
        }
        
        printf("%c", str[i]);
    }
}

void printReverseText(char txt[__SIZEOF_TEXT__][__SIZEOF_WORD__], int actualTextSize) {
    printf(" ");
    int i;
    for (i = actualTextSize - 1; i >= 0; i--) {
        printWord(txt[i]);
        printf(" ");
    }
}

void main(void) {
    char text[__SIZEOF_TEXT__][__SIZEOF_WORD__] = { { "" }};

    int i = 0, j = 0;
    char curr;
    while (scanf("%c", &curr) == 1) {
        if (!isLetter(curr)) {
            if (j != 0) {
                i++;
            }

            text[i][j] = '\0';
            j = 0;
            continue;
        }

        text[i][j] = curr;
        j++;
    }

    printReverseText(text, i);
}
