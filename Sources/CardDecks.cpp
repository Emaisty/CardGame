#include "CardDecks.h"

const std::vector<CardDeck> &AllCardDecks::getAllCards() const {
    return allCards;
}

AllCardDecks::AllCardDecks() {

}

const std::vector<Combat_card> &CardDeck::getCombatCards() const {
    return Combat_cards;
}

const std::vector<Spell_card> &CardDeck::getSpellCards() const {
    return Spell_cards;
}

const std::vector<Hero_buff_card> &CardDeck::getHeroCards() const {
    return Hero_cards;
}
