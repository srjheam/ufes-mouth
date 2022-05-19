#include <stdio.h>
#include <math.h>

int verificapH(float pH) {
    if (pH > 7) {
        return 2;
    }
    else if (pH < 7) {
        return 1;
    }
    else {
        return 0;
    }
}

int verificaGotaChuvaAcida(float pH) {
    return pH < 5.7;
}

float porcentagem(float total, float valor) {
    return (valor / total) * 100;
}

void imprimeResultadosAnalise(float porcentagemGotasChuvaAcida, float porcentagemGotasChuvaNormal) {
    if (porcentagemGotasChuvaNormal >= 75) {
        printf("Chuva Normal %.2f%% %.2f%%", porcentagemGotasChuvaAcida, porcentagemGotasChuvaNormal);
    }
    else if (porcentagemGotasChuvaAcida >= 75) {
        printf("Chuva Acida %.2f%% %.2f%%", porcentagemGotasChuvaAcida, porcentagemGotasChuvaNormal);
    }
    else {
        printf("Chuva com indicios de chuva acida %.2f%% %.2f%%", porcentagemGotasChuvaAcida, porcentagemGotasChuvaNormal);
    }
}

void main(void) {
    int area = 0, density = 0, time = 0;
    scanf("%d %d %d", &area, &density, &time);

    int totalDrops = area * density * time;
    int dropCount = 0, acidDropCount = 0, lowPHCount = 0, neutralPHCount = 0, highPHCount = 0;
    float minPH = 14.0, mostNeutral = .0, maxPH = .0;
    int i;
    for (i = 0; i < totalDrops; i++) {
        float curr = .0;
        scanf("%f", &curr);
        dropCount++;

        if (verificaGotaChuvaAcida(curr)) {
            acidDropCount++;
        }
        switch (verificapH(curr)) {
        case 0:
            neutralPHCount++;
            break;

        case 1:
            lowPHCount++;
            break;

        case 2:
            highPHCount++;
            break;
        }
        if (curr < minPH)
        {
            minPH = curr;
        }
        if (fabs(curr - 7.0) < fabs(mostNeutral - 7.0)) {
            mostNeutral = curr;
        }
        if (curr > maxPH)
        {
            maxPH = curr;
        }
    }

    if (dropCount) {
        printf("%d %d %d %.2f %.2f %.2f\n", lowPHCount, highPHCount, neutralPHCount, minPH, maxPH, mostNeutral);
        float porcentagemGotasChuvaAcida = porcentagem(dropCount, acidDropCount);
        imprimeResultadosAnalise(porcentagemGotasChuvaAcida, 100 - porcentagemGotasChuvaAcida);
    }
    else {
        printf("%s", "Nenhuma gota foi avaliada");
    }
}
