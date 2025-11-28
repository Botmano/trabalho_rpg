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

void quicksort(Personagem lista[], int min, int max){
  if(min < max){
    int index_pivo = particionar(lista, min, max);
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

void monstrar_ordem(Personagem lista[], int num_participantes){
  printf("---------------------------\n");
  for (int i = 0; i < num_participantes; i++)
  {
    printf("Ordem:%d Personagem:%s\n", i+1 ,lista[i].nome);
  }
  printf("\n---------------------------\n");
}

void iniciar_combate(Personagem lista_em_combate[], int num_participantes){

    for(int i = 0; i<num_participantes; i++){
      lista_em_combate[i].em_combate = true;
    }

    iniciativas_dos_personagens(lista_em_combate, num_participantes);
    definir_turnos(lista_em_combate, num_participantes);

    monstrar_ordem(lista_em_combate, num_participantes);
}

void adicionar_personagem_combate(Personagem lista_em_combate[], int* qtd_atual){
  if(*qtd_atual == MAX_PERSONAGENS_COMBATE){
    printf("Numero maximo de participantes em combate\n");
    return;
  }

  char nome[30];
  int nivel;
  int dado;
  printf("\nDigite o nome do personagem: ");
  
  scanf(" %[^\n]",nome);
  printf("\nDigite o nivel do personagem: ");
  scanf("%d", &nivel);
  printf("\nDigite o dado do personagem: ");
  scanf("%d", &dado);

  Personagem personagem_adicionado = criar_personagem(nome, dado, nivel);
  personagem_adicionado.em_combate = true;
  calcular_iniciativa(&personagem_adicionado); //Calcula a iniciativa para ele entrar em combate;

  lista_em_combate[*qtd_atual] = personagem_adicionado;
  (*qtd_atual)++;

  definir_turnos(lista_em_combate,*qtd_atual);
  printf("Personagem %s entrou no combate com iniciativa %d!\n", nome, personagem_adicionado.iniciativa);
  monstrar_ordem(lista_em_combate, *qtd_atual);
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
    printf("Nao ha personagem com esse nome \n");
    return;
  }

  for(int i = index_nome; i<*qtd_atual-1; i++){
    lista_em_combate[i] = lista_em_combate[i+1];
  }
  (*qtd_atual)--;

  insertion_sort(lista_em_combate, *qtd_atual);
  monstrar_ordem(lista_em_combate, *qtd_atual);
}

void avancar_turno(Personagem lista_em_combate[], int num_participantes){
  iniciativas_dos_personagens(lista_em_combate, num_participantes);
  definir_turnos(lista_em_combate, num_participantes);
  monstrar_ordem(lista_em_combate, num_participantes);
  
}

void teste_branch();

int main(){
  srand(time(NULL)); //Inicialização do timer para ser usado no rand

  Personagem personagens[MAX_PERSONAGENS_COMBATE];
  int qtd_atual = 0;

  while (qtd_atual == 0 || qtd_atual == 1)
  {
  printf("Quantos Personagens quer adicionar no combate inicial ?\n");
  scanf("%d", &qtd_atual);
  if(qtd_atual == 1){
    printf("Impossivel ter um combate com apenas um personagem \n");

  }
  if(qtd_atual > MAX_PERSONAGENS_COMBATE || qtd_atual < 0){
    qtd_atual = 0;
    printf("Valor invalido, digite novamente\n");
  }

  }
  
  for(int i = 0; i < qtd_atual; i++){

    printf("digite o nome do personagem: \n");
    scanf(" %[^\n]", personagens[i].nome);
    printf("digite o nivel: \n");
    scanf("%d", &personagens[i].nivel);
    printf("digite o tipo de dado do personagem(d4, d6,d8,d10,d12,d20, digite apenas o número): \n");
    scanf("%d", &personagens[i].dado);
    if(personagens[i].dado != 4  
    && personagens[i].dado != 6
    && personagens[i].dado != 8
    && personagens[i].dado != 10
    && personagens[i].dado != 12 
    && personagens[i].dado != 20 ){
      personagens[i].dado = 4;
      printf("Valor de dado invalido, colocando como padrao d4\n ");
    }
  }
  iniciar_combate(personagens, qtd_atual);

  int qual_func = 0;
  while (qual_func != 4)
  {
  printf("Quer 1: Adicionar Personagem \n 2: Remover Personagem \n 3: Avancar Turno \n 4: Finalizar combate\n");
  scanf("%d", &qual_func);

  switch (qual_func)
    {
  case 1:
    adicionar_personagem_combate(personagens,&qtd_atual);
    break;
  case 2:
    printf("\nQual eh o Nome do personagem a ser removido:");
    char nome_remover[30];
    scanf(" %[^\n]", nome_remover);
    remover_personagem(personagens, &qtd_atual, nome_remover);
    if(qtd_atual == 1){
      printf("Combate finalizado pois so ha 1 participante");
      qual_func = 4;
    }
    break;
  case 3:
    avancar_turno(personagens, qtd_atual);
    break;
  case 4:
    printf("Combate finalizado\n");
    monstrar_ordem(personagens, qtd_atual);
    break;
  
  default:
    printf("Numero invalido, digite um valido\n");
    break;
    }
  }
  
  return 0;
}












