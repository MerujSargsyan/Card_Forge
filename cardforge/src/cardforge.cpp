#include "cardforge.hpp"

Card::Card(string src) {
    this->src = src;
    txt = LoadTexture(src.c_str());
    rotation = 0;
}

Card::Card(float rotation, string src) {
    this->src = src;
    txt = LoadTexture(src.c_str());
    this->rotation = rotation;
}

void Card::display(float x, float y) {
    if(IsTextureReady(txt)) DrawTextureEx(txt, (Vector2){x, y}, rotation, card_scale, WHITE);
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

void Game::add_container(float start_x, float start_y) {
    auto cont_ptr = std::make_shared<Container>(start_x, start_y);
    containers.push_back(cont_ptr);
}

void Game::add_container(float start_x, float start_y, float x_padding, float y_padding) {
    auto cont_ptr = std::make_shared<Container>(start_x, start_y, x_padding, y_padding);
    containers.push_back(cont_ptr);
}

Container::Container(float start_x, float start_y) {
    rect = (Rectangle){start_x, start_y, 1.0f, 1.0f};   
    cards = std::vector<std::shared_ptr<Card>>();
    x_padding = 50.0f;
    y_padding = 0.0f;
}

Container::Container(float start_x, float start_y, float x_padding, float y_padding) {
    rect = (Rectangle){start_x, start_y, 1.0f, 1.0f};   
    cards = std::vector<std::shared_ptr<Card>>();
    this->x_padding = x_padding;
    this->y_padding = y_padding;
}

void Container::add_card(string src) {
    auto card_ptr = std::make_shared<Card>(src);
    cards.push_back(card_ptr);
}

void Container::add_card(float rotation, string src) { 
    auto card_ptr = std::make_shared<Card>(rotation, src);
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
