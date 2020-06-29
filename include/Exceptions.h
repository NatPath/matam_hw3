#ifndef _GAME_EXCEPTIONS_H_
#define _GAME_EXCEPTIONS_H_

namespace mtm{
    class Exception : public std::exception{};

    class GameException:public Exception{
        std::string error;
        
        public:
        GameException(const std::string error_class){
            error = std::string("A game related error has occurred:"+error_class);
        };
        const char* what() const noexcept override{ 
            return error.c_str();
        };
    };

    class IllegalArgument: public GameException{
        public:
        IllegalArgument():GameException("IllegalArgument"){};
        
    };

    class IllegalCell: public GameException{ 
        public:
        IllegalCell():GameException("IllegalCell"){};
        
    };
    class CellEmpty: public GameException{ 
        public:
        CellEmpty():GameException("CellEmpty"){};
    };
    class MoveTooFar: public GameException{ 
        public:
        MoveTooFar():GameException("MoveTooFar"){};
        
    };
    class CellOccupied: public GameException{
        public:
        CellOccupied():GameException("CellOccupied"){};
        
    };
    class OutOfRange: public GameException{ 
        public:
        OutOfRange():GameException("OutOfRange"){};
    };
    class OutOfAmmo: public GameException{ 
        public:
        OutOfAmmo():GameException("OutOfAmmo"){};
    };
    class IllegalTarget: public GameException{ 
        public:
        IllegalTarget():GameException("OutOfAmmo"){};
    };


}


#endif