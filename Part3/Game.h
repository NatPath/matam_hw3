#ifndef _GAME_H_
#define _GAME_H_

#include "Auxiliaries.h"
#include "Matrix.h"
#include "Character.h"


namespace mtm{
    class Game{
        Matrix<Character_ptr> board;

        //checks if coordinates are in the scope of the board
        bool inScope(const GridPoint& coordinates) const;

        //gets a reference to Character_ptr from the specific coordinates given. Will throw CellEmpty if it is so
        Character_ptr& getCharacter(const GridPoint& coordinates);

        //checks if the legal GridPoint contains a well made Character
        bool containsCharacter(const GridPoint& coordinates) ;

        //checks if a "coordinate to coordinate" action is legal, if it isn't throws the fitting exception 
        //a better name is needed
        void cordToCordCheck(const GridPoint& src_coordinates, const GridPoint& dst_coordinates); 


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