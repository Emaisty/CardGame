#ifndef CARDGAME_CARD_H
#define CARDGAME_CARD_H

#include <iostream>


class Card {
public:

    virtual ~Card() {}
    enum class_of_card {
        defensive, attacking, healing, spell, weapon, armor
    };

    void setName(const std::string &name);

    void setTypeOfClass(class_of_card typeOfClass);

    const std::string getName() const;

    class_of_card getTypeOfClass() const;

    virtual void setValue(int value) = 0;

    virtual int getValue() const = 0;

    int getMana() const;

    virtual Card *clone() const = 0;

protected:
    int mana;
    std::string name;
    class_of_card type_of_class;
};

#endif