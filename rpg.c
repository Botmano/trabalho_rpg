#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "personagem.h"
#include "combate.h"


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

    printf("\ndigite o nome do personagem: \n");
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
    mostrar_ordem(personagens, qtd_atual);
    break;
  
  default:
    printf("Numero invalido, digite um valido\n");
    break;
    }
  }
  
  return 0;
}












