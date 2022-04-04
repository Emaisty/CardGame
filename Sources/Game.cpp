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
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    printPlayerInformation(opponent);
    std::cout << "\n\n";
    std::cout << "==========================================================================================";
    std::cout << "\n\n";
    printPlayerInformation(player);
    printPlayerHandInformation(player);
    std::cout << "\n";
}

void Game::printPlayerInformation(Player &player) {
    std::cout << "Name: " << player.getName() << std::endl;
    std::cout << "Hp: " << player.getHp() << " | Armor: " << player.getArmor() << " | Weapon: "
              << player.getWeapon() << std::endl;
    std::cout << "========\n";
    for (int i = 0; i < player.getPlayerFiled().size(); ++i) {
        Combat_card card = player.getPlayerFiled()[i];
        std::cout << i << ") " << card.getName() << " (" << card.getAttack() << ") (" << card.getHp() << ")\n";
    }
    std::cout << "========\n";
}

void Game::printPlayerHandInformation(Player &player) {
    std::cout << "Cards :";
    int i, j, k;
    for (i = 0; i < player.getPlayerCombatCards().size(); ++i) {
        Card card = player.getPlayerCombatCards()[i];
        std::cout << " (" << i + j + k + 1 << ") " << card.getName();
    }
    for (j = 0; j < player.getPlayerSpellCards().size(); ++j) {
        Card card = player.getPlayerSpellCards()[j];
        std::cout << " (" << i + j + k + 1 << ") " << card.getName();
    }
    for (k = 0; k < player.getPlayerHeroesCards().size(); ++k) {
        Card card = player.getPlayerHeroesCards()[k];
        std::cout << " (" << i + j + k + 1 << ") " << card.getName();
    }
}

const Player &Game::getPlayer1() const {
    return player1;
}

const Player &Game::getPlayer2() const {
    return player2;
}
