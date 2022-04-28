#include <raylib.h>
#include <stdio.h>
#include <math.h>
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

    //int framesCounter = 0;
    float deltaTime;

    //SetTargetFPS(60);     


    // Main game loop
    while (!WindowShouldClose()){
         
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
            if(personagem1.atk == 1 && personagem1.defendendo == 0){
                DrawRectangleRec(personagem1.ataque,BLUE);
            }
            if(personagem2.atk == 1 && personagem2.defendendo == 0){
                DrawRectangleRec(personagem2.ataque,RED);
            }
            
            DrawRectangleRec(personagem2.corpo, GREEN);
            ClearBackground(WHITE);
            DrawRectangleRec(chao, RED);
            DrawRectangleRec(personagem1.corpo, RED);


        EndDrawing();

     }

    CloseWindow(); 

    return 0;
}
