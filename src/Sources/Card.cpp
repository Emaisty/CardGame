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

void Card::setMana(int mana) {
    Card::mana = mana;
}

void Card::writeCardIntoFile(std::ostream &file) const {
    char *var = new char[sizeof(int)];
    int class_of_card;
    if (this->type_of_class == Card::defensive || this->type_of_class == Card::attacking) {
        class_of_card = 0;
    }
    if (this->type_of_class == Card::healing || this->type_of_class == Card::spell) {
        class_of_card = 1;
    }
    if (this->type_of_class == Card::armor || this->type_of_class == Card::weapon) {
        class_of_card = 2;
    }
    //which card is it - combat spell or hero
    memcpy(var, &class_of_card, sizeof(int));//write type of card
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
    delete[] var;
    delete[] type;
}

std::string readNameOfCard(std::ifstream &file) {
    char *var = new char[sizeof(int)];
    //read name
    int size_of_name;
    file.read(var, sizeof(int));
    memcpy(&size_of_name, var, sizeof(int));
    std::string new_name;
    for (int i = 0; i < size_of_name; ++i) {
        int letter;
        file.read(var, sizeof(int));
        memcpy(&letter, var, sizeof(int));
        new_name.push_back((char) letter);
    }
    delete[] var;
    return new_name;
}

int readManaOfCard(std::ifstream &file) {
    char *var = new char[sizeof(int)];
    int mana;
    file.read(var, sizeof(int));
    memcpy(&mana, var, sizeof(int));
    delete[] var;
    return mana;
}

Card::class_of_card readType_of_classOfCard(std::ifstream &file) {
    Card::class_of_card class_of_new_card;
    char *class_of_card = new char[sizeof(Card::class_of_card)];
    file.read(class_of_card, sizeof(Card::class_of_card));
    memcpy(&class_of_new_card, class_of_card, sizeof(Card::class_of_card));
    delete[] class_of_card;
    return class_of_new_card;
}