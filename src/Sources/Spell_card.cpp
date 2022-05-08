#include "Spell_card.h"

Spell_card::Spell_card(const std::string &name, bool target, int value, int mana) {
    this->name = name;
    this->target = target;
    this->value = value;
    this->mana = mana;
}

bool Spell_card::isTarget() const {
    return target;
}

int Spell_card::getValue() const {
    return value;
}

void Spell_card::setTarget(bool target) {
    Spell_card::target = target;
}

void Spell_card::setValue(int value) {
    Spell_card::value = value;
}


Spell_card *Spell_card::clone() const {
    return new Spell_card(*this);
}

void Spell_card::writeCard(std::ostream &file) const {
    writeCardIntoFile(file);
    //write is target card or not
    char *is_target = new char[sizeof(bool)];
    memcpy(is_target, &target, sizeof(bool));
    file.write(is_target, sizeof(bool));
    //write value of card
    char *var = new char[sizeof(int)];
    memcpy(var, &value, sizeof(int));
    file.write(var, sizeof(int));
    delete[] var;
    delete[] is_target;
}

Spell_card *Spell_card::inputNewCard(std::istream &iss, std::ostream &oss) {
    this->name = inputNameOfCard(iss, oss);
    this->mana = inputManaOfCard(iss, oss);
    oss << std::endl << "Type value of card: ";
    int value;
    if (!inputCorrectNumber(value, iss))
        throw std::invalid_argument("invalid value input");
    oss << std::endl << "Type is_targer of card:[1/0] ";
    int is_targer;
    if (!inputCorrectNumber(is_targer, iss))
        throw std::invalid_argument("invalid is_targer input");
    this->value = value;
    this->target = is_targer;
    return this;
}

Spell_card *Spell_card::readCard(std::ifstream &file) {
    this->name = readNameOfCard(file);
    this->mana = readManaOfCard(file);
    this->type_of_class = readType_of_classOfCard(file);
    char *var = new char[sizeof(int)];
    //read is target card or not
    char *tar = new char[sizeof(bool)];
    bool is_target;
    file.read(tar, sizeof(bool));
    memcpy(&is_target, tar, sizeof(bool));
    //read value of card
    int value;
    file.read(var, sizeof(int));
    memcpy(&value, var, sizeof(int));
    this->target = is_target;
    this->value = value;
    delete[] var;
    delete[] tar;
    return this;
}

void Spell_card::displayCard(std::ostream &oss) const {
    this->displayMainCard(oss);
    oss << "value: " << value << " is it target: " << target << std::endl;
}