#include "Medic.h"
#include <iostream>

Character* Medic::clone() const {
    return new Medic(*this); 
}