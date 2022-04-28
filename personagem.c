#include "personagem.h"
#include "raylib.h"



void iniciarPersonagem(objPersonagem *player, int lado, float posicao){

    player->pulando = 1;
    player->vida=10;
    player->posicao.x = posicao;
    player->posicao.y=GetScreenHeight() - ALTURA_CHAO - ALTURA_PERSONAGEM;
    player->corpo = (Rectangle) { player->posicao.x , player->posicao.y, LARGURA_PERSONAGEM, ALTURA_PERSONAGEM };
    player->velocidade = 0.0;
    player->lado = lado;
}

void atualizarPersonagem(objPersonagem *player, Rectangle chao, float delta){
        if (IsKeyDown(KEY_RIGHT)) {
            player->lado = 1;
            player->posicao.x += 8.0f;
        }
        if (IsKeyDown(KEY_LEFT)) {
            player->lado = 0;
            player->posicao.x -= 8.0f;
        }
        if (IsKeyDown(KEY_UP) && player->pulando == 0){
             player->velocidade = -VELOCIDADE_PULO;
             player->posicao.y -= 5.0f;
             player->pulando = 1;
        }
        if(IsKeyPressed(KEY_SPACE)){
            player->atk =1 ;
        }else{
            player->atk =0 ;
        }

        if(CheckCollisionRecs(player->corpo, chao)) {
            player->pulando = 0;
        }else{
            player->posicao.y += player->velocidade * delta;
            player->velocidade += G*delta;
        }
        
        //1 - olhando para direita    0 - olhando para esquerda
        if(player->lado == 1) {
            player->ataque = (Rectangle) {player->posicao.x + LARGURA_PERSONAGEM-17, player->posicao.y + (ALTURA_PERSONAGEM/4), ALCANCE_ATAQUE, 20};
        }
        else if(player->lado == 0) {
            player->ataque = (Rectangle) {player->posicao.x - ALCANCE_ATAQUE, player->posicao.y + (ALTURA_PERSONAGEM/4), ALCANCE_ATAQUE, 20};
        }

        player->corpo = (Rectangle) { player->posicao.x - 20, player->posicao.y - 40, LARGURA_PERSONAGEM, ALTURA_PERSONAGEM };

}


void checarSolo(objPersonagem *player)
{
    if(player->posicao.x <= 0){
        player->posicao.x = 0;
    }else if(player-> posicao.x >= GetScreenWidth() - LARGURA_PERSONAGEM +16){
        player->posicao.x = GetScreenWidth() - LARGURA_PERSONAGEM +16;
    }
}
