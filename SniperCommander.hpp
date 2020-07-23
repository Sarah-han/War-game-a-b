/**
 * @author Raphael Gozlan Sarah hananayev 
 * @since  2020-05
*/

#pragma once

#include "Sniper.hpp"

namespace WarGame
{

    class SniperCommander : public Sniper
    {
    private:
        static const int initial_health_points = 120;
        static const int damage_per_activity = 100;

    public:
        SniperCommander(
            int player,
            int initial_health_points = 120,
            int damage_per_activity = 100) : Sniper(player, initial_health_points, damage_per_activity) {}

        ~SniperCommander() {}

        int attack(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> soldier_position) override
        {
            Soldier *strongest_soldier = nullptr;
            int strongest = -1;

            for (size_t i = 0; i < board.size(); i++)
            {
                for (size_t j = 0; j < board[i].size(); j++)
                {
                    Soldier *soldier = board[i][j];

                    if (soldier && soldier->getPlayer() != _player && soldier->isAlive())
                    {
                        if (soldier->getHealth() > strongest)
                        {
                            strongest_soldier = soldier;
                            strongest = soldier->getHealth();
                        }
                    }
                }
            }
            if (strongest_soldier)
                strongest_soldier->setHealth(strongest_soldier->getHealth() - _damage);

            for (size_t i = 0; i < board.size(); i++)
            {
                for (size_t j = 0; j < board[i].size(); j++)
                {
                    Soldier *soldier = board[i][j];
                    if (soldier && soldier->getPlayer() == _player && soldier->isAlive())
                    {

                        if (dynamic_cast<Sniper *>(soldier) && !dynamic_cast<SniperCommander *>(soldier))
                        {
                            soldier->attack(board, {i, j});
                        }
                    }
                }
            }

            return (EXIT_SUCCESS);
        }
    };
} // namespace WarGame