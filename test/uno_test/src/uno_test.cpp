#include <cardforge.hpp>

string format(string color, char num) {
    string origin = "./resources/uno/*_*.png";
    int pos1 = origin.find('*', 0);
    origin.replace(pos1, 1, color);
    int pos2 = origin.find('*', 0);
    origin.replace(pos2, 1, 1, num);
    return origin;
}

int main(void) {
    Game g = Game(0.5f);
    InitWindow(500, 500, "Uno Test");

    g.add_container(150.0f, 150.0f, 25.0f, 0);
    g.add_container(50.0f, 50.0f, 0.0f, 100.0f);
    g.add_container(300.0f, 200.0f, 25.0f, 25.0f);

    g.containers.at(0)->add_card("yellow", '0', NORMAL, format("yellow", '0'));
    g.containers.at(0)->add_card("green", '1', 15.0f, NORMAL, format("green", '1'));
    g.containers.at(0)->add_card("blue", '2', 30.0f, NORMAL, format("blue", '2'));

    g.containers.at(1)->add_card("yellow", '7', 45.0f, NORMAL, format("yellow", '7'));
    g.containers.at(1)->add_card("green", '7', NORMAL, format("green", '7'));
    g.containers.at(1)->add_card("blue", '7', NORMAL, format("blue", '7'));

    g.containers.at(2)->add_card("green", '5', 0.0f, NORMAL, format("green", '5'));
    g.containers.at(2)->add_card("red", '4', 0.0f, NORMAL, format("red", '4'));
    g.containers.at(2)->add_card("yellow", '3', 0.0f, NORMAL, format("yellow", '3'));

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        g.update();
        EndDrawing();
    }
    CloseWindow();
}
