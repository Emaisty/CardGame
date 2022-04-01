#include "Hero_buff_card.h"

Hero_buff_card::Hero_buff_card(const std::string &name, int value) : Card(name), value(value) {}

int Hero_buff_card::getValue() const {
    return value;
}

void Hero_buff_card::setValue(int value) {
    Hero_buff_card::value = value;
}
