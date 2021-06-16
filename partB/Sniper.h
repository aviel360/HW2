#ifndef SNIPER_H
#define SNIPER_H
#include "Character.h"

namespace mtm{
    class Sniper : Character {
    public:
        Character* clone();
        Sniper(Team team, units_t health, units_t ammo, units_t range, units_t power);
    };
}

#endif