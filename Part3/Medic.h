#ifndef _MEDIC_H_
#define _MEDIC_H_

#include "Character.h"
namespace mtm{

    class Medic: public Character{

        public:
        Medic(mtm::Team team,mtm::units_t health, mtm::units_t ammo, mtm::units_t range, mtm::units_t power);
        Character* clone() const override;
        void attack(Matrix<Character_ptr> &board, GridPoint& src_coordinates, GridPoint& dst_coordinates) override;
    };




}
#endif