#include <iostream>
#include "Game.h"
#include "CardDecks.h"

void printMenuInformation() {
    std::cout << "Hello to game.\n";
    std::cout << "Choose what you want to do:\n";
    std::cout << "1) Start a game.\n";
    std::cout << "2) See all card decks\n";
    std::cout << "3) exit the game (if you want exit in middle of a game, type 'exit_force')\n";
    std::cout << "Input: ";
}

std::string inputName() {
    std::cout << "Input your name: ";
    std::string name;
    std::cin >> name;
    return name;
}

void chooseDeck(Player &player) {
    AllCardDecks allDecks;
    std::cout << "Choose your deck (list of decks can be seen in main menu): ";
    std::string user_input;
    int user_choose_deck = -1;
    std::cin >> user_input;
    try {
        user_choose_deck = stoi(user_input);
    } catch (const std::invalid_argument &) {} catch (const std::out_of_range &) {}
    while (user_choose_deck < 0 || user_choose_deck >= allDecks.getAllCards().size()) {
        system("clear");
        std::cout << "Invalid input. Please choose right deck: ";
        std::cin >> user_input;
        try {
            user_choose_deck = stoi(user_input);
        } catch (const std::invalid_argument &) {} catch (const std::out_of_range &) {}
    }
    player.setPlayerCombatCards(allDecks.getAllCards()[user_choose_deck].getCombatCards());
    player.setPlayerSpellCards(allDecks.getAllCards()[user_choose_deck].getSpellCards());
    player.setPlayerHeroesCards(allDecks.getAllCards()[user_choose_deck].getHeroCards());
}

void setPassword(Player &player) {
    std::cout << "Please, set password: ";
    std::string user_input;
    std::cin >> user_input;
    player.setPassword(user_input);
}

void prepareForGame() {
    std::string Player1_name = inputName();
    Player player1(Player1_name, 30);
    chooseDeck(player1);
    setPassword(player1);

    system("clear");
    printMenuInformation();
    std::string Player2_name = inputName();
    Player player2(Player2_name, 30);
    chooseDeck(player2);
    setPassword(player2);

    Game game(player1, player2);
    game.run();
}

void printCardDecks() {

};

void mainPage() {
    system("clear");
    printMenuInformation();
    int users_input;
    while (std::cin >> users_input) {
        system("clear");
        printMenuInformation();
        switch (users_input) {
            case 1:
                prepareForGame();
                system("clear");
                printMenuInformation();
                break;
            case 2:
                printCardDecks();
                system("clear");
                printMenuInformation();
                break;
            case 3:
                //TODO
                return;
            default:
                std::cout << "invalid input.\n";
        }
    }
}