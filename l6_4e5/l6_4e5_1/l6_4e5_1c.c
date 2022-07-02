#include <stdio.h>

typedef struct {
    int msgId;
    int pctId;
    int msgSize;
    char msg[9];
    int errorCode;
} tPacote;

tPacote newPacote(int msgId, int pctId, int msgSize, char msg[], int errorCode) {
    tPacote pacote;
    pacote.msgId = msgId;
    pacote.pctId = pctId;
    pacote.msgSize = msgSize;
    pacote.errorCode = errorCode;

    int i;
    for (i = 0; i < msgSize; i++)
        pacote.msg[i] = msg[i];
    
    pacote.msg[msgSize] = '\0';

    return pacote;
}

tPacote LePacote() {
    int msgId, pctId, msgSize;
    scanf("%d %d %1d", &msgId, &pctId, &msgSize);
    
    char msg[msgSize + 1];
    int i;
    for (i = 0; i < msgSize; i++)
        scanf("%c", &msg[i]);

    msg[msgSize] = '\0';

    char curr;
    while (scanf("%c", &curr) == 1) {
        if (curr == ' ') {
            break;
        }
    }

    int errorCode;
    scanf("%d", &errorCode);

    tPacote pct = newPacote(msgId, pctId, msgSize, msg, errorCode);
    return pct;
}

int getPctId(tPacote this) {
    return this.pctId;
}

int getMsgId(tPacote this) {
    return this.msgId;
}

int getPctValue(tPacote this) {
    int value = 0;

    value += this.msgId;
    value += this.pctId;
    value += this.msgSize;

    int i;
    for (i = 0; this.msg[i]; i++)
        value += this.msg[i];

    return value;
}

int ehPacoteValido(tPacote pct) {
    int expected = getPctValue(pct);
    return expected == pct.errorCode;
}

void ImprimePacote(tPacote pct) {
    if (ehPacoteValido(pct)) {
        printf("%s", pct.msg);
    }
    else {
        printf("##FALHA##");
    }
}

void SortPcts(tPacote pcts[], int n) {
    int i;
    for (i = 1; i < n; i++) {
        if (getPctId(pcts[i]) < getPctId(pcts[i - 1])) {
            tPacote tmp = pcts[i];
            pcts[i] = pcts[i - 1];
            pcts[i - 1] = tmp;
            i = 0;
        }
    }
}

typedef struct {
    tPacote pcts[100];
    int size;
    int id;
} tMensagens;

tMensagens newMensagens(tPacote pct) {
    tMensagens mensagens;
    mensagens.pcts[0] = pct;
    mensagens.size = 1;
    mensagens.id = getMsgId(pct);

    return mensagens;
}

int getId(tMensagens this) {
    return this.id;
}

tMensagens addPct(tMensagens this, tPacote pct) {
    if (this.id != getMsgId(pct)) {
        return this;
    }

    this.pcts[this.size] = pct;
    this.size++;

    return this;
}

void ImprimeMensagens(tMensagens msg) {
    SortPcts(msg.pcts, msg.size);

    int i;
    for (i = 0; i < msg.size; i++)
        ImprimePacote(msg.pcts[i]);
}

void SortMsgs(tMensagens msgs[], int n) {
    int i;
    for (i = 1; i < n; i++) {
        if (getId(msgs[i]) < getId(msgs[i - 1])) {
            tMensagens tmp = msgs[i];
            msgs[i] = msgs[i - 1];
            msgs[i - 1] = tmp;
            i = 0;
        }
    }
}

void main(void) {
    int n;
    scanf("%d", &n);

    int msgsCount = 0;
    tMensagens msgs[n];
    while (n--) {
        tPacote pct = LePacote();
        
        int i;
        for (i = 0; i < msgsCount; i++) {
            if (getId(msgs[i]) == getMsgId(pct)) {
                msgs[i] = addPct(msgs[i], pct);
                break;
            }
        }
        if (i == msgsCount) {
            msgs[msgsCount] = newMensagens(pct);
            msgsCount++;
        }
    }

    SortMsgs(msgs, msgsCount);
    int i;
    for (i = 0; i < msgsCount; i++) {
        ImprimeMensagens(msgs[i]);
        if (i < msgsCount - 1) {
            printf("\n");
        }
    }
}
