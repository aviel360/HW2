#ifndef SNIPER_H
#define SNIPER_H
#include "Character.h"

namespace mtm{
    class Sniper : public Character {
        virtual std::shared_ptr<Character> cloneAux() const override;
        int headshot;
        static const int MAX_MOVEMENT = 4;
        static const int AMMO = 2;
        
    public:
        Sniper(Team team, units_t health, units_t ammo, units_t range, units_t power);
        Sniper(const Sniper&) = default;
        Sniper& operator=(const Sniper& Sniper) = default;
        ~Sniper() = default;
        void move(Board board, const GridPoint& src, const GridPoint& dst) override;
        void attack(Board board, const GridPoint& src, const GridPoint & dst) override;
        void reload() override;
        void aoeAttack(Board board, const GridPoint & dst);
    };
}

#endif