#ifndef COMBATE_H
#define COMBATE_H
#include "personagem.h"
#define MAX_PERSONAGENS_COMBATE 10

void iniciar_combate(Personagem lista_em_combate[], int num_participantes);
void adicionar_personagem_combate(Personagem lista_em_combate[], int* qtd_atual);
void remover_personagem(Personagem lista_em_combate[], int* qtd_atual, char nome_ser_removido[30]);
void avancar_turno(Personagem lista_em_combate[], int num_participantes);

#endif