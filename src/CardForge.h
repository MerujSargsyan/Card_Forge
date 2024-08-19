#include <raylib.h>

using std::string;

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

class Container;

class Game
{
public:
    static Vector2 card_size;

    Game(float card_width, float card_height) {
        card_size = (Vector2){.x = card_width, .y = card_height};
        containers = std::vector<std::shared_ptr<Container>>();
    }

    void update() {
        for(const std::shared_ptr<Container>& cont : containers) {
            cont->display();
        }
    }

    static void set_card_size(float x, float y) {
        // TODO
    }

    void update_card_size() {
        // TODO
    }
private:
    std::vector<std::shared_ptr<Container>> containers;
};

Vector2 Game::card_size = {75.0f, 50.0f};

class Container 
{
public:
    Rectangle rect;

    Container(float start_x, float start_y, int init_count) {
        rect = Rectangle(start_x, start_y, Game::card_size.x * init_count, Game::card_size.y, BLACK);   
    }

    void add_card(string color, int num, CardType t) {
        auto card_ptr = std::make_shared<Card>(color, num, t, 50.0f, 50.0f);
        cards.push_back(card_ptr);
    }

    void display() {
        for(const std::shared_ptr<Card>& card : cards) {
            card->display();
        }
    }

private:
    std::vector<std::shared_ptr<Card>> cards;
};
