#include <raylib.h>
#include <stdio.h>
#include <math.h>

void main() {
    SetConfigFlags(FLAG_VSYNC_HINT);
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();
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
