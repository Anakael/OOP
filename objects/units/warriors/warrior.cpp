#include "warrior.h"

namespace game::units::warriors
{
    warrior::warrior(int _health, int _armor, int _attack)
            : unit(_health, _armor, _attack, 1)
    {
    }

    warrior::~warrior()
    = default;
}


