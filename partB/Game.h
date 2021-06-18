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

        bool isCellInBoard(const GridPoint& coordinates);
        static bool isCellOccupied(const GridPoint& coordinates, Board board);
        static bool isTypeValid(CharacterType type);
        static bool isTeamValid(Team team);
        static bool isHealthValid(units_t health);
        static bool isAmmoValid(units_t ammo);
        static bool isRangeValid(units_t range);
        static bool isPowerValid(units_t power);
        static bool isInRange(int to_check, int max);

        public:
        Game(int height, int width);
        ~Game();
        Game(const Game& other);
        Game& operator=(const Game& other);
        void addCharacter(const GridPoint& coordinates, std::shared_ptr<Character> character);
        virtual void move(const GridPoint& src_coordinates, const GridPoint& dst_coordinates);
        void attack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates);
        void reload(const GridPoint & coordinates);
        static std::shared_ptr<Character> makeCharacter(CharacterType type, Team team,
                    units_t health, units_t ammo, units_t range, units_t power);
        
        bool isOver(Team* winningTeam=NULL) const;

        friend std::ostream& operator<<(std::ostream& os, const Game& game);      
    };
}
#endif