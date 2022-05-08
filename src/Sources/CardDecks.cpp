#include "CardDecks.h"

void printMenuCardInformation() {
    std::cout << "Card Menu" << std::endl;
    std::cout << "Choose what you want to do:" << std::endl;
    std::cout << "1) Show all cards" << std::endl;
    std::cout << "2) Show all decks" << std::endl;
    std::cout << "3) Create new card" << std::endl;
    std::cout << "4) Create new deck" << std::endl;
    std::cout << "5) exit" << std::endl;
}

void cardMenu() {
    system("clear");
    printMenuCardInformation();
    int users_input;
    while (true) {
        if (!inputCorrectNumber(users_input, std::cin) || users_input < 1 || users_input > 5) {
            system("clear");
            printMenuCardInformation();
            std::cout << "Error: invalid input. Please, write correct number" << std::endl;
            continue;
        }
        system("clear");
        printMenuCardInformation();
        switch (users_input) {
            case 1: {
                All_cards cards_to_display;
                cards_to_display.displayCards();
                system("clear");
                printMenuCardInformation();
                break;
            }
            case 2: {
                break;
            }
            case 3: {
                All_cards cards_for_update;
                try {
                    cards_for_update.createNewCard();
                    system("clear");
                    printMenuCardInformation();
                } catch (std::invalid_argument &e) {
                    system("clear");
                    printMenuCardInformation();
                    std::cout << "error. cannot create new card. " << e.what() << std::endl;
                }
                break;
            }
            case 4: {
                break;
            }
            case 5: {
                return;
            }
            default:
                std::cout << "invalid input.\n";
        }
    }
}


All_cards::All_cards() {
    std::ifstream file;
    file.open("src/cards/allCards");
    char *var = new char[sizeof(int)];
    int number_of_all_cards;
    file.read(var, sizeof(int));
    memcpy(&number_of_all_cards, var, sizeof(int));
    for (int i = 0; i < number_of_all_cards; ++i) {
        int type_of_card;
        file.read(var, sizeof(int));
        memcpy(&type_of_card, var, sizeof(int));
        switch (type_of_card) {
            case 0: {
                Combat_card new_card;
                new_card.readCard(file);
                cards.push_back(new_card.clone());
                break;
            }
            case 1: {
                Spell_card new_card;
                new_card.readCard(file);
                cards.push_back(new_card.clone());
                break;
            }
            case 2: {
                Hero_buff_card new_card;
                new_card.readCard(file);
                cards.push_back(new_card.clone());
                break;
            }
            default:
                throw "";
        }
    }
    delete[] var;
    file.close();
}

All_cards::~All_cards() {
    std::ofstream file;
    file.open("src/cards/allCards");
    char *var = new char[sizeof(int)];
    int size_of_cards = cards.size();
    memcpy(var, &size_of_cards, sizeof(int));
    file.write(var, sizeof(int));
    for (int i = 0; i < size_of_cards; ++i) {
        cards[i]->writeCard(file);
    }
    for (int i = 0; i < cards.size(); ++i) {
        delete cards[i];
    }
    delete[] var;
    file.close();
}

bool All_cards::createNewCard() {
    system("clear");
    std::cout << "Which type of card: 1) attacking; 2) defensive; 3)spell; 4) heal; 5) armor; 6) weapon" << std::endl;
    int type_of_card;
    if (!inputCorrectNumber(type_of_card, std::cin))
        return false;
    switch (type_of_card) {
        case 1: {
            Combat_card new_card;
            new_card.setTypeOfClass(Card::attacking);
            new_card.inputNewCard(std::cin, std::cout);
            cards.push_back(new_card.clone());
            break;
        }
        case 2: {
            Combat_card new_card;
            new_card.setTypeOfClass(Card::defensive);
            new_card.inputNewCard(std::cin, std::cout);
            cards.push_back(new_card.clone());
            break;
        }
        case 3: {
            Spell_card new_card;
            new_card.setTypeOfClass(Card::spell);
            new_card.inputNewCard(std::cin, std::cout);
            cards.push_back(new_card.clone());
            break;
        }
        case 4: {
            Spell_card new_card;
            new_card.setTypeOfClass(Card::healing);
            new_card.inputNewCard(std::cin, std::cout);
            cards.push_back(new_card.clone());
            break;
        }
        case 5: {
            Hero_buff_card new_card;
            new_card.setTypeOfClass(Card::armor);
            new_card.inputNewCard(std::cin, std::cout);
            cards.push_back(new_card.clone());
            break;
        }
        case 6: {
            Hero_buff_card new_card;
            new_card.setTypeOfClass(Card::weapon);
            new_card.inputNewCard(std::cin, std::cout);
            cards.push_back(new_card.clone());
            break;
        }
        default:
            return false;
    }
    return true;
}

void All_cards::displayCards() {
    system("clear");
    std::cout << "List of cards:" << std::endl;
    std::cout << "Name | type | mana |..." << std::endl;
    for (int i = 0; i < cards.size(); ++i) {
        std::cout << i + 1 << ") ";
        cards[i]->displayCard(std::cout);
    }
    std::cout << std::endl << "To exit, input any char" << std::endl;
    char c;
    std::cin >> c;
    return;
}

Card *All_cards::getCard(int number_of_card) {
    return cards[number_of_card];
}

const std::vector<CardDeck> &AllCardDecks::getAllCards() const {
    return allCards;
}

AllCardDecks::AllCardDecks() {
    CardDeck new_cardDeck;
    Combat_card combat1("Knight", 5, 5), combat2("Troop", 10, 2), combat3("King", 7, 7);
    combat1.setTypeOfClass(Card::attacking);
    combat2.setTypeOfClass(Card::attacking);
    combat3.setTypeOfClass(Card::attacking);
    Spell_card spell1("fireball", false, 5), spell2("heal", true, 4);
    spell1.setTypeOfClass(Card::spell);
    spell2.setTypeOfClass(Card::healing);
    Hero_buff_card hero1("axe", 5), hero2("armor", 3);
    hero1.setTypeOfClass(Card::weapon);
    hero2.setTypeOfClass(Card::armor);
    std::vector<Combat_card> combats;
    combats.push_back(combat1);
    combats.push_back(combat2);
    combats.push_back(combat3);
    combats.push_back(combat1);
    combats.push_back(combat2);
    combats.push_back(combat3);
    combats.push_back(combat1);
    combats.push_back(combat2);
    combats.push_back(combat3);
    combats.push_back(combat1);
    combats.push_back(combat2);
    combats.push_back(combat3);
    combats.push_back(combat1);
    combats.push_back(combat2);
    combats.push_back(combat3);
    new_cardDeck.setCombatCards(combats);
    std::vector<Spell_card> spells;
    spells.push_back(spell1);
    spells.push_back(spell2);
    spells.push_back(spell2);
    spells.push_back(spell2);
    spells.push_back(spell2);
    spells.push_back(spell2);
    spells.push_back(spell2);
    new_cardDeck.setSpellCards(spells);
    std::vector<Hero_buff_card> heroes;
    heroes.push_back(hero1);
    heroes.push_back(hero2);
    heroes.push_back(hero1);
    heroes.push_back(hero2);
    heroes.push_back(hero1);
    heroes.push_back(hero2);
    heroes.push_back(hero1);
    heroes.push_back(hero2);
    new_cardDeck.setHeroCards(heroes);
    allCards.push_back(new_cardDeck);
    std::vector<Card *> lol;
    lol.push_back(combat1.clone());
    lol.push_back(combat2.clone());
    lol.push_back(combat3.clone());
    lol.push_back(spell1.clone());
    lol.push_back(spell2.clone());
    lol.push_back(hero1.clone());
    lol.push_back(hero2.clone());
    std::ofstream file;
    file.open("src/cards/allCards");
    char *var = new char[sizeof(int)];
    int a = 7;
    memcpy(var, &a, sizeof(int));
    file.write(var, sizeof(int));
    for (int i = 0; i < lol.size(); ++i) {
        lol[i]->writeCard(file);
    }
    for (int i = 0; i < lol.size(); ++i) {
        delete lol[i];
    }
    delete[] var;
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
