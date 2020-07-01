#ifndef _SNIPER_H_
#define _SNIPER_H_

#include "Character.h"
namespace mtm{

    class Sniper: public Character{
        int combo_counter;
        public:
        Sniper(mtm::Team team,mtm::units_t health, mtm::units_t ammo, mtm::units_t range, mtm::units_t power);
        Character* clone() const override;
        /**
         * attack:
         * Executes sniper attack, checks if the target is legal and if so change the game state according to the rules
         * (Will throw an exception if The attack target in dst_coordinates is illegal)
         * */
        void attack(Matrix<Character_ptr> &board,const GridPoint& src_coordinates, const GridPoint& dst_coordinates) override;

        /**
         * checkAttackValid:
         * Checks if the attack is in Sniper range , will throw an exception(OutOfRange) if not so
         * Checks if has enough ammo for the attack, will throw an exception(OutofAmmo) if not so
         * Note:
         * Sniper range is different from other characters range, that is why it overrides the parent function
         * */
        void checkAttackValid(const GridPoint& src_coordinates,const GridPoint& dst_coordinates) override;

        //returns 'N' for CPP sniper and 'n' for python sniper
        const char getSymbol() override;





    };




}
#endif