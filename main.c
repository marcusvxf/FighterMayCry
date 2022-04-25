#include <raylib.h>
#include <stdio.h>
#include <math.h>

int void() {
    SetConfigFlags(FLAG_VSYNC_HINT);
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic screen manager");

    int framesCounter = 0;

    SetTargetFPS(60);     

    // Main game loop


        // Update

        // Draw

    BeginDrawing();

    EndDrawing();

    CloseWindow(); 

}
