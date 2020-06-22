#ifndef _SOLDIER_H_
#define _SOLDIER_H_

#include "Character.h"

#define MOVMENT 3
namespace mtm{

    class Soldier: public Character{
        static const int movment=3;
    
        public:
        Character* clone() const override;
        





    };




}
#endif