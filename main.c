#include <raylib.h>
#include <stdio.h>
#include <math.h>
#include "personagem.h"

int main() {
    SetConfigFlags(FLAG_VSYNC_HINT);
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic screen manager");
    //if(!IsWindowFullscreen()) ToggleFullscreen();


    objPersonagem personagem1;
    objPersonagem personagem2;
    Rectangle chao = (Rectangle) {0, GetScreenHeight()-ALTURA_CHAO, GetScreenWidth(), 1};
    Rectangle paredeEsquerda = (Rectangle) {60, 0, 2, GetScreenHeight()};
    Rectangle paredeDireita = (Rectangle) {GetScreenWidth()-2, 0, 2, GetScreenHeight()};

    iniciarPersonagem(&personagem1);
    iniciarPersonagem(&personagem2);

    int framesCounter = 0;
    float deltaTime;

    SetTargetFPS(60);     


    // Main game loop
    while (!WindowShouldClose()){
         
        // Update  
        deltaTime = GetFrameTime();      
        atualizarPersonagem(&personagem1,chao, deltaTime);
        checarSolo(&personagem1);


        // Draw
        BeginDrawing();
            ClearBackground(WHITE);
            DrawRectangleRec(paredeEsquerda,BLUE);
            DrawRectangleRec(chao, RED);
            DrawRectangleRec(personagem1.corpo, RED);
            DrawRectangleRec(paredeDireita,BLUE);

        EndDrawing();

     }

    CloseWindow(); 

    return 0;
}
