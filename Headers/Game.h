#ifndef CARDGAME_GAME_H
#define CARDGAME_GAME_H

#include "Player.h"

class Game {
public:
    Game(Player player1, Player player2);

    void round(Player &player, Player &opponent);

    void printInformation(Player &player, Player &opponent);

    void printPlayerHandInformation(Player &player);

    void printPlayerInformation(Player &player);

    const Player &getPlayer1() const;

    const Player &getPlayer2() const;

protected:
    Player player1, player2;
    int which_turn = 1;
};

#endif //CARDGAME_GAME_H
