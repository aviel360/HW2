#ifndef SOLDIER_H
#define SOLDIER_H
#include "Character.h"

namespace mtm{
    class Soldier : public Character {
    
    public:
        bool move(const int distance) override;
        void attack(Board board, const GridPoint & dst) override;
        void reload() override;
        int* enemyInAoe(const GridPoint & dst);
        static const int MAX_RANGE = 5;
    };
}

#endif