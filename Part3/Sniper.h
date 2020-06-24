#ifndef _SNIPER_H_
#define _SNIPER_H_

#include "Character.h"
namespace mtm{

    class Sniper: public Character{
        int combo_counter;
        public:
        Sniper(mtm::Team team,mtm::units_t health, mtm::units_t ammo, mtm::units_t range, mtm::units_t power);
        Character* clone() const override;
        void attack(Matrix<Character_ptr> &board, GridPoint& src_coordinates, GridPoint& dst_coordinates) override;





    };




}
#endif