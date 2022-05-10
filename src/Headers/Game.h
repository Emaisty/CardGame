#ifndef CARDGAME_GAME_H
#define CARDGAME_GAME_H

#include "Player.h"
#include <filesystem>
#include <fstream>
#include <cstring>

class Game {
public:
    //run the game
    void run();

    //if player human
    bool humanRound(Player &player, Player &opponent);

    //if player is computer
    bool computerRound(Player &player, Player &opponent);

    void checkingPassword(Player &player);

    //display game
    void printInformation(Player &player, Player &opponent);

    void printPlayerHandInformation(Player &player);

    void printPlayerInformation(Player &player);

    void playCardFromHand(Player &player, Player &opponent, long unsigned int number_of_card);

    static void playCardFromField(Player &player, Player &opponent, long unsigned int who_attack, int target);

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
