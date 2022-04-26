#include <raylib.h>
#include <stdio.h>
#include <math.h>

#define G 800

int main() {
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    InitWindow(screenWidth, screenHeight, "teste");

    Rectangle jogador = {600, GetScreenHeight()-300, 100, 300};
    
    if (!IsWindowFullscreen()) ToggleFullscreen();

    while(!WindowShouldClose()) {
        
        BeginDrawing();
        ClearBackground(GREEN);
        DrawRectangleRec(jogador, RED);
        EndDrawing();
    }


    CloseWindow();

    return 0;
}
