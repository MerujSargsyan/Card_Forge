//#ifndef CARDFORGE_H
//#define CARDFORGE_H
#include <cardforge.hpp>
//#endif

typedef enum {
    NORMAL,
    SKIP,
    REVERSE,
    WILD,
    DRAW4
} CardType;

string format(string color, char num) {
    string origin = "./resources/uno/*_*.png";
    int pos1 = origin.find('*', 0);
    origin.replace(pos1, 1, color);
    int pos2 = origin.find('*', 0);
    origin.replace(pos2, 1, 1, num);
    return origin;
}

class UnoCard: public Card
{
public:
    string color;
    int num;
    CardType t;

    UnoCard(string color, int num, CardType t) : Card(format(color, num)) {
        this->color = color;
        this->num = num;
        this->t = t;
    }
    UnoCard(string color, int num, float rotation, CardType t) : Card(rotation, format(color, num)) {
        this->color = color;
        this->num = num;
        this->t = t;
    }
};
