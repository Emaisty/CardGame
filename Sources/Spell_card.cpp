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

void Spell_card::saveCard(std::ostream &file) const {
    writeCardIntoFile(file);
    //write hp of card
    char *is_target = new char[sizeof(bool)];
    memcpy(is_target, &target, sizeof(bool));
    file.write(is_target, sizeof(bool));
    //write value of card
    char *var = new char[sizeof(int)];
    memcpy(var, &value, sizeof(int));
    file.write(var, sizeof(int));
}