#include <raylib.h>
#include <vector>
#include <string>

const int window_size = 500;

std::string format(string origin, int num, string color)

typedef enum {
    NORMAL,
    SKIP,
    REVERSE,
    WILD,
    DRAW4
} CardType;

class Card 
{
public:
    int num;
    Color color;
    CardType type;
    std::string src;
    Vector2 pos;

    Card(int num, Color color, CardType type) {
        this.num = num;
        this.color = color;
        this.type = type;
        src = std::format("resources/uno/{}_{}.png", color, num);
        pos = {.x = 250, .y = 250};
        txt = LoadTexture(src.c_str());
    }
    display() {
        if(IsTextureReady(txt)) DrawTexture(txt, pos.x, pos.y, WHITE);
    }

private:
    Texture2D txt;
    ~Card() {
        UnloadTexture(txt);
    }

}

std::vector<Card> cards;


void addCard(Card card) {
    cards.push_back(card);
}

void update() {
    std::for_each(cards.begin(), cards.end(), [](Card card) {
        card.display();
    });
}

int main(int argc, char** argv) {
    SetTargetFPS(30);

    InitWindow(window_size, window_size, "CardForge");
    addCard(BLUE, 0);
    addCard(RED, 5);
    addCard(YELLOW, 3);
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        update();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
