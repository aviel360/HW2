#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <vector>
#include <memory>
#include "Auxiliaries.h"
#include "Exceptions.h"

namespace mtm{
    class Character{
        virtual std::shared_ptr<Character> cloneAux() const = 0;

        protected:
        Team team;
        units_t health;
        units_t ammo;
        units_t range; 
        units_t power;

        public:
        typedef std::vector<std::vector<std::shared_ptr<Character>>> Board;
        Character(Team team, int health, int ammo, int range, int power);
        Character(const Character& character) = default;
        Character& operator=(const Character&) = default;
        virtual ~Character() = default;
        virtual void move(Board board, const GridPoint& src, const GridPoint& dst) = 0;
        virtual void attack(Board board, const GridPoint& src, const GridPoint& dst) = 0;
        virtual void reload() = 0;
        virtual char getSymbol() = 0;
        std::shared_ptr<Character> clone() const;
        units_t getAmmo();
        units_t getRange();
        units_t getHealth();
        units_t getPower();
        units_t getTeam();
        units_t setAmmo();
        units_t setRange();
        units_t setHealth();
        units_t setPower();
        units_t setTeam();
    };
}

#endif
