#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "Auxiliaries.h";

namespace mtm{

    class Character{
        mtm::units_t health;
        mtm::units_t ammo;

        protected:
        const mtm::units_t movement_speed; // find a better way to handle inheritance of "static" variables
        const mtm::units_t reload_amount;
        mtm::units_t range;
        mtm::units_t power;
        mtm::Team team;

        public:
        Character(mtm::Team team,mtm::units_t health, mtm::units_t ammo, mtm::units_t range, mtm::units_t power);
        virtual Character* clone() const = 0;
        virtual void addAmmo();
        virtual void changeHealth(int amount);
        virtual void attack(Character& target) = 0;
        mtm::Team getTeam();
        





    };




}
#endif