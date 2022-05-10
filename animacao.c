#include "animacao.h"
#include "raylib.h"
#include "personagem.h"


void animacaoPersonagem(objPersonagem *player,int frameCounter,int *fimDeJogo){
    int mult = 1;
    if(player->lado == 1){
        mult = 1;
    }else if(player->lado == 0){
        mult = -1;
    }

    if(player->vida <=0){
        DrawTextureRec(player->morrer.textura, (Rectangle){player->morrer.frameAtual * player->morrer.textura.width/player->morrer.qntFrames, 0, player->morrer.textura.width/player->morrer.qntFrames, player->andar.textura.height}, player->posicao, WHITE);
        if(player->morrer.frameAtual == player->morrer.qntFrames - 1){
                (*fimDeJogo) = 1;
        }
        else if(frameCounter <= 60/200){
            player->morrer.frameAtual = (player->morrer.frameAtual + 1) % player->morrer.qntFrames;
        }

    }

    else if (IsKeyDown(player->controle.direita) && player->pulando == 0  && player->defendendo == 0 && player->atk == 0){
        DrawTextureRec(player->andar.textura, (Rectangle){player->andar.frameAtual * player->andar.textura.width/player->andar.qntFrames, 0, player->andar.textura.width/player->andar.qntFrames, player->andar.textura.height}, player->posicao, WHITE);
        if(frameCounter <= 60/50){
            player->andar.frameAtual = (player->andar.frameAtual + 1) % player->andar.qntFrames;
        }

    }
    else if(IsKeyDown(player->controle.esquerda)  && player->pulando == 0 && player->atk == 0) {
        DrawTextureRec(player->andar.textura, (Rectangle){player->andar.frameAtual * player->andar.textura.width/player->andar.qntFrames, 0, -player->andar.textura.width/player->andar.qntFrames, player->andar.textura.height}, player->posicao, WHITE);
        if(frameCounter <= 60/50){
            player->andar.frameAtual = (player->andar.frameAtual + 1) % player->andar.qntFrames;
        }
    }
    else if (player->pulando == 1 && player->atk == 0 && player->defendendo == 0){
        if(player->velocidade <0){
            DrawTextureRec(player->pular.textura, (Rectangle){0, 0,mult* player->pular.textura.width, player->pular.textura.height}, player->posicao, WHITE);
        }else{
            DrawTextureRec(player->cair.textura, (Rectangle){0, 0,mult* player->cair.textura.width, player->cair.textura.height}, player->posicao, WHITE);
        }
        
    }else if(player->defendendo == 1  && player->atk == 0){
        DrawTextureRec(player->defender.textura, (Rectangle){0, 0,mult* player->defender.textura.width, player->defender.textura.height}, player->posicao, WHITE);
        
    }
        
    else if(player->atk==1 && player->defendendo == 0){
        if(player->lado == 1){
            DrawTextureRec(player->atacar.textura, (Rectangle){player->atacar.frameAtual * player->atacar.textura.width/player->atacar.qntFrames, 0, mult*player->atacar.textura.width/player->atacar.qntFrames, player->atacar.textura.height}, player->posicao, WHITE);
            
        }   
        else if(player->lado == 0){
            DrawTextureRec(player->atacar.textura, (Rectangle){player->atacar.frameAtual * player->atacar.textura.width/player->atacar.qntFrames, 0, mult*player->atacar.textura.width/player->atacar.qntFrames, player->atacar.textura.height}, (Vector2){player->posicao.x - 150, player->posicao.y}, WHITE);
           
        }
        
        if(frameCounter <= 60/50){
            player->atacar.frameAtual = (player->atacar.frameAtual + 1) % player->atacar.qntFrames;
            if(player->atacar.frameAtual == player->atacar.qntFrames - 1){
                player->atk = 0;
            }
        }
    }
    else{
        DrawTextureRec(player->parado.textura, (Rectangle){0,0,mult* player->parado.textura.width,player->parado.textura.height}, player->posicao, WHITE);
    }
}

void terminarAnimacao(objPersonagem *player){
    UnloadTexture(player->parado.textura);
    UnloadTexture(player->atacar.textura);
    UnloadTexture(player->pular.textura);
    UnloadTexture(player->andar.textura);
    UnloadTexture(player->cair.textura);
    UnloadTexture(player->defender.textura);
    UnloadTexture(player->morrer.textura);
}