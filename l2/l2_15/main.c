#include <stdio.h>

void main(void) {
    int i, neg = 0, pos = 0, negSum = 0, posSum = 0;

    int val = 0;
    while(scanf("%d%*c", &val) != EOF) {
        if (val > 0) {
            pos++;
            posSum += val;
        }
        else if (val < 0) {
            neg++;
            negSum += val;
        }
    }
    
    printf("%d %d %d %d", neg, pos, negSum, posSum);
}
