#include "Sniper.h"

#define SMALL_N 'n'
#define BIG_N 'N'
namespace mtm{

    Sniper::Sniper(mtm::Team team,mtm::units_t health, mtm::units_t ammo, mtm::units_t range, mtm::units_t power):
    Character(team,health,ammo,range,power,4,2),symbol('N'){combo_counter = 0;}

    Character* Sniper::clone() const{
        return new Sniper(*this);
    }
    void Sniper::attack(Matrix<Character_ptr> &board, GridPoint& src_coordinates, GridPoint& dst_coordinates) { 
        if(GridPoint::distance(src_coordinates,dst_coordinates) < ceil(range/2)){
            throw Game::OutOfRange();
        }
        Character* target = *(board(src_coordinates.row,dst_coordinates.col));
        if(target->getTeam() == team){
            throw Game::IllegalTarget();
        }
        int damage = -power;
        if(++combo_counter == 3){
            combo_counter = 0;
            damage*=2;
        }
        target->changeHealth(damage);
    }

    const char Sniper::getSymbol(){
        if (team==PYTHON){
            return SMALL_N;
        }
        return BIG_N;

    }
}