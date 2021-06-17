#ifndef MEDIC_H
#define MEDIC_H
#include "Character.h"

namespace mtm{
    class Medic : public Character {
        virtual std::shared_ptr<Character> cloneAux() const override;
        static const int MAX_MOVEMENT = 5;
        static const int AMMO = 5;
        
    public:
        Medic(Team team, units_t health, units_t ammo, units_t range, units_t power);
        Medic(const Medic&) = default;
        Medic& operator=(const Medic& medic) = default;
        ~Medic() = default;
        void move(Board& board, const GridPoint& src, const GridPoint& dst) override;
        void attack(Board& board, const GridPoint& src, const GridPoint & dst) override;
        void reload() override;
        virtual char getSymbol() override ;
    };
}

#endif