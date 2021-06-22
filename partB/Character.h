#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <vector>
#include <memory>
#include "Auxiliaries.h"
#include "Exceptions.h"

namespace mtm{

    class Character;

    typedef std::vector<std::vector<std::shared_ptr<Character>>> Board;
    class Character {
        
        virtual std::shared_ptr<Character> cloneAux() const = 0;
        protected:
        Team team;
        units_t health;
        units_t ammo;
        units_t range; 
        units_t power;

        public: 
        /**
         * @brief Construct a new Character object, due to the class being abstract this is only used when creating a 
         *        known type character(Medic/Sniper/Soldier). 
         * 
         * @param team 
         * @param health 
         * @param ammo 
         * @param range 
         * @param power 
         */
        Character(Team team, int health, int ammo, int range, int power);
        Character(const Character& character) = default;
        Character& operator=(const Character&) = default;
        virtual ~Character() = default;
        /**
         * @brief moves the character from the first point to the second each character has maximum movement range,
         *        detailed in their respective .h.
         * @param board - the game board 
         * @param src - the current place of the character
         * @param dst - the destination for the character
         */
        virtual void move(Board& board, const GridPoint& src, const GridPoint& dst) = 0;
        /**
         * @brief make the character attack, each character has different attack pattern detailed in their respective .h. 
         * 
        * @param board - the game board 
         * @param src - the current place of the character
         * @param dst - the destination for the attack
         */
        virtual void attack(Board& board, const GridPoint& src, const GridPoint& dst) = 0;
        /**
         * @brief - make the character reload
         * 
         */
        virtual void reload() = 0;
        /**
         * @brief Get the Symbol object
         * 
         * @return char represents the type and team 
         */
        virtual char getSymbol() = 0;
        /**
         * @brief a "virtual copy constructor" for copying the character deatils to a new character
         * 
         * @return std::shared_ptr<Character> 
         */
        std::shared_ptr<Character> clone() const;
        /**
         * @brief Get the Ammo object
         * 
         * @return units_t 
         */
        units_t getAmmo();
        /**
         * @brief Get the Range object
         * 
         * @return units_t 
         */
        units_t getRange();
        /**
         * @brief Get the Health object
         * 
         * @return units_t 
         */
        units_t getHealth();
        /**
         * @brief Get the Power object
         * 
         * @return units_t 
         */
        units_t getPower();
        /**
         * @brief Get the Team object
         * 
         * @return units_t 
         */
        units_t getTeam();
        /**
         * @brief lower the health of the character by this number
         * 
         * @param damage 
         */
        void decreaseHealth(units_t damage);
        /**
         * @brief increase the health of the character by this number
         * 
         * @param heal 
         */
        void increaseHealth(units_t heal);
    };

   
}

#endif