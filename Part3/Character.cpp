#include "Character.h"
namespace mtm{
        Character::Character(mtm::Team team,mtm::units_t health, mtm::units_t ammo, mtm::units_t range, mtm::units_t power)   
         :team(team),health(health),ammo(ammo),range(range),power(power),movement_speed(0),reload_amount(0){}
        void Character::addAmmo(){
            ammo+=reload_amount;
        }
        void Character::changeHealth(int amount){
            health+=amount;
        }
        
        mtm::Team Character::getTeam(){
            return team;
        }
        

}