#include <iostream>

class Card {
public:
    Card(const std::string &name);

protected:
    enum class_of_card {
        defensive, attacking, healing, spell, weapon, armor
    };

    std::string name;
};
