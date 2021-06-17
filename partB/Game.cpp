#include "Game.h"
#include "Exceptions.h" 
#include <iostream>
#include <assert.h>
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

   /* //copy constructor
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
        if (this == &other) {
		return *this;
	}
        Game game = new Game(other);
        return game;
    }*/

    /*std::ostream& operator<<(std::ostream& os, const Game& game)
    {
        int row = game.board_size[0], col = game.board_size[1];
        std::vector<std::vector<char>> printed_board =  std::vector<std::vector<char>>(row, std::vector<char>(col, ' '));

        const char* begin= &printed_board[0][0];
        const char* end= &(printed_board[row][col])+1;

        for (int row =0; row < game.board_size[0]; row++ ){
            for (int col =0; col < game.board_size[1]; col++ ){
                std::shared_ptr<Character> current_character = game.board[row][col];
                if (current_character == nullptr){
                    printed_board[row][col] = ' ';
                    continue;
                }
                printed_board[row][col] = current_character->getSymbol(); 
            }
        }
        return printGameBoard(std::cout,begin,end,col);
    }*/
    std::ostream& operator<<(std::ostream& os, const Game& game){
        int row = game.board_size[0], col = game.board_size[1];
        std::string delimiter = std::string(2 * col + 1, '*');
        char temp = ' ';
        os << delimiter << std::endl;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                std::shared_ptr<Character> character = game.board[i][j];
                if(character != nullptr){
                    temp = character->getSymbol();
                }
                os << "|" << temp;
                temp = ' ';
            }
            os << "|" << std::endl;
        }
        os << delimiter;
        return os;
    }

    void Game::addCharacter(const GridPoint& coordinates, std::shared_ptr<Character> character)
    {
        if (!isCellInBoard(coordinates, this->board_size)){
            throw IllegalCell();
        }
        if (isCellOccupied(coordinates,this->board)){
            throw CellOccupied();
        }
        this->board[coordinates.row][coordinates.col] = character;
    }

    std::shared_ptr<Character> Game::makeCharacter(CharacterType type, Team team,
                    units_t health, units_t ammo , units_t range, units_t power)
    {
        if (!isHealthValid(health) || !isAmmoValid(ammo) || !isRangeValid(range) ||
                    !isPowerValid(power) || !isTypeValid(type) || !isTeamValid(team)){
            throw IllegalArgument();                
        }
                        
        switch(type){
            case SOLDIER:{
                std::shared_ptr<Character> new_charcter_ptr(new Soldier(team,health,ammo,range,power));
                return new_charcter_ptr;
            }
            case MEDIC:{
                std::shared_ptr<Character> new_charcter_ptr(new Medic(team,health,ammo,range,power));
                return new_charcter_ptr;
            }
            case SNIPER:{
                std::shared_ptr<Character> new_charcter_ptr(new Sniper(team,health,ammo,range,power));
                return new_charcter_ptr;
            }
        }
        return nullptr;
    }
    

    void Game::move(const GridPoint & src_coordinates, const GridPoint & dst_coordinates)
    {
        if (!isCellInBoard(src_coordinates, this->board_size) ||!isCellInBoard(dst_coordinates, this->board_size)){
            throw IllegalCell();
        }
        if (!isCellOccupied(src_coordinates, this->board)){
            throw CellEmpty();
        }
        if(isCellOccupied(dst_coordinates,this->board)){
            throw CellOccupied();
        }
        board[src_coordinates.row][src_coordinates.col]->move(board, src_coordinates, dst_coordinates);
        
    }

    void Game::attack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates)
    {
        if (!isCellInBoard(src_coordinates, this->board_size) ||!isCellInBoard(dst_coordinates, this->board_size)){
            throw IllegalCell();
        }
        if (!isCellOccupied(src_coordinates,board)){
            throw CellEmpty();
        }
        board[src_coordinates.row][src_coordinates.col]->attack(board,src_coordinates, dst_coordinates);
    }

    void Game::reload(const GridPoint & coordinates)
    {
        if (!isCellInBoard(coordinates, this->board_size)){
            throw IllegalCell();
        }
        if (!isCellOccupied(coordinates,this->board)){
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
  
   bool Game::isInRange(int to_check, int max){
        return (to_check >= 0 && to_check <= max);
    }

    bool Game::isCellInBoard(const GridPoint& coordinates, int board_size[]){
        return (isInRange(coordinates.row, board_size[0]) && isInRange(coordinates.col,board_size[1]));

    }
 
    bool Game::isCellOccupied(const GridPoint& coordinates, Board board){
        return  (board[coordinates.row][coordinates.col] != nullptr);
    }

    bool Game::isTypeValid(CharacterType type){
        return (type == SOLDIER || type == SNIPER || type == MEDIC);
    }

    bool Game::isTeamValid(Team team){
        return (team == CROSSFITTERS || team == POWERLIFTERS);
    }

    bool Game::isHealthValid(units_t health){
        return (health > 0 );
    }

    bool Game::isAmmoValid(units_t ammo){
        return (ammo >= 0) ;
    }

    bool Game::isRangeValid(units_t range){
        return (range > 0) ;
    }

    bool Game::isPowerValid(units_t power){
        return (power >= 0) ;
    }



                
}
//construcor