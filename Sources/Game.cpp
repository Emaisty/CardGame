#include "Game.h"


Game::Game(Player player1, Player player2) : player1(player1), player2(player2) {
    while (player1.ifPlayerAlive() && player2.ifPlayerAlive()) {
        if (which_turn == 1) {
            round(player1, player2);
            which_turn = 2;
        } else {
            round(player2, player1);
            which_turn = 1;
        }
    }

}

void Game::round(Player &player, Player &opponent) {
    printInformation(player, opponent);
    std::string input;
    std::cin >> input;
    while (input != "end") {

    }
}

void Game::printInformation(Player &player, Player &opponent) {
    std::cout << opponent.getName() << std::endl;
    std::cout << player.getName() << std::endl;
}

const Player &Game::getPlayer1() const {
    return player1;
}

const Player &Game::getPlayer2() const {
    return player2;
}
