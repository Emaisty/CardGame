#ifndef CARDGAME_GAME_H
#define CARDGAME_GAME_H

#include "Player.h"
#include <filesystem>
#include <fstream>
#include <cstring>

class Game {
public:
    Game();

    void run();

    bool humanRound(Player &player, Player &opponent);

    bool computerRound(Player &player, Player &opponent);

    void checkingPassword(Player &player);

    void printInformation(Player &player, Player &opponent);

    void printPlayerHandInformation(Player &player);

    void printPlayerInformation(Player &player);

    void playCardFromHand(Player &player, Player &opponent);

    static void playCardFromField(Player &player, Player &opponent);

    void saveTheGame();

    void loadTheGame();

    const Player &getPlayer1() const;

    const Player &getPlayer2() const;

    void setPlayer1(const Player &player1);

    void setPlayer2(const Player &player2);

protected:
    Player player1, player2;
    int which_turn = 1;
};

#endif //CARDGAME_GAME_H
