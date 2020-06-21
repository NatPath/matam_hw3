#ifndef _MEDIC_H_
#define _MEDIC_H_

#include "Character.h"
namespace mtm{

    class Medic: public Character{
    
        public:
        Character* clone() const override;
        





    };




}
#endif