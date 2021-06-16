#ifndef MEDIC_H
#define MEDIC_H
#include "Character.h"

namespace mtm{
    class Medic : Character {
    public:
        Character* clone();
        Medic(Team team, units_t health, units_t ammo, units_t range, units_t power);
    };
}

#endif