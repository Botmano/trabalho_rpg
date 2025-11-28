#include "personagem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



Personagem criar_personagem(char nome[30], int dado, int nivel){
  Personagem p;
  strcpy(p.nome, nome);
  p.dado = dado;
  p.nivel = nivel;
  p.iniciativa = 0;
  p.em_combate = false;
  return p;
}
void mostrar_ordem(Personagem lista[], int num_participantes){
  printf("\n---------------------------\n");
  for (int i = 0; i < num_participantes; i++)
  {
    printf("Ordem:%d Personagem:%s Iniciativa:%d\n", i+1 ,lista[i].nome, lista[i].iniciativa);
  }
  printf("\n---------------------------\n");
}