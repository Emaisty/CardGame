#ifndef CARDGAME_CARDDECKS_H
#define CARDGAME_CARDDECKS_H

#include <vector>
#include <fstream>
#include <cstring>
#include "Combat_card.h"
#include "Spell_card.h"
#include "Hero_buff_card.h"

void printMenuCardInformation();

void cardMenu();

class All_cards {
public:
    //load from file all cards
    All_cards();

    //write to file all cards
    ~All_cards();

    bool createNewCard();

    void displayCards();

    Card *getCard(int number_of_card);

    long unsigned int getSize();

private:
    std::vector<Card *> cards;
};

class All_decks {
public:
    //load from file all decks
    All_decks();

    //write to file all decks
    ~All_decks();

    void createNewDeck();

    void displayDecks();

    std::vector<Card *> getDeck(int number_of_deck);

    long unsigned int getSize();

private:
    All_cards cards;
    std::vector<std::vector<int>> decks;
};

#endif //CARDGAME_CARDDECKS_H
