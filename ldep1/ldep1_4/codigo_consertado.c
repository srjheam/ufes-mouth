#include <stdio.h>

int main() {
  int i=0, den=1, primo=0, qtd=0, cont=0;

  scanf("%d", &qtd);

  // My grandma runs faster than this code
  for(i=2; i<=qtd; i++){
    while(den <= i){
      if(i%den==0){
        cont++;
      }
      den++;
    }
    if(cont==2)
      printf("%d ", i);

    den = 1;
    cont = 0;
  }

  return 0;
}
