#include <raylib.h>

const int window_size = 500;

void drawCard() {
    Texture2D txt = LoadTexture("resources/small/blue_0.png");
    if(IsTextureReady(txt)) DrawTexture(txt, 250, 250, WHITE);
    UnloadTexture(txt);
}

int main(int argc, char** argv) {
    SetTargetFPS(30);

    InitWindow(window_size, window_size, "CardForge");
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        drawCard();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
