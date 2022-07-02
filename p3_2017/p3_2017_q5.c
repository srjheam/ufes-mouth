#include <stdio.h>

void LeArr(int seq[], int n) {
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &seq[i]);
}

void ShiftSeq(int seq[], int n) {
    int tmp = seq[n - 1];
    int i;
    for (i = n - 1; i > 0; i--)
        seq[i] = seq[i - 1];

    seq[0] = tmp;
}

void PrintSeq(int seq[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d", seq[i]);  
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

void main(void) {
    int s;
    while (scanf("%d", &s) == 1) {
        int seq[s];
        LeArr(seq, s);

        int mov;
        while (scanf("%d", &mov) == 1) {
            if (mov == -1) {
                break;
            }

            while (mov--)            
                ShiftSeq(seq, s);

            PrintSeq(seq, s);
        }
    }
    scanf("\n");
}
