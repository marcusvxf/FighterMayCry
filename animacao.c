#include "animacao.h"
#include "raylib.h"
#include "personagem.h"


void animacaoPersonagem(objPersonagem *player){
    if (IsKeyDown(player->controle.direita)) {

    }
    else if (IsKeyDown(player->controle.esquerda)) {

    }
    else if (IsKeyDown(player->controle.cima) && player->pulando == 0){

    }else{
        DrawTextureRec(player->parado.textura, (Rectangle){0,0, player->parado.textura.width, player->parado.textura.height}, player->posicao, WHITE);
    }
}

void terminarAnimacao(objPersonagem *player){
    UnloadTexture(player->parado.textura);
    UnloadTexture(player->atacar.textura);
    //UnloadTexture(player->pulo.textura);
    UnloadTexture(player->andar.textura);

}