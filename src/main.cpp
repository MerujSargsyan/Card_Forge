#include <raylib.h>
#include <vector>
#include <string>
#include <iostream>

using std::string;

const int window_size = 500;

string format(string origin, char num, string color) {
    int pos1 = origin.find('*', 0);
    origin.replace(pos1, 1, color);
    int pos2 = origin.find('*', 0);
    origin.replace(pos2, 1, 1, num);
    std::cout << origin << '\n';
    return origin;
}

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
    string color;
    CardType type;
    string src;
    Vector2 pos;

    Card(string color, char num, CardType type) {
        this->num = num;
        this->color = color;
        this->type = type;
        src = format(string("resources/uno/*_*.png"), num, color);
        pos = {.x = 250, .y = 250};
        txt = LoadTexture(src.c_str());
    }
    ~Card() {
        UnloadTexture(txt);
    }

    void display() {
        if(IsTextureReady(txt)) DrawTexture(txt, pos.x, pos.y, WHITE);
    }

private:
    Texture2D txt;
};

std::vector<Card> cards;

void addCard(const Card& card) {
    cards.push_back(card);
}

void update() {
    for(int i = 0; i < cards.size(); i++) {
        cards[i].display();
    }
}

int main(int argc, char** argv) {
    SetTargetFPS(30);

    InitWindow(window_size, window_size, "CardForge");

    Card c = Card("blue", '0', NORMAL);

    addCard(c); // card is going out of scope inside of here

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        update();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
