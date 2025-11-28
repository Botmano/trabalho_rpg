
#include "combate.h"
#include "utils.h"   
#include <stdio.h>
#include <string.h>


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