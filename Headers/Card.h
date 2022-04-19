#ifndef CARDGAME_CARD_H
#define CARDGAME_CARD_H

#include <iostream>


class Card {
public:
    enum class_of_card {
        defensive, attacking, healing, spell, weapon, armor
    };

    Card(const std::string &name = "");

    void setName(const std::string &name);

    void setTypeOfClass(class_of_card typeOfClass);

    const std::string &getName() const;

    class_of_card getTypeOfClass() const;

protected:

    std::string name;
    class_of_card type_of_class;
};

#endif