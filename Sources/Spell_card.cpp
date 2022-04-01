#include "Spell_card.h"

Spell_card::Spell_card(const std::string &name, bool target, int value) : Card(name), target(target), value(value) {}
