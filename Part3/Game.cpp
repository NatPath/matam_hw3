#include "Game.h"
#include "Cell.h"
#include "Matrix.h"
#include "Character.h"
#include "Soldier.h"
#include "Medic.h"
#include "Sniper.h"
#include "Exceptions.h"


#define EMPTY_CHAR ' ' 

namespace mtm{
    //no longer shows the error,
    Game::Game(int height, int width)
    try:board(Dimensions(height,width),nullptr)
    {}
    catch(Board::IllegalInitialization e)
    {
        throw IllegalArgument();
    }
    


    bool Game::inScope(const GridPoint& coordinates) const{
        if (coordinates.col<0||coordinates.col>=board.width()||coordinates.row<0||coordinates.row>=board.height()){
            return false;
        }
        return true;
    }
    
    Character_ptr& Game::getCharacter(const GridPoint& coordinates){
        return board(coordinates.row,coordinates.col);
    }

    bool Game::containsCharacter(const GridPoint& coordinates) {
        return getCharacter(coordinates)!=nullptr;
    }
    
    void Game::cordToCordCheck(const GridPoint& src_coordinates, const GridPoint& dst_coordinates){
        if (!inScope(src_coordinates)||!inScope(dst_coordinates)){
            throw IllegalCell();
        }
        if (!containsCharacter(src_coordinates)){
            throw CellEmpty();
        }
    }

    void Game::addCharacter (const GridPoint& coordinates, Character_ptr character){
        if (!inScope(coordinates)){
            throw IllegalCell();
        }
        if(board(coordinates.row,coordinates.col)!=nullptr){
            throw CellOccupied();
        }
        board(coordinates.row,coordinates.col)=character;

    }
    Character_ptr Game::makeCharacter(CharacterType type, Team team,units_t health, units_t ammo, units_t range, units_t power){
        Character_ptr new_character=nullptr;
        if(health<=0 || ammo < 0 || range < 0 || power < 0 ){
            throw IllegalArgument();            
        }

        switch(type){
            case SOLDIER:
                new_character=Character_ptr(new Soldier(team,health,ammo,range,power));
                break;
            case MEDIC:
                new_character=Character_ptr(new Medic(team,health,ammo,range,power));
                break;
            case SNIPER:
                new_character=Character_ptr(new Sniper(team,health,ammo,range,power));
                break;
        }
        return new_character;
    }


    void Game::move(const GridPoint& src_coordinates, const GridPoint& dst_coordinates){
        cordToCordCheck(src_coordinates,dst_coordinates);

        Character_ptr to_move = getCharacter(src_coordinates);
        to_move->checkMovementValid(src_coordinates,dst_coordinates);//wiil throw a MoveTooFar if it isn't
        if (containsCharacter(dst_coordinates)){
            throw CellOccupied();
        }
        getCharacter(dst_coordinates)=to_move;
        to_move=nullptr;
    }

    void Game::attack(const GridPoint& src_coordinates, const GridPoint& dst_coordinates){
        cordToCordCheck(src_coordinates,dst_coordinates);

        Character_ptr to_attack_with= getCharacter(src_coordinates);
        to_attack_with->attackWrapper(board, src_coordinates, dst_coordinates);
    }

    void Game::reload(const GridPoint& coordinates){
        if (!inScope(coordinates)){
            throw IllegalCell();
        }        
        if(!containsCharacter(coordinates)){
            throw CellEmpty();
        }
        Character_ptr to_reload = getCharacter(coordinates);
        to_reload->reload();
    }

    const char characterTochar(const Character_ptr to_convert){
        if(to_convert == nullptr){
            return EMPTY_CHAR;
        }
        return to_convert->getSymbol();
    }
    std::ostream& operator<<(std::ostream& os,const Game& to_print){
        const Board board_to_print=to_print.board;
        /**
         * should find a different way to do that 
         * */
        char* chars_to_print = new char[board_to_print.size()+1];

        int index=0;
        try{
            Board::const_iterator i=board_to_print.begin();
            for (; i!=board_to_print.end();i++, index++){
                chars_to_print[index]= characterToChar(*i);
            }
        }
        catch(...){
            delete[] chars_to_print;
            throw;
        }
        return printGameBoard(os,chars_to_print,chars_to_print+index,board_to_print.width());
    }

    
    bool Game::isOver(Team* winningTeam) const{
        //we can split this function abit.. 
        int python_count=0;
        int cpp_count=0;
        for (Board::const_iterator i=board.begin(); i != board.end(); i++){
            if ( (*i)->getTeam() == PYTHON){
                python_count++;
            }            
            else if ( (*i)->getTeam() == CPP){
                cpp_count++;
            }
        }
        if ( cpp_count==0 && python_count!=0){
            if (winningTeam!=NULL){
                *winningTeam=PYTHON;
            }
            return true;
        }
        if ( cpp_count!=0 && python_count==0){
            if(winningTeam!=NULL){
                *winningTeam=CPP;
            }
            return true;
        }
        return false;
    }







}