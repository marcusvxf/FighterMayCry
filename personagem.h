#ifndef personagem
#define personagem
#include "raylib.h"

#include <math.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct{
    int vida;
    Vector2 posicao;
}objPersonagem;

void iniciarPersonagem(objPersonagem *player);

void moverPersonagem(objPersonagem *player);


#endif