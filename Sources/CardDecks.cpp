#include "CardDecks.h"

const std::vector<CardDeck> &AllCardDecks::getAllCards() const {
    return allCards;
}

AllCardDecks::AllCardDecks() {
    CardDeck new_cardDeck;
    Combat_card combat1("Knight", 5, 5), combat2("Troop", 10, 2), combat3("King", 7, 7);
    Spell_card spell1("fireball", 0, 5), spell2("heal", 1, 4);
    Hero_buff_card hero1("axe", 5), hero2("armor", 3);
    std::vector<Combat_card> combats;
    combats.push_back(combat1);
    combats.push_back(combat2);
    combats.push_back(combat3);
    new_cardDeck.setCombatCards(combats);
    std::vector<Spell_card> spells;
    spells.push_back(spell1);
    spells.push_back(spell2);
    new_cardDeck.setSpellCards(spells);
    std::vector<Hero_buff_card> heroes;
    heroes.push_back(hero1);
    heroes.push_back(hero2);
    new_cardDeck.setHeroCards(heroes);
    allCards.push_back(new_cardDeck);
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

void CardDeck::setCombatCards(const std::vector<Combat_card> &combatCards) {
    Combat_cards = combatCards;
}

void CardDeck::setSpellCards(const std::vector<Spell_card> &spellCards) {
    Spell_cards = spellCards;
}

void CardDeck::setHeroCards(const std::vector<Hero_buff_card> &heroCards) {
    Hero_cards = heroCards;
}
