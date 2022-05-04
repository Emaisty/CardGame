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

void Player::increaseArmor(int armor) {
    Player::armor = armor;
}

void Player::setWeapon(int weapon) {
    Player::weapon = weapon;
}

void Player::setPassword(std::string new_password) {
    password = std::hash<std::string>{}(new_password);
}

bool Player::checkPassword(std::string password) {
    size_t users_password = std::hash<std::string>{}(password);
    return this->password == users_password;
}

void Player::takeDamage(int damage) {
    Player::hp -= damage;
}

bool Player::ifPlayerAlive() {
    return hp > 0;
}

std::vector<Combat_card> &Player::getPlayerFiled() {
    return player_filed;
}

const std::vector<Card *> &Player::getPlayerCards() const {
    return players_cards;
}

void Player::setPlayerCombatCards(const std::vector<Combat_card> &playerCombatCards) {
    for (int i = 0; i < playerCombatCards.size(); ++i) {
        Card *new_card = playerCombatCards[i].clone();
        players_cards.push_back(new_card);
    }
}

void Player::setPlayerFiled(const std::vector<Combat_card> &playerFiled) {
    player_filed = playerFiled;
}

void Player::setPlayerHeroesCards(const std::vector<Hero_buff_card> &playerHeroesCards) {
    for (int i = 0; i < playerHeroesCards.size(); ++i) {
        Card *new_card = playerHeroesCards[i].clone();
        players_cards.push_back(new_card);
    }
}

void Player::setPlayerSpellCards(const std::vector<Spell_card> &playerSpellCards) {
    for (int i = 0; i < playerSpellCards.size(); ++i) {
        Card *new_card = playerSpellCards[i].clone();
        players_cards.push_back(new_card);
    }
}

void Player::killUnit(int number_of_card) {
    this->player_filed.erase(this->player_filed.begin() + number_of_card);
    this->can_play_card.erase(this->can_play_card.begin() + number_of_card);
}

void Player::damageOnUnit(int number_of_card, int value) {
    this->player_filed[number_of_card].getDamage(value);
}

void Player::healOnUnit(int number_of_card, int value) {
    this->player_filed[number_of_card].getHeal(value);
}

void Player::fromHandtoField(int number_of_card) {
    Combat_card *new_field_card = dynamic_cast<Combat_card *>(players_cards[number_of_card]);
    this->player_filed.push_back(*new_field_card);
    delete players_cards[number_of_card];
    this->players_cards.erase(this->players_cards.begin() + number_of_card);
    this->can_play_card.push_back(false);
}

void Player::useSpellCard(int number_of_card) {
    delete this->players_cards[number_of_card];
    this->players_cards.erase(this->players_cards.begin() + number_of_card);
}

void Player::useHeroCard(int number_od_card) {
    Hero_buff_card *new_hero_card = dynamic_cast<Hero_buff_card *>(players_cards[number_od_card]);
    if (new_hero_card->getTypeOfClass() == Card::class_of_card::armor)
        increaseArmor(new_hero_card->getValue());
    if (new_hero_card->getTypeOfClass() == Card::class_of_card::weapon)
        setWeapon(new_hero_card->getValue());
    delete this->players_cards[number_od_card];
    this->players_cards.erase(this->players_cards.begin() + number_od_card);
}

void Player::setName(const std::string &name) {
    Player::name = name;
}

const std::string &Player::getName() const {
    return name;
}

Player::Player(const std::string &name, int hp, int armor, int weapon) : name(name), hp(hp), armor(armor),
                                                                         weapon(weapon) {}

Player::~Player() {
    for (int i = 0; i < players_cards.size(); ++i)
        delete players_cards[i];

}

void Player::setAllCardsPlayable() {
    for (int i = 0; i < can_play_card.size(); ++i)
        can_play_card[i] = true;
}

const std::vector<bool> &Player::getCanPlayCard() const {
    return can_play_card;
}

void Player::setCardNotPlayable(int number_of_card) {
    can_play_card[number_of_card] = false;
}

int Player::getMana() const {
    return current_mana;
}

void Player::decreaseMana(int value) {
    current_mana -= value;
}

void Player::prepareForRound() {
    mana++;
    current_mana = mana;
    this->setAllCardsPlayable();
}