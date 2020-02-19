#include "killing_strategy.h"
#include <objects/units/unit.h>

namespace game::field::neutral_objects::strategies
{
    void killing_strategy::affect_to_unit(game::units::unit& _unit)
    {
        _unit.take_damage(attributes::attack_attribute(999999999, 0));
    }
}