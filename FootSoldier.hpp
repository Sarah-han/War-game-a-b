/**
 * @author Raphael Gozlan Sarah hananayev 
 * @since  2020-05
*/

#pragma once

#include "Soldier.hpp"

namespace WarGame
{

    class FootSoldier : public Soldier
    {
    private:
        static const int initial_health_points = 100;
        static const int damage_per_activity = 10;

    public:
        FootSoldier(
            int player,
            int initial_health_points = 100,
            int damage_per_activity = 10) : Soldier(player, initial_health_points, damage_per_activity) {}

        ~FootSoldier() {}
        int attack(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> soldier_position) override
        {
            Soldier *close_soldier = nullptr;
            float closest = MAXFLOAT;

            for (size_t i = 0; i < board.size(); i++)
            {
                for (size_t j = 0; j < board[i].size(); j++)
                {
                    Soldier *soldier = board[i][j];

                    if (soldier && soldier->getPlayer() != _player && soldier->isAlive())
                    {
                        float dist = Board::dist({i, j}, soldier_position);
                        if (dist <= closest)
                        {
                            close_soldier = soldier;
                            closest = dist;
                        }
                    }
                }
            }
            if (close_soldier)
                close_soldier->setHealth(close_soldier->getHealth() - _damage);
            return (EXIT_SUCCESS);
        }
    };

} // namespace WarGame