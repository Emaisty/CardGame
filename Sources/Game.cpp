#include "Game.h"


Game::Game(Player player1, Player player2) : player1(player1), player2(player2) {}

void Game::run() {
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
    checkingPassword();
    printInformation(player, opponent);
    std::string input;
    std::cin >> input;
    while (input != "end") {
        if (input == "attack") {

        } else if (input == "hand") {
            if (!playCardFromHand(player)) {

            }
        } else {

        }

        std::cin >> input;
    }
    system("clear");
}


void Game::checkingPassword() {
    std::string password;
    std::cout << "Enter password: ";
    std::cin >> password;
    while (this->password != password) {
        system("clear");
        std::cout << "Wrong password. Please, give correct one:";
        std::cin >> password;
    }
}

void Game::printInformation(Player &player, Player &opponent) {
    system("clear");
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
    int i = 0, j = 0, k = 0;
    for (; i < player.getPlayerCombatCards().size(); ++i) {
        Card card = player.getPlayerCombatCards()[i];
        std::cout << " (" << i + j + k + 1 << ") " << card.getName();
    }
    for (; j < player.getPlayerSpellCards().size(); ++j) {
        Card card = player.getPlayerSpellCards()[j];
        std::cout << " (" << i + j + k + 1 << ") " << card.getName();
    }
    for (; k < player.getPlayerHeroesCards().size(); ++k) {
        Card card = player.getPlayerHeroesCards()[k];
        std::cout << " (" << i + j + k + 1 << ") " << card.getName();
    }
}

bool Game::playCardFromHand(Player &player) {
    int size_of_cards = player.getPlayerCombatCards().size() + player.getPlayerSpellCards().size() +
                        player.getPlayerHeroesCards().size();
    int number_of_card = -1;

    std::cin >> number_of_card;
    if (number_of_card > size_of_cards) {
        return false;
    }
    if (number_of_card < player.getPlayerCombatCards().size())
        player.fromHandtoField(number_of_card + 1);
    //TODO if spell card or hero card
    return true;
}

const Player &Game::getPlayer1() const {
    return player1;
}

const Player &Game::getPlayer2() const {
    return player2;
}
