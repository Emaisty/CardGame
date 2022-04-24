#ifndef CARDGAME_GAME_H
#define CARDGAME_GAME_H

#include "Player.h"


class Game {
public:
    Game(Player player1, Player player2);

    void run();

    void round(Player &player, Player &opponent);

    void checkingPassword(Player &player);

    void printInformation(Player &player, Player &opponent);

    void printPlayerHandInformation(Player &player);

    void printPlayerInformation(Player &player);

    bool playCardFromHand(Player &player, Player &opponent);

    static bool playCardFromField(Player &player, Player &opponent);

    const Player &getPlayer1() const;

    const Player &getPlayer2() const;

protected:
    Player player1, player2;
    int which_turn = 1;
};

#endif //CARDGAME_GAME_H
