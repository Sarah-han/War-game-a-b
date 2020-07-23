/**
 * @author Raphael Gozlan Sarah hananayev 
 * @since  2020-05
*/

#pragma once

#include "Soldier.hpp"

namespace WarGame
{
    class Sniper : public Soldier
    {
    private:
        static const int initial_health_points = 100;
        static const int damage_per_activity = 50;

    public:
        Sniper(
            int player,
            int initial_health_points = 100,
            int damage_per_activity = 50) : Soldier(player, initial_health_points, damage_per_activity) {}

        ~Sniper() {}

        int attack(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> soldier_position) override
        {
            Soldier *strongest_soldier = nullptr;
            int strongest = 0;

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
            return (EXIT_SUCCESS);
        }
    };

} // namespace WarGame