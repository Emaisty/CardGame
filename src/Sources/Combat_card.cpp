#include "Combat_card.h"

Combat_card::Combat_card(const std::string &name, int hp, int attack, int mana) {
    this->name = name;
    this->hp = hp;
    this->attack = attack;
    this->mana = mana;
}

int Combat_card::getHp() const {
    return hp;
}

void Combat_card::getDamage(int damage) {
    hp -= damage;
}

void Combat_card::getHeal(int heal) {
    hp += heal;
}

int Combat_card::getValue() const {
    return attack;
}

void Combat_card::setHp(int hp) {
    Combat_card::hp = hp;
}

void Combat_card::setValue(int attack) {
    Combat_card::attack = attack;
}

Combat_card *Combat_card::clone() const {
    return new Combat_card(*this);
}

void Combat_card::writeCard(std::ostream &file) const {
    writeCardIntoFile(file);
    char *var = new char[sizeof(int)];
    //write hp of card
    memcpy(var, &hp, sizeof(int));
    file.write(var, sizeof(int));
    //write attack of card
    memcpy(var, &attack, sizeof(int));
    file.write(var, sizeof(int));
    delete[] var;
}

Combat_card *Combat_card::inputNewCard(std::istream &iss, std::ostream &oss) {
    this->name = inputNameOfCard(iss, oss);
    this->mana = inputManaOfCard(iss, oss);
    oss << std::endl << "Type hp of card: ";
    int hp;
    if (!inputCorrectNumber(hp, iss))
        throw std::invalid_argument("invalid hp input");
    oss << std::endl << "Type attack of card: ";
    int attack;
    if (!inputCorrectNumber(attack, iss))
        throw std::invalid_argument("invalid attack input");
    this->hp = hp;
    this->attack = attack;
    return this;
}

Combat_card *Combat_card::readCard(std::ifstream &file) {
    this->name = readNameOfCard(file);
    this->mana = readManaOfCard(file);
    this->type_of_class = readType_of_classOfCard(file);
    char *var = new char[sizeof(int)];
    //read hp of card
    int hp;
    file.read(var, sizeof(int));
    memcpy(&hp, var, sizeof(int));
    //read attack of card
    int attack;
    file.read(var, sizeof(int));
    memcpy(&attack, var, sizeof(int));
    this->hp = hp;
    this->attack = attack;
    delete[] var;
    return this;
}

void Combat_card::displayCard(std::ostream &oss) const {
    this->displayMainCard(oss);
    oss << "hp: " << hp << " | attack: " << attack << std::endl;
}