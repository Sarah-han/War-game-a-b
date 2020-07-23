/**
 * @author Raphael Gozlan Sarah hananayev
 * @since  2020-05
*/
#pragma once

#include <iostream>
#include <algorithm>

// using namespace WarGame;
namespace WarGame
{
    class Soldier
    {
    protected:
        int _player;
        int _health;
        int _damage;
        const int _maxHeal;

    public:
        Soldier(int player, int health, int damage) : _player(player), _health(health), _maxHeal(health), _damage(damage)
        {
            // std::cout << "Solider Constructed" << std::endl;
        }
        ~Soldier()
        {
            // std::cout << "Solider Deconstructed" << std::endl;
        }
        int getPlayer()
        {
            return _player;
        }
        int getHealth()
        {
            return _health;
        }
        int getMaxHeal()
        {
            return _maxHeal;
        }
        void setHealth(int health)
        {
            _health = health;
        }
        int getDamage()
        {
            return _damage;
        }
        bool isAlive()
        {
            return 0 < _health;
        }

        virtual int attack(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> soldier_position) = 0;
    };
} // namespace WarGame
