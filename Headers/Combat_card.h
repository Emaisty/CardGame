#ifndef CARDGAME_COMBER_CARD_H
#define CARDGAME_COMBER_CARD_H

#include "Card.h"

class Combat_card : Card {
public:
    Combat_card(const std::string &name, int hp, int attack);

    void setHp(int hp);

    void setAttack(int attack);

    int getHp() const;

    int getAttack() const;

protected:
    int hp;
    int attack;
};

#endif