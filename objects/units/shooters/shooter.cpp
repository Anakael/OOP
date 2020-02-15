#include "shooter.h"

namespace game::units::shooters
{
    shooter::shooter(int _health, int _armor, int _attack, int _attack_range)
            : unit(_health, _armor, _attack, _attack_range)
    {
    }
    shooter::~shooter()
    = default;
}


