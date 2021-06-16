#include "Soldier.h"
#include <iostream>

Character* Soldier::clone() const {
    return new Soldier(*this); 
}