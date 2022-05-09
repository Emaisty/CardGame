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
    All_decks all_decks;
    std::cout << "Choose your deck (list of decks can be seen in main menu): ";
    int user_choose_deck = -1;
    if (!inputCorrectNumber(user_choose_deck, std::cin) || user_choose_deck < 1 ||
        user_choose_deck > all_decks.getSize()) {
        throw user_choose_deck;
    }
    player.setPlayerStackCards(all_decks.getDeck(--user_choose_deck));
}

void setPassword(Player &player) {
    std::cout << "Please, set password: ";
    std::string user_input;
    std::cin >> user_input;
    player.setPassword(user_input);
}

void prepareForGameWithComputer() {
    system("clear");
    std::string Player1_name = inputName();
    Player player1(Player1_name, 30);
    try {
        chooseDeck(player1);
    } catch (int &e) {
        throw std::invalid_argument("Wrong number of deck" + std::to_string(e));
    }

    system("clear");

    All_decks all_decks;
    srand((unsigned int) time(NULL));
    int random_deck = rand() % all_decks.getSize();
    Player player2("Computer", 30);
    player2.setPlayerStackCards(all_decks.getDeck(random_deck));
    player2.setIsComputer(true);
    Game game;
    player1.initGame();
    player2.initGame();
    game.setPlayer1(player1);
    game.setPlayer2(player2);
    game.run();
}

void prepareForGame() {
    system("clear");
    std::string Player1_name = inputName();
    Player player1(Player1_name, 30);
    try {
        chooseDeck(player1);
    } catch (int &e) {
        throw std::invalid_argument("Wrong number of deck" + std::to_string(e));
    }
    setPassword(player1);

    system("clear");
    std::string Player2_name = inputName();
    Player player2(Player2_name, 30);
    try {
        chooseDeck(player2);
    } catch (int &e) {
        throw std::invalid_argument("Wrong number of deck" + std::to_string(e));
    }
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
                try {
                    prepareForGame();
                    system("clear");
                    printMenuInformation();
                } catch (std::invalid_argument &e) {
                    system("clear");
                    printMenuInformation();
                    std::cout << e.what() << std::endl;
                }
                break;
            case 2:
                try {
                    prepareForGameWithComputer();
                    system("clear");
                    printMenuInformation();
                } catch (std::invalid_argument &e) {
                    system("clear");
                    printMenuInformation();
                    std::cout << e.what() << std::endl;
                }
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