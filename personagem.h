#ifndef PERSONAGEM_H
#define PERSONAGEM_H 

#include <stdbool.h>

typedef struct personagem
{
    char nome[30];
    int dado;
    int nivel;
    int iniciativa;
    bool em_combate;
}Personagem;

Personagem criar_personagem(char nome[30], int dado, int nivel);
void mostrar_ordem(Personagem lista[], int num_participantes);

#endif







