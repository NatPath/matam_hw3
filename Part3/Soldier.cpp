#include "Soldier.h"

#define SMALL_S 's'
#define BIG_S 'S'
namespace mtm{

    Soldier::Soldier(mtm::Team team,mtm::units_t health, mtm::units_t ammo, mtm::units_t range, mtm::units_t power):
    Character(team,health,ammo,range,power,5,5){}

    Character* Soldier::clone() const{
        return new Soldier(*this);
    }
    

    void Soldier::attack(Matrix<Character_ptr> &board,const GridPoint& src_coordinates, const GridPoint& dst_coordinates) {
        Character* target = *(board(dst_coordinates.row,dst_coordinates.col));
        if(src_coordinates.row != dst_coordinates.row && src_coordinates.col != dst_coordinates.col){ // make sure to update according to forum response
            throw Game::IllegalTarget();
        }
    
        Character* target;
        int damage;
        int distance;
        for(int i = 0; i < board.height(); i++){
            for(int j = 0; j< board.width(); j++){
                target = *(board(i,j));
                distance = (abs(dst_coordinates.row - i) + abs(dst_coordinates.col - j));
                if(distance > ceil(range/3) || target->getTeam() == team){
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