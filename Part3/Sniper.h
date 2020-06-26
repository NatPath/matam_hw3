#ifndef _SNIPER_H_
#define _SNIPER_H_

#include "Character.h"
namespace mtm{

    class Sniper: public Character{
        int combo_counter;
        public:
        Sniper(mtm::Team team,mtm::units_t health, mtm::units_t ammo, mtm::units_t range, mtm::units_t power);
        Character* clone() const override;
        void attack(Matrix<Character_ptr> &board,const GridPoint& src_coordinates, const GridPoint& dst_coordinates) override;
        void checkAttackValid(const GridPoint& src_coordinates,const GridPoint& dst_coordinates) override;
        const char getSymbol() override;





    };




}
#endif