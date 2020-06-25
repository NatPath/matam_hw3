#include "Character.h"

namespace mtm{
        Character::Character(mtm::Team team,mtm::units_t health, mtm::units_t ammo, mtm::units_t range,
        mtm::units_t power, mtm::units_t movement_speed, mtm::units_t reload_amount)   
        :team(team),health(health),ammo(ammo),range(range),power(power),
        movement_speed(movement_speed),reload_amount(reload_amount){}
        void Character::changeAmmo(int amount){
            ammo+=amount;
        }
        void Character::changeHealth(int amount){
            health+=amount;
        }

       

        void Character::checkMovementValid(const GridPoint& src_coordinates,const GridPoint& dst_coordinates){
            if(GridPoint::distance(src_coordinates,dst_coordinates) > movement_speed){
                throw Game::MoveTooFar();
            }  
            if(ammo<=0){
                throw Game::OutOfAmmo();
            }

        }
        void Character::checkAttackValid(const GridPoint& src_coordinates,const GridPoint& dst_coordinates){
            if(GridPoint::distance(src_coordinates,dst_coordinates)>range){
                throw Game::OutOfRange();
            }  
            if(ammo<=0){
                throw Game::OutOfAmmo();
            }
        }
        

        void Character::attackWrapper(Matrix<Character_ptr> &board,const GridPoint& src_coordinates,const GridPoint& dst_coordinates){
            checkAttackValid(src_coordinates,dst_coordinates);
            attack(board,src_coordinates,dst_coordinates);
            changeAmmo(-1);
        }

        mtm::Team Character::getTeam(){
            return team;
        }

        mtm::units_t Character::getMovementSpeed(){
            return movement_speed;
        }

        void Character::reload(){
            changeAmmo(reload_amount);
        }
        

}