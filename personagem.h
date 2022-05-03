#ifndef personagem
#define personagem
#include "raylib.h"

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define ALTURA_CHAO 100
#define G 900
#define VELOCIDADE_PULO 900.0f
#define ALTURA_PERSONAGEM 205
#define LARGURA_PERSONAGEM 100
#define ALCANCE_ATAQUE 220

typedef struct {
    int cima;
    int esquerda;
    int direita;
    int ataque;
    int defesa;
} Controle;

typedef struct{
    int vida,pulando,defendendo,dano;
    Vector2 posicao;
    float velocidade;
    Rectangle corpo;
    Rectangle ataque;
    int lado,atk;
    Controle controle;
    int comando; //0:parado 1:esquerda 2:direitas
    //Texture2D idle;
    //Texture2D andar;
    //Texture2D pular;
    //Texture2D atacar;
}objPersonagem;

void iniciarPersonagem(objPersonagem *player, int lado, float posicao,Texture2D textura);

void atualizarPersonagem(objPersonagem *player, Rectangle chao, float delta);

void checarParede(objPersonagem *player);

void ataque(objPersonagem *player1, objPersonagem *player2);





#endif