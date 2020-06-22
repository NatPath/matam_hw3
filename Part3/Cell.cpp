#include "Cell.h"


namespace mtm{
    Cell::Cell(mtm::GridPoint& coordinates): coordinates(coordinates),character(nullptr){}

    void Cell::transferCharacter(Cell& destination){
        destination.character = character;
        character = nullptr;
    }

    bool Cell::isOccupied(){
        return character == nullptr;
    }

    char Cell::print(){
        if(!isOccupied()){
            return ' ';
            
        }
    }


}