#include "Sniper.h"
#include <memory>

namespace mtm{
    Sniper::Sniper(Team team, units_t health, units_t ammo, units_t range, units_t power) : 
                Character(team, health, ammo, range, power), headshot(1) {}

    void Sniper::move(Board& board, const GridPoint& src, const GridPoint& dst){
        if(dst.distance(src, dst) > MAX_MOVEMENT){
            throw MoveTooFar();
        }
        if(board[dst.row][dst.col] != nullptr){
            throw CellOccupied();
        }
        board[dst.row][dst.col] = board[src.row][ src.col];
        board[src.row][src.col] = nullptr;
    }
    
    void Sniper::attack(Board& board, const GridPoint& src, const GridPoint & dst){
        if(src.distance(src, dst) > range || src.distance(src, dst) < ceil(static_cast<double>(range) / 2)){
            throw OutOfRange();
        }
        if(ammo == 0){
            throw OutOfAmmo();
        }
        if(board[dst.row][dst.col] == nullptr || board[dst.row][dst.col]->getTeam() == team){
            throw IllegalTarget();
        }
        units_t temp = power;
        if(headshot % 3 == 0){
            power = power * 2;
        }
        board[dst.row][dst.col]->decreaseHealth(power);
        headshot++;
        ammo--;
        power = temp;
    }

    void Sniper::reload(){
        ammo += AMMO;
    }

    char Sniper::getSymbol() {
        if (this->team == POWERLIFTERS){
            return 'N';
        }
        return 'n';
    }
    std::shared_ptr<Character> Sniper::cloneAux() const {
        return std::shared_ptr<Sniper>(new Sniper(*this));
    } 
}