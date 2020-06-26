#include "Game.h"



using namespace mtm;
void testCreateGame(){
    int height=4;
    int width=4;
    Game new_game(height,width);
    GridPoint p1(1,1);
    GridPoint p2(2,2);
    GridPoint p3(2,2);
    GridPoint p4(5,5);

    units_t yuri_health=4;
    units_t yuri_ammo=3;
    units_t yuri_range=5;
    units_t yuri_power=9001;
    Character_ptr yuri_soldier=new_game.makeCharacter(SOLDIER,CPP,yuri_health,yuri_ammo,yuri_range,yuri_power);
    new_game.addCharacter(p1,yuri_soldier);
    new_game.addCharacter(p2,yuri_soldier);
    try{
        new_game.addCharacter(p2,yuri_soldier);
    }
    catch(mtm::Exception& e){
        std::cout<<e.what()<<std::endl;

    }
    std::cout<<new_game<<std::endl;
}
int main(){
    testCreateGame();

}