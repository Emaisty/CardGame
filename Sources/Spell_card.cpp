#include "Spell_card.h"

Spell_card::Spell_card(const std::string &name, bool target, int value) {
    this->name = name;
    this->target = target;
    this->value = value;
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
