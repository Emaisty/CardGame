#include "Menu.h"

void printMenuInformation() {
    std::cout << "Hello to game.\n";
    std::cout << "Choose what you want to do:" << std::endl;
    std::cout << "1) Start a game (Pl vs Pl)." << std::endl;
    std::cout << "2) Start a game (Pl vs Comp)." << std::endl;
    std::cout << "3) See all card decks" << std::endl;
    std::cout << "4) Load game from saves" << std::endl;
    std::cout << "5) exit the game" << std::endl;
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

void prepareForGameWithComputer() {
    std::string Player1_name = inputName();
    Player player1(Player1_name, 30);
    chooseDeck(player1);
    setPassword(player1);

    system("clear");
}

void prepareForGame() {
    std::string Player1_name = inputName();
    Player player1(Player1_name, 30);
    chooseDeck(player1);
    setPassword(player1);

    system("clear");
    std::string Player2_name = inputName();
    Player player2(Player2_name, 30);
    chooseDeck(player2);
    setPassword(player2);
    system("clear");
    Game game;
    player1.initGame();
    player2.initGame();
    game.setPlayer1(player1);
    game.setPlayer2(player2);
    game.run();
}

void loadGame() {
    Game game;
    game.loadTheGame();
}

void printCardDecks() {
    cardMenu();
};

void mainPage() {
    system("clear");
    printMenuInformation();
    int users_input;
    while (true) {
        if (!inputCorrectNumber(users_input, std::cin) || users_input < 1 || users_input > 5) {
            system("clear");
            printMenuInformation();
            std::cout << "Error: invalid input. Please, write correct number" << std::endl;
            continue;
        }
        system("clear");
        printMenuInformation();
        switch (users_input) {
            case 1:
                prepareForGame();
                system("clear");
                printMenuInformation();
                break;
            case 2:
                prepareForGameWithComputer();
                system("clear");
                printMenuInformation();
                break;
            case 3:
                printCardDecks();
                system("clear");
                printMenuInformation();
                break;
            case 4:
                try {
                    loadGame();
                    system("clear");
                    printMenuInformation();
                } catch (std::invalid_argument &e) {
                    system("clear");
                    printMenuInformation();
                    if (e.what() == "src/Games/") {
                        std::cout << "You havent saved any game before" << std::endl;
                    } else {
                        std::cout << "Cannot open " << e.what() << std::endl;
                    }
                }
                break;
            case 5:
                return;
            default:
                std::cout << "invalid input.\n";
        }
    }
}