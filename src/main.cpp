#include <raylib.h>
#include <vector>

const int window_size = 500;

std::vector<Texture2D> cards;

void addCard() {
    cards.push_back(LoadTexture("resources/small/blue_0.png"));
}

void update() {
    int n = 0;
    std::for_each(cards.begin(), cards.end(), [&n](Texture2D &txt){
        if(IsTextureReady(txt)) DrawTexture(txt, n*50, n*50, WHITE);
        n++;
    });
}

int main(int argc, char** argv) {
    SetTargetFPS(30);

    InitWindow(window_size, window_size, "CardForge");
    addCard();
    addCard();
    addCard();
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        update();
        EndDrawing();
    }
    CloseWindow();
    UnloadTexture(cards[0]);
    return 0;
}
