#ifndef CARDGAME_CARDDECKS_H
#define CARDGAME_CARDDECKS_H

#include <vector>
#include "Combat_card.h"
#include "Spell_card.h"
#include "Hero_buff_card.h"

class CardDeck {
public:
    const std::vector<Combat_card> &getCombatCards() const;

    const std::vector<Spell_card> &getSpellCards() const;

    const std::vector<Hero_buff_card> &getHeroCards() const;

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
