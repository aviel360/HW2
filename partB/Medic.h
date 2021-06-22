#ifndef MEDIC_H
#define MEDIC_H
#include "Character.h"

namespace mtm{
    class Medic : public Character {
        /**
         * @brief a "virtual copy constructor" for copying the character deatils to a new character
         * 
         * @return std::shared_ptr<Character> 
         */
        virtual std::shared_ptr<Character> cloneAux() const override;
        static const int MAX_MOVEMENT = 5;
        static const int AMMO = 5;
        
    public:
        /**
         * @brief Construct a new Medic object
         * 
         * @param team 
         * @param health 
         * @param ammo 
         * @param range 
         * @param power 
         */
        Medic(Team team, units_t health, units_t ammo, units_t range, units_t power);
        /**
         * @brief Copy constructor
         * 
         */
        Medic(const Medic&) = default;
        /**
         * @brief assignment operator
         * 
         * @param medic 
         * @return Medic& 
         */
        Medic& operator=(const Medic& medic) = default;
        /**
         * @brief Destroy the Medic object
         * 
         */
        ~Medic() = default;
        /**
         * @brief moves the character from the first point to the second, max movement range for Medic is 5 squares.
         * @param board - the game board 
         * @param src - the current place of the character
         * @param dst - the destination for the character
         */
        void move(Board& board, const GridPoint& src, const GridPoint& dst) override;
        /**
         * @brief make the character attack or heal, healing allies doesn't require ammo,
         *        if the dst target is an enemy the medic attacks it. 
         *        The damage/heal equals the character's power.
         * 
        * @param board - the game board 
         * @param src - the current place of the character
         * @param dst - the destination for the attack
         */
        void attack(Board& board, const GridPoint& src, const GridPoint & dst) override;
        /**
         * @brief - make the character reload 5 ammo.
         * 
         */
        void reload() override;
         /**
         * @brief Get the Symbol object
         * 
         * @return char represents the type and team 
         */
        virtual char getSymbol() override ;
    };
}

#endif