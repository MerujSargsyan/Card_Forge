#include <cardforge.hpp>

int main(void) {
    Game g = Game(0.5f);
    InitWindow(500, 500, "Uno Test");

    g.add_container(150.0f, 150.0f, 25.0f, 0, 1);
    g.add_container(0.0f, 0.0f, 0.0f, 100.0f, 1);

    g.containers.at(0)->add_card("yellow", '0', NORMAL);
    g.containers.at(0)->add_card("green", '1', NORMAL);
    g.containers.at(0)->add_card("blue", '2', NORMAL);

    g.containers.at(1)->add_card("yellow", '7', NORMAL);
    g.containers.at(1)->add_card("green", '7', NORMAL);
    g.containers.at(1)->add_card("blue", '7', NORMAL);

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        g.update();
        EndDrawing();
    }
    CloseWindow();
}
