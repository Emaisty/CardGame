#include "Card.h"

class Spell_card : Card {
public:
    Spell_card(const std::string &name, bool target, int value);

protected:
    bool target;
    int value;
};
