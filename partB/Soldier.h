#ifndef SOLDIER_H
#define SOLDIER_H
#include "Character.h"
#include <cmath>

namespace mtm{
    class Soldier : public Character {
        virtual std::shared_ptr<Character> cloneAux() const override;
        const int HEAD = ceil(static_cast<double>(range) /3 );
        const int MAX_ATTACK_RANGE = HEAD*2 + 1;
        const int AOE_DAMAGE = ceil(static_cast<double>(power) / 2);
        static const int MAX_MOVEMENT = 3;
        static const int AMMO = 3;
        
    public:
        Soldier(Team team, units_t health, units_t ammo, units_t range, units_t power);
        Soldier(const Soldier&) = default;
        Soldier& operator=(const Soldier& soldier) = default;
        ~Soldier() = default;
        virtual void move(Board& board, const GridPoint& src, const GridPoint& dst) override;
        virtual void attack(Board& board, const GridPoint& src, const GridPoint & dst) override;
        virtual void reload() override;
        virtual char getSymbol() override ;
        /**
         * @brief make the soldier attack the rest of the characters in his attack range
         * 
         * @param board - the game board
         * @param dst - coordinates to attack
         */
        void aoeAttack(Board& board, const GridPoint & dst);
    };
}

#endif