#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "Auxiliaries.h"
#include "Matrix.h"
#include "Exceptions.h"
#include "math.h"
#include <memory>

namespace mtm{
    class Character;
    typedef std::shared_ptr<Character> Character_ptr;
    class Character{


        protected:
        mtm::Team team;
        mtm::units_t health;
        mtm::units_t ammo;
        mtm::units_t range;
        mtm::units_t power;
        const mtm::units_t movement_speed; // find a better way to handle inheritance of "static" variables
        const mtm::units_t reload_amount;
         

        public:
        Character() = default;
        Character(mtm::Team team,mtm::units_t health, mtm::units_t ammo, mtm::units_t range, mtm::units_t power,
        mtm::units_t movement_speed, mtm::units_t reload_ammount);
        Character(const Character& other) = default;
        virtual Character* clone() const = 0;
        void changeAmmo(int amount);
        void reload();
        void changeHealth(int amount);
        void checkMovementValid(const GridPoint& src_coordinates,const GridPoint& dst_coordinates);
        virtual void checkAttackValid(const GridPoint& src_coordinates,const GridPoint& dst_coordinates);
        void attackWrapper(Matrix<Character_ptr> &board,const GridPoint& src_coordinates,const GridPoint& dst_coordinates);
        mtm::units_t getMovementSpeed();

        //attacks certain location on board, according to specifiec class rules. Returns true iff attack succeeded.
        virtual void attack(Matrix<Character_ptr> &board,const GridPoint& src_coordinates,const GridPoint& dst_coordinates) = 0;
        mtm::Team getTeam();

        virtual const char getSymbol() = 0;


    };




}
#endif