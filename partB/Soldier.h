#ifndef SOLDIER_H
#define SOLDIER_H
#include "Character.h"
#include <cmath>

namespace mtm{
    class Soldier : public Character {
        /**
         * @brief a "virtual copy constructor" for copying the character deatils to a new character
         * 
         * @return std::shared_ptr<Character> 
         */
        virtual std::shared_ptr<Character> cloneAux() const override;
        const int HEAD = ceil(static_cast<double>(range) /3 );
        const int MAX_ATTACK_RANGE = HEAD*2 + 1;
        const int AOE_DAMAGE = ceil(static_cast<double>(power) / 2);
        static const int MAX_MOVEMENT = 3;
        static const int AMMO = 3;
        
    public:
        /**
         * @brief Construct a new Soldier object
         * 
         * @param team 
         * @param health 
         * @param ammo 
         * @param range 
         * @param power 
         */
        Soldier(Team team, units_t health, units_t ammo, units_t range, units_t power);
        /**
         * @brief Copy constructor
         * 
         */
        Soldier(const Soldier&) = default;
        /**
         * @brief assignment operator
         * 
         * @param soldier 
         * @return Soldier& 
         */
        Soldier& operator=(const Soldier& soldier) = default;
        /**
         * @brief Destroy the Soldier object
         * 
         */
        ~Soldier() = default;
        /**
         * @brief moves the character from the first point to the second 
         * @param board - the game board 
         * @param src - the current place of the character
         * @param dst - the destination for the character
         */
        virtual void move(Board& board, const GridPoint& src, const GridPoint& dst) override;
        /**
         * @brief make the character attack 
         * 
        * @param board - the game board 
         * @param src - the current place of the character
         * @param dst - the destination for the attack
         */
        virtual void attack(Board& board, const GridPoint& src, const GridPoint & dst) override;
        /**
         * @brief - make the character reload
         * 
         */
        virtual void reload() override;
        /**
         * @brief Get the Symbol object
         * 
         * @return char represents the type and team 
         */
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