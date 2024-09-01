#include "unolib.hpp"

int main(void) {
    Game g = Game(0.5f);
    InitWindow(500, 500, "Uno Test");

    g.add_container(150.0f, 150.0f, 25.0f, 0);
    g.add_container(50.0f, 50.0f, 0.0f, 100.0f);
    g.add_container(300.0f, 200.0f, 25.0f, 25.0f);

    g.containers.at(0)->add_card(format("yellow", '0'));
    g.containers.at(0)->add_card(format("green", '1'));
    g.containers.at(0)->add_card(format("blue", '2'));

    g.containers.at(1)->add_card(format("yellow", '7'));
    g.containers.at(1)->add_card(format("green", '7'));
    g.containers.at(1)->add_card(format("blue", '7'));

    g.containers.at(2)->add_card(format("green", '5'));
    g.containers.at(2)->add_card(format("red", '4'));
    g.containers.at(2)->add_card(format("yellow", '3'));

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        g.update();
        EndDrawing();
    }
    CloseWindow();
}
