#include "healing_strategy.h"
#include <objects/units/unit.h>

namespace game::field::neutral_objects::strategies
{
    bool healing_strategy::affect_to_unit(game::units::unit& _unit)
    {
        _unit.get_healing(heal_point);
        return true;
    }
}
