#include "animacao.h"
#include "raylib.h"
#include "personagem.h"


void animacaoPersonagem(objPersonagem *player,int frameCounter){
    if (IsKeyDown(player->controle.direita)){
        DrawTextureRec(player->andar.textura, (Rectangle){player->andar.frameAtual * player->andar.textura.width/player->andar.qntFrames, 0, player->andar.textura.width/player->andar.qntFrames, player->andar.textura.height}, player->posicao, WHITE);
        if(frameCounter <= 60/50){
            player->andar.frameAtual = (player->andar.frameAtual + 1) % player->andar.qntFrames;
        }

    }
    else if (IsKeyDown(player->controle.esquerda)) {
        DrawTextureRec(player->andar.textura, (Rectangle){player->andar.frameAtual * player->andar.textura.width/player->andar.qntFrames, 0, -player->andar.textura.width/player->andar.qntFrames, player->andar.textura.height}, player->posicao, WHITE);
        if(frameCounter <= 60/50){
            player->andar.frameAtual = (player->andar.frameAtual + 1) % player->andar.qntFrames;
        }
    }
    else if (IsKeyDown(player->controle.cima) && player->pulando == 0){
        
    }else{
        if(player->lado == 1){
            DrawTextureRec(player->parado.textura, (Rectangle){0,0, player->parado.textura.width, player->parado.textura.height}, player->posicao, WHITE);
        }else{
            DrawTextureRec(player->parado.textura, (Rectangle){0,0, -player->parado.textura.width, player->parado.textura.height}, player->posicao, WHITE);
        }
        
    }
}

void terminarAnimacao(objPersonagem *player){
    UnloadTexture(player->parado.textura);
    UnloadTexture(player->atacar.textura);
    //UnloadTexture(player->pulo.textura);
    UnloadTexture(player->andar.textura);

}