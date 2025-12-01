#include "personagem.h"
#include <stdlib.h>




int rolar_dado(int dado){
  return (1+(rand()%dado)); // Mais 1 para ficar enves de 0 ate o valor do dado menos 1 fica de 1 até o valor do dado;
}

void trocar(Personagem* a, Personagem* b){
  Personagem temp = *a;
  *a = *b;
  *b = temp;
}

int particionar(Personagem lista[], int min, int max){
  int pivo = lista[max].iniciativa;
  int i = min-1;

  for(int j = min; j<=max-1;j++) {
    if(lista[j].iniciativa > pivo){
      i++;
      trocar(&lista[i], &lista[j]);
    }
  }
  
  trocar(&lista[i+1], &lista[max]);

  return(i+1); 
}


void insertion_sort(Personagem v[], int qtd_atual){
    for(int i = 1; i<qtd_atual;i++){
        Personagem key = v[i];
        int j = i-1;
        while(j >= 0 && v[j].iniciativa < key.iniciativa){
            v[j+1]= v[j];
            j = j-1;
        }
        v[j+1] = key;
    }
}

void quicksort(Personagem lista[], int min, int max){
  if(min < max){
    int index_pivo = particionar(lista, min, max);
    quicksort(lista, min, index_pivo-1);
    quicksort(lista, index_pivo+1, max);
  }
}
