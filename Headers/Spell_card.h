#ifndef CARDGAME_SPELL_CARD_H
#define CARDGAME_SPELL_CARD_H

#include "Card.h"

class Spell_card : public Card {
public:
    Spell_card(const std::string &name = "", bool target = 0, int value = 0, int mana = 1);

    void setTarget(bool target);

    void setValue(int value) override;

    bool isTarget() const;

    int getValue() const override;

    Spell_card *clone() const override;

protected:
    bool target;
    int value;
};

#endif