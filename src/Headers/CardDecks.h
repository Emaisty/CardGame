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
    All_cards();

    ~All_cards();

    bool createNewCard();

    void displayCards();

    Card *getCard(int number_of_card);

    size_t getSize();

private:
    std::vector<Card *> cards;
};

class All_decks {
public:
    All_decks();

    ~All_decks();

    void createNewDeck();

    void displayDecks();

    std::vector<Card *> getDeck(int number_of_deck);

    size_t getSize();

private:
    All_cards cards;
    std::vector<std::vector<int>> decks;
};

#endif //CARDGAME_CARDDECKS_H
