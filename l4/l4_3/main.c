#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} tData;

tData tDataConstructor(int dia, int mes, int ano) {
    tData data;
    int diasNoMes;

    data.ano = ano;
    data.mes = mes;
    data.dia = dia;

    if (mes > 12) {
        data.mes = 12;
    }
    else if (mes < 1) {
        data.mes = 1;
    }

    diasNoMes = getDiasNoMes(data);
    if (dia > diasNoMes) {
        data.dia = diasNoMes;
    }
    else if (dia < 1) {
        data.dia = 1;
    }
    
    return data;
}

int ehBissexto(int ano) {
    return ((ano % 4 == 0) && (ano % 100 != 0)) || (ano % 400 == 0);
}

int getDiasNoMes(tData data) {
    if (data.mes == 2) {
        if (ehBissexto(data.ano) ) {
            return 29;
        }

        return 28;
    }

    if (data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11) {
        return 30;
    }

    return 31;
}

/*
 * @returns
 *      -1: lower than
 *       0: equals
 *       1: greater than
 */
int CompareTo(tData a, tData b){
    if (a.dia == b.dia && a.mes == b.mes && a.ano == b.ano) {
        return 0;
    }

    if (a.ano > b.ano) {
        return 1;
    }
    else if (a.ano < b.ano){
        return -1;
    }
    
    if (a.mes > b.mes) {
        return 1;
    }
    else if (a.mes < b.mes){
        return -1;
    }

    if (a.dia > b.dia) {
        return 1;
    }
    else if (a.dia < b.dia){
        return -1;
    }
}

void printData(tData this) {
    printf("'%02d/%02d/%04d'", this.dia, this.mes, this.ano);
}

tData readData() {
    tData data;
    int dd, mm, aa;

    scanf("%d %d %d", &dd, &mm, &aa);
    
    data = tDataConstructor(dd, mm, aa);
    
    return data;
}

tData nextData(tData this)                                               
{
    if (this.dia < getDiasNoMes(this)) {
        this.dia++;
    }
    else {
        this.dia = 1;
        if (this.mes < 12) {
            this.mes++;
        }
        else {
            this.mes = 1;
            this.ano++;
        }
    }

    return this;
}

void main(void)
{
    int n;
    scanf("%d", &n);

    while (n > 0)
    {
        tData curr = readData();

        printData(curr);
        if (ehBissexto(curr.ano)) {
            printf(":Bisexto\n");
        }
        else {
            printf(":Normal\n");
        }

        n--;
    }
}

