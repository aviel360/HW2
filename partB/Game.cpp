#include "Game.h"
#include "Exceptions.h" 
#include <iostream>
#include <memory>
#include "Medic.h"
#include "Soldier.h"
#include "Sniper.h"



namespace mtm{
    Game::Game(int height, int width) 
    {
        if (height <= 0 || width <=0){
            throw IllegalArgument();
        }
        board_size[0]= height;
        board_size[1]= width;

        board = std::vector<std::vector<std::shared_ptr<Character>>>
                        (height, std::vector<std::shared_ptr<Character>>(width, nullptr));
    }

    //copy constructor
    Game::Game(const Game& other)
    {
        board_size[0]= other.board_size[0];
        board_size[1]= other.board_size[0];

        board = std::vector<std::vector<std::shared_ptr<Character>>>
                        (board_size[0], std::vector<std::shared_ptr<Character>>(board_size[1], nullptr));


        for (int row =0; row < board_size[0]; row++ ){
            for (int col =0; col < board_size[1]; col++ ){
                board[row][col] = other.board[row][col]->clone();
            }
        }   
    }

    //operator =
    Game& Game::operator=(const Game& other)
    {
        Game game(other);
        return game;
    }

    std::ostream& Game::operator<<(const Game& game)
    {
        int row = game.board_size[0], col = game.board_size[1];
        std::vector<std::vector<char>> printed_board =  std::vector<std::vector<char>>(row, std::vector<char>(col, ' '));

        const char* begin= &printed_board[0][0];
        const char* end= &(printed_board[row][col])+1;

        for (int row =0; row < board_size[0]; row++ ){
            for (int col =0; col < board_size[1]; col++ ){
                std::shared_ptr<Character> current_character = game.board[row][col];
                if (current_character == nullptr){
                    printed_board[row][col] = ' ';
                    continue;
                }
                printed_board[row][col] = current_character->getSymbul(); 
            }
        }
        return printGameBoard(std::cout,begin,end,col);
    }

    void Game::addCharacter(const GridPoint& coordinates, std::shared_ptr<Character> character)
    {
        if (!isTheCellInTheBoard(coordinates, this->board_size)){
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
            {
                std::shared_ptr<Character> new_charcter_ptr(new Soldier(team,health,ammo,range,power));
                return new_charcter_ptr;
            }
            case MEDIC:
            {
                std::shared_ptr<Character> new_charcter_ptr(new Medic(team,health,ammo,range,power));
                return new_charcter_ptr;
            }
            case SNIPER:
            {
                std::shared_ptr<Character> new_charcter_ptr(new Sniper(team,health,ammo,range,power));
                return new_charcter_ptr;
            }    
        }
    }

    void Game::move(const GridPoint & src_coordinates, const GridPoint & dst_coordinates)
    {
        if (!isTheCellInTheBoard(src_coordinates, this->board_size) ||!isTheCellInTheBoard(dst_coordinates, this->board_size)){
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
        if (!isTheCellInTheBoard(src_coordinates, this->board_size) ||!isTheCellInTheBoard(dst_coordinates, this->board_size)){
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

        Character& character = *(board[src_coordinates.row][src_coordinates.col]);
        Board board = this->board;

        character.attack(board,src_coordinates, dst_coordinates);
        clearCasualties(this->board);
    }

    void Game::reload(const GridPoint & coordinates)
    {
        if (!isTheCellInTheBoard(coordinates, this->board_size)){
            throw IllegalCell();
        }
        if (!isTheCellOccupied(coordinates)){
            throw CellEmpty();
        }
        std::shared_ptr<Character> new_charcter_ptr = this->board[coordinates.row][coordinates.col];
        new_charcter_ptr->reload();
    }

    bool Game::isOver(Team* winningTeam) const 
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
    /*
    void clearCasualties(Board board){
        for (std::vector<std::shared_ptr<Character>> col : board){
            for (std::shared_ptr<Character> character_ptr : col ){
                if (character_ptr->getHealth() <= 0){
                    character_ptr = nullptr;
                    }
                }
            }

        }
    */

   bool isInRange(int to_check, int max){
        return (to_check >= 0 && to_check <= max);
    }

    bool isTheCellInTheBoard(const GridPoint& coordinates, int board_size[]){
        return (isInRange(coordinates.row, board_size[0]) && isInRange(coordinates.col,board_size[1]));

    }
 
    static bool isTheCellOccupied(const GridPoint& coordinates, Board board){
        return  (board[coordinates.row][coordinates.col] != nullptr);
    }

    bool isTypeValid(CharacterType type){
        return (type == SOLDIER || type == SNIPER || type == MEDIC);
    }

    bool isTeamValid(Team team){
        return (team == CROSSFITTERS || team == POWERLIFTERS);
    }

    bool isHealthValid(units_t health){
        return (health > 0 );
    }

    bool isAmmoValid(units_t ammo){
        return (ammo >= 0) ;
    }

    bool isRangeValid(units_t range){
        return (range > 0) ;
    }

    bool isPowerValid(units_t power){
        return (power >= 0) ;
    }



                
}
//construcor