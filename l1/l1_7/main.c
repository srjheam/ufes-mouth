#include <stdio.h>

void main(void) {
    int temperature = 0;
    char unit;

    scanf("%d %c", &temperature, &unit);

    if (unit == 'F' || unit == 'f') {
        // cast from fahrenheit to celsius
        printf("%.2f (C)", (temperature - 32) / 1.8);
    }
    else {
        // cast from celsius to fahrenheit
        printf("%.2f (F)", 1.8 * temperature + 32);
    }
}
