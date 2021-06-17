#include "Soldier.h"
#include <memory>

namespace mtm{
    Soldier::Soldier(Team team, units_t health, units_t ammo, units_t range, units_t power) : 
                Character(team, health, ammo, range, power) {}

    void Soldier::move(Board& board, const GridPoint& src, const GridPoint& dst){
        if(dst.distance(src, dst) > MAX_MOVEMENT){
            throw MoveTooFar();
        }
        board[dst.row][dst.col] = board[src.row][src.col];
        board[src.row][src.col] = nullptr;
    }
    
    void Soldier::attack(Board& board, const GridPoint& src, const GridPoint & dst){
        if(src.distance(src, dst) > range){
            throw OutOfRange();
        }
        if(ammo == 0){
            throw OutOfAmmo();
        }
        if(src.col != dst.col && src.row != dst.row){
            throw IllegalTarget();
        }
        if(board[dst.row][dst.col] != nullptr && board[dst.row][dst.col]->getTeam() != team ){
            board[dst.row][dst.col]->decreaseHealth(power);
        }
        ammo--;
        aoeAttack(board, dst);
    }

    void Soldier::reload(){
        ammo += AMMO;
    }

    char Soldier::getSymbol() {
        if (this->team == POWERLIFTERS){
            return 'S';
        }
        return 's';
    }

    void Soldier::aoeAttack(Board& board, const GridPoint& dst){
        GridPoint head(dst.row - HEAD, dst.col - HEAD);
        for(int i = 0; i < MAX_ATTACK_RANGE; i++){
            for(int j = 0; j < MAX_ATTACK_RANGE; j++){
                GridPoint current(head.row + i, head.col + j);
                if(dst.distance(dst, current) > HEAD || i == dst.row + HEAD && j == dst.col + HEAD){
                    continue;
                }
                if(board[current.row][current.col] != nullptr && board[current.row][current.col]->getTeam() != team ){
                    board[current.row][current.col]->decreaseHealth(AOE_DAMAGE);
                    if(board[current.row][current.col]->getHealth() <= 0){
                        board[current.row][current.col] = nullptr;
                    }
                }
            }
        }
    }
    std::shared_ptr<Character> Soldier::cloneAux() const {
        return std::shared_ptr<Soldier>(new Soldier(*this));
    } 
}