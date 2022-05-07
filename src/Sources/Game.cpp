#include "Game.h"

bool input_number(int &number) {
    std::string user_input;
    std::cin >> user_input;
    try {
        number = stoi(user_input);
    } catch (const std::invalid_argument &) { return false; } catch (const std::out_of_range &) { return false; }
    return true;
}


Game::Game() {}

bool Game::humanRound(Player &player, Player &opponent) {
    if (!opponent.isComputer()) checkingPassword(player);
    printInformation(player, opponent);
    std::string input;
    std::cin >> input;
    while (input != "end") {
        if (input == "attack") {
            try {
                playCardFromField(player, opponent);
                printInformation(player, opponent);
            } catch (std::invalid_argument &e) {
                printInformation(player, opponent);
                std::cout << "error: " << e.what() << ". Please input again" << std::endl;
            }
        } else if (input == "hand") {
            try {
                playCardFromHand(player, opponent);
                printInformation(player, opponent);
            } catch (std::invalid_argument &e) {
                printInformation(player, opponent);
                std::cout << "error: " << e.what() << ". Please input again" << std::endl;
            }
        } else if (input == "save") {
            saveTheGame();
            return false;
        } else {
            printInformation(player, opponent);
            std::cout << "Error: unknown command" << std::endl;
        }
        std::cin >> input;
    }
    system("clear");
    return true;
}

bool Game::computerRound(Player &player, Player &opponent) {
    return true;
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
              << player.getWeapon() << "| Mana: " << player.getMana() << std::endl;
    std::cout << "========\n";
    for (int i = 0; i < player.getPlayerFiled().size(); ++i) {
        std::cout << i + 1 << ") " << player.getPlayerFiled()[i].getName() << " ("
                  << player.getPlayerFiled()[i].getValue() << ") ("
                  << player.getPlayerFiled()[i].getHp() << ")";
        if (player.getPlayerFiled()[i].getTypeOfClass() == Card::defensive)
            std::cout << "   SHIELDED";
        std::cout << "\n";
    }
    std::cout << "========\n";
}

void Game::printPlayerHandInformation(Player &player) {
    std::cout << "Cards :";
    for (int i = 0; i < player.getPlayerCards().size(); ++i) {
        std::cout << " (" << i + 1 << ") " << player.getPlayerCards()[i]->getName();
    }
}

void Game::playCardFromHand(Player &player, Player &opponent) {
    int size_of_cards = player.getPlayerCards().size();
    int number_of_card = -1;

    if (!input_number(number_of_card))
        throw std::invalid_argument("invalid input of card");
    number_of_card--;
    if (number_of_card < 0 || number_of_card >= size_of_cards)
        throw std::invalid_argument("index out of range");
    if (player.getMana() < player.getPlayerCards()[number_of_card]->getMana())
        throw std::invalid_argument("not enough mana");
    //if card is playable
    if (player.getPlayerCards()[number_of_card]->getTypeOfClass() ==
        Card::attacking || player.getPlayerCards()[number_of_card]->getTypeOfClass() == Card::defensive) {
        player.decreaseMana(player.getPlayerCards()[number_of_card]->getMana());
        player.fromHandToField(number_of_card);
        return;
    }
    //if card is spell
    //in the reason, what spell casting on opponent, realization of spell card is hear
    //if it is healing
    if (player.getPlayerCards()[number_of_card]->getTypeOfClass() == Card::healing) {
        Spell_card *spell = dynamic_cast<Spell_card *>(player.getPlayerCards()[number_of_card]);
        if (spell->isTarget()) {
            std::cout << "Choose target: ";
            int target = -1;
            if (!input_number(target)) throw std::invalid_argument("invalid input of target");
            target--;
            if (target < 0 || target >= player.getPlayerFiled().size())
                throw std::invalid_argument("target index out of range");
            player.healOnUnit(target, spell->getValue());
        } else {
            for (int i = 0; i < player.getPlayerFiled().size(); ++i) {
                player.healOnUnit(i, spell->getValue());
            }
        }
        player.decreaseMana(player.getPlayerCards()[number_of_card]->getMana());
        player.useSpellCard(number_of_card);
        return;
    }
    //if it is a spell
    if (player.getPlayerCards()[number_of_card]->getTypeOfClass() == Card::spell) {
        Spell_card *spell = dynamic_cast<Spell_card *>(player.getPlayerCards()[number_of_card]);
        if (spell->isTarget()) {
            std::cout << "Choose target: ";
            int target = -1;
            if (!input_number(target) || target == -1) throw std::invalid_argument("invalid input of target");
            target--;
            if (target < 0 || target >= opponent.getPlayerFiled().size())
                throw std::invalid_argument("target index out of range");
            opponent.damageOnUnit(target, spell->getValue());
        } else {
            for (int i = 0; i < opponent.getPlayerFiled().size(); ++i) {
                opponent.damageOnUnit(i, spell->getValue());
            }
        }
        player.decreaseMana(player.getPlayerCards()[number_of_card]->getMana());
        player.useSpellCard(number_of_card);
        return;
    }
    //if card is buff for hero
    if (player.getPlayerCards()[number_of_card]->getTypeOfClass() ==
        Card::armor || player.getPlayerCards()[number_of_card]->getTypeOfClass() == Card::weapon) {
        player.decreaseMana(player.getPlayerCards()[number_of_card]->getMana());
        player.useHeroCard(number_of_card);
        return;
    }
}

void Game::playCardFromField(Player &player, Player &opponent) {
    int who_attack = -1, target = -1;
    if (!input_number(who_attack)) throw std::invalid_argument("invalid input of your card");
    if (!input_number(target)) throw std::invalid_argument("invalid input of target");
    if (who_attack < 1 && who_attack >= player.getPlayerFiled().size())
        throw std::invalid_argument("out of range in yours card");
    if (target < 0 && target >= opponent.getPlayerFiled().size())
        throw std::invalid_argument("out of range in opponents card");
    who_attack--;
    target--;
    if (!player.getCanPlayCard()[who_attack]) {
        throw std::invalid_argument("cannot play with this card right now");
    }
    player.setCardNotPlayable(who_attack);
    if (target != -1) {
        opponent.getPlayerFiled()[target].getDamage(player.getPlayerFiled()[who_attack].getValue());
        player.getPlayerFiled()[who_attack].getDamage(opponent.getPlayerFiled()[target].getValue());
        if (opponent.getPlayerFiled()[target].getHp() <= 0)
            opponent.killUnit(target);
        if (player.getPlayerFiled()[who_attack].getHp() <= 0)
            player.killUnit(who_attack);

    } else {
        opponent.takeDamage(player.getPlayerFiled()[who_attack].getValue());
        player.getPlayerFiled()[who_attack].getDamage(opponent.getWeapon());
        if (player.getPlayerFiled()[who_attack].getHp() <= 0)
            player.killUnit(who_attack);
    }
}

const Player &Game::getPlayer1() const {
    return player1;
}

const Player &Game::getPlayer2() const {
    return player2;
}

void Game::saveTheGame() {
    std::cout << "Input the name of file: ";
    std::string name;
    std::cin >> name;
    for (const auto &entry: std::filesystem::directory_iterator("src/Games/")) {
        std::cout << entry.path() << std::endl;
        if (entry.path() == ("src/Games/" + name))
            throw "";
    }
    std::ofstream file;
    file.open("src/Games/" + name);
    char *mas = new char[sizeof(int)];
    memcpy(mas, &which_turn, sizeof(int));
    file.write(mas, sizeof(int));

    player1.savePlayer(file);
    player2.savePlayer(file);
    file.close();
}

void Game::loadTheGame() {
    std::cout << "Input the name of file: ";
    std::string name;
    std::cin >> name;
    for (const auto &entry: std::filesystem::directory_iterator("src/Games/"))
        if (entry.path() == ("src/Games/" + name)) {
            std::ifstream file;
            file.open("src/Games/" + name);
            char *mas = new char[sizeof(int)];
            int turn;
            file.read(mas, sizeof(int));
            memcpy(&turn, mas, sizeof(int));
            which_turn = turn;
            player1.loadPlayer(file);
            player2.loadPlayer(file);
            file.close();
            run();
            return;
        }
    throw "";
}

void Game::run() {
    while (player1.ifPlayerAlive() && player2.ifPlayerAlive()) {
        if (which_turn == 1) {
            if (!player1.isComputer())
                if (!humanRound(player1, player2)) return;
                else computerRound(player1, player2);
            which_turn = 2;
            player1.prepareForRound();
        } else {
            if (!player2.isComputer())
                if (!humanRound(player2, player1)) return;
                else computerRound(player2, player1);
            which_turn = 1;
            player2.prepareForRound();
        }
    }
}

void Game::setPlayer1(const Player &player1) {
    Game::player1 = player1;
}

void Game::setPlayer2(const Player &player2) {
    Game::player2 = player2;
}
