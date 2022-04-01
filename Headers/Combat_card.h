#include "Card.h"

class Combat_card : Card {
public:
    Combat_card(const std::string &name, int hp, int attack);

protected:
    int hp;
    int attack;
};