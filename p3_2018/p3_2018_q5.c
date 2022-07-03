#include <stdio.h>

#define MAX_DIGITS 50

typedef struct
{
    int length;
    int digits[MAX_DIGITS];
} tBigNum;

tBigNum sumBigNum(tBigNum num1, tBigNum num2) {
    tBigNum result = { num1.length };

    int i, j;
    for (i = MAX_DIGITS - num1.length, j = MAX_DIGITS - num2.length
        ; i < MAX_DIGITS
        ; i++, j++) {
        int columnSum = result.digits[i - 1] + num1.digits[i];
        if (j < MAX_DIGITS) {
            columnSum += num2.digits[j];
        }
        
        int q = columnSum / 10;
        columnSum -= q * 10;

        result.digits[i - 1] = columnSum;
        result.digits[i] = q;
    }
    if (result.digits[MAX_DIGITS - 1] != 0) {
        result.length++;
    }

    return result;
}

void printBigNum(tBigNum this) {
    if (this.digits[MAX_DIGITS - 1] != 0) {
        printf("%d", this.digits[MAX_DIGITS - 1]);
        this.length--;
    }

    int i;
    for (i = MAX_DIGITS  - 2; this.length > 0; i--, this.length--)
        printf("%d", this.digits[i]);
}

tBigNum readBigNum() {
    tBigNum bigNum = { 0, { 0 } };

    int digit;
    int i;
    for (i = MAX_DIGITS - 1; scanf("%d", &digit) == 1; i--) {
        if (digit == -1) {
            break;
        }
        
        bigNum.digits[i] = digit;
        bigNum.length++;
    }

    return bigNum;
}

void main(void) {
    int n;
    scanf("%d", &n);

    while (n--) {
        tBigNum num1 = readBigNum();
        tBigNum num2 = readBigNum();

        tBigNum sum = sumBigNum(num1, num2);

        printBigNum(sum);
        printf("\n");
    }
}
