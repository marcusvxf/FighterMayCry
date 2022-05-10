#ifndef mapa
#define mapa
#include "animacao.h"
#include "raylib.h"
#include "personagem.h"

typedef struct{
    Texture2D background;
    Texture2D midground;
    Texture2D foreground;
    Texture2D chao;
    sprite asset1;
    Texture2D asset2;
    Texture2D asset3;
    Texture2D barraVida;
    
}Mapa;

void carregarItensMapa(Mapa *myMapa);

void descarregarItensMapa(Mapa *myMapa);

#endif