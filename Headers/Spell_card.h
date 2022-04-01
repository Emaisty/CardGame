#ifndef CARDGAME_SPELL_CARD_H
#define CARDGAME_SPELL_CARD_H

#include "Card.h"

class Spell_card : Card {
public:
    Spell_card(const std::string &name, bool target, int value);

    void setTarget(bool target);

    void setValue(int value);

    bool isTarget() const;

    int getValue() const;

protected:
    bool target;
    int value;
};

#endif