#ifndef CARDFORGE_H
#define CARDFORGE_H

#include <raylib.h>
#include <string>
#include <vector>
#include <memory>

using std::string;

static Vector2 card_size = {.x = 40.0f, .y = 50.0f};

string format(string origin, char num, string color); 

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

    Card(string color, char num, CardType type);
    void display();
    ~Card();

private:
    Texture2D txt;
};

class Game
{
public:
    static Vector2 card_size;

    Game(float card_width, float card_height);
    void update();
    static void set_card_size(float x, float y);
    void add_card(string color, int num, CardType t);
    void update_card_size();
private:
    std::vector<std::shared_ptr<Card>> cards;
};

/*class Container 
{
public:
    Rectangle rect;

    Container(float start_x, float start_y, int init_count) {
        rect = Rectangle(start_x, start_y, card_size.x * init_count, card_size.y, BLACK);   
    }

    void add_card(string color, int num, CardType t) {
        auto card_ptr = std::make_shared<Card>(color, num, t);
        cards.push_back(card_ptr);
    }

    void display() {
        for(const std::shared_ptr<Card>& card : cards) {
            card->display();
        }
    }

private:
    std::vector<std::shared_ptr<Card>> cards;
};*/

#endif
