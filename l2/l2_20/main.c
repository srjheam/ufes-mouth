#include <stdio.h>
#include <math.h>

#define NONE 0
#define DECREASING 1
#define INCREASING 2

void main(void) {
    float a = .0, b = .0, c = .0, d =.0;
    int min = 0, max = 0;
    scanf("%f %f %f %f %d %d", &a, &b, &c, &d, &min, &max);

    /*
     * None = 0,
     * Decreasing = 1,
     * Increasing = 2
     */
    int slopeEnum = 0;
    float lastValue = __FLT_MIN__;
    int peakCount = 0, valleyCount = 0;
    int i;
    for (i = min; i <= max; i++) {
        float curr = a * pow(i, 3) + b * pow(i, 2) + c * i + d;
        switch (slopeEnum) {
        case DECREASING:
            if (curr > lastValue){
                printf("Vale em x=%d\n", i - 1);
                slopeEnum = INCREASING;
                valleyCount++;
            }
            break;
        
        case INCREASING:
            if (curr < lastValue){
                printf("Pico em x=%d\n", i - 1);
                slopeEnum = DECREASING;
                peakCount++;
            }
            
            break;
        
        default:
            if (lastValue == __FLT_MIN__)
                break;
            
            if (curr < lastValue) {
                slopeEnum = DECREASING;
            }
            else if (curr > lastValue) {
                slopeEnum = INCREASING;
            }
        }
        lastValue = curr;
    }

    if (!peakCount)
    {
        printf("%s", "Nao ha pico\n");
    }
    if (!valleyCount)
    {
        printf("%s", "Nao ha vale");
    }
    
}
