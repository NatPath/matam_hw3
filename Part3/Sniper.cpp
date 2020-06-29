#include "Sniper.h"

#define SMALL_N 'n'
#define BIG_N 'N'
namespace mtm{

    const int SNIPER_MOVEMENT = 4;
    const int SNIPER_RELOAD_AMOUNT = 2;
    Sniper::Sniper(mtm::Team team,mtm::units_t health, mtm::units_t ammo, mtm::units_t range, mtm::units_t power):
    Character(team,health,ammo,range,power,SNIPER_MOVEMENT,SNIPER_RELOAD_AMOUNT){combo_counter = 0;}

    Character* Sniper::clone() const{
        return new Sniper(*this);
    }
    void Sniper::attack(Matrix<Character_ptr> &board,const GridPoint& src_coordinates,const GridPoint& dst_coordinates) {
        Character_ptr target = board(dst_coordinates.row,dst_coordinates.col);
        if(target->getTeam() == team || target == nullptr){
            throw IllegalTarget();
        }
        int damage = -power;
        if(++combo_counter == 3){
            combo_counter = 0;
            damage*=2;
        }
        target->changeHealth(damage);
        if (target->isDead()){
            target=nullptr;
        }
    }

    void Sniper::checkAttackValid(const GridPoint& src_coordinates,const GridPoint& dst_coordinates){
        int distance = GridPoint::distance(src_coordinates,dst_coordinates);
        if( distance > range || distance < ceil(range/2)){
            throw OutOfRange();
        }  
        if(ammo<=0){
            throw OutOfAmmo();
        }
    }

    const char Sniper::getSymbol(){
        if (team==PYTHON){
            return SMALL_N;
        }
        return BIG_N;

    }
}