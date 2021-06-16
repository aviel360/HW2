#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <vector>
#include <memory>
#include "Auxiliaries.h"
#include "Exceptions.h"

namespace mtm{
    typedef std::vector<std::vector<std::shared_ptr<Character>>> Board;

    class Character {
        protected:
        Team team;
        units_t health;
        units_t ammo;
        units_t range; 
        units_t power;

        public: 
        Character(Team team, int health, int ammo, int range, int power);
        Character(const Character& character) = default;
        Character& operator=(const Character&) = default;
        ~Character() = default;
        virtual void move(Board board, const GridPoint& src, const GridPoint& dst);
        virtual void attack(Board board, const GridPoint& src, const GridPoint& dst);
        virtual void reload();
        virtual Character* clone() const = 0;
    };
}

#endif