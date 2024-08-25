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
    txt = LoadTexture(src.c_str());
}

void Card::display(float x, float y) {
    if(IsTextureReady(txt)) DrawTextureEx(txt, (Vector2){x, y}, 0.0f, card_scale, WHITE);
}

Card::~Card() {
    UnloadTexture(txt);
}

Game::Game(float scale) {
    card_scale = scale;
    containers = std::vector<std::shared_ptr<Container>>();
}

void Game::update() {
    for(const std::shared_ptr<Container>& cont : containers) {
        cont->display();
    }
}

void Game::add_container(float start_x, float start_y, int init_count) {
    auto cont_ptr = std::make_shared<Container>(start_x, start_y, init_count);
    containers.push_back(cont_ptr);
}

void Game::add_container(float start_x, float start_y, float x_padding, float y_padding, int init_count) {
    auto cont_ptr = std::make_shared<Container>(start_x, start_y, x_padding, y_padding, init_count);
    containers.push_back(cont_ptr);
}

Container::Container(float start_x, float start_y, int init_count) {
    rect = (Rectangle){start_x, start_y, 1.0f, 1.0f};   
    cards = std::vector<std::shared_ptr<Card>>();
    x_padding = 50.0f;
}

Container::Container(float start_x, float start_y, float x_padding, float y_padding, int init_count) {
    rect = (Rectangle){start_x, start_y, 1.0f, 1.0f};   
    cards = std::vector<std::shared_ptr<Card>>();
    this->x_padding = x_padding;
    this->y_padding = y_padding;
}

void Container::add_card(string color, int num, CardType t) {
    auto card_ptr = std::make_shared<Card>(color, num, t);
    cards.push_back(card_ptr);
}

void Container::display() {
    float current_x = rect.x;
    float current_y = rect.y;
    for(const std::shared_ptr<Card>& card : cards) {
        card->display(current_x, current_y);
        current_x += x_padding;
        current_y += y_padding;
    }
}
