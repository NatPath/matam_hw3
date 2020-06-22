#ifndef _CELL_H_
#define _CELL_H_
#include "Auxiliaries.h"
#include "Character.h"
#include <memory>
namespace mtm{
    class Cell{
        const GridPoint& coordinates; 
        std::shared_ptr<Character> character;
        public:
        Cell() = default;
        Cell(GridPoint& coordinates);
        Cell(const Cell& to_copy) = default;
        void transferCharacter(Cell& destination);
        bool isOccupied();
        char print();
    };

    
}
#endif
