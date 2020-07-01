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
        const mtm::units_t movement_speed; 
        const mtm::units_t reload_amount;
         

        public:
        Character() = default;
        Character(mtm::Team team,mtm::units_t health, mtm::units_t ammo, mtm::units_t range, mtm::units_t power,
        mtm::units_t movement_speed, mtm::units_t reload_ammount);
        Character(const Character& other) = default;
        /**
         * clone:
         * A method for returning a pointer to an identical but new character to the one the method is called upon
         * */
        virtual Character* clone() const = 0;
        //change ammo of character by amout (can be negative or positive)
        void changeAmmo(int amount);
        //will change ammo by reload amout
        void reload();
        //change heath by amount (can be negative or positive)
        void changeHealth(int amount);
        //will throw an Exception if src_coordinates and dst_coordinates are too far apart for movement
        void checkMovementValid(const GridPoint& src_coordinates,const GridPoint& dst_coordinates);
        //will throw an Exception if Attack is not in range or doesn't have enough ammo for the attack
        virtual void checkAttackValid(const GridPoint& src_coordinates,const GridPoint& dst_coordinates);
        //checks for attack validity and executes the attack(calls attack function)
        //will change ammo and game state according to the character and rules
        void attackWrapper(Matrix<Character_ptr> &board,const GridPoint& src_coordinates,const GridPoint& dst_coordinates);
        //returns movement_speed field of character
        mtm::units_t getMovementSpeed();

        //attacks certain location on board, according to specifiec class rules. will throw Exceptions when it is fitting. 
        virtual void attack(Matrix<Character_ptr> &board,const GridPoint& src_coordinates,const GridPoint& dst_coordinates) = 0;
        //returns wether the health of the character is non-positive
        bool isDead();
        //returns the team of the character
        mtm::Team getTeam();

        //returns The Symbol representing the type and team of character
        virtual const char getSymbol() = 0;


    };




}
#endif