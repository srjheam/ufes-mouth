#include <stdio.h>

void main(void) {
    char c1;
    int n1, n2;
    scanf("(%c,%d,%d)", &c1, &n1, &n2);

    int thousandsN1 = n1 / 1000;
    int hundredsN1 = (n1 / 100) % 10;
    int tensN1 = (n1 / 10) % 10;
    int onesN1 = n1 % 10;

    int thousandsN2 = n2 / 1000;
    int hundredsN2 = (n2 / 100) % 10;
    int tensN2 = (n2 / 10) % 10;
    int onesN2 = n2 % 10;

    if (c1 >= 'a' && c1 <= 'z' || c1 >= 'A' && c1 <= 'Z') {
        int merge = 0;
        merge += thousandsN2 * 1e7;
        merge += thousandsN1 * 1e6;
        merge += hundredsN2 * 1e5;
        merge += hundredsN1 * 1e4;
        merge += tensN2 * 1e3;
        merge += tensN1 * 1e2;
        merge += onesN2 * 1e1;
        merge += onesN1 * 1e0;

        printf("(%d)\n", merge);
    }
    else {
        int merge = 0;
        merge += thousandsN1 * 1e7;
        merge += thousandsN2 * 1e6;
        merge += hundredsN1 * 1e5;
        merge += hundredsN2 * 1e4;
        merge += tensN1 * 1e3;
        merge += tensN2 * 1e2;
        merge += onesN1 * 1e1;
        merge += onesN2 * 1e0;

        printf("(%d)\n", merge);

    }
}
