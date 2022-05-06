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

Hero_buff_card *Hero_buff_card::readCard(std::ifstream &file) {
    this->name = readNameOfCard(file);
    this->mana = readManaOfCard(file);
    this->type_of_class = readType_of_classOfCard(file);
    char *var = new char[sizeof(int)];
    //read value of card
    int value;
    file.read(var, sizeof(int));
    memcpy(&value, var, sizeof(int));
    this->value = value;
    return this;
}