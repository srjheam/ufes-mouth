#include <stdio.h>

void main(void) {
    int n = 0;
    scanf("%d", &n);

    int i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0, i6 = 0, i7 = 0, i8 = 0, i9 = 0;
    int i;
    for (i = 1; i <= n; i++) {
        int curr = 0;
        scanf("%d", &curr);

        switch (i)
        {
        case 1:
            i1 = curr;
            break;
        
        case 2:
            i2 = curr;
            break;
        
        case 3:
            i3 = curr;
            break;
        
        case 4:
            i4 = curr;
            break;
        
        case 5:
            i5 = curr;
            break;
        
        case 6:
            i6 = curr;
            break;
        
        case 7:
            i7 = curr;
            break;
        
        case 8:
            i8 = curr;
            break;
        
        case 9:
            i9 = curr;
            break;
        }
    }
    scanf("%*c%*c");
    
    while (1)
    {
        char ch = '\0';
        scanf("%c", &ch);

        if (ch == '\"')
            break;
        
        if (ch == '%') {
            int index = 0;
            scanf("%d", &index);

            if (index < 1 || index > n) {
                printf("%s", "ERRO");
                continue;
            }
            
            int val = 0;
            switch (index) {
            case 1:
                val = i1;
                break;

            case 2:
                val = i2;
                break;

            case 3:
                val = i3;
                break;

            case 4:
                val = i4;
                break;

            case 5:
                val = i5;
                break;

            case 6:
                val = i6;
                break;

            case 7:
                val = i7;
                break;

            case 8:
                val = i8;
                break;

            case 9:
                val = i9;
                break;
            }

            printf("%d", val);
        }
        else {
            printf("%c", ch);
        }
    }
}
