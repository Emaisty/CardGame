#include "Card.h"

class Hero_buff_card : Card{
public:
    Hero_buff_card(const std::string &name, int value);

protected:
    int value;
};
