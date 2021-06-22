#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <memory>
#include "Auxiliaries.h"
#include "Exceptions.h"
#include "Character.h"

#define DIMENSIONS 2

namespace mtm{
    class Game {
        int board_size[DIMENSIONS];
        Board board;

        /**
         * @brief return if this coordinates is in the board
         * 
         * @param coordinates 
         * @return true - if this coordinates is in the board
         * @return false - if this coordinates is out of the board
         */
        bool isCellInBoard(const GridPoint& coordinates);
        /**
         * @brief 
         * 
         * @param coordinates -  the cell in question 
         * @param board - the game board 
         * @return true - if there is a character in this cell 
         * @return false - if this cell empty
         */
        static bool isCellOccupied(const GridPoint& coordinates, Board board);
        /**
         * @brief - returns if this type is valid
         * 
         * @param type 
         * @return true 
         * @return false 
         */
        static bool isTypeValid(CharacterType type);
        /**
         * @brief return if this team is valid
         * 
         * @param team 
         * @return true 
         * @return false 
         */
        static bool isTeamValid(Team team);
        /**
         * @brief return if health is valid
         * 
         * @param health 
         * @return true 
         * @return false 
         */
        static bool isHealthValid(units_t health);
        /**
         * @brief 
         * 
         * @param ammo 
         * @return true 
         * @return false 
         */
        static bool isAmmoValid(units_t ammo);
        /**
         * @brief 
         * 
         * @param range 
         * @return true 
         * @return false 
         */
        static bool isRangeValid(units_t range);
        /**
         * @brief 
         * 
         * @param power 
         * @return true 
         * @return false 
         */
        static bool isPowerValid(units_t power);
        /**
         * @brief return if to_check is in the character range
         * 
         * @param to_check 
         * @param max 
         * @return true 
         * @return false 
         */
        static bool isInRange(int to_check, int max);

        public:
        /**
         * @brief Construct a new Game object
         * 
         * @param height 
         * @param width 
         */
        Game(int height, int width);
        /**
         * @brief Destroy the Game object
         * 
         */
        ~Game();
        /**
         * @brief copy constructor
         * 
         * @param other 
         */
        Game(const Game& other);
        /**
         * @brief assignment operator
         * 
         * @param other 
         * @return Game& 
         */
        Game& operator=(const Game& other);
        /**
         * @brief add a new character to the game 
         * 
         * @param coordinates - the coordinates for the character
         * @param character - the new character
         */
        void addCharacter(const GridPoint& coordinates, std::shared_ptr<Character> character);
        /**
         * @brief moves the character from the first point to the second 
         * 
         * @param src_coordinates  - the current place of the character
         * @param dst_coordinates - the destination for the character
         */
        virtual void move(const GridPoint& src_coordinates, const GridPoint& dst_coordinates);
        /**
         * @brief - make the character attack 
         * 
         * @param src_coordinates - the current place of the character
         * @param dst_coordinates - the destination for the attack
         */
        void attack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates);
        /**
         * @brief - make the character reload
         * 
         * @param coordinates - the coordinates of the character
         */
        void reload(const GridPoint & coordinates);
        /**
         * @brief - building a new character 
         * 
         * @param type 
         * @param team 
         * @param health 
         * @param ammo 
         * @param range 
         * @param power 
         * @return std::shared_ptr<Character> 
         */
        static std::shared_ptr<Character> makeCharacter(CharacterType type, Team team,
                    units_t health, units_t ammo, units_t range, units_t power);
        
        /**
         * @brief return if one of the teams has one 
         * 
         * @param winningTeam 
         * @return true - if all the character from the board belongs to a single team 
         * @return false - if there is characters from both teams 
         */
        bool isOver(Team* winningTeam=NULL) const;

        friend std::ostream& operator<<(std::ostream& os, const Game& game);      
    };
}
#endif