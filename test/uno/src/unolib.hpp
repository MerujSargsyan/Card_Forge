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

string format(string color, char num); 

class UnoCard: public Card
{
public:
    string color;
    int num;
    CardType t;

    UnoCard(string color, int num, CardType t) : Card(format(color, num));
    /*UnoCard(string color, int num, float rotation, CardType t) : Card(rotation, format(color, num)) {
        this->color = color;
        this->num = num;
        this->t = t;
    }*/
};
