#include "personagem.h"
#include "raylib.h"



void iniciarPersonagem(objPersonagem *player, int lado, float posicao, Texture2D textura){
    
    //player->Textura = LoadTexture("assets/images/run.png");

    player->pulando = 1;
    player->vida=100;
    player->dano = 5;
    player->defendendo = 0;
    player->posicao.x = posicao;
    player->posicao.y=GetScreenHeight() - ALTURA_CHAO - ALTURA_PERSONAGEM;
    player->corpo = (Rectangle) { player->posicao.x , player->posicao.y, LARGURA_PERSONAGEM, ALTURA_PERSONAGEM };
    player->velocidade = 0.0;
    player->lado = lado;

    if(lado == 1) {
        player->controle.cima = KEY_W;
        player->controle.direita = KEY_D;
        player->controle.esquerda = KEY_A;
        player->controle.ataque = KEY_SPACE;
        player->controle.defesa = KEY_S;
    }
    else if(lado == 0) {
        player->controle.cima = KEY_UP;
        player->controle.direita = KEY_RIGHT;
        player->controle.esquerda = KEY_LEFT;
        player->controle.ataque = KEY_ENTER;
        player->controle.defesa = KEY_DOWN;
    }
}

void atualizarPersonagem(objPersonagem *player, Rectangle chao, float delta){
        if (IsKeyDown(player->controle.direita)) {
            player->lado = 1;
            player->posicao.x += 8.0f;
        }
        else if (IsKeyDown(player->controle.esquerda)) {
            player->lado = 0;
            player->posicao.x -= 8.0f;
        }
        else if (IsKeyDown(player->controle.cima) && player->pulando == 0){
             player->velocidade = -VELOCIDADE_PULO;
             player->posicao.y -= 5.0f;
             player->pulando = 1;
        }

        if(IsKeyPressed(player->controle.ataque)){
            player->atk = 1;
        }
        else{
            player->atk = 0;
            //player->Textura = LoadTexture("assets/images/run.png");
        }

        if(IsKeyDown(player->controle.defesa)){
            player->defendendo = 1;
        }
        else{
            player->defendendo = 0;
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


void checarParede(objPersonagem *player)
{
    if(player->posicao.x <= 0){
        player->posicao.x = 0;
    }else if(player-> posicao.x >= GetScreenWidth() - LARGURA_PERSONAGEM +16){
        player->posicao.x = GetScreenWidth() - LARGURA_PERSONAGEM +16;
    }
}

void ataque(objPersonagem *player1, objPersonagem *player2) {
    if(CheckCollisionRecs(player1->ataque, player2->corpo) && player2->defendendo == 0) {
        player2->vida -= player1->dano;
    }
}