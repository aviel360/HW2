#include "Sniper.h"
#include <iostream>

Character* Sniper::clone() const {
    return new Sniper(*this); 
}