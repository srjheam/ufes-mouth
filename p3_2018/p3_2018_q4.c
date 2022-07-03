#include <stdio.h>
#include <string.h>

#define STR_MAX_LENGTH 1024

void main(void) {
    char strGreatest[STR_MAX_LENGTH] = "", str1[STR_MAX_LENGTH], str2[STR_MAX_LENGTH];
    while (scanf("%s", str1) == 1 && scanf("%s", str2) == 1) {
        int len1 = strlen(str1), len2 = strlen(str2);

        if (len1 == len2) {
            continue;
        }

        int lenGreatest = strlen(strGreatest);
        if (len1 > len2) {
            printf("%s\n", str1);
            if (len1 > lenGreatest)
                strcpy(strGreatest, str1);
        }
        else {
            printf("%s\n", str2);
            if (len2 > lenGreatest)
                strcpy(strGreatest, str2);
        }
    }

    printf("MAX:");
    if (strGreatest[0] == '\0') {
        printf("--");
    }
    else {
        printf("%s", strGreatest);
    }
    printf("\n");
}
