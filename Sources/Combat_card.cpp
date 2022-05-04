#include "Combat_card.h"

Combat_card::Combat_card(const std::string &name, int hp, int attack, int mana) {
    this->name = name;
    this->hp = hp;
    this->attack = attack;
    this->mana = mana;
}

int Combat_card::getHp() const {
    return hp;
}

void Combat_card::getDamage(int damage) {
    hp -= damage;
}

void Combat_card::getHeal(int heal) {
    hp += heal;
}

int Combat_card::getValue() const {
    return attack;
}

void Combat_card::setHp(int hp) {
    Combat_card::hp = hp;
}

void Combat_card::setValue(int attack) {
    Combat_card::attack = attack;
}

Combat_card *Combat_card::clone() const {
    return new Combat_card(*this);
}