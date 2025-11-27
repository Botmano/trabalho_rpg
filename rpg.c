#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_PERSONAGENS_COMBATE 10

typedef struct personagem
{
    char nome[30];
    int dado;
    int nivel;
    int iniciativa;
    bool em_combate;
}Personagem;

Personagem criar_personagem(char nome[30], int dado, int nivel){
  Personagem p;
  strcpy(p.nome, nome);
  p.dado = dado;
  p.nivel = nivel;
  p.iniciativa = 0;
  p.em_combate = false;
  return p;
}

void trocar(Personagem* a, Personagem* b){
  Personagem temp = *a;
  *a = *b;
  *b = temp;
}

int particionar(Personagem lista[], int max, int min){
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

void quicksort(Personagem lista[], int min, int max){
  if(min < max){
    int index_pivo = particionar(lista, max, 0);
    quicksort(lista, min, index_pivo-1);
    quicksort(lista, index_pivo+1, max);
  }
}

int rolar_dado(int dado){
  return (1+(rand()%dado)); // Mais 1 para ficar enves de 0 ate o valor do dado menos 1 fica de 1 até o valor do dado;
}

void calcular_iniciativa(Personagem* p){
  p->iniciativa = rolar_dado(p->dado)+p->nivel;
}

void iniciativas_dos_personagens(Personagem participantes[], int num_personagens){
    for (int i = 0; i < num_personagens; i++){
        calcular_iniciativa(&participantes[i]);
    }
}

void definir_turnos(Personagem participantes[], int num_personagens){
  quicksort(participantes, 0, num_personagens-1);
}

void iniciar_combate(Personagem lista_em_combate[], int num_participantes){
    iniciativas_dos_personagens(lista_em_combate, num_participantes);
    definir_turnos(lista_em_combate, num_participantes);

    for(int i=0; i<num_participantes; i++){
      printf("Posição %d, personagem:%s \n", i+1, lista_em_combate[i].nome);
    }
}

int main(){
  srand(time(NULL)); //Inicialização do timer para ser usado no rand

  Personagem personagens[MAX_PERSONAGENS_COMBATE];
  int qtd_atual = 0;
    // 2. Adicionar personagens
    personagens[qtd_atual++] = criar_personagem("Guerreiro", 20, 5); // d20 + 5
    personagens[qtd_atual++] = criar_personagem("Mago", 6, 2);       // d6 + 2
    personagens[qtd_atual++] = criar_personagem("Goblin", 20, 1);    // d20 + 1
    personagens[qtd_atual++] = criar_personagem("Dragão", 20, 10);   // d20 + 10

    // 3. Iniciar a lógica de combate
    iniciar_combate(personagens, qtd_atual);

    return 0;
}












