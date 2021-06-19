#include "Medic.h"
#include "Character.h"
#include <memory>
#include <iostream>



namespace mtm{
std::shared_ptr<Character> shared_nullptr(nullptr);

    Medic::Medic(Team team, units_t health, units_t ammo, units_t range, units_t power) : 
                Character(team, health, ammo, range, power) {}

    void Medic::move(Board& board, const GridPoint& src, const GridPoint& dst){
        if(dst.distance(src, dst) > MAX_MOVEMENT){
            throw MoveTooFar();
        }
        board[dst.row][dst.col] = board[src.row][src.col];
        board[src.row][src.col] = nullptr;
    }
    
    void Medic::attack(Board& board, const GridPoint& src, const GridPoint & dst){
        
        if(src.distance(src, dst) > range){
            throw OutOfRange();
        }
        if(ammo == 0){
            throw OutOfAmmo();
        }
        if(board[dst.row][ dst.col] == nullptr || board[dst.row][ dst.col] == board[src.row][ src.col]){
            throw IllegalTarget();
        }
        if(board[dst.row][dst.col]->getTeam() != team ){
            ammo--;
            board[dst.row][dst.col]->decreaseHealth(power);
        }
        if(board[dst.row][ dst.col]->getTeam() == team ){
            board[dst.row][ dst.col]->increaseHealth(power);
        }
    }

    void Medic::reload(){
        ammo += AMMO;
    }

    char Medic::getSymbol() {
        if (this->team == POWERLIFTERS){
            return 'M';
        }
        return 'm';
    }
    std::shared_ptr<Character> Medic::cloneAux() const {
        return std::shared_ptr<Medic>(new Medic(*this));
    }

}