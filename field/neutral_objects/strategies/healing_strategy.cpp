#include "healing_strategy.h"
#include <objects/units/unit.h>

namespace game::field::neutral_objects::strategies
{
    void healing_strategy::operator()(game::units::unit& _unit)
    {
        _unit.take_healing(heal_point);
    }
}
