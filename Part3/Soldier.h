#ifndef _SOLDIER_H_
#define _SOLDIER_H_

#include "Character.h"
namespace mtm{

    class Soldier: public Character{
    
        public:
        Character* clone() const override;
        





    };




}
#endif