#ifndef _GAME_EXCEPTIONS_H_
#define _GAME_EXCEPTIONS_H_

#include "Game.h"
namespace mtm{

    class Game::Exception:public mtm::Exception{
        const std::string error;
        public:
        Exception(const std::string error):error(error){};
        const char* what() const noexcept override{
            return std::string("A game related error has occurred:"+error).c_str();
        };
    };

    class Game::IllegalArgument: public mtm::Game::Exception{
        public:
        IllegalArgument():Exception("IllegalArgument"){};
        
    };

    class Game::IllegalCell: public mtm::Game::Exception{ 
        public:
        IllegalCell():Exception("IllegalCell"){};
        
    };
    class Game::CellEmpty: public mtm::Game::Exception{ 
        public:
        CellEmpty():Exception("CellEmpty"){};
    };
    class Game::MoveTooFar: public mtm::Game::Exception{ 
        public:
        MoveTooFar():Exception("MoveTooFar"){};
        
    };
    class Game::CellOccupied: public mtm::Game::Exception{
        public:
        CellOccupied():Exception("CellOccupied"){};
        
    };
    class Game::OutOfRange: public mtm::Game::Exception{ 
        public:
        OutOfRange():Exception("OutOfRange"){};
    };
    class Game::OutOfAmmo: public mtm::Game::Exception{ 
        public:
        OutOfAmmo():Exception("OutOfAmmo"){};
    };

}


#endif