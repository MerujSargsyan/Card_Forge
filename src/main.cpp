#include <raylib.h>

typedef enum {
    HEART,
    DIAMOND,
    SPADE,
    CLUB
} Suit;

class Card 
{
    public:
    int num;
    Suit suit;

    Card(int num, Suit suit) {
        this.num = num;
        this.suit = suit;
    }
}

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
