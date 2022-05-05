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

int Card::getMana() const {
    return mana;
}

void Card::writeCardIntoFile(std::ostream &file) const {
    char *var = new char[sizeof(int)];
    int card_is_combat = 1;
    //which card is it - combat spell or hero
    memcpy(var, &card_is_combat, sizeof(int));//write type of card
    file.write(var, sizeof(int));
    //write name into file
    int size_of_name = name.size();
    memcpy(var, &size_of_name, sizeof(int));
    file.write(var, sizeof(int));
    for (int i = 0; i < size_of_name; ++i) {
        int letter = (int) name[i];
        memcpy(var, &letter, sizeof(int));
        file.write(var, sizeof(int));
    }
    //write mana
    memcpy(var, &mana, sizeof(int));
    file.write(var, sizeof(int));
    //type of class
    char *type = new char[sizeof(Card::class_of_card)];
    memcpy(type, &type_of_class, sizeof(Card::class_of_card));
    file.write(type, sizeof(Card::class_of_card));
}
