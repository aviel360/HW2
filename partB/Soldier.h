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
         * @brief moves the character from the first point to the second, max movement range for Soldier is 3 squares.
         * @param board - the game board 
         * @param src - the current place of the character
         * @param dst - the destination for the character
         * @exception MoveTooFar if it isnt a valid move
         */
        virtual void move(Board& board, const GridPoint& src, const GridPoint& dst) override;
        /**
         * @brief make the character attack anything in the same row or colum of the Soldier within its range
         *        whether its an ally or a foe or en empty square, although only enemies will suffer damage.
         *        This character's attack expand to enemies within its AOE, more details in aoeAttack function.
         * 
        * @param board - the game board 
         * @param src - the current place of the character
         * @param dst - the destination for the attack
         * @exception MoveTooFar if isnt a valid move
         * @exception CellOccupied if dst cell is occupied
         */
        virtual void attack(Board& board, const GridPoint& src, const GridPoint & dst) override;
        /**
         * @brief - make the character reload 3 ammo.
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
         * @brief the Soldier's AOE is any enemies within distance of range / 3 of its initial attack location.
         *        each enemy will lose damage equals to the Soldier's power / 2.
         * 
         * @param board - the game board
         * @param dst - coordinates to attack
         */
        void aoeAttack(Board& board, const GridPoint & dst);
    };
}

#endif