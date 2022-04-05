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

std::string input_name() {
    std::cout << "Input your name: ";
    std::string name;
    std::cin >> name;
    return name;
}

void Choose_deck(Player &player) {
    AllCardDecks allDecks;
    std::cout << "Choose your deck (list of decks can be seen in main menu): ";
    int user_input;
    std::cin >> user_input;
    while (user_input < 0 || user_input > allDecks.getAllCards().size()) {
        std::cout << "Invalid input. Please choose right deck: ";
        std::cin >> user_input;
    }
    player.setPlayerCombatCards(allDecks.getAllCards()[user_input].getCombatCards());
    player.setPlayerSpellCards(allDecks.getAllCards()[user_input].getSpellCards());
    player.setPlayerHeroesCards(allDecks.getAllCards()[user_input].getHeroCards());
}

void prepareForGame() {
    std::string Player1_name = input_name();
    Player player1(Player1_name, 30);
    Choose_deck(player1);

    std::string Player2_name = input_name();
    Player player2(Player2_name, 30);
    Choose_deck(player2);

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
                break;
            case 2:
                printCardDecks();
                break;
            case 3:
                return;
                break;
            default:
                std::cout << "invalid input.\n";
        }
    }
}