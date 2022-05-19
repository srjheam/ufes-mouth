#include <stdio.h>

/* YES - Presentation differences */
void main(void) {
    int option = 0, n = 0;
    scanf("%d %d ", &option, &n);

    int i;
    char curr = '\0';
    switch (option) {
    case 1:
        while (curr != '.') {
            scanf("%c", &curr);
            if (curr >= 97 && curr <= 122) {
                printf("%c", 97 + (curr - 97 + n) % 26);
            }
            else {
                printf("%c", curr);
            }
        }
        break;
    
    case 2:
        while (curr != '.') {
            scanf("%c", &curr);
            if (curr >= 97 && curr <= 122) {
                int r = (curr - 97 - n) % 26;
                if (r >= 0) {
                    printf("%c", 97 + r);
                }
                else {
                    printf("%c", 122 + r + 1);
                }
                /* ^^ best approach: ` printf("%c", 122 + (curr -122 - n) % 26) ` ^^ */
            }
            else {
                printf("%c", curr);
            }
        }
        break;
    
    default:
        printf("%s", "Operacao invalida.");
        break;
    }
}
