#include <stdio.h>

typedef struct {
    int msgId;
    int pctId;
    int msgSize;
    char *msg;
    int errorCode;
} tPacote;

tPacote LePacote() {
    int msgId, pctId, msgSize;
    scanf("%d %d %1d", &msgId, &pctId, &msgSize);
    
    char msg[msgSize + 1];
    int i;
    for (i = 0; i < msgSize; i++) {
        scanf("%c", &msg[i]);
    }
    msg[msgSize] = '\0';

    char curr;
    while (scanf("%c", &curr) == 1) {
        if (curr == ' ') {
            break;
        }
    }

    int errorCode;
    scanf("%d", &errorCode);

    tPacote pct = { msgId, pctId, msgSize, msg, errorCode };
    return pct;
}

void ImprimePacote(tPacote pacote) {
    printf("PCT: %d,%d,%d,%s,%d\n", pacote.msgId, pacote.pctId, pacote.msgSize, pacote.msg, pacote.errorCode);
}

void main(void) {
    int n;
    scanf("%d", &n);

    while (n--) {
        tPacote pct = LePacote();
        ImprimePacote(pct);
    }
}
