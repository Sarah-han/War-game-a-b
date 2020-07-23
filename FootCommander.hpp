/**
 * @author Raphael Gozlan Sarah Hananyev 
 * @since  2020-05
*/

#include "FootSoldier.hpp"

namespace WarGame
{

    class FootCommander : public FootSoldier
    {
    private:
        static const int initial_health_points = 150;
        static const int damage_per_activity = 20;

    public:
        FootCommander(
            int player,
            int initial_health_points = 150,
            int damage_per_activity = 20) : FootSoldier(player, initial_health_points, damage_per_activity) {}

        ~FootCommander() {}
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

            for (size_t i = 0; i < board.size(); i++)
            {
                for (size_t j = 0; j < board[i].size(); j++)
                {
                    Soldier *soldier = board[i][j];

                    if (soldier && soldier->getPlayer() == _player && soldier->isAlive())
                    {
                        if (dynamic_cast<FootSoldier*>(soldier) && !dynamic_cast<FootCommander*>(soldier))
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
