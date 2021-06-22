#ifndef SNIPER_H
#define SNIPER_H
#include "Character.h"

namespace mtm{
    class Sniper : public Character {
        /**
         * @brief a "virtual copy constructor" for copying the character deatils to a new character
         * 
         * @return std::shared_ptr<Character> 
         */
        virtual std::shared_ptr<Character> cloneAux() const override;
        int headshot;
        static const int MAX_MOVEMENT = 4;
        static const int AMMO = 2;
        
    public:
        /**
         * @brief Construct a new Sniper object
         * 
         * @param team 
         * @param health 
         * @param ammo 
         * @param range 
         * @param power 
         */
        Sniper(Team team, units_t health, units_t ammo, units_t range, units_t power);
        /**
         * @brief Copy constructor
         * 
         */
        Sniper(const Sniper&) = default;
        /**
         * @brief assignment operator
         * 
         * @param Sniper 
         * @return Sniper& 
         */
        Sniper& operator=(const Sniper& Sniper) = default;
        /**
         * @brief Destroy the Sniper object
         * 
         */
        ~Sniper() = default;
        /**
         * @brief moves the character from the first point to the second, max movement range for Sniper is 4 squares.
         * @param board - the game board 
         * @param src - the current place of the character
         * @param dst - the destination for the character
         */
        void move(Board& board, const GridPoint& src, const GridPoint& dst) override;
        /**
         * @brief make the character attack, enemies which are within the character's range but not the ones 
         *        that are closer than the Sniper's range / 2. Every third attack the Sniper does double damage. 
         * 
         * @param board - the game board 
         * @param src - the current place of the character
         * @param dst - the destination for the attack
         * @exception MoveTooFar if isnt a valid move
         * @exception CellOccupied if dst cell is occupied
         */
        void attack(Board& board, const GridPoint& src, const GridPoint & dst) override;
        /**
         * @brief - make the character reload 2 ammo.
         * @exception OutOfRange if the destination is too far for this character
         * @exception OutOfAmmo if this characterw's ammo is zero
         * @exception IllegalTarget if the the terget is illegal
         */
        void reload() override;
        /**
         * @brief Get the Symbol object
         * 
         * @return char represents the type and team 
         */
        virtual char getSymbol() override ;
        /**
         * @brief Get the Team object
         * 
         * @return Team 
         */
        static Team getTeam();
        /**
         * @brief Get the Health object
         * 
         * @return units_t 
         */
        static units_t getHealth();
    };
}

#endif