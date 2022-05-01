#include <stdio.h>
#include <math.h>

void main(void) {
    float x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
    printf("%.2f", 2 * fabs(x2 - x1) + 2 * fabs(y2 - y1));
}
