#include "raylib.h"

#include <stdio.h>
#include <math.h>

#include "personagem.h"



void main() {
    SetConfigFlags(FLAG_VSYNC_HINT);
    const int screenWidth = 1920;
    const int screenHeight = 980;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic screen manager");
     Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };

    objPersonagem personagem1;

    iniciarPersonagem(&personagem1);

    int framesCounter = 0;

    SetTargetFPS(60);     


    // Main game loop
     while (!WindowShouldClose()){
         
        // Update
        moverPersonagem(&personagem1);

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawCircleV(personagem1.posicao, 50, MAROON);

        EndDrawing();

     }


    CloseWindow(); 

}
