#include <stdio.h>

void main(void) {
	float val = .0;
	scanf("%f", &val);
	printf("INTEIRO:%d,REAL:%.2f", (int)val, val - (int)val);
}
