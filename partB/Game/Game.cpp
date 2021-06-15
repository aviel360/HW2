#include "Game.h"
#include "../Exceptions.h" 
#include <typeinfo>
#include "../Medic/Medic.h"
#include "../Soldier/soldier.h"
#include "../Sniper/Sniper.h"



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
                !isPowerValid(power) || isTypeValid(type) || isTeamValid(team))
                        {
                            throw IllegalArgument();                
                        }
                     
    switch(type){
        case SOLDIER:
            std::shared_ptr<Character> new_charcter_ptr(new Soldier(team,health,ammo,range,power));
            return new_charcter_ptr;
        case MEDIC:
            std::shared_ptr<Character> new_charcter_ptr(new Medic(team,health,ammo,range,power));
            return new_charcter_ptr;
        case SNIPER:
            std::shared_ptr<Character> new_charcter_ptr(new Sniper(team,health,ammo,range,power));
            return new_charcter_ptr;
    }
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

    std::shared_ptr<Character> new_charcter_ptr = this->board[src_coordinates.row][src_coordinates.col];
    this->board[dst_coordinates.row][dst_coordinates.col] = new_charcter_ptr;
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
    std::shared_ptr<Character> new_charcter_ptr = this->board[coordinates.row][coordinates.col];
    new_charcter_ptr->reload();
}

bool Game::isOver(Team* winningTeam=NULL) const 
{
    int powerlifters_counter=0,crossfitters_counter=0;
    for (std::vector<std::shared_ptr<Character>> col : this->board){
        for (std::shared_ptr<Character> character_ptr : col ){
            if (character_ptr != nullptr){
                if ((*character_ptr).getTeam() == POWERLIFTERS){
                    powerlifters_counter++;
                }
                else {
                    crossfitters_counter++;
                }

            }
        }

    }
    if (crossfitters_counter == 0 && powerlifters_counter == 0){
        return false;
    }
    if (crossfitters_counter == 0){
        if (winningTeam !=nullptr){
            *winningTeam = POWERLIFTERS;
        }
        return true;
    }
    if (powerlifters_counter == 0){
        if (winningTeam !=nullptr){
            *winningTeam = CROSSFITTERS;
        }
        return true;
    }
    return false;
}



                