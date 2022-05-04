#include "Hero_buff_card.h"

Hero_buff_card::Hero_buff_card(const std::string &name, int value) {
    this->name = name;
    this->value = value;
}

int Hero_buff_card::getValue() const {
    return value;
}

void Hero_buff_card::setValue(int value) {
    Hero_buff_card::value = value;
}

Hero_buff_card *Hero_buff_card::clone() const {
    return new Hero_buff_card(*this);
}