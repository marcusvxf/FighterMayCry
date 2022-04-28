#ifndef personagem
#define personagem
#include "raylib.h"

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define ALTURA_CHAO 100
#define G 900
#define VELOCIDADE_PULO 900.0f
#define ALTURA_PERSONAGEM 300
#define LARGURA_PERSONAGEM 150
#define ALCANCE_ATAQUE 220

typedef struct{
    int vida,pulando,defendendo,dano;
    Vector2 posicao;
    float velocidade;
    Rectangle corpo;
    Rectangle ataque;
    int lado,atk;
}objPersonagem;

void iniciarPersonagem(objPersonagem *player, int lado, float posicao);

void atualizarPersonagem(objPersonagem *player, Rectangle chao, float delta);

void checarSolo(objPersonagem *player);

void ataque(objPersonagem *player1,objPersonagem *player2);




#endif