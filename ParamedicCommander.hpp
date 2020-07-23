/**
 * @author Raphael Gozlan Sarah hananayev 
 * @since  2020-05
*/

#pragma once

#include "Paramedic.hpp"

namespace WarGame
{

    class ParamedicCommander : public Soldier
    {
    private:
        static const int initial_health_points = 200;
        static const int damage_per_activity = 0;

    public:
        ParamedicCommander(
            int player,
            int initial_health_points = 200,
            int damage_per_activity = 0) : Soldier(player, initial_health_points, damage_per_activity) {}

        ~ParamedicCommander() {}
        int attack(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> soldier_position) override
        {
            Soldier *close_soldier = nullptr;

            for (size_t i = std::max(0, soldier_position.first - 1); i < std::min(static_cast<int>(board.size()), soldier_position.second + 1); i++)
            {
                for (size_t j = std::max(0, soldier_position.second - 1); j < std::min(static_cast<int>(board.at(i).size()), soldier_position.second + 1); j++)
                {
                    Soldier *soldier = board.at(i).at(j);
                    std::pair<int,int> currnetPosition(i,j);
                    if (soldier && soldier->getPlayer() == _player && soldier->isAlive() && soldier_position != currnetPosition)
                    {
                        soldier->setHealth(soldier->getMaxHeal());
                    }
                }
            }
            for (size_t i = 0; i < board.size(); i++)
            {
                for (size_t j = 0; j < board[i].size(); j++)
                {
                    Soldier *soldier = board[i][j];

                    if (soldier && soldier->getPlayer() == _player && soldier->isAlive())
                    {
                        if (dynamic_cast<Paramedic *>(soldier) && !dynamic_cast<ParamedicCommander *>(soldier))
                        {
                            soldier->attack(board, {i, j});
                        }
                    }
                }
            }

            return(EXIT_SUCCESS);
        }
    };
} // namespace WarGame