#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "Auxiliaries.h";

namespace mtm{

    class Character{
        mtm::units_t health;
        mtm::units_t range;
        mtm::units_t power;
        mtm::units_t ammo;

        mtm::Team team;

        protected:
        const mtm::units_t movement_speed; // find a better way to handle inheritance of "static" variables
        const mtm::units_t reload_amount;


        public:
        Character(mtm::Team,mtm::units_t health, mtm::units_t range, mtm::units_t power, mtm::units_t ammo);
        virtual Character* clone() const = 0;
        





    };




}
#endif