#include <stdio.h>
#include <math.h>

float calcAverage(int x[], int n) {
    float average = 0;
    int i;
    for (i = 0; i < n; i++) {
        average += x[i] / (float)n;
    }

    return average;
}

float calcStd(int x[], int n) {
    float std = 0;
    float average = calcAverage(x, n);

    int i;
    for (i = 0; i < n; i++) {
        std += pow(x[i] - average, 2) / (float)n;
    }

    return sqrt(std);
}

int countAboveAverage(int x[], int n) {
    int count = 0;
    float average = calcAverage(x, n);

    int i;
    for (i = 0; i < n; i++) {
        if (x[i] > average) {
            count++;
        }
    }
    
    return count;
}

void main(void) {
    int n;
    scanf("%d", &n);

    int grades[n];
    int min = __INT_MAX__;
    int max = 0;
    int flunkedCount = 0;

    int i;
    for (i = 0; i < n; i++) {
        int curr;
        scanf("%d", &curr);

        grades[i] = curr;
        if (curr < min) {
            min = curr;
        }
        if (curr > max) {
            max = curr;
        }
        if (curr < 70) {
            flunkedCount++;
        }
    }
    
    float average = calcAverage(grades, n);
    float std = calcStd(grades, n);
    int aboveAvg = countAboveAverage(grades, n);

    printf("MENOR:%d, MAIOR:%d, MEDIA:%.2f, STD:%.2f, ACIMA_MEDIA_CONC:%d, REPROV:%d", min, max, average, std, aboveAvg, flunkedCount);
}
