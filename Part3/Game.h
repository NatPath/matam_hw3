#ifndef _GAME_H_
#define _GAME_H_

#include "Auxiliaries.h"
#include "Matrix.h"
#include "Character.h"


namespace mtm{
    class Game;

    typedef Matrix<Character_ptr> Board;
    class Game{
        Board board;

        //checks if coordinates are in the scope of the board
        bool inScope(const GridPoint& coordinates) const;

        //gets a reference to Character_ptr from the specific coordinates given. Will throw CellEmpty if it is so
        Character_ptr& getCharacter(const GridPoint& coordinates);

        //checks if the legal GridPoint contains a well made Character
        bool containsCharacter(const GridPoint& coordinates) ;

        //checks if a "coordinate to coordinate" action is legal, if it isn't throws the fitting exception 
        //coordinate to coordinate action is an action in which: 
        //(1)  both the coordinates are in the scope of the border
        //(2)  the source coordinate contains a character
        void cordToCordCheck(const GridPoint& src_coordinates, const GridPoint& dst_coordinates); 


        public:
        
        Game(int height, int width);
        Game(const Game& other);
        ~Game()=default;
        Game& operator=(const Game& other);
        void addCharacter (const GridPoint& coordinates, Character_ptr character);
        static Character_ptr makeCharacter(CharacterType type, Team team,units_t health, units_t ammo, units_t range, units_t power);
        void move(const GridPoint& src_coordinates, const GridPoint& dst_coordinates);
        void attack(const GridPoint& src_coordinates, const GridPoint& dst_coordinates);
        void reload(const GridPoint& coordinates);
        friend std::ostream& operator<<(std::ostream& os,const Game& to_print);
        bool isOver(Team* winningTeam=NULL) const;

    };
    std::ostream& operator<<(std::ostream& os,const Game& to_print);
    //converts a given Character_ptr to the Symbol of the character
    const char characterToChar(const Character_ptr to_convert);
}

#endif