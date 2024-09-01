#include "unolib.hpp"

string format(string color, char num) {
    string origin = "./resources/uno/*_*.png";
    int pos1 = origin.find('*', 0);
    origin.replace(pos1, 1, color);
    int pos2 = origin.find('*', 0);
    origin.replace(pos2, 1, 1, num);
    return origin;
}

UnoCard::UnoCard(string color, int num, CardType t) : Card(format(color, num)) {
    this->color = color;
    this->num = num;
    this->t = t;
}

