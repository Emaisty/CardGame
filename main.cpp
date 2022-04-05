#include <iostream>
#include "Game.h"

int main() {
    Game game(Player("BAZA1", 30), Player("BAZA2", 30));
    game.run();
    return 0;
}
