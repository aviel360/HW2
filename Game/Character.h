#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include "Auxiliaries.h"
#include "Exceptions.h"

namespace mtm{
    class Character {
        protected:
        Team team;
        int health;
        int ammo;
        int range; 
        int power;

        public: 
        virtual ~Character();
        virtual bool move(const int distance);
        virtual void attack(Board board, const GridPoint & dst_coordinates);
        virtual void reload();
        virtual Character* clone() const = 0;
    };
}

#endif