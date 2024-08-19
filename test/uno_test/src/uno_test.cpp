#include <vector>
#include <string>
#include <CardForge.h>

const int window_size = 500;

int main(int argc, char** argv) {
    SetTraceLogLevel(LOG_WARNING);
    SetTargetFPS(30);

    Game g = Game(50.0f, 50.0f);
    Container c = Container(50.0f, 50.0f, 5);
    InitWindow(window_size, window_size, "CardForge");

    c.add_card("yellow", '0', NORMAL);

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        g.update();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
