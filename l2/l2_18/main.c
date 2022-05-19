#include <stdio.h>

void main(void) {
	int l = 0, c = 0, max = -32767, maxL = 0, maxC = 0;

	scanf("%d %d", &l, &c);

	int i;
	for (i = 0; i < l; i++) {
		int j;
		for (j = 0; j < c; j++) {
			int curr = 0;
			scanf("%d", &curr);

			if (curr >= max) {
				max = curr;
				maxL = i + 1;
				maxC = j + 1;
			}
		}
	}

	printf("%d (%d, %d)", max, maxL, maxC);
}

