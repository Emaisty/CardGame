#ifndef CARDGAME_CARD_H
#define CARDGAME_CARD_H

#include <iostream>

class Card {
public:
    Card(const std::string &name = "");

    enum class_of_card {
        defensive, attacking, healing, spell, weapon, armor
    };

    void setName(const std::string &name);

    const std::string &getName() const;

protected:
    std::string name;
};

#endif