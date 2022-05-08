#ifndef CARDGAME_CARD_H
#define CARDGAME_CARD_H

#include <iostream>
#include <fstream>
#include <cstring>

bool inputCorrectNumber(int &number, std::istream &iss);

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

    void setMana(int mana);

    int getMana() const;

    virtual Card *clone() const = 0;

    virtual void writeCard(std::ostream &) const = 0;

    virtual Card *readCard(std::ifstream &) = 0;

    virtual void displayCard(std::ostream &) const = 0;

    virtual Card *inputNewCard(std::istream &, std::ostream &) = 0;

    void writeCardIntoFile(std::ostream &file) const;

    void displayMainCard(std::ostream &oss) const;

protected:
    int mana;
    std::string name;
    class_of_card type_of_class;
};

std::string readNameOfCard(std::ifstream &file);

int readManaOfCard(std::ifstream &file);

Card::class_of_card readType_of_classOfCard(std::ifstream &file);

std::string inputNameOfCard(std::istream &iss, std::ostream &oss);

int inputManaOfCard(std::istream &iss, std::ostream &oss);

#endif