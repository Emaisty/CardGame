#ifndef CARDGAME_HERO_BUFF_H
#define CARDGAME_HERO_BUFF_H

#include "Card.h"

class Hero_buff_card : public Card {
public:
    Hero_buff_card(const std::string &name = "", int value = 0, int mana = 1);

    void setValue(int value) override;

    int getValue() const override;

    Hero_buff_card *clone() const override;

    void saveCard(std::ostream& file) const override;

protected:
    int value;
};

#endif