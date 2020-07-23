/**
 * @author Raphael Gozlan Sarah Hananyev 
 * @since  2020-05
*/

#include "Board.hpp"

namespace WarGame
{

    Soldier*& Board::operator[](std::pair<int, int> location)
    {
        // return board[location.first][location.second];
        return board.at(location.first).at(location.second);
    }

    Soldier* Board::operator[](std::pair<int, int> location) const
    {
        return board[location.first][location.second];
    }

    void Board::move(uint player_number, std::pair<int, int> source, MoveDIR direction)
    {
        Soldier *soldier = getSoldier(source);
        // std::cout << "Moving from " << source.first << ":" << source.second << " to ";
        std::pair<int, int> dest = calculateDest(source, direction);
        // std::cout << dest.first << ":" << dest.second << std::endl;
        if (checkValidMove(player_number, source, dest))
        {
            // make move
            board.at(source.first).at(source.second) = nullptr;
            board.at(dest.first).at(dest.second) = soldier;
            // play
            soldier->attack(board, source);
            // update board
        }
        this->updateBoard();
    }
    // may throw std::invalid_argument
    bool Board::checkValidMove(uint player_number, std::pair<int, int> source, std::pair<int, int> dest) const
    {
        Soldier *soldier = getSoldier(source);

        // There is no soldier in the source location (i.e., the soldier pointer is null)
        if (!soldier)
        {
            throw std::invalid_argument("There is no soldier in the source location");
        }

        // The soldier in the source location belongs to the other player
        if (soldier->getPlayer() != player_number)
        {
            throw std::invalid_argument("The soldier in the source location belongs to the other player");
        }

        // There is already another soldier (of this or the other player) in the target location.
        Soldier *temp = getSoldier(dest);
        if (temp)
        {
            throw std::invalid_argument("There is already another soldier in the target location");
        }

        return true;
    }

    std::pair<int, int> Board::calculateDest(std::pair<int, int> source, Board::MoveDIR direction) const
    {
        // std::cout << source.first << ":" << source.second << "Going " << direction << std::endl;
        switch (direction)
        {
        case MoveDIR::Up:
            return {source.first + 1, source.second};
        case MoveDIR::Right:
            return {source.first, source.second + 1};
        case MoveDIR::Down:
            return {source.first - 1, source.second};
        case MoveDIR::Left:
            return {source.first, source.second - 1};
        }
        // std::cout << dest.first << ":" << dest.second << std::endl;
    }

    bool Board::has_soldiers(uint player_number) const
    {
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board.at(i).size(); j++)
            {
                Soldier *soldier = board.at(i).at(j);
                if (soldier && soldier->getPlayer() == player_number && soldier->isAlive())
                {
                    return true;
                }
            }
        }
        return false;
    }

    Soldier *Board::getSoldier(std::pair<int, int> location) const
    {
        return board.at(location.first).at(location.second);
    }
    // Function to calculate distance
    float Board::dist(const std::pair<int, int> &source, const std::pair<int, int> &dest)
    {
        // Calculating distance
        return sqrt(pow(dest.second - source.second, 2) +
                    pow(dest.first - source.first, 2) * 1.0);
    }

    void Board::updateBoard()
    {
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board.at(i).size(); j++)
            {
                Soldier *soldier = board.at(i).at(j);
                if (soldier && !(soldier->isAlive()))
                {
                    board.at(i).at(j) = nullptr;
                }
            }
        }
    }
} // namespace WarGame