#include "cardforge.hpp"

string format(string origin, char num, string color) {
    int pos1 = origin.find('*', 0);
    origin.replace(pos1, 1, color);
    int pos2 = origin.find('*', 0);
    origin.replace(pos2, 1, 1, num);
    return origin;
}

Card::Card(string color, char num, CardType type) {
    this->num = num;
    this->color = color;
    this->type = type;
    src = format(string("./resources/uno/*_*.png"), num, color); // TODO: make more general
    pos = {.x = 250, .y = 250};
    txt = LoadTexture(src.c_str());
}

void Card::display() {
    if(IsTextureReady(txt)) DrawTexture(txt, pos.x, pos.y, WHITE);
}

Card::~Card() {
    UnloadTexture(txt);
}

Game::Game(float card_width, float card_height) {
    card_size = (Vector2){.x = card_width, .y = card_height};
    cards = std::vector<std::shared_ptr<Card>>();
}

void Game::update() {
    for(const std::shared_ptr<Container>& cont : containers) {
        cont->display();
    }
}

void Game::add_container(Container* container) {
    auto cont_ptr = std::make_shared<Container>(container);
    containers.push_back(cont_ptr);
}

Container::Container(float start_x, float start_y, int init_count) {
    rect = Rectangle(start_x, start_y, card_size.x * init_count, card_size.y, BLACK);   
    containers = std::vector<std::shared_ptr<Card>>();
}

void Container::add_card(string color, int num, CardType t) {
    auto card_ptr = std::make_shared<Card>(color, num, t);
    .push_back(card_ptr);
}

void display() {
    for(const std::shared_ptr<Card>& card : cards) {
        card->display();
    }
}
