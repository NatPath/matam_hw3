#include "Medic.h"

#define BIG_M 'M'
#define SMALL_M 'm'
namespace mtm{

    const int MEDIC_MOVEMENT = 5;
    const int MEDIC_RELOAD_AMOUNT = 5;
    Medic::Medic(mtm::Team team,mtm::units_t health, mtm::units_t ammo, mtm::units_t range, mtm::units_t power):
    Character(team,health,ammo,range,power,MEDIC_MOVEMENT,MEDIC_RELOAD_AMOUNT){}

    Character* Medic::clone() const{
        return new Medic(*this);
    }
    

    void Medic::attack(Matrix<Character_ptr> &board, const GridPoint& src_coordinates, const GridPoint& dst_coordinates) {
        Character_ptr target = board(dst_coordinates.row,dst_coordinates.col);
        if(target == nullptr || src_coordinates == dst_coordinates){
            throw IllegalTarget();
        }
        int health_amount = -power;
        if(target->getTeam() == team){
            health_amount*= -1;
            changeAmmo(1); // 1 ammo will be removed by the wrapper, make sure we stay with the same amount
        }
        target->changeHealth(health_amount);
    }
    const char Medic::getSymbol(){
        if (team==PYTHON){
            return SMALL_M;
        }
        return BIG_M;

    }
}