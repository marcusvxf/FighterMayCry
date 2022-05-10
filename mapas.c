#include "personagem.h"
#include "animacao.h"
#include "mapas.h"
#include "raylib.h"



void carregarItensMapa(Mapa *myMapa) {
    myMapa->background = LoadTexture("assets/images/backgorund/back.png");
    myMapa->midground = LoadTexture("assets/images/backgorund/mid.png");
    myMapa->foreground = LoadTexture("assets/images/backgorund/fore.png");
    myMapa->chao = LoadTexture("assets/images/backgorund/Chao1.png");
    myMapa->asset1.textura = LoadTexture("assets/images/backgorund/loja.png");
    myMapa->asset1.qntFrames = 6;
    myMapa->asset1.frameAtual = 0;
    myMapa->barraVida = LoadTexture("assets/images/backgorund/barraVida.png");
    myMapa->asset2 = LoadTexture("assets/images/backgorund/lampada.png");
    myMapa->asset3 = LoadTexture("assets/images/backgorund/cerca.png");
}

void descarregarItensMapa(Mapa *myMapa) {
    UnloadTexture(myMapa->background);
    UnloadTexture(myMapa->midground);
    UnloadTexture(myMapa->foreground);
    UnloadTexture(myMapa->chao);
    UnloadTexture(myMapa->barraVida);
    UnloadTexture(myMapa->asset1.textura);
    UnloadTexture(myMapa->asset2);
    UnloadTexture(myMapa->asset3);
}