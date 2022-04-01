#ifndef CARDGAME_PLAYER_H
#define CARDGAME_PLAYER_H


#include <vector>
#include "Combat_card.h"
#include "Hero_buff_card.h"
#include "Spell_card.h"

struct set_of_cards {
    std::vector<Combat_card> player_comber_cards;
    std::vector<Hero_buff_card> player_heroes_cards;
    std::vector<Spell_card> player_spell_cards;
};

class Player {
public:
    Player(int hp = 30, int armor = 0, int weapon = 0);

    void setHp(int hp);

    void setArmor(int armor);

    void setWeapon(int weapon);

    void setOnField(const set_of_cards &onField);

    void setOnHand(const set_of_cards &onHand);

    int getHp() const;

    int getArmor() const;

    int getWeapon() const;

    const set_of_cards &getOnField() const;

    const set_of_cards &getOnHand() const;

protected:
    int hp, armor, weapon;
    set_of_cards on_field, on_hand;
};

#endif