#include "Game.h"
#include "../Exceptions.h" 

using namespace mtm;


//construcor
Game::Game(int height, int width) 
{
    if (height <= 0 || width <=0){
        throw IllegalArgument();
    }
    board = std::vector<std::vector<std::shared_ptr<Character>>>
                    (height, std::vector<std::shared_ptr<Character>>(width, nullptr));
}

//copy constructor
Game::Game(const Game& other)
{
//clone
}

//operator =
Game& Game::operator=(const Game& other)
{
//clone
}

void Game::addCharacter(const GridPoint& coordinates, std::shared_ptr<Character> character)
{
    if (!isTheCellInTheBoard(coordinates)){
        throw IllegalCell();
    }
    if (isTheCellOccupied(coordinates)){
        throw CellOccupied();
    }
    this->board[coordinates.row][coordinates.col] = character;
}

std::shared_ptr<Character> Game::makeCharacter(CharacterType type, Team team,
                units_t health, units_t ammo , units_t range, units_t power)
{
    if (!isHealthValid(health) || !isAmmoValid(ammo) || !isRangeValid(range) ||
                            !isPowerValid(power) || isTypeValid(type) || isTeamValid(team)){
                throw IllegalArgument();                
    }

    Character new_charcter(type, team,health,ammo,range,power); 
    return new_charcter;
}

void Game::move(const GridPoint & src_coordinates, const GridPoint & dst_coordinates)
{
     if (!isTheCellInTheBoard(src_coordinates) ||!isTheCellInTheBoard(dst_coordinates)){
        throw IllegalCell();
    }
    if (!isTheCellOccupied(src_coordinates)){
        throw CellEmpty();
    }
    if(!isValidCharcterMovement(src_coordinates, dst_coordinates)){
        throw MoveTooFar();
    }
    if(isTheCellOccupied(src_coordinates)){
        throw CellOccupied();
    }

    Character character = this->board[src_coordinates.row][src_coordinates.col];
    this->board[dst_coordinates.row][dst_coordinates.col] = character;
    this->board[src_coordinates.row][src_coordinates.col] = nullptr;
}

void Game::attack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates)
{
    if (!isTheCellInTheBoard(src_coordinates) ||!isTheCellInTheBoard(dst_coordinates)){
        throw IllegalCell();
    }
    if (!isTheCellOccupied(src_coordinates)){
        throw CellEmpty();
    }
    if(!isAttackInRange(src_coordinates,dst_coordinates)){
        throw OutOfRange();
    }
    if(!issStillEnoughAmmo(src_coordinates,dst_coordinates)){
        throw OutOfAmmo();
    } 
    if(!isCharacterAttackValid(src_coordinates,dst_coordinates)){
        throw IllegalTarget();
    }

    attackNow(this->board,src_coordinates,dst_coordinates);
    clearCasualties(this->board);
}

void Game::reload(const GridPoint & coordinates)
{
    if (!isTheCellInTheBoard(coordinates)){
        throw IllegalCell();
    }
    if (!isTheCellOccupied(coordinates)){
        throw CellEmpty();
    }
    Character character = this->board[coordinates.row][coordinates.col];
    character.reload();
}



                