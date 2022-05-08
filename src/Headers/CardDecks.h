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

private:
    All_cards cards;
    std::vector<std::vector<int>> decks;
};


class CardDeck {
public:
    const std::vector<Combat_card> &getCombatCards() const;

    const std::vector<Spell_card> &getSpellCards() const;

    const std::vector<Hero_buff_card> &getHeroCards() const;

    void setCombatCards(const std::vector<Combat_card> &combatCards);

    void setSpellCards(const std::vector<Spell_card> &spellCards);

    void setHeroCards(const std::vector<Hero_buff_card> &heroCards);

private:
    std::vector<Combat_card> Combat_cards;
    std::vector<Spell_card> Spell_cards;
    std::vector<Hero_buff_card> Hero_cards;
};

class AllCardDecks {
public:
    AllCardDecks();

public:
    const std::vector<CardDeck> &getAllCards() const;

private:
    std::vector<CardDeck> allCards;
};

#endif //CARDGAME_CARDDECKS_H
