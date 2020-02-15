#include "strengthening_strategy.h"
#include <objects/units/unit.h>

namespace game::field::neutral_objects::strategies
{
    bool strengthening_strategy::affect_to_unit(game::units::unit& _unit)
    {
        _unit.increase_armore(armor_point);
        return true;
    }
}
