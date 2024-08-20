#include <cardforge.hpp>

int main(void) {
    Game g = Game(50.0f, 50.0f);
    InitWindow(500, 500, "Uno Test");

    g.add_card("yellow", '0', NORMAL);

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        g.update();
        EndDrawing();
    }
    CloseWindow();
}
