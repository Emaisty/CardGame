#include "Card.h"

Card::Card(const std::string &name) : name(name) {}

void Card::setName(const std::string &name) {
    Card::name = name;
}

const std::string &Card::getName() const {
    return name;
}
