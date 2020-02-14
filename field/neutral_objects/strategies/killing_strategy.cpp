#include "killing_strategy.h"

namespace game::field::neutral_objects::strategies
{
    void killing_strategy::affect_to_unit(game::units::unit& _unit)
    {
        _unit.die();
    }
}