#include <stdio.h>

void pad(int n, char c) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%c", c);
    }
}  

void padUnderscores(int n) {
    pad(n, '_');
}

void padDollarSigns(int n) {
    pad(n, '$');
}

int main() {
    int topo, meio;
    scanf("%d %d", &topo, &meio);
    
    int i = topo, pace = 1;
    while (i > 0) {
        int padHalf = (meio - i) / 2;
        padUnderscores(padHalf);
        padDollarSigns(i);
        padUnderscores(padHalf);
        printf("%c", '\n');
        
        if (i == meio) {
            pace = -1;
        }
        
        i += 2 * pace;
    }
}

