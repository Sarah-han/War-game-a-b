#include "doctest.h"
#include <stdbool.h>
#include "Board.hpp"
#include "FootCommander.hpp"
#include "FootSoldier.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Soldier.hpp"
using namespace WarGame;

TEST_CASE("Snipers And Paramedics") {
    Board board(6,6);
    //-----Player 1 soldiers-------//
    CHECK(!board.has_soldiers(1));
    board[{0,0}] = new Paramedic(1);
    CHECK(typeid(board[{0,0}]) == typeid(Paramedic)); //Checks whether placement has occurred
    CHECK(board.has_soldiers(1));
    board[{0,1}] = new ParamedicCommander(1);
    CHECK(typeid(board[{0,1}]) == typeid(ParamedicCommander)); //Checks whether placement has occurred
    board[{0,2}] = new Sniper(1);
    CHECK(typeid(board[{0,2}]) == typeid(Sniper)); //Checks whether placement has occurred
    board[{0,3}] = new SniperCommander(1);
    CHECK(typeid(board[{0,3}]) == typeid(SniperCommander)); //Checks whether placement has occurred
    board[{0,4}] = new Paramedic(1);
    CHECK(typeid(board[{0,4}]) == typeid(Paramedic)); //Checks whether placement has occurred
    board[{0,5}] = new Sniper(1);
    CHECK(typeid(board[{0,5}]) == typeid(Sniper)); //Checks whether placement has occurred
    CHECK(board.has_soldiers(1));
    //-----Player 2 soldiers-------//
    CHECK(!board.has_soldiers(2));
    board[{5,5}] = new Paramedic(2);
    CHECK(typeid(board[{5,5}]) == typeid(Paramedic)); //Checks whether placement has occurred
    CHECK(board.has_soldiers(2));
    board[{5,4}] = new ParamedicCommander(2);
    CHECK(typeid(board[{5,4}]) == typeid(ParamedicCommander)); //Checks whether placement has occurred
    board[{5,3}] = new Sniper(2);
    CHECK(typeid(board[{5,3}]) == typeid(Sniper)); //Checks whether placement has occurred
    board[{5,2}] = new SniperCommander(2);
    CHECK(typeid(board[{5,2}]) == typeid(SniperCommander)); //Checks whether placement has occurred
    board[{5,1}] = new Paramedic(2);
    CHECK(typeid(board[{5,1}]) == typeid(Paramedic)); //Checks whether placement has occurred
    board[{5,0}] = new Sniper(2);
    CHECK(typeid(board[{5,0}]) == typeid(Sniper)); //Checks whether placement has occurred
    CHECK(board.has_soldiers(2));
//-----------moves---------------------------------------------------------
    CHECK_NOTHROW(board.move(1, {0,3}, Board::MoveDIR::Up));  // move to {1,3} and shoot; damage 10
    CHECK(board[{0,3}]== nullptr); //Checks whether the soldier is moving and is no longer in his starting position
    CHECK(typeid(board[ {1,3}]) == typeid(SniperCommander)); //Checks whether the new location has the right soldier type,i.e the soldier has actually moved

    CHECK_NOTHROW(board.move(2, {5,2}, Board::MoveDIR::Down));  // move to {4,2} and shoot; damage 10
    CHECK(board[{5,2}]== nullptr); //Checks whether the soldier is moving and is no longer in his starting position
    CHECK(typeid(board[ {4,2}]) == typeid(SniperCommander));

    CHECK_NOTHROW(board.move(1, {0,5}, Board::MoveDIR::Up));  // move to {1,5} and shoot; damage 10
    CHECK(board[{0,5}]== nullptr); //Checks whether the soldier is moving and is no longer in his starting position
    CHECK(typeid(board[ {1,5}]) == typeid(Sniper)); //Checks whether the new location has the right soldier type,i.e the soldier has actually moved

    CHECK_NOTHROW(board.move(2, {5,0}, Board::MoveDIR::Down));  // move to {4,0} and shoot; damage 10
    CHECK(board[{5,0}]== nullptr); //Checks whether the soldier is moving and is no longer in his starting position
    CHECK(typeid(board[ {4,0}]) == typeid(Sniper));

    CHECK_NOTHROW(board.move(1, {1,3}, Board::MoveDIR::Up));  // move to {2,3} and shoot; damage 10
    CHECK(board[{1,3}]== nullptr); //Checks whether the soldier is moving and is no longer in his starting position
    CHECK(typeid(board[ {2,3}]) == typeid(SniperCommander)); //Checks whether the new location has the right soldier type,i.e the soldier has actually moved

    CHECK_NOTHROW(board.move(2, {5,3}, Board::MoveDIR::Down));  // move to {4,3} and shoot; damage 10
    CHECK(board[{5,3}]== nullptr); //Checks whether the soldier is moving and is no longer in his starting position
    CHECK(typeid(board[ {4,3}]) == typeid(Sniper));

    CHECK_NOTHROW(board.move(1, {0,4}, Board::MoveDIR::Up));  // move to {1,4} and shoot; damage 10
    CHECK(board[{0,4}]== nullptr); //Checks whether the soldier is moving and is no longer in his starting position
    CHECK(typeid(board[ {1,4}]) == typeid(Paramedic)); //Checks whether the new location has the right soldier type,i.e the soldier has actually moved

    CHECK_NOTHROW(board.move(2, {4,3}, Board::MoveDIR::Down));  // move to {3,3} and shoot; damage 10
    CHECK(board[{4,3}]== nullptr); //Checks whether the soldier is moving and is no longer in his starting position
    CHECK(typeid(board[ {3,3}]) == typeid(Sniper));

    CHECK_NOTHROW(board.move(1, {0,2}, Board::MoveDIR::Up));  // move to {1,2} and shoot; damage 10
    CHECK(board[{0,2}]== nullptr); //Checks whether the soldier is moving and is no longer in his starting position
    CHECK(typeid(board[ {1,2}]) == typeid(Sniper)); //Checks whether the new location has the right soldier type,i.e the soldier has actually moved

    CHECK_NOTHROW(board.move(2, {5,1}, Board::MoveDIR::Down));  // move to {4,1} and shoot; damage 10
    CHECK(board[{5,1}]== nullptr); //Checks whether the soldier is moving and is no longer in his starting position
    CHECK(typeid(board[ {4,1}]) == typeid(Paramedic));

}

TEST_CASE("Foot soldiers simple game") {
    Board board (8,1);
    CHECK(!board.has_soldiers(1));
    board[{0,0}] = new FootSoldier(1);
    CHECK(board.has_soldiers(1));
    CHECK(!board.has_soldiers(2));
    board[{7,0}] = new FootSoldier(2);
    CHECK(board.has_soldiers(2));

    CHECK_NOTHROW(board.move(1, {0,0}, Board::MoveDIR::Up));  // move to {1,0} and shoot; damage 10
    CHECK(board[{0,0}]== nullptr); //Checks whether the soldier is moving and is no longer in his starting position
    CHECK(typeid(board[ {1,0}]) == typeid(FootSoldier)); //Checks whether the new location has the right soldier type,i.e the soldier has actually moved

    CHECK_NOTHROW( board.move(1, {1,0}, Board::MoveDIR::Down));  // move back to {0,0} and shoot; damage 10
    CHECK(board[{1,0}]== nullptr); //Checks whether the soldier is moving and is no longer in his starting position
    CHECK(typeid(board[ {0,0}]) == typeid(FootSoldier)); //Checks whether the new location has the right soldier type,i.e the soldier has actually moved

    CHECK_NOTHROW(board.move(1, {0,0}, Board::MoveDIR::Up));  // move to {1,0} and shoot; damage 10
    CHECK(board[{0,0}]== nullptr); //Checks whether the soldier is moving and is no longer in his starting position
    CHECK(typeid(board[ {1,0}]) == typeid(FootSoldier)); //Checks whether the new location has the right soldier type,i.e the soldier has actually moved

    CHECK_NOTHROW(board.move(1, {1,0}, Board::MoveDIR::Down));  // move back to {0,0} and shoot; damage 10
    CHECK(board[{1,0}]== nullptr); //Checks whether the soldier is moving and is no longer in his starting position
    CHECK(typeid(board[ {0,0}]) == typeid(FootSoldier)); //Checks whether the new location has the right soldier type,i.e the soldier has actually moved

    CHECK_NOTHROW(board.move(1, {0,0}, Board::MoveDIR::Up));  // move to {1,0} and shoot; damage 10
    CHECK(board[{0,0}]== nullptr); //Checks whether the soldier is moving and is no longer in his starting position
    CHECK(typeid(board[ {1,0}]) == typeid(FootSoldier)); //Checks whether the new location has the right soldier type,i.e the soldier has actually moved

    CHECK_NOTHROW(board.move(1, {1,0}, Board::MoveDIR::Down));  // move back to {0,0} and shoot; damage 10
    CHECK(board[{1,0}]== nullptr); //Checks whether the soldier is moving and is no longer in his starting position
    CHECK(typeid(board[{0,0}]) == typeid(FootSoldier)); //Checks whether the new location has the right soldier type,i.e the soldier has actually moved

    CHECK_NOTHROW(board.move(1, {0,0}, Board::MoveDIR::Up));  // move to {1,0} and shoot; damage 10
    CHECK(board[{0,0}]== nullptr); //Checks whether the soldier is moving and is no longer in his starting position
    CHECK(typeid(board[ {1,0}]) == typeid(FootSoldier)); //Checks whether the new location has the right soldier type,i.e the soldier has actually moved

    CHECK_NOTHROW(board.move(1, {1,0}, Board::MoveDIR::Down));  // move back to {0,0} and shoot; damage 10
    CHECK(board[{1,0}]== nullptr); //Checks whether the soldier is moving and is no longer in his starting position
    CHECK(typeid(board[{0,0}]) == typeid(FootSoldier)); //Checks whether the new location has the right soldier type,i.e the soldier has actually moved

    CHECK_NOTHROW(board.move(1, {0,0}, Board::MoveDIR::Up));  // move to {1,0} and shoot; damage 10
    CHECK(board[{0,0}]== nullptr); //Checks whether the soldier is moving and is no longer in his starting position
    CHECK(typeid(board[ {1,0}]) == typeid(FootSoldier)); //Checks whether the new location has the right soldier type,i.e the soldier has actually moved

    CHECK_NOTHROW(board.move(1, {1,0}, Board::MoveDIR::Down));  // move back to {0,0} and shoot; damage 10
    CHECK(board[{1,0}]== nullptr);  //Checks whether the soldier is moving and is no longer in his starting position
    CHECK(typeid(board[{0,0}]) == typeid(FootSoldier)); //Checks whether the new location has the right soldier type,i.e the soldier has actually moved

    CHECK(!board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
}

TEST_CASE("Foot soldiers simple game2") {
    Board board (4,4);
    CHECK(!board.has_soldiers(1));
    board[{0,0}] = new FootSoldier(1);
    CHECK(typeid(board[{0,0}]) == typeid(FootSoldier)); //Checks whether placement has occurred
    CHECK(board.has_soldiers(1));
    board[{0,3}] = new FootCommander(1);
    CHECK(typeid(board[{0,3}]) == typeid(FootCommander)); //Checks whether placement has occurred
    CHECK(board.has_soldiers(1));
    CHECK(!board.has_soldiers(2));
    board[{3,0}] = new FootSoldier(2);
    CHECK(typeid(board[{3,0}]) == typeid(FootSoldier)); //Checks whether placement has occurred
    board[{3,1}] = new Paramedic(2);
    CHECK(typeid(board[{3,1}]) == typeid(Paramedic)); //Checks whether placement has occurred
    board[{3,3}] = new FootCommander(2);
    CHECK(typeid(board[{3,3}]) == typeid(FootCommander)); //Checks whether placement has occurred
    CHECK(board.has_soldiers(2));

    CHECK_NOTHROW(board.move(1, {0,3}, Board::MoveDIR::Up));  // move to {1,3} and shoot; damage 10 and damage 20
    CHECK(board[{0,3}]== nullptr);  //Checks whether the soldier is moving and is no longer in his starting position
    CHECK(typeid(board[{1,3}]) == typeid(FootCommander)); //Checks whether placement has occurred

    CHECK_NOTHROW(board.move(2, {3,3}, Board::MoveDIR::Left));  // move to {3,2} and shoot; damage 10 and damage 20
    CHECK(board[{3,3}]== nullptr);  //Checks whether the soldier is moving and is no longer in his starting position
    CHECK(typeid(board[{3,2}]) == typeid(FootCommander)); //Checks whether placement has occurred

    CHECK_NOTHROW(board.move(1, {0,0}, Board::MoveDIR::Right));  // move to {0,1} and shoot; damage 10
    CHECK(board[{0,0}]== nullptr);  //Checks whether the soldier is moving and is no longer in his starting position
    CHECK(typeid(board[{0,1}]) == typeid(FootSoldier)); //Checks whether placement has occurred

    CHECK_NOTHROW( board.move(2, {3,1}, Board::MoveDIR::Down));  // move back to {2,0} and shoot; damage 10
    CHECK(board[{3,1}]== nullptr);  //Checks whether the soldier is moving and is no longer in his starting position
    CHECK(typeid(board[{2,1}]) == typeid(Paramedic)); //Checks whether placement has occurred

    CHECK_NOTHROW( board.move(1, {1,3}, Board::MoveDIR::Up));  // move to {1,0} and shoot; damage 10
    CHECK(board[{1,3}]== nullptr);  //Checks whether the soldier is moving and is no longer in his starting position
    CHECK(typeid(board[{2,3}]) == typeid(FootCommander)); //Checks whether placement has occurred

    CHECK_NOTHROW( board.move(2, {3,2}, Board::MoveDIR::Down));  // move to {1,0} and shoot; damage 10
    CHECK(board[{3,2}]== nullptr);  //Checks whether the soldier is moving and is no longer in his starting position
    CHECK(typeid(board[{2,2}]) == typeid(FootCommander)); //Checks whether placement has occurred


    CHECK_NOTHROW( board.move(2, {2,2}, Board::MoveDIR::Up));  // move to {1,0} and shoot; damage 10
    CHECK(board[{2,2}]== nullptr);  //Checks whether the soldier is moving and is no longer in his starting position
    CHECK(typeid(board[{3,2}]) == typeid(FootCommander)); //Checks whether placement has occurred


    CHECK_NOTHROW( board.move(2, {3,2}, Board::MoveDIR::Down));  // move to {1,0} and shoot; damage 10
    CHECK(board[{3,2}]== nullptr);  //Checks whether the soldier is moving and is no longer in his starting position
    CHECK(typeid(board[{2,2}]) == typeid(FootCommander)); //Checks whether placement has occurred

    CHECK_NOTHROW( board.move(2, {2,2}, Board::MoveDIR::Up));  // move to {1,0} and shoot; damage 10
    CHECK(board[{2,2}]== nullptr);  //Checks whether the soldier is moving and is no longer in his starting position
    CHECK(typeid(board[{3,2}]) == typeid(FootCommander)); //Checks whether placement has occurred


    CHECK_NOTHROW( board.move(2, {3,2}, Board::MoveDIR::Down));  // move to {1,0} and shoot; damage 10
    CHECK(board[{3,2}]== nullptr);  //Checks whether the soldier is moving and is no longer in his starting position
    CHECK(typeid(board[{2,2}]) == typeid(FootCommander)); //Checks whether placement has occurred

    CHECK_NOTHROW( board.move(2, {2,2}, Board::MoveDIR::Up));  // move to {1,0} and shoot; damage 10
    CHECK(board[{2,2}]== nullptr);  //Checks whether the soldier is moving and is no longer in his starting position
    CHECK(typeid(board[{3,2}]) == typeid(FootCommander)); //Checks whether placement has occurred


    CHECK_NOTHROW( board.move(2, {3,2}, Board::MoveDIR::Down));  // move to {1,0} and shoot; damage 10
    CHECK(board[{3,2}]== nullptr);  //Checks whether the soldier is moving and is no longer in his starting position
    CHECK(typeid(board[{2,2}]) == typeid(FootCommander)); //Checks whether placement has occurred

    CHECK_NOTHROW( board.move(2, {2,2}, Board::MoveDIR::Up));  // move to {1,0} and shoot; damage 10
    CHECK(board[{2,2}]== nullptr);  //Checks whether the soldier is moving and is no longer in his starting position
    CHECK(typeid(board[{3,2}]) == typeid(FootCommander)); //Checks whether placement has occurred

 

    CHECK(!board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
}