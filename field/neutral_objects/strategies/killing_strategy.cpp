#include "killing_strategy.h"
#include <objects/units/unit.h>

namespace game::field::neutral_objects::strategies
{
    bool killing_strategy::affect_to_unit(game::units::unit& _unit)
    {
        _unit.get_damage(999999999);
        return true;
    }
}