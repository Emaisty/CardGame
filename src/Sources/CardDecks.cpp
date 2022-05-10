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
    int check = system("clear");
    if (check == -1)
        return;
    printMenuCardInformation();
    int users_input;
    while (true) {
        if (!inputCorrectNumber(users_input, std::cin) || users_input < 1 || users_input > 5) {
            int check = system("clear");
    if (check == -1)
        return;
            printMenuCardInformation();
            std::cout << "Error: invalid input. Please, write correct number" << std::endl;
            continue;
        }
        int check = system("clear");
    if (check == -1)
        return;
        printMenuCardInformation();
        switch (users_input) {
            case 1: {
                All_cards cards_to_display;
                cards_to_display.displayCards();
                int check = system("clear");
    if (check == -1)
        return;
                printMenuCardInformation();
                break;
            }
            case 2: {
                All_decks deck_to_display;
                deck_to_display.displayDecks();
                int check = system("clear");
    if (check == -1)
        return;
                printMenuCardInformation();
                break;
            }
            case 3: {
                All_cards cards_for_update;
                try {
                    cards_for_update.createNewCard();
                    int check = system("clear");
    if (check == -1)
        return;
                    printMenuCardInformation();
                } catch (std::invalid_argument &e) {
                    int check = system("clear");
    if (check == -1)
        return;
                    printMenuCardInformation();
                    std::cout << "error. cannot create new card. " << e.what() << std::endl;
                }
                break;
            }
            case 4: {
                All_decks decks_for_update;
                try {
                    decks_for_update.createNewDeck();
                    int check = system("clear");
    if (check == -1)
        return;
                    printMenuCardInformation();
                } catch (int &e) {
                    int check = system("clear");
    if (check == -1)
        return;
                    printMenuCardInformation();
                    std::cout << "error. cannot create new deck. Wrong number at " << e << " card." << std::endl;
                }
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
    for (long unsigned int i = 0; i < size_of_cards; ++i) {
        cards[i]->writeCard(file);
    }
    for (auto &card: cards) {
        delete card;
    }
    delete[] var;
    file.close();
}

bool All_cards::createNewCard() {
    int check = system("clear");
    if (check == -1)
        return false;
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
    int check = system("clear");
    if (check == -1)
        return;
    std::cout << "List of cards:" << std::endl;
    std::cout << "Name | type | mana |..." << std::endl;
    for (int i = 0; i < cards.size(); ++i) {
        std::cout << i + 1 << ") ";
        cards[i]->displayCard(std::cout);
    }
    std::cout << std::endl << "To exit, input any char" << std::endl;
    char c;
    std::cin >> c;
}

Card *All_cards::getCard(int number_of_card) {
    return cards[number_of_card];
}

long unsigned int All_cards::getSize() {
    return cards.size();
}

All_decks::All_decks() {
    std::ifstream file;
    file.open("src/cards/allDecks");
    char *var = new char[sizeof(int)];
    int number_of_all_decks;
    file.read(var, sizeof(int));
    memcpy(&number_of_all_decks, var, sizeof(int));
    for (int i = 0; i < number_of_all_decks; ++i) {
        std::vector<int> deck;
        for (int j = 0; j < 30; ++j) {
            int card;
            file.read(var, sizeof(int));
            memcpy(&card, var, sizeof(int));
            deck.push_back(card);
        }
        decks.push_back(deck);
    }
    delete[] var;
    file.close();
}

All_decks::~All_decks() {
    std::ofstream file;
    file.open("src/cards/allDecks");
    char *var = new char[sizeof(int)];
    int number_of_all_decks = decks.size();
    memcpy(var, &number_of_all_decks, sizeof(int));
    file.write(var, sizeof(int));
    for (int i = 0; i < number_of_all_decks; ++i) {
        for (int j = 0; j < 30; ++j) {
            memcpy(var, &decks[i][j], sizeof(int));
            file.write(var, sizeof(int));
        }
    }
    delete[] var;
    file.close();
}

void All_decks::createNewDeck() {
    int check = system("clear");
    if (check == -1)
        return;
    std::cout << "Input 30 number from 1 to " << cards.getSize() << ": " << std::endl;
    std::vector<int> new_deck;
    for (int i = 0; i < 30; ++i) {
        int new_card;
        if (!inputCorrectNumber(new_card, std::cin) || new_card < 1 || new_card > cards.getSize())
            throw i;
        new_deck.push_back(--new_card);
    }
    decks.push_back(new_deck);
}

void All_decks::displayDecks() {
    int check = system("clear");
    if (check == -1)
        return;
    std::cout << "List of decks:" << std::endl;
    for (long unsigned int i = 0; i < decks.size(); ++i) {
        std::cout << i + 1 << " deck)" << std::endl;
        for (int j = 0; j < 30; ++j) {
            std::cout << "      ";
            cards.getCard(decks[i][j])->displayCard(std::cout);
        }
    }
    std::cout << std::endl << "To exit, input any char" << std::endl;
    char c;
    std::cin >> c;
}

std::vector<Card *> All_decks::getDeck(int number_of_deck) {
    std::vector<Card *> result;
    for (int i = 0; i < 30; ++i) {
        result.push_back(cards.getCard(decks[number_of_deck][i]));
    }
    return result;
}

long unsigned int All_decks::getSize() {
    return decks.size();
}

