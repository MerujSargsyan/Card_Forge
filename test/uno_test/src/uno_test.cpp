#include <cardforge.hpp>

int main(void) {
    Game g = Game(75.0f, 50.0f);
    InitWindow(500, 500, "Uno Test");

    g.add_container(150.0f, 150.0f, 1);
    g.containers.at(0)->add_card("yellow", '0', NORMAL);
    g.containers.at(0)->add_card("green", '1', NORMAL);
    g.containers.at(0)->add_card("blue", '2', NORMAL);

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        g.update();
        EndDrawing();
    }
    CloseWindow();
}
