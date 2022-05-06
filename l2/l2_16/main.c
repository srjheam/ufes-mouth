#include <stdio.h>

void main(void) {
    int stMin = __INT_MAX__, fstPos = __INT_MAX__, lstPos = -1;

    int val = 0;
    while (scanf("%d", &val) == 1) {
        if (val < stMin) {
            stMin = val;
        }
    }

    scanf("%*[^\n]");

    int i;
    for (i = 0; scanf("%d", &val) == 1; i++) {
        if (val == stMin)
        {
            if (i < fstPos)
            {
                fstPos = i;
            }
            if (i > lstPos)
            {
                lstPos = i;
            }
        }
    }

    if (lstPos == -1)
    {
        fstPos = i;
        lstPos = i;
    }
    
    printf("%d %d %d", stMin, fstPos, lstPos);
}
