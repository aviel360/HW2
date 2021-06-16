#include "Sniper.h"

namespace mtm{
    Sniper::Sniper(Team team, units_t health, units_t ammo, units_t range, units_t power) : 
                Character(team, health, ammo, range, power) {}

    void Sniper::move(Board board, const GridPoint& src, const GridPoint& dst){
        if(dst.distance(src, dst) > MAX_MOVEMENT){
            throw MoveTooFar();
        }
        board[dst.row, dst.col] = board[src.row, src.col];
        board[src.row, src.col] = nullptr;
    }
    
    void Sniper::attack(Board board, const GridPoint & dst){
        if(ammo = 0){
            throw OutOfAmmo();
        }
        if(board[dst.row, dst.col] == nullptr || board[dst.row, dst.col] == this){
            throw IllegalTarget();
        }
        if(board[dst.row, dst.col]->team != team ){
            ammo--;
            board[dst.row, dst.col]->health -= power;
            if(board[dst.row, dst.col]->health <= 0){
                board[dst.row, dst.col] = nullptr;
            }
        }
        if(board[dst.row, dst.col]->team != team ){
            ammo--;
            board[dst.row, dst.col]->health += power;
        }
    }

    void Sniper::reload(){
        ammo += AMMO;
    }
    Character* Sniper::clone() const {
        return new Sniper(*this);
    } 
}