#ifndef SOLDIER_H
#define SOLDIER_H
#include "Character.h"
#include <cmath>

namespace mtm{
    class Soldier : public Character {

        const int HEAD = ceil(range / 3 );
        const int MAX_ATTACK_RANGE = HEAD*2 + 1;
        const int AOE_DAMAGE = power / 2;
        const int DAMAGE = ceil(power / 2);
        static const int MAX_MOVEMENT = 3;
        static const int AMMO = 3;
        
    public:

        void move(Board board, const GridPoint& src, const GridPoint& dst) override;
        void attack(Board board, const GridPoint & dst) override;
        void reload() override;
        void aoeAttack(Board board, const GridPoint & dst);
    };
}

#endif