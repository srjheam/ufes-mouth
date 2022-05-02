#include <stdio.h>

void main(void) {
    int values[3];

    scanf("%d %d %d", &values[0], &values[1], &values[2]);

    int sequence[3] =  { 0, 1, 2 };
    int i;
    for (i = 0; i < 3; i++)
    {
        int j;
        for (j = i + 1; j < 3; j++)
        {
            if (values[sequence[i]] > values[sequence[j]])
            {
                int tmp = sequence[i];
                sequence[i] = sequence[j];
                sequence[j] = tmp;
            }
        }
    }
    
    printf("N%d = %d, N%d = %d, N%d = %d", sequence[0] + 1, values[sequence[0]], sequence[1] + 1, values[sequence[1]], sequence[2] + 1, values[sequence[2]]);
}
