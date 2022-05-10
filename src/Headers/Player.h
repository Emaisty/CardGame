#ifndef CARDGAME_PLAYER_H
#define CARDGAME_PLAYER_H


#include <vector>
#include <cstring>
#include "Combat_card.h"
#include "Hero_buff_card.h"
#include "Spell_card.h"

class Player {
public:
    Player(const std::string &name = "", int hp = 0, int armor = 0, int weapon = 0, bool is_computer = false);

    ~Player();

    Player &operator=(Player const &player);

    void increaseArmor(int armor);

    void setWeapon(int weapon);

    void setPassword(std::string new_password);

    bool checkPassword(std::string password);

    int getHp() const;

    int getArmor() const;

    int getWeapon() const;

    void takeDamage(int damage);

    bool ifPlayerAlive();

    void setPlayerFiled(const std::vector<Combat_card> &playerFiled);

    void setPlayerHandCards(const std::vector<Card *> &new_hand_cards);

    void setPlayerStackCards(const std::vector<Card *> &new_stack_cards);

    const std::vector<Card *> &getPlayerCards() const;

    std::vector<Combat_card> &getPlayerFiled();

    void killUnit(int number_of_card);

    void fromHandToField(int number_of_card);

    void damageOnUnit(int number_of_card, int value);

    void healOnUnit(int number_of_card, int value);

    void useSpellCard(int number_of_card);

    void useHeroCard(int number_od_card);

    const std::string &getName() const;

    void setName(const std::string &name);

    void setAllCardsPlayable();

    const std::vector<bool> &getCanPlayCard() const;

    void setCardNotPlayable(int number_of_card);

    int getMana() const;

    void decreaseMana(int value);

    void prepareForRound();

    void initGame();

    bool isComputer() const;

    //write inf about player into file
    void savePlayer(std::ostream &file) const;

    //read inf about player from file
    void loadPlayer(std::ifstream &file);

    void setIsComputer(bool isComputer);

protected:
    std::string name;
    int hp, armor, weapon, current_mana = 1, mana = 1;
    size_t password;
    bool is_computer;
    std::vector<Combat_card> player_filed;
    std::vector<bool> can_play_card;
    std::vector<Card *> players_cards, players_stack;
};


#endif