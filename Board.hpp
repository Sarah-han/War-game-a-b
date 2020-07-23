/**
 * Header file for the board of the war game.
 * 
 * @author Raphael Gozlan Sarah Hananyev 
 * @since  2020-05
 */

#include <string>
#include <vector>
#include <stdexcept>
#include <bits/stdc++.h> 
#include "Soldier.hpp"

namespace WarGame
{

  class Board
  {
  private:
    std::vector<std::vector<Soldier*>> board;
    u_int row, colum;

  public:
    enum MoveDIR
    {
      Up,
      Down,
      Right,
      Left
    };

    Board(uint numRows, uint numCols) : board(numRows, std::vector<Soldier *>(numCols, nullptr)),
                                        row(numRows),
                                        colum(numCols) {}

    // operator for putting soldiers on the game-board during initialization.
    Soldier *&operator[](std::pair<int, int> location);

    // operator for reading which soldiers are on the game-board.
    Soldier *operator[](std::pair<int, int> location) const;

    // The function "move" tries to move the soldier of player "player"
    //     from the "source" location to the "target" location,
    //     and activates the special ability of the soldier.
    // If the move is illegal, it throws "std::invalid_argument".
    // Illegal moves include:
    //  * There is no soldier in the source location (i.e., the soldier pointer is null);
    //  * The soldier in the source location belongs to the other player.
    //  * There is already another soldier (of this or the other player) in the target location.
    // IMPLEMENTATION HINT: Do not write "if" conditions that depend on the type of soldier!
    // Your code should be generic. All handling of different types of soldiers
    //      must be handled by polymorphism.
    void move(uint player_number, std::pair<int, int> source, MoveDIR direction);

    // returns true iff the board contains one or more soldiers of the given player.
    bool has_soldiers(uint player_number) const;
    
    static float dist(const std::pair<int, int> &source, const std::pair<int, int> &dest);

  private:
    Soldier *getSoldier(std::pair<int, int> location) const;
    bool checkValidMove(uint player_number, std::pair<int, int> source, std::pair<int, int> dest) const;
    std::pair<int, int> calculateDest(std::pair<int, int> source, MoveDIR direction) const;
    void updateBoard();
    

  };

} // namespace WarGame