#include <raylib.h>
#include <stdio.h>
#include <math.h>
#include "animacao.h"
#include "personagem.h"
#include "mapas.h"

#define NUM_FRAMES  3



int main() {
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitAudioDevice();
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();
    InitWindow(screenWidth, screenHeight, "Fighter May Cry");
  
    if(!IsWindowFullscreen()) ToggleFullscreen();

    Music musica = LoadMusicStream("assets/audios/backgroundSong.mp3");
    Mapa maps;
    objPersonagem personagem1;
    objPersonagem personagem2;
    Rectangle chao = (Rectangle) {0, GetScreenHeight()-ALTURA_CHAO, GetScreenWidth(), 1};


    Texture2D button = LoadTexture("assets/images/background/botao.png");
    Texture2D buttonAjuda = LoadTexture("assets/images/background/botaoAjuda.png");
    Texture2D buttonVoltar = LoadTexture("assets/images/background/botaoVoltar.png");
    Texture2D logo = LoadTexture("assets/images/background/logo.png");
    Texture2D botoes1 = LoadTexture("assets/images/background/botoesPlayer1.png");
    Texture2D botoes2 = LoadTexture("assets/images/background/botoesPlayer2.png");
    Texture2D botoesExtra = LoadTexture("assets/images/background/botoesExtra.png");
    Texture2D fimDeJogo = LoadTexture("assets/images/background/fimDeJogo.png");

    SetMusicVolume(musica, 0.2f);
    PlayMusicStream(musica);
    carregarItensMapa(&maps);
    iniciarPersonagem(&personagem1, 1, 60);
    iniciarPersonagem(&personagem2, 0, GetScreenWidth() - 60 - LARGURA_PERSONAGEM);

    int vencedor = 0;
    int framesCounter = 0;
    int framesSpeed = 8;
    int currentFrame = 0;
    int parteDoJogo = 2;

    int frameAtualButton = 0;
    int frameAtualButtonAjuda = 0;
    int frameAtualButtonVoltar = 0;

    Vector2 mousePoint = { 0.0f, 0.0f };


    SetTargetFPS(60);     


    float deltaTime;

    while (!WindowShouldClose()){
        UpdateMusicStream(musica);  
        framesCounter++;
        if(IsCursorOnScreen()) mousePoint = GetMousePosition();

        if(parteDoJogo == 0){
            if(IsCursorOnScreen()) HideCursor();

            if (framesCounter >= (60/framesSpeed))
            {
                
                framesCounter = 0;
                currentFrame++;
            }
            
            // Update  
            deltaTime = GetFrameTime();      
            if(personagem1.vida > 0) atualizarPersonagem(&personagem1, chao, deltaTime);
            if(personagem2.vida > 0) atualizarPersonagem(&personagem2, chao, deltaTime);
            checarParede(&personagem1);
            checarParede(&personagem2);
            if(personagem1.atk == 1 && personagem1.defendendo == 0){
                ataque(&personagem1,&personagem2);
            }
            if(personagem2.atk == 1 && personagem2.defendendo == 0 ){
                ataque(&personagem2, &personagem1);
            }

            if(IsKeyPressed(KEY_P)) parteDoJogo = 3;

        }else if(parteDoJogo == 2){
            

            // Botao comecar jogo
            if (CheckCollisionPointRec(mousePoint, (Rectangle){GetScreenWidth()/2-button.width/4, GetScreenHeight()-button.height-100, button.width/2, button.height}))
            {   
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
                    frameAtualButton =1;
                    
                }
                if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                    frameAtualButton = 0;
                    parteDoJogo=0;
                }
                
            }
            if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                    frameAtualButton = 0;
            }

            //Botao Ajuda
            
            if (CheckCollisionPointRec(mousePoint, (Rectangle){GetScreenWidth()-buttonAjuda.width/2-50, GetScreenHeight()-buttonAjuda.height-100, buttonAjuda.width/2, buttonAjuda.height}))
            {   
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
                    frameAtualButtonAjuda =1;
                    
                }
                if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                    frameAtualButtonAjuda = 1;
                    parteDoJogo=4;
                }
                
            }

            if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                    frameAtualButtonAjuda = 0;
            }
            
        }
        else if(parteDoJogo == 3) {  //pausa
            if(IsKeyPressed(KEY_P)) parteDoJogo = 0;
        }
        //tela de ajuda
        else if(parteDoJogo == 4){

            

            if (CheckCollisionPointRec(mousePoint, (Rectangle){GetScreenWidth()-buttonVoltar.width/2-50, GetScreenHeight()-buttonVoltar.height-100, buttonVoltar.width/2, buttonVoltar.height}))
            {   
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
                    frameAtualButtonVoltar =1;
                    
                }
                if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                    frameAtualButtonVoltar = 0;
                    parteDoJogo = 2;
                }
                
            }
            if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                    frameAtualButtonVoltar = 0;
            }
        }

        //Tela Final
        else if(parteDoJogo == 1){
            if (CheckCollisionPointRec(mousePoint, (Rectangle){GetScreenWidth()-buttonVoltar.width/2-50, GetScreenHeight()-buttonVoltar.height-100, buttonVoltar.width/2, buttonVoltar.height}))
            {   
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
                    frameAtualButtonVoltar =1;
                    
                }
                if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                    frameAtualButtonVoltar = 0;
                    parteDoJogo = 2;
                }
                
            }
            if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                    frameAtualButtonVoltar = 0;
                }
        }




        // Draw
        BeginDrawing();
            //Menu
            if(parteDoJogo == 2){

                ClearBackground(BLUE);
                
                DrawTexture(logo,GetScreenWidth()/2-logo.width/2,GetScreenHeight() - logo.height-200,WHITE);

                DrawTextureRec(button, (Rectangle){frameAtualButton*button.width/2,0, button.width/2, button.height }, (Vector2){ GetScreenWidth()/2-button.width/4, GetScreenHeight()-button.height-100}, WHITE);
                DrawTextureRec(buttonAjuda, (Rectangle){frameAtualButtonAjuda*buttonAjuda.width/2,0, buttonAjuda.width/2, buttonAjuda.height }, (Vector2){ GetScreenWidth()-buttonAjuda.width/2-50, GetScreenHeight()-buttonAjuda.height-100}, WHITE);


                
            }
            //Jogo
            else if(parteDoJogo==0){
                ClearBackground(WHITE);
                DrawTexture(maps.background,0,0,WHITE);
                DrawTexture(maps.midground,0,0,WHITE);
                DrawTexture(maps.foreground,0,0,WHITE);


                DrawRectangleRec((Rectangle) {115 + 8*(100 - personagem1.vida), 100, 8*personagem1.vida, 50}, RED);
                DrawRectangleRec((Rectangle) {GetScreenWidth()/2+60, 100, 8*personagem2.vida, 50}, BLUE);
                
                DrawTextureRec(maps.asset1.textura, (Rectangle){maps.asset1.frameAtual * maps.asset1.textura.width/maps.asset1.qntFrames, 0, maps.asset1.textura.width/maps.asset1.qntFrames, maps.asset1.textura.height}, (Vector2){1100,280}, WHITE);
                if(framesCounter <= 60/50){
                    maps.asset1.frameAtual = (maps.asset1.frameAtual + 1) % maps.asset1.qntFrames;  
                }

                DrawTexture(maps.barraVida,0,0,WHITE);
                DrawText("Dan",185,40,60,BLACK);
                DrawText("Marc",GetScreenWidth() - 185-125,40,60,BLACK);
                animacaoPersonagem(&personagem1,framesCounter,&parteDoJogo);
                animacaoPersonagem(&personagem2, framesCounter,&parteDoJogo);
                DrawTexture(maps.chao,0,GetScreenHeight()-ALTURA_CHAO-10,WHITE);

                //reseta os personagens para proxima patida
                if(parteDoJogo == 1) { 
                    if(personagem1.vida <= 0 && personagem2.vida > 0) vencedor = 2;
                    else if(personagem2.vida <= 0 && personagem1.vida > 0) vencedor = 1;
                    else vencedor = 0;
                    personagem1.vida = 100;
                    personagem2.vida = 100;
                    personagem1.posicao.x = 60;
                    personagem1.posicao.y = GetScreenHeight() - ALTURA_CHAO - ALTURA_PERSONAGEM-500;
                    personagem2.posicao.x = GetScreenWidth() - 60 - LARGURA_PERSONAGEM;
                    personagem2.posicao.y = GetScreenHeight() - ALTURA_CHAO - ALTURA_PERSONAGEM-500;
                }

                

            }
            //Final
            else if (parteDoJogo == 1){
                ClearBackground(BLUE);
                if(IsCursorOnScreen()) ShowCursor();
                DrawTextureRec(buttonVoltar, (Rectangle){frameAtualButtonVoltar*buttonVoltar.width/2,0, buttonVoltar.width/2, buttonVoltar.height }, (Vector2){ GetScreenWidth()-buttonVoltar.width/2-50, GetScreenHeight()-buttonVoltar.height-100}, WHITE);

                DrawTexture(fimDeJogo, GetScreenWidth() / 2 - fimDeJogo.width/2, 200, WHITE);

                if(vencedor == 2) {
                    DrawText("Player 2 venceu",GetScreenWidth() / 2-50, fimDeJogo.height+200, 100,BLACK);
                }
                else if(vencedor == 1) {
                    DrawText("Player 1 venceu",GetScreenWidth() / 2-50, fimDeJogo.height+200,100,BLACK);
                }
                else {
                    DrawText("Empate",GetScreenWidth() / 2-50, fimDeJogo.height+200, 100,BLACK);
                }
            }
            //pausa
            else if(parteDoJogo == 3) {
                DrawText("Pausado", GetScreenWidth()/2 - 75, GetScreenHeight()/2, 40, GREEN);
            }
            else if (parteDoJogo == 4){
                ClearBackground(BLUE);
                DrawTextureRec(buttonVoltar, (Rectangle){frameAtualButtonVoltar*buttonVoltar.width/2,0, buttonVoltar.width/2, buttonVoltar.height }, (Vector2){ GetScreenWidth()-buttonVoltar.width/2-50, GetScreenHeight()-buttonVoltar.height-100}, WHITE);


                DrawTexture(botoes1, 300, 50, WHITE);
                DrawTexture(botoes2, GetScreenWidth()-botoes2.width-300, 50, WHITE);
                DrawTexture(botoesExtra, 400, GetScreenHeight()-botoesExtra.height-100, WHITE);

            }
            

        EndDrawing();


        }
    
    descarregarItensMapa(&maps);
    terminarAnimacao(&personagem1);
    terminarAnimacao(&personagem2);
    encerrarSons(&personagem1);
    encerrarSons(&personagem2);
    UnloadMusicStream(musica);
    UnloadTexture(button);
    UnloadTexture(buttonAjuda);
    UnloadTexture(logo);
    UnloadTexture(buttonVoltar);
    UnloadTexture(botoes1);
    UnloadTexture(botoes2);
    UnloadTexture(botoesExtra);
    UnloadTexture(fimDeJogo);
    CloseAudioDevice();
    CloseWindow(); 

    return 0;
}
