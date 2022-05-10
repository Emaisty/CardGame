#include "Player.h"

Player::Player(const std::string &name, int hp, int armor, int weapon, bool is_computer) : name(name), hp(hp),
                                                                                           armor(armor),
                                                                                           weapon(weapon),
                                                                                           is_computer(is_computer) {}

Player::~Player() {
    for (auto & players_card : players_cards)
        delete players_card;
    for (auto & i : players_stack)
        delete i;
}

Player &Player::operator=(Player const &player) {
    if (this == &player)
        return *this;
    this->hp = player.hp;
    this->armor = player.armor;
    this->weapon = player.weapon;
    this->current_mana = player.current_mana;
    this->mana = player.mana;
    this->name = player.name;
    this->password = player.password;
    this->is_computer = player.is_computer;
    setPlayerFiled(player.player_filed);
    setPlayerHandCards(player.players_cards);
    setPlayerStackCards(player.players_stack);
    return *this;
}

int Player::getHp() const {
    return hp;
}

int Player::getArmor() const {
    return armor;
}

int Player::getWeapon() const {
    return weapon;
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

void Player::setPlayerFiled(const std::vector<Combat_card> &playerFiled) {
    player_filed = playerFiled;
}

void Player::setPlayerHandCards(const std::vector<Card *> &new_hand_cards) {
    for (auto new_hand_card : new_hand_cards)
        players_cards.push_back(new_hand_card->clone());
}

void Player::setPlayerStackCards(const std::vector<Card *> &new_stack_cards) {
    for (auto new_stack_card : new_stack_cards)
        players_stack.push_back(new_stack_card->clone());
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

void Player::fromHandToField(int number_of_card) {
    auto *new_field_card = dynamic_cast<Combat_card *>(players_cards[number_of_card]);
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
    auto *new_hero_card = dynamic_cast<Hero_buff_card *>(players_cards[number_od_card]);
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


void Player::setAllCardsPlayable() {
    for (auto && i : can_play_card)
        i = true;
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
    if (mana <= 10)
        mana++;
    current_mana = mana;
    this->setAllCardsPlayable();
    srand((unsigned int) time(NULL));
    int random_card = rand() % players_stack.size();
    Card *new_card = players_stack[random_card]->clone();
    players_cards.push_back(new_card);
    delete players_stack[random_card];
    players_stack.erase(players_stack.begin() + random_card);
}

bool Player::isComputer() const {
    return is_computer;
}

void Player::initGame() {
    for (int i = 0; i < 3; ++i) {
        srand((unsigned int) time(NULL));
        int random_card = rand() % players_stack.size();
        Card *new_card = players_stack[random_card]->clone();
        players_cards.push_back(new_card);
        delete players_stack[random_card];
        players_stack.erase(players_stack.begin() + random_card);
    }
}

void Player::savePlayer(std::ostream &file) const {
    char *var = new char[sizeof(int)];
    //save size of name of player
    long unsigned int size_of_name = name.size();
    memcpy(var, &size_of_name, sizeof(int));
    file.write(var, sizeof(int));

    //save name of player
    for (int i = 0; i < size_of_name; ++i) {
        int letter = (int) name[i];
        memcpy(var, &letter, sizeof(int));
        file.write(var, sizeof(int));
    }

    //save player password hash
    char *password_raw = new char[sizeof(size_t)];
    memcpy(password_raw, &password, sizeof(size_t));
    file.write(password_raw, sizeof(size_t));
    //save player stats
    memcpy(var, &hp, sizeof(int));//save hp
    file.write(var, sizeof(int));
    memcpy(var, &armor, sizeof(int));//save armor
    file.write(var, sizeof(int));
    memcpy(var, &weapon, sizeof(int));//save weapon
    file.write(var, sizeof(int));
    memcpy(var, &current_mana, sizeof(int));//save current_mana
    file.write(var, sizeof(int));
    memcpy(var, &mana, sizeof(int));//save max cap of mana
    file.write(var, sizeof(int));

    //save information, about if player is computer or not
    char *computer_player_or_not = new char[sizeof(bool)];
    memcpy(computer_player_or_not, &is_computer, sizeof(bool));
    file.write(computer_player_or_not, sizeof(bool));

    //save players filed
    long unsigned int size_of_field = player_filed.size();
    memcpy(var, &size_of_field, sizeof(int));
    file.write(var, sizeof(int));

    for (long unsigned int i = 0; i < size_of_field; ++i) {
        player_filed[i].writeCard(file);
    }

    //save player hand
    long unsigned int size_of_hand = players_cards.size();
    memcpy(var, &size_of_hand, sizeof(int));
    file.write(var, sizeof(int));

    for (long unsigned int i = 0; i < size_of_hand; ++i) {
        players_cards[i]->writeCard(file);
    }

    //save player stack
    long unsigned int size_of_stack = players_stack.size();
    memcpy(var, &size_of_stack, sizeof(int));
    file.write(var, sizeof(int));

    for (long unsigned int i = 0; i < size_of_stack; ++i) {
        players_stack[i]->writeCard(file);
    }
    delete[] var;
    delete[] password_raw;
    delete[] computer_player_or_not;
}

void Player::loadPlayer(std::ifstream &file) {
    char *var = new char[sizeof(int)];
    //read name of player from file
    int size_of_name;
    std::string new_name;
    file.read(var, sizeof(int));
    memcpy(&size_of_name, var, sizeof(int));
    for (int i = 0; i < size_of_name; ++i) {
        int letter;
        file.read(var, sizeof(int));
        memcpy(&letter, var, sizeof(int));
        new_name.push_back((char) letter);
    }
    //load player raw password
    char *password_raw = new char[sizeof(size_t)];
    size_t new_password;
    file.read(password_raw, sizeof(size_t));
    memcpy(&new_password, password_raw, sizeof(size_t));
    //load player stats
    int hp, armor, weapon, current_mana, mana;
    file.read(var, sizeof(int));
    memcpy(&hp, var, sizeof(int));
    file.read(var, sizeof(int));
    memcpy(&armor, var, sizeof(int));
    file.read(var, sizeof(int));
    memcpy(&weapon, var, sizeof(int));
    file.read(var, sizeof(int));
    memcpy(&current_mana, var, sizeof(int));
    file.read(var, sizeof(int));
    memcpy(&mana, var, sizeof(int));
    //load if player computer or not
    bool is_computer;
    char *if_player_comp = new char[sizeof(bool)];
    file.read(if_player_comp, sizeof(bool));
    memcpy(&is_computer, if_player_comp, sizeof(bool));
    //read players field
    int size_of_field;
    file.read(var, sizeof(int));
    memcpy(&size_of_field, var, sizeof(int));
    std::vector<Combat_card> new_players_filed;
    for (int i = 0; i < size_of_field; ++i) {
        int type_of_card;
        Combat_card new_card;
        file.read(var, sizeof(int));
        memcpy(&type_of_card, var, sizeof(int));
        if (type_of_card != 0)
            throw "";
        new_card.readCard(file);
        new_players_filed.push_back(new_card);
    }
    //read player hand
    int size_of_hand;
    file.read(var, sizeof(int));
    memcpy(&size_of_hand, var, sizeof(int));
    std::vector<Card *> new_players_hand;
    for (int i = 0; i < size_of_hand; ++i) {
        int type_of_card;
        file.read(var, sizeof(int));
        memcpy(&type_of_card, var, sizeof(int));
        switch (type_of_card) {
            case 0: {
                Combat_card new_card;
                new_card.readCard(file);
                new_players_hand.push_back(new_card.clone());
                break;
            }
            case 1: {
                Spell_card new_card;
                new_card.readCard(file);
                new_players_hand.push_back(new_card.clone());
                break;
            }
            case 2: {
                Hero_buff_card new_card;
                new_card.readCard(file);
                new_players_hand.push_back(new_card.clone());
                break;
            }
            default:
                throw "";
        }
    }
    //read player stack
    int size_of_stack;
    file.read(var, sizeof(int));
    memcpy(&size_of_stack, var, sizeof(int));
    std::vector<Card *> new_players_stack;
    for (int i = 0; i < size_of_stack; ++i) {
        int type_of_card;
        Combat_card new_card;
        file.read(var, sizeof(int));
        memcpy(&type_of_card, var, sizeof(int));
        switch (type_of_card) {
            case 0: {
                Combat_card new_card;
                new_card.readCard(file);
                new_players_stack.push_back(new_card.clone());
                break;
            }
            case 1: {
                Spell_card new_card;
                new_card.readCard(file);
                new_players_stack.push_back(new_card.clone());
                break;
            }
            case 2: {
                Hero_buff_card new_card;
                new_card.readCard(file);
                new_players_stack.push_back(new_card.clone());
                break;
            }
            default:
                throw "";
        }
    }
    this->name = new_name;
    this->password = new_password;
    this->hp = hp;
    this->armor = armor;
    this->weapon = weapon;
    this->current_mana = current_mana;
    this->mana = mana;
    this->is_computer = is_computer;
    setPlayerFiled(new_players_filed);
    setPlayerHandCards(new_players_hand);
    setPlayerStackCards(new_players_stack);
    for (auto & i : new_players_hand) {
        delete i;
    }
    for (auto & i : new_players_stack) {
        delete i;
    }
    delete[] var;
    delete[] password_raw;
    delete[] if_player_comp;
}

void Player::setIsComputer(bool isComputer) {
    is_computer = isComputer;
}
