#ifndef _GAME_EXCEPTIONS_H_
#define _GAME_EXCEPTIONS_H_

namespace mtm{

    class GameException:public Exception{
        //const std::string error;
        const char* error_msg;
        public:
        GameException(const std::string error){error_msg =  std::string("A game related error has occurred:"+error).c_str();};
        const char* what() const noexcept override{         
            return error_msg;
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