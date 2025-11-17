#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX_PERSONAGENS_COMBATE 10;

typedef struct personagem
{
    char nome[30];
    int dado;
    int nivel;
    int iniciativa;
}Personagem;

int rolar_dado(int dado){
  return (1+(rand()%dado)); // Mais 1 para ficar enves de 0 ate o valor do dado menos 1 fica de 1 até o valor do dado;
}

void calcular_iniciativa(Personagem* p){
  p->iniciativa = rolar_dado(p->dado)+p->nivel;
}

Personagem criar_personagem(char nome[30], int dado, int nivel){
  Personagem p;
  strcpy(p.nome, nome);
  p.dado = dado;
  p.nivel = nivel;
  p.iniciativa = 0;
  return p;
}
void iniciar_combat(Personagem lista_em_combate[]){
  
}

int main(){
  Personagem lista_em_combate[MAX_PERSONAGENS_COMBATE];


  srand(time(NULL));
}












