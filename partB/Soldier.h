#include "Auxiliaries.h"
#include "Character.h"

class Soldier : public Character{

    public:
    Soldier (Team team,
                units_t health, units_t ammo , units_t range, units_t power);


    virtual Character* clone() const override;

         
};