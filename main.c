#include <raylib.h>
#include <stdio.h>
#include <math.h>

float d2(Vector2 a, Vector2 b) {
    return ((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y));
}

int main() {
    SetConfigFlags(FLAG_VSYNC_HINT);
    if (!IsWindowFullscreen()) ToggleFullscreen();


    return 0;
}
