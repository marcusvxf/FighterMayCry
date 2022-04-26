#include "personagem.h"
#include "raylib.h"



void iniciarPersonagem(objPersonagem *player){

    player->pulando = 1;
    player->vida=10;
    player->posicao.x = 60;
    player->posicao.y=GetScreenHeight() - ALTURA_CHAO - ALTURA_PERSONAGEM;
    player->corpo = (Rectangle) { player->posicao.x , player->posicao.y, LARGURA_PERSONAGEM, ALTURA_PERSONAGEM };
    player->velocidade = 0.0;
}

void atualizarPersonagem(objPersonagem *player, Rectangle chao, float delta){
        if (IsKeyDown(KEY_RIGHT)) player->posicao.x += 4.0f;
        if (IsKeyDown(KEY_LEFT)) player->posicao.x -= 4.0f;
        if (IsKeyDown(KEY_UP) && player->pulando == 0){
             //player->posicao.y -= 50.0f;
             player->velocidade = -VELOCIDADE_PULO;
             player->posicao.y -= 5.0f;
             player->pulando = 1;
        }

        if(CheckCollisionRecs(player->corpo, chao)) {
            player->pulando = 0;
        }else{
            player->posicao.y += player->velocidade * delta;
            player->velocidade += G*delta;
        }
        


        player->corpo = (Rectangle) { player->posicao.x - 20, player->posicao.y - 40, LARGURA_PERSONAGEM, ALTURA_PERSONAGEM };

}

