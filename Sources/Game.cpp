#include "Game.h"

bool input_number(int &number) {
    std::string user_input;
    std::cin >> user_input;
    try {
        number = stoi(user_input);
    } catch (const std::invalid_argument &) { return false; } catch (const std::out_of_range &) { return false; }
    return true;
}


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
    checkingPassword(player);
    printInformation(player, opponent);
    std::string input;
    std::cin >> input;
    while (input != "end") {
        if (input == "attack") {
            if (!playCardFromField(player, opponent)) {
                printInformation(player, opponent);
                std::cout << "Cannot play with that card or attack this target" << std::endl;
            }
        } else if (input == "hand") {
            if (!playCardFromHand(player, opponent)) {
                printInformation(player, opponent);
                std::cout << "Cannot play with that card or cast spell on this target" << std::endl;
            }
        } else {
            printInformation(player, opponent);
            std::cout << "Error: unknown command" << std::endl;
        }
        printInformation(player, opponent);
        std::cin >> input;
    }
    system("clear");
}


void Game::checkingPassword(Player &player) {
    std::string password;
    std::cout << "Enter password: ";
    std::cin >> password;
    while (!player.checkPassword(password)) {
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
        std::cout << i + 1 << ") " << card.getName() << " (" << card.getAttack() << ") (" << card.getHp() << ")\n";
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

bool Game::playCardFromHand(Player &player, Player &opponent) {
    int size_of_cards = player.getPlayerCombatCards().size() + player.getPlayerSpellCards().size() +
                        player.getPlayerHeroesCards().size();
    int number_of_card = -1;

    if (!input_number(number_of_card))
        return false;
    number_of_card--;
    if (number_of_card > size_of_cards)
        return false;

    if (number_of_card < player.getPlayerCombatCards().size()) {
        player.fromHandtoField(number_of_card);
        return true;
    }
    number_of_card -= player.getPlayerCombatCards().size();
    if (number_of_card < player.getPlayerSpellCards().size()) {
        Spell_card casted_card = player.getPlayerSpellCards()[number_of_card];
        if (casted_card.getTypeOfClass() == Card::spell) {
            if (casted_card.isTarget()) {
                //TODO in normal way
                int a = -1;
                if (!input_number(a)) return false;
                a--;
                if (a < 0 || a >= opponent.getPlayerFiled().size())
                    return false;
                opponent.damageOnUnit(a, casted_card.getValue());
            } else {
                for (int i = 0; i < opponent.getPlayerFiled().size(); ++i) {
                    opponent.damageOnUnit(i, casted_card.getValue());
                    if (opponent.getPlayerFiled()[i].getHp() <= 0) {
                        opponent.killUnit(i);
                        --i;
                    }
                }
                opponent.takeDamage(casted_card.getValue());
            }
            player.useSpellCard(number_of_card);
        } else {
            if (casted_card.isTarget()) {
                int a = -1;
                if (!input_number(a)) return false;
                a--;
                if (a < 0 || a >= opponent.getPlayerFiled().size())
                    return false;
                player.healOnUnit(a, casted_card.getValue());
            } else {
                for (int i = 0; i < player.getPlayerFiled().size(); ++i) {
                    player.healOnUnit(i, casted_card.getValue());
                }
            }
            player.useSpellCard(number_of_card);
        }
        return true;
    }
    number_of_card -= player.getPlayerSpellCards().size();
    player.useHeroCard(number_of_card);
    return true;
}

bool Game::playCardFromField(Player &player, Player &opponent) {
    int who_attack = -1, target = -1;
    if (!input_number(who_attack)) return false;
    if (!input_number(target)) return false;
    if (who_attack < 1 && who_attack >= player.getPlayerFiled().size()) return false;
    if (target < 0 && target >= opponent.getPlayerFiled().size()) return false;
    who_attack--;
    target--;
    int damage = player.getPlayerFiled()[who_attack].getAttack();
    if (target == -1) {
        opponent.takeDamage(damage);
        player.getPlayerFiled()[who_attack].getDamage(opponent.getWeapon());
        if (player.getPlayerFiled()[who_attack].getHp() < 1)
            player.killUnit(who_attack);
    } else {
        opponent.getPlayerFiled()[target].getDamage(damage);
        player.getPlayerFiled()[who_attack].getDamage(opponent.getPlayerFiled()[target].getAttack());
        if (opponent.getPlayerFiled()[target].getHp() < 1)
            opponent.killUnit(target);
        if (player.getPlayerFiled()[who_attack].getHp() < 1)
            player.killUnit(who_attack);
    }
    return true;
}

const Player &Game::getPlayer1() const {
    return player1;
}

const Player &Game::getPlayer2() const {
    return player2;
}
