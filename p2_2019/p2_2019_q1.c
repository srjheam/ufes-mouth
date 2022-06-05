#include <stdio.h>

void main(void) {
    int custoT1, custoT2, custoT3;
    scanf("%d %d %d", &custoT1, &custoT2, &custoT3);

    int n, acc = 0;
    scanf("%d", &n);
    while (n > 0) {
        int currT;
        scanf("%d", &currT);

        switch (currT) {
        case 1:
            acc += custoT1;
            break;
        
        case 2:
            acc += custoT2;
            break;
            
        case 3:
            acc += custoT3;
            break;
        }
        n--;
    }
    printf("CUSTO:%d\n", acc);
}
