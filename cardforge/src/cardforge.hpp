#ifndef CARDFORGE_H
#define CARDFORGE_H

#include <raylib.h>
#include <string>
#include <vector>
#include <memory>

using std::string;

static float card_scale = 1.0f;

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
    float rotation;

    Card(string color, char num, CardType type, string src);
    Card(string color, char num, float rotation, CardType type, string src);
    void display(float x, float y);
    ~Card();

private:
    Texture2D txt;
};

class Container 
{
public:
    Rectangle rect;
    float x_padding;
    float y_padding;

    Container(float start_x, float start_y); 
    Container(float start_x, float start_y, float x_padding, float y_padding); 
    void add_card(string color, int num, CardType t, string src);
    void add_card(string color, int num, float rotation, CardType t, string src);
    void display();
private:
    std::vector<std::shared_ptr<Card>> cards;
};

class Game
{
public:
    Game(float card_scale);
    void update();
    void add_container(float start_x, float start_y);
    void add_container(float start_x, float start_y, float x_padding, float y_padding);
    std::vector<std::shared_ptr<Container>> containers;
};



#endif
