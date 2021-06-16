#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include "Auxiliaries.h"


class Character {

    protected:
    Team team;
    int health;
    int ammo;
    int  range; 
    int power;
    

    public: 
    virtual ~Character();
    virtual void attack();
    virtual void move(); 
    virtual void reload();
    virtual Character* clone() const = 0;
    int getHealth();
    int getTeam();


};

#endif