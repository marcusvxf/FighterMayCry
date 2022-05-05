#include <raylib.h>
#include <stdio.h>
#include <math.h>
#include "animacao.h"
#include "personagem.h"


int main() {
    SetConfigFlags(FLAG_VSYNC_HINT);
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic screen manager");
    if(!IsWindowFullscreen()) ToggleFullscreen();


    objPersonagem personagem1;
    objPersonagem personagem2;
    Rectangle chao = (Rectangle) {0, GetScreenHeight()-ALTURA_CHAO, GetScreenWidth(), 1};

    iniciarPersonagem(&personagem1, 1, 60);
    iniciarPersonagem(&personagem2, 0, GetScreenWidth() - 60 - LARGURA_PERSONAGEM);

    int framesCounter = 0;
    int framesSpeed = 8;
    int currentFrame = 0;
    int numeroFrames = 0;
    SetTargetFPS(60);     

    char str[20];

    float deltaTime;


    // Main game loop
    while (!WindowShouldClose()){
        framesCounter++;

        if (framesCounter >= (60/framesSpeed))
        {
            framesCounter = 0;
            currentFrame++;
        }
         
        // Update  
        deltaTime = GetFrameTime();      
        atualizarPersonagem(&personagem1,chao, deltaTime);
        atualizarPersonagem(&personagem2, chao, deltaTime);
        checarParede(&personagem1);
        checarParede(&personagem2);
        if(personagem1.atk == 1 && personagem1.defendendo == 0){
            ataque(&personagem1,&personagem2);
        }
        if(personagem2.atk == 1 && personagem2.defendendo == 0){
            ataque(&personagem2, &personagem1);
        }

        // Draw
        BeginDrawing();
            /*if(personagem1.atk == 1 && personagem1.defendendo == 0){
                DrawRectangleRec(personagem1.ataque,BLUE);
            }
            if(personagem2.atk == 1 && personagem2.defendendo == 0){
                DrawRectangleRec(personagem2.ataque,RED);
            }*/
            //DrawTextureRec(parado, (Rectangle){0,0, parado.width, parado.height}, personagem1.posicao, WHITE);
            animacaoPersonagem(&personagem1,framesCounter);
            animacaoPersonagem(&personagem2, framesCounter);
            //DrawRectangleRec(personagem2.corpo, GREEN);
            ClearBackground(WHITE);
            DrawRectangleRec(chao, RED);
            //DrawText(str, 250, 20, 20, DARKGRAY);
            //DrawRectangleRec(personagem1.corpo, RED);

            //teste vida
            DrawRectangleRec((Rectangle) {20, 20, personagem1.vida, 20}, GREEN);
            DrawRectangleRec((Rectangle) {500, 20, personagem2.vida, 20}, RED);

        EndDrawing();

     }

    terminarAnimacao(&personagem1);
    terminarAnimacao(&personagem2);
    CloseWindow(); 

    return 0;
}
