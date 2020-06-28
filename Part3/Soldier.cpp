#include "Soldier.h"

#define SMALL_S 's'
#define BIG_S 'S'
namespace mtm{

    const int SOLDIER_MOVEMENT = 3;
    const int SOLDIER_RELOAD_AMOUNT = 3;
    Soldier::Soldier(mtm::Team team,mtm::units_t health, mtm::units_t ammo, mtm::units_t range, mtm::units_t power):
    Character(team,health,ammo,range,power,SOLDIER_MOVEMENT,SOLDIER_RELOAD_AMOUNT){}

    Character* Soldier::clone() const{
        return new Soldier(*this);
    }
    

    void Soldier::attack(Matrix<Character_ptr> &board,const GridPoint& src_coordinates, const GridPoint& dst_coordinates) {
        if(src_coordinates.row != dst_coordinates.row && src_coordinates.col != dst_coordinates.col){
            throw IllegalTarget();
        }
    
        Character_ptr target;
        int damage;
        int distance;
        for(int i = 0; i < board.height(); i++){
            for(int j = 0; j< board.width(); j++){
                target = board(i,j);
                distance = GridPoint::distance(dst_coordinates,GridPoint(i,j));
                if(target == nullptr || distance > ceil(range/3) || target->getTeam() == team){
                    continue;
                }
                damage = (distance == 0)? -power:ceil(-power/2);
                target->changeHealth(damage);
            }
        }
    }

    const char Soldier::getSymbol(){
        if (team==PYTHON){
            return SMALL_S;
        }
        return BIG_S;

    }
}