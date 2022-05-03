#include <stdio.h>
#include <string.h>

void main(void) {
    int value = 0, rank = 0;

    scanf("%d %d", &value, &rank);

    // value.ToString()
    char str[12];
    sprintf(str, "%d", value);

    int strLength = strlen(str);
    int isEven = ((int)str[strLength - rank] - '0') % 2 == 0;

    printf("%s", isEven ? "PAR" : "IMPAR");
}
