#include <stdio.h>

void main(void) {
    int people = 0, items = 0;

    scanf("%d %d", &people, &items);

    int resp = items % people;
    printf("RESP:%d", resp ? resp : people);
}
