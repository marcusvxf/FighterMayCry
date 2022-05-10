#ifndef animacao
#define animacao
#include "raylib.h"

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "personagem.h"

void animacaoPersonagem(objPersonagem *player,int frameCounter,int *fimDeJogo);

void terminarAnimacao(objPersonagem *player);

#endif