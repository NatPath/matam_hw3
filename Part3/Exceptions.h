#ifndef _GAME_EXCEPTIONS_H_
#define _GAME_EXCEPTIONS_H_
#include "Game.h"

namespace mtm{

    class GameException:public mtm::Exception{
        const std::string error;
        public:
        GameException(const std::string error):error(error){};
        const char* what() const noexcept override{
            return std::string("A game related error has occurred:"+error).c_str();
        };
    };

    class Game::IllegalArgument: public mtm::GameException{
        public:
        IllegalArgument():GameException("IllegalArgument"){};
        
    };

    class Game::IllegalCell: public mtm::GameException{ 
        public:
        IllegalCell():GameException("IllegalCell"){};
        
    };
    class Game::CellEmpty: public mtm::GameException{ 
        public:
        CellEmpty():GameException("CellEmpty"){};
    };
    class Game::MoveTooFar: public mtm::GameException{ 
        public:
        MoveTooFar():GameException("MoveTooFar"){};
        
    };
    class Game::CellOccupied: public mtm::GameException{
        public:
        CellOccupied():GameException("CellOccupied"){};
        
    };
    class Game::OutOfRange: public mtm::GameException{ 
        public:
        OutOfRange():GameException("OutOfRange"){};
    };
    class Game::OutOfAmmo: public mtm::GameException{ 
        public:
        OutOfAmmo():GameException("OutOfAmmo"){};
    };
    class Game::IllegalTarget: public mtm::GameException{ 
        public:
        IllegalTarget():GameException("OutOfAmmo"){};
    };


}


#endif