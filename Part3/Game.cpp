#include "Game.h"
#include "Cell.h"
#include "Matrix.h"
#include "Character.h"
#include "Soldier.h"
#include "Medic.h"
#include "Sniper.h"
#include "Game_Exceptions.h"


namespace mtm{

    Game::Game(int height, int width){
        if (height<=0 || width <=0){
            throw IllegalArgument();
        }
        Matrix<Character_ptr> new_board(Dimensions(height,width)); 
        board = new_board;
    }


    bool Game::inScope(const GridPoint& coordinates) const{
        if (coordinates.col<0||coordinates.col>=board.width()||coordinates.row<0||coordinates.row>=board.height()){
            return false;
        }
        return true;
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
        if(health<=0){
            
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







}