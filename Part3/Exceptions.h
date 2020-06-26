#ifndef _GAME_EXCEPTIONS_H_
#define _GAME_EXCEPTIONS_H_
#include "Game.h"

namespace mtm{

    class GameException:public Exception{
        const std::string error;
        public:
        GameException(const std::string error):error(error){};
        const char* what() const noexcept override{
            return std::string("A game related error has occurred:"+error).c_str();
        };
    };

    class Game::IllegalArgument: public GameException{
        public:
        IllegalArgument():GameException("IllegalArgument"){};
        
    };

    class Game::IllegalCell: public GameException{ 
        public:
        IllegalCell():GameException("IllegalCell"){};
        
    };
    class Game::CellEmpty: public GameException{ 
        public:
        CellEmpty():GameException("CellEmpty"){};
    };
    class Game::MoveTooFar: public GameException{ 
        public:
        MoveTooFar():GameException("MoveTooFar"){};
        
    };
    class Game::CellOccupied: public GameException{
        public:
        CellOccupied():GameException("CellOccupied"){};
        
    };
    class Game::OutOfRange: public GameException{ 
        public:
        OutOfRange():GameException("OutOfRange"){};
    };
    class Game::OutOfAmmo: public GameException{ 
        public:
        OutOfAmmo():GameException("OutOfAmmo"){};
    };
    class Game::IllegalTarget: public GameException{ 
        public:
        IllegalTarget():GameException("OutOfAmmo"){};
    };


}


#endif