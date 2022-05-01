#include <stdio.h>
#include <math.h>
#define PI  3.141592

void main(void) {
    float radius = .0;
    scanf("%f", &radius);

    float area = PI * pow(radius, 2);
    float halfAreaRadius = sqrt(area / (2 * PI));
    printf("%.2f %.2f", area, halfAreaRadius);
}
