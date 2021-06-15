#include "../Auxiliaries.h"
#include "../Character/Character.h"
class Medic: public Character {
    int something;

    public:
    Medic(Team team, units_t health, units_t ammo , units_t range, units_t power);

};