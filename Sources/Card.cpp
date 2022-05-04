#include "Card.h"

void Card::setName(const std::string &name) {
    Card::name = name;
}

const std::string Card::getName() const {
    return name;
}

Card::class_of_card Card::getTypeOfClass() const {
    return type_of_class;
}

void Card::setTypeOfClass(Card::class_of_card typeOfClass) {
    type_of_class = typeOfClass;
}
