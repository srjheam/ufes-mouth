#include <stdio.h>

void main(void) {
    int n;
    scanf("%d", &n);

    while (n--) {
        int c;
        scanf("%d", &c);

        int arr[c];
        int i;
        for (i = 0; i < c; i++)
            scanf("%d", &arr[i]);
        
        for (i = 0; i < c; i++) {
            int acc = 0;
            int j;
            for (j = 0; j < c; j++)
                if (arr[j] > arr[i])
                    acc++;
            
            printf("%d ", acc);
        }
        printf("\n");
    }
}
