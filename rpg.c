#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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

    for(int i = 0; i<num_participantes; i++){
      lista_em_combate[i].em_combate = true;
    }

    iniciativas_dos_personagens(lista_em_combate, num_participantes);
    definir_turnos(lista_em_combate, num_participantes);

    for(int i=0; i<num_participantes; i++){
      printf("Posicao %d, personagem:%s \n", i+1, lista_em_combate[i].nome);
    }
}

void adicionar_personagem_combate(Personagem lista_em_combate[], int* qtd_atual){
  if(*qtd_atual == MAX_PERSONAGENS_COMBATE){
    printf("Número máximo de participantes em combate");
    return;
  }
  printf("Digite o nome do personagem: ");
  char nome[30];
  int nivel;
  int dado;
  scanf("%s\n",&nome);
  printf("Digite o nivel do personagem: ");
  scanf("%d\n", &nivel);
  printf("Digite o dado do personagem: ");
  scanf("%d\n", &dado);

  Personagem personagem_adicionado = criar_personagem(nome, dado, nivel);
  personagem_adicionado.em_combate = true;
  calcular_iniciativa(&personagem_adicionado); //Calcula a iniciativa para ele entrar em combate;

  lista_em_combate[*qtd_atual] = personagem_adicionado;
  *qtd_atual++;

  definir_turnos(lista_em_combate,*qtd_atual);

}

void remover_personagem(Personagem lista_em_combate[], int* qtd_atual, char nome_ser_removido[30]){
  int index_nome = -1;
  for(int i = 0; i<*qtd_atual;i++){
    if(strcmp(nome_ser_removido, lista_em_combate[i].nome)== 0){
      index_nome = i;
      break;
    }
  }

  if (index_nome == -1){
    printf("Não há personagem com esse nome \n");
    return;
  }

  for(int i = index_nome; i<*qtd_atual-1; i++){
    lista_em_combate[i] = lista_em_combate[i+1];
  }
  (*qtd_atual)--;

  insertion_sort(lista_em_combate, *qtd_atual);
}

void avancar_turno(Personagem lista_em_combat[], int num_participantes);


int main(){
  srand(time(NULL)); //Inicialização do timer para ser usado no rand

  Personagem personagens[MAX_PERSONAGENS_COMBATE];
  int qtd_atual = 0;

    personagens[qtd_atual++] = criar_personagem("Guerreiro", 20, 5); // d20 + 5
    personagens[qtd_atual++] = criar_personagem("Mago", 6, 2);       // d6 + 2
    personagens[qtd_atual++] = criar_personagem("Goblin", 20, 1);    // d20 + 1
    personagens[qtd_atual++] = criar_personagem("Dragao", 20, 10);   // d20 + 10

    iniciar_combate(personagens, qtd_atual);

    return 0;
}












