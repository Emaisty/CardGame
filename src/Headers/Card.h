#ifndef CARDGAME_CARD_H
#define CARDGAME_CARD_H

#include <iostream>
#include <fstream>
#include <cstring>

bool inputCorrectNumber(int &number, std::istream &iss);
/*
 * Main class of cards
 * have got:
 *  -name
 *  -mana
 *  -type of class
 *  can return them and set
 */
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

    //write information about card into file
    virtual void writeCard(std::ostream &) const = 0;

    //read card from file
    virtual Card *readCard(std::ifstream &) = 0;

    //output to ostream information about card
    virtual void displayCard(std::ostream &) const = 0;

    //users input new card from istream
    virtual Card *inputNewCard(std::istream &, std::ostream &) = 0;

    //write main information (name, mana, type) to file
    void writeCardIntoFile(std::ostream &file) const;

    //display main information (name, mana, type) to ostream
    void displayMainCard(std::ostream &oss) const;

protected:
    int mana;
    std::string name;
    class_of_card type_of_class;
};

//read name from file
std::string readNameOfCard(std::ifstream &file);

//read mana from file
int readManaOfCard(std::ifstream &file);

//read type from file
Card::class_of_card readType_of_classOfCard(std::ifstream &file);

//users input name of new card from istream
std::string inputNameOfCard(std::istream &iss, std::ostream &oss);

//users input mana of new card from istream
int inputManaOfCard(std::istream &iss, std::ostream &oss);

#endif