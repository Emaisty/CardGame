#include "Hero_buff_card.h"

Hero_buff_card::Hero_buff_card(const std::string &name, int value, int mana) {
    this->name = name;
    this->value = value;
    this->mana = mana;
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

void Hero_buff_card::saveCard(std::ostream &file) const {
    writeCardIntoFile(file);
    char *var = new char[sizeof(int)];
    //write value of card
    memcpy(var, &value, sizeof(int));
    file.write(var, sizeof(int));
}