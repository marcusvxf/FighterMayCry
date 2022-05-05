#ifndef personagem
#define personagem
#include "raylib.h"

#include <math.h>
#include <stdlib.h>
#include <stdio.h>


#define ALTURA_CHAO 100
#define G 900
#define VELOCIDADE_PULO 900.0f
#define ALTURA_PERSONAGEM 250
#define LARGURA_PERSONAGEM 105
#define ALCANCE_ATAQUE 220

typedef struct {
    int cima;
    int esquerda;
    int direita;
    int ataque;
    int defesa;
} Controle;

typedef struct {
    int qntFrames;
    int frameAtual;
    Texture2D textura;
} sprite;

typedef struct{
    int pulando,defendendo;
    Vector2 posicao;
    float velocidade, dano, vida;
    Rectangle corpo;
    Rectangle ataque;
    int lado,atk;
    Controle controle;
    sprite parado;
    sprite andar;
    sprite pular;
    sprite cair;
    sprite atacar;
    sprite defender;
}objPersonagem;

#include "animacao.h"

void iniciarPersonagem(objPersonagem *player, int lado, float posicao);

void atualizarPersonagem(objPersonagem *player, Rectangle chao, float delta);

void checarParede(objPersonagem *player);

void ataque(objPersonagem *player1, objPersonagem *player2);





#endif