#include <stdio.h>

/*
 * @return int 0 are equal, 1 f greater than s, -1 lower than s.
 */
int comparaHorario(int fhh, int fmm, int fss, int shh, int smm, int sss) {
    if (fhh == shh) {
        if (fmm == smm) {
            if (fss == sss) {
                return 0;
            }
            else if (fss > sss) {
                return 1;
            }
            else {
                return -1;
            }
        }
        else if (fmm > smm) {
            return 1;
        }
        else {
            return -1;
        }
    }
    else if (fhh > shh) {
        return 1;
    }
    else {
        return -1;
    }
}

int somaHorario(int hh, int mm, int ss) {
    return hh + mm + ss;
}

void main(void) {
    int fstH = 0, fstM = 0, fstS = 0, sndH = 0, sndM = 0, sndS = 0;
    scanf("%d %d %d %d %d %d", &fstH, &fstM, &fstS, &sndH, &sndM, &sndS);

    int compara = comparaHorario(fstH, fstM, fstS, sndH, sndM, sndS);
    if (compara == 0) {
        printf("IGUAIS");
    }
    else {
        int soma = 0;
        if (compara == 1) {
            soma = somaHorario(fstH, fstM, fstS);
        }
        else {
            soma = somaHorario(sndH, sndM, sndS);
        }
        
        printf("RESP:%d", (soma / 10) % 10);
    }
}
