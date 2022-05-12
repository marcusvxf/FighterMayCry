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
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic screen manager");
  
    if(!IsWindowFullscreen()) ToggleFullscreen();

    Music musica = LoadMusicStream("assets/audios/backgroundSong.mp3");
    Mapa maps;
    objPersonagem personagem1;
    objPersonagem personagem2;
    Rectangle chao = (Rectangle) {0, GetScreenHeight()-ALTURA_CHAO, GetScreenWidth(), 1};

    sprite botoesP1;
    sprite botoesP2;
    sprite botoesExtra;
    Texture2D button = LoadTexture("assets/images/background/botao.png");
    Texture2D buttonAjuda = LoadTexture("assets/images/background/botaoAjuda.png");
    Texture2D buttonVoltar = LoadTexture("assets/images/background/botaoVoltar.png");
    Texture2D logo = LoadTexture("assets/images/background/logo.png");
    botoesP1.textura = LoadTexture("assets/images/background/botoesPlayer1.png");
    botoesP1.textura = LoadTexture("assets/images/background/botoesPlayer2.png");
    botoesExtra.textura = LoadTexture("assets/images/background/botoesExtra.png");

    SetMusicVolume(musica, 0.2f);
    PlayMusicStream(musica);
    carregarItensMapa(&maps);
    iniciarPersonagem(&personagem1, 1, 60);
    iniciarPersonagem(&personagem2, 0, GetScreenWidth() - 60 - LARGURA_PERSONAGEM);

    int framesCounter = 0;
    int framesSpeed = 8;
    int currentFrame = 0;
    //int numeroFrames = 0;
    int parteDoJogo = 2;

    int frameAtualButton = 0;
    int frameAtualButtonAjuda = 0;
    int frameAtualButtonVoltar = 0;
    botoesP1.frameAtual = 0;
    botoesP1.qntFrames = 9;
    botoesP2.frameAtual = 0;
    botoesP2.qntFrames = 9;
    botoesExtra.frameAtual = 0;
    botoesExtra.qntFrames = 5;

    //float frameHeight = (float)button.height/NUM_FRAMES;
    //Rectangle sourceRec = {frameAtualButton*button.width/2,0, button.width/2, button.height };



    Vector2 mousePoint = { 0.0f, 0.0f };


    SetTargetFPS(60);     


    float deltaTime;

    //SetExitKey(KEY_NULL);
    // Main game loop
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
                DrawText("Ajax",185,40,60,BLACK);
                DrawText("Xaja",GetScreenWidth() - 185-125,40,60,BLACK);
                animacaoPersonagem(&personagem1,framesCounter,&parteDoJogo);
                animacaoPersonagem(&personagem2, framesCounter,&parteDoJogo);
                DrawTexture(maps.chao,0,GetScreenHeight()-ALTURA_CHAO-10,WHITE);

                //reseta os personagens para proxima patida
                if(parteDoJogo == 1) { 
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
                ClearBackground(WHITE);
                if(IsCursorOnScreen()) ShowCursor();
                DrawText("Final", 250, 20, 20, DARKGRAY);
                DrawTextureRec(buttonVoltar, (Rectangle){frameAtualButtonVoltar*buttonVoltar.width/2,0, buttonVoltar.width/2, buttonVoltar.height }, (Vector2){ GetScreenWidth()-buttonVoltar.width/2-50, GetScreenHeight()-buttonVoltar.height-100}, WHITE);

            }
            //pausa
            else if(parteDoJogo == 3) {
                DrawText("Pausado", GetScreenWidth()/2 - 75, GetScreenHeight()/2, 40, GREEN);
            }
            else if (parteDoJogo == 4){
                ClearBackground(BLUE);
                DrawTextureRec(buttonVoltar, (Rectangle){frameAtualButtonVoltar*buttonVoltar.width/2,0, buttonVoltar.width/2, buttonVoltar.height }, (Vector2){ GetScreenWidth()-buttonVoltar.width/2-50, GetScreenHeight()-buttonVoltar.height-100}, WHITE);

                DrawTextureRec(botoesP1.textura, (Rectangle) {botoesP1.frameAtual * botoesP1.textura.width / botoesP1.qntFrames, 0, botoesP1.textura.width/botoesP1.qntFrames, botoesP1.textura.height}, (Vector2) {300, 0}, WHITE);
                if(framesCounter <= 60/50){
                    botoesP1.frameAtual = (botoesP1.frameAtual + 1) % botoesP1.qntFrames;
                }

                //DrawTextureRec(botoesP2.textura, (Rectangle) {botoesP2.frameAtual * botoesP2.textura.width / botoesP2.qntFrames, 0, botoesP2.textura.width/botoesP2.qntFrames, botoesP2.textura.height}, (Vector2) {300, 0}, WHITE);
                if(framesCounter <= 60/50){
                    botoesP2.frameAtual = (botoesP2.frameAtual + 1) % botoesP2.qntFrames;
                }

                //DrawTextureRec(botoesExtra.textura, (Rectangle) {botoesExtra.frameAtual * botoesExtra.textura.width / botoesExtra.qntFrames, 0, botoesExtra.textura.width/botoesExtra.qntFrames, botoesExtra.textura.height}, (Vector2) {3, 0}, WHITE);
                if(framesCounter <= 60/50){
                    botoesExtra.frameAtual = (botoesExtra.frameAtual + 1) % botoesExtra.qntFrames;
                }
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
    UnloadTexture(botoesP1.textura);
    UnloadTexture(botoesP2.textura);
    UnloadTexture(botoesExtra.textura);
    CloseAudioDevice();
    CloseWindow(); 

    return 0;
}
