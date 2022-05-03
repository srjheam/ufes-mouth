#include <stdio.h>

void main(void) {
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
	scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

	int isInside = 0;
	isInside = (x1 < x2 ? x1 : x2) <= x3 && x3 <= (x1 > x2 ? x1 : x2);
	if (isInside) {
		isInside = (y1 < y2 ? y1 : y2) <= y3 && y3 <= (y1 > y2 ? y1 : y2);
	}
	else {
		isInside = 0;
	}

	printf("%s", isInside ? "Dentro" : "Fora");
}

