#include "Player.h"


int Player::getHp() const {
    return hp;
}

int Player::getArmor() const {
    return armor;
}

int Player::getWeapon() const {
    return weapon;
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

void Player::takeDamage(int damage) {
    Player::hp -= damage;
}

bool Player::ifPlayerAlive() {
    return hp > 0;
}

const std::vector<Combat_card> &Player::getPlayerCombatCards() const {
    return player_combat_cards;
}

const std::vector<Combat_card> &Player::getPlayerFiled() const {
    return player_filed;
}

const std::vector<Hero_buff_card> &Player::getPlayerHeroesCards() const {
    return player_heroes_cards;
}

const std::vector<Spell_card> &Player::getPlayerSpellCards() const {
    return player_spell_cards;
}

void Player::setPlayerCombatCards(const std::vector<Combat_card> &playerCombatCards) {
    player_combat_cards = playerCombatCards;
}

void Player::setPlayerFiled(const std::vector<Combat_card> &playerFiled) {
    player_filed = playerFiled;
}

void Player::setPlayerHeroesCards(const std::vector<Hero_buff_card> &playerHeroesCards) {
    player_heroes_cards = playerHeroesCards;
}

void Player::setPlayerSpellCards(const std::vector<Spell_card> &playerSpellCards) {
    player_spell_cards = playerSpellCards;
}

void Player::fromHandtoField(int number_of_card) {
    this->player_filed.push_back(this->player_combat_cards[number_of_card]);
    this->player_combat_cards.erase(this->player_combat_cards.begin() + number_of_card);
}

void Player::useSpell(int number_of_card) {
    this->player_spell_cards.erase(this->player_spell_cards.begin() + number_of_card);
}

void Player::useHeroCard(int number_od_card) {
    if (this->player_heroes_cards[number_od_card].getTypeOfClass() == Card::class_of_card::armor)
        this->armor += this->player_heroes_cards[number_od_card].getValue();
    if (this->player_heroes_cards[number_od_card].getTypeOfClass() == Card::class_of_card::weapon)
        setWeapon(this->player_heroes_cards[number_od_card].getValue());
}

void Player::setName(const std::string &name) {
    Player::name = name;
}

const std::string &Player::getName() const {
    return name;
}

Player::Player(int hp, int armor, int weapon, const std::string &name) : hp(hp), armor(armor), weapon(weapon),
                                                                         name(name) {}
