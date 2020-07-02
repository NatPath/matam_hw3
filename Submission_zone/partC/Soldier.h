#ifndef _SOLDIER_H_
#define _SOLDIER_H_

#include "Character.h"

namespace mtm{

    class Soldier: public Character{
    
        public:
        Soldier(mtm::Team team,mtm::units_t health, mtm::units_t ammo, mtm::units_t range, mtm::units_t power);
        Character* clone() const override;
        void attack(Matrix<Character_ptr> &board, const GridPoint& src_coordinates,const GridPoint& dst_coordinates) override;
        // check if target is in range and the soldier has enough ammo
        void checkAttackValid(const GridPoint& src_coordinates,const GridPoint& dst_coordinates) override;
        const char getSymbol() override;





    };




}
#endif