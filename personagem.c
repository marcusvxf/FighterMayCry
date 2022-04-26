#include "personagem.h"
#include "raylib.h"



void iniciarPersonagem(objPersonagem *player){

    (*player).vida=100;
    (*player).posicao.x = 400;
    (*player).posicao.y=300;

}

void moverPersonagem(objPersonagem *player){
        if (IsKeyDown(KEY_RIGHT)) (*player).posicao.x += 4.0f;
        if (IsKeyDown(KEY_LEFT)) (*player).posicao.x -= 4.0f;
        if (IsKeyDown(KEY_UP)) (*player).posicao.y -= 50.0f;
        if (IsKeyDown(KEY_DOWN)) (*player).posicao.y += 2.0f;
}