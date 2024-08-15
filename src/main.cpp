#include <raylib.h>

const int window_size = 500;

int main(int argc, char** argv) {
    InitWindow(window_size, window_size, "CardForge");
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
