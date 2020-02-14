#include "healing_strategy.h"

namespace game::field::neutral_objects::strategies
{
    void healing_strategy::affect_to_unit(game::units::unit& _unit)
    {
        _unit.get_healing(heal_point);
    }
}
