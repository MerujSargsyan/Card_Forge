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
    Card(string color, char num, CardType type, float x, float y) {
        this->num = num;
        this->color = color;
        this->type = type;
        src = format(string("resources/uno/*_*.png"), num, color);
        pos = {.x = x, .y = y};
        txt = LoadTexture(src.c_str());
    }
    
    void display() {
        if(IsTextureReady(txt)) DrawTexture(txt, pos.x, pos.y, WHITE);
    }

    ~Card() {
        UnloadTexture(txt);
    }

private:
    Texture2D txt;
};

class Game
{
public:
    Game(float card_width, float card_height) {
        card_size = (Vector2){.x = card_width, .y = card_height};
        cards = std::vector<std::shared_ptr<Card>>();
    }

    void update() {
        for(const std::shared_ptr<Card>& card : cards) {
            card->display();
        }
    }

    static void set_card_size(float x, float y) {
        //card_size = (Vector2){.x = x, .y = y};
    }

    void update_card_size() {
        for(const std::shared_ptr<Card>& card : cards) {
            //card->texture = ;
        }
    }

    void add_card(string color, int num, CardType t, float x, float y) {
        auto card_ptr = std::make_shared<Card>(color, num, t, x, y);
        cards.push_back(card_ptr);
    }

private:
    Vector2 card_size;
    std::vector<std::shared_ptr<Card>> cards;
};

int main(int argc, char** argv) {
    SetTargetFPS(30);

    Game g = Game(50.0f, 50.0f);
    InitWindow(window_size, window_size, "CardForge");

    g.add_card("yellow", '0', NORMAL, 5.0f, 5.0f);
    g.add_card("green", '9', NORMAL, 35.0f, 40.0f);
    g.add_card("green", '9', NORMAL, 125.0f, 125.0f);

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        g.update();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
