#ifndef _GAME_H_
#define _GAME_H_

#include <memory>
#include "Auxiliaries.h"
#include "Matrix.h"
#include "Cell.h"
#include "Character.h"
#include "Game_Exceptions.h"


namespace mtm{
    typedef std::shared_ptr<Character> Character_ptr;
    class Game{
        Matrix<Character_ptr> board;

        bool inScope(const GridPoint& coordinates) const;//checks if coordinates are in the scope of the board
        public:
        //Exceptions
        class Exception;
        class IllegalArgument;
        class IllegalCell;
        class CellEmpty;
        class MoveTooFar;
        class CellOccupied;
        class OutOfRange;
        class OutOfAmmo;
        class IllegalTarget;

        
        Game(int height, int width);
        Game(const Game& other)=default;
        ~Game()=default;
        Game& operator=(const Game& other)=default;
        void addCharacter (const GridPoint& coordinates, Character_ptr character);
        static Character_ptr makeCharacter(CharacterType type, Team team,units_t health, units_t ammo, units_t range, units_t power);
        void move(const GridPoint& src_coordinates, const GridPoint& dst_coordinates);
        void attack(const GridPoint& src_coordinates, const GridPoint& dst_coordinates);
        void reload(const GridPoint& coordinates);
        std::ostream& printGameBoard(std::ostream& os, const char* begin, const char* end, unsigned int width) const;
        bool isOver(Team* winningTeam=NULL) const;

        

    };
}

#endif