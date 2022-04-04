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
    Player(int hp, int armor, int weapon, const std::string &name);

    void setHp(int hp);

    void setArmor(int armor);

    void setWeapon(int weapon);

    int getHp() const;

    int getArmor() const;

    int getWeapon() const;

    void takeDamage(int damage);

    bool ifPlayerAlive();

    void setPlayerCombatCards(const std::vector<Combat_card> &playerCombatCards);

    void setPlayerFiled(const std::vector<Combat_card> &playerFiled);

    void setPlayerHeroesCards(const std::vector<Hero_buff_card> &playerHeroesCards);

    void setPlayerSpellCards(const std::vector<Spell_card> &playerSpellCards);

    const std::vector<Combat_card> &getPlayerCombatCards() const;

    const std::vector<Combat_card> &getPlayerFiled() const;

    const std::vector<Hero_buff_card> &getPlayerHeroesCards() const;

    const std::vector<Spell_card> &getPlayerSpellCards() const;

    void fromHandtoField(int number_of_card);

    void useSpell(int number_of_card);

    void useHeroCard(int number_od_card);

    const std::string &getName() const;

    void setName(const std::string &name);



protected:
    int hp, armor, weapon;
    std::string name;
    std::vector<Combat_card> player_combat_cards, player_filed;
    std::vector<Hero_buff_card> player_heroes_cards;
    std::vector<Spell_card> player_spell_cards;
};

#endif