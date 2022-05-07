# Card RPG

## Installation

```bash
cd CardGame
make
./CardGame
```

## Usage
### Menu:
1 - start of a game player vs player\
2 - start of a game player vs computer\
3 - see all deck, create own and create new cards\
4 - load game from file\
5 - exit game

### While a game

hand var_a - use var_a card from your hand. If it is attacking or defensive, it will move from your hand to the field. If it is spell or hero buff - it will auto uses

attack var_a var_b - a card from your hand, attack var_b card of opponent. If var_b = 0, card will attack hero.

save - save game to a file

end - end your turn.

## Description

