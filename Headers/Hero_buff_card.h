#ifndef CARDGAME_HERO_BUFF_H
#define CARDGAME_HERO_BUFF_H

#include "Card.h"

class Hero_buff_card : public Card {
public:
    Hero_buff_card(const std::string &name, int value);

    void setValue(int value);

    int getValue() const;

protected:
    int value;
};

#endif