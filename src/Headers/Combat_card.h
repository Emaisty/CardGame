#ifndef CARDGAME_COMBER_CARD_H
#define CARDGAME_COMBER_CARD_H

#include "Card.h"
#include <cstring>

class Combat_card : public Card {
public:
    Combat_card(const std::string &name = "", int hp = 0, int attack = 0, int mana = 1);

    void setHp(int hp);

    void getDamage(int damage);

    void getHeal(int heal);

    int getHp() const;

    void setValue(int value) override;

    //return attack
    int getValue() const override;

    Combat_card *clone() const override;

    //write card to file
    void writeCard(std::ostream &file) const override;

    //read inf about card from file
    Combat_card *readCard(std::ifstream &file) override;

    //users input of new card
    Combat_card *inputNewCard(std::istream &iss, std::ostream &oss) override;

    void displayCard(std::ostream &oss) const override;

protected:
    int hp, attack;
};

#endif