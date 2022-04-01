#include "Combat_card.h"

Combat_card::Combat_card(const std::string &name, int hp, int attack) : Card(name), hp(hp), attack(attack) {}

int Combat_card::getHp() const {
    return hp;
}

int Combat_card::getAttack() const {
    return attack;
}

void Combat_card::setHp(int hp) {
    Combat_card::hp = hp;
}

void Combat_card::setAttack(int attack) {
    Combat_card::attack = attack;
}
