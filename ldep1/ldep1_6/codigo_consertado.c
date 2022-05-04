#include <stdio.h>

int main(){
	
	int l, c, i, j;
	int soma = 0, somaTotal = 0, atual;

	scanf("%d %d", &l, &c);

	
	for (i = 0; i<l; i++){
		for(j = 0; j<c; j++){
			scanf("%d", &atual);
			soma += atual;
		}
		printf("%d\n", soma);
		somaTotal += soma;
		soma = 0;
	}

	printf("%d\n", somaTotal);

	return 0;
}
