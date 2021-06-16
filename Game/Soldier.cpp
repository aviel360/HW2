#include "Soldier.h"

namespace mtm{
    void Soldier::move(Board board, const GridPoint& src, const GridPoint& dst){
        if(dst.distance(src, dst) > MAX_MOVEMENT){
            throw MoveTooFar{};
        }
        // need to check if in the same row or col
        board[dst.row, dst.col] = board[src.row, src.col];
        board[src.row, src.col] = nullptr;
    }
    
    void Soldier::attack(Board board, const GridPoint & dst){
        if(ammo = 0){
            throw OutOfAmmo{};
        }
        if(board[dst.row, dst.col] != nullptr && board[dst.row, dst.col]->team != team ){
            board[dst.row, dst.col]->health -= DAMAGE;
        }
        aoeAttack(board, dst);
    }

    void Soldier::reload(){
        ammo += AMMO;
    }

    void Soldier::aoeAttack(Board board, const GridPoint& dst){
        GridPoint head(dst.row - HEAD, dst.col - HEAD);
        for(int i = 0; i < MAX_ATTACK_RANGE; i++){
            for(int j = 0; j < MAX_ATTACK_RANGE; j++){
                GridPoint current(head.row + i, head.col + j);
                if(dst.distance(dst, current) > HEAD){
                    continue;
                }
                if(board[current.row, current.col] != nullptr && board[current.row, current.col]->team != team ){
                    board[current.row, current.col]->health -= AOE_DAMAGE;
                    if(board[current.row, current.col]->health <= 0){
                        board[current.row, current.col] = nullptr;
                    }
                }
            }
        }
    }
}