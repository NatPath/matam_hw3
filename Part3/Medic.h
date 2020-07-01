#ifndef _MEDIC_H_
#define _MEDIC_H_

#include "Character.h"
namespace mtm{

    class Medic: public Character{

        public:
        Medic(mtm::Team team,mtm::units_t health, mtm::units_t ammo, mtm::units_t range, mtm::units_t power);
        Character* clone() const override;
        /**
         * attack:
         * Executes an attack by the medic, checks if it is abbiding the rules( if not throws a fitting exception):
         * 1) Has enough ammo for the attack (if medic attacks a teammate it does not need any)
         * 2) attack destination (dst_coordinate) is not empty
         * 
         * will change game state(which sent the board) according the the rules of the game(health of characters, etc..)
         * 
         * */
        void attack(Matrix<Character_ptr> &board, const GridPoint& src_coordinates, const GridPoint& dst_coordinates) override;
        /**
         * Will check if attack is in range, throw an exception if not so
         * Note:
         * Unlike regular character checkAttackValid, a medic can attack even if he doesn't have ammo,
         * That is, if he attacks a teammate inrange. Ammo check will be done inside the attack function.
         * This is why this function is overriding the parent one.
         * */
        void checkAttackValid(const GridPoint& src_coordinates,const GridPoint& dst_coordinates) override;

        //returns 'M' for CPP medic and 'm' for python medic
        const char getSymbol() override;
    };




}
#endif