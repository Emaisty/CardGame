#ifndef CARDGAME_PLAYER_H
#define CARDGAME_PLAYER_H


#include <vector>
#include "Combat_card.h"
#include "Hero_buff_card.h"
#include "Spell_card.h"

/*struct set_of_cards {
    std::vector<Combat_card> player_comber_cards;
    std::vector<Hero_buff_card> player_heroes_cards;
    std::vector<Spell_card> player_spell_cards;
};*/

class Player {
public:
    Player(const std::string &name, int hp, int armor = 0, int weapon = 0);

    ~Player();

    void setHp(int hp);

    void setArmor(int armor);

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

    void setPlayerCombatCards(const std::vector<Combat_card> &playerCombatCards);

    void setPlayerHeroesCards(const std::vector<Hero_buff_card> &playerHeroesCards);

    void setPlayerSpellCards(const std::vector<Spell_card> &playerSpellCards);

    void setPlayerCards(const std::vector<Card *> &playerSpellCards);

    const std::vector<Card *> &getPlayerCards() const;

    std::vector<Combat_card> &getPlayerFiled();

    void killUnit(int number_of_card);

    void fromHandtoField(int number_of_card);

    void damageOnUnit(int number_of_card, int value);

    void healOnUnit(int number_of_card, int value);

    void useSpellCard(int number_of_card);

    void useHeroCard(int number_od_card);

    const std::string &getName() const;

    void setName(const std::string &name);


protected:
    int hp, armor, weapon;
    std::string name;
    size_t password;
    std::vector<Combat_card> player_filed;
    std::vector<Card *> players_cards;
};


#endif