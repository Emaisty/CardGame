#include "Player.h"

Player::Player(int hp, int armor, int weapon) : hp(hp), armor(armor), weapon(weapon) {}

int Player::getHp() const {
    return hp;
}

int Player::getArmor() const {
    return armor;
}

int Player::getWeapon() const {
    return weapon;
}

const set_of_cards &Player::getOnField() const {
    return on_field;
}

const set_of_cards &Player::getOnHand() const {
    return on_hand;
}

void Player::setHp(int hp) {
    Player::hp = hp;
}

void Player::setArmor(int armor) {
    Player::armor = armor;
}

void Player::setWeapon(int weapon) {
    Player::weapon = weapon;
}

void Player::setOnField(const set_of_cards &onField) {
    on_field = onField;
}

void Player::setOnHand(const set_of_cards &onHand) {
    on_hand = onHand;
}
