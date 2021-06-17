#include "Character.h"

namespace mtm{
    Character::Character(Team team, units_t health, units_t ammo, units_t range, units_t power) : 
            team(team), health(health), ammo(ammo), range(range), power(power) {}
    units_t Character::getAmmo(){
        return ammo;
    }
    units_t Character::getRange(){
        return range;
    }
    units_t Character::getHealth(){
        return health;
    }
    units_t Character::getPower(){
        return power;
    }
    units_t Character::getTeam(){
        return team;
    }
    std::shared_ptr<Character> Character::clone() const{
        return cloneAux();
    }

}