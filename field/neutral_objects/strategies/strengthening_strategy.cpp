#include "strengthening_strategy.h"
#include <objects/units/unit.h>

namespace game::field::neutral_objects::strategies
{
    void strengthening_strategy::affect_to_unit(game::units::unit& _unit)
    {
        _unit.increase_armor(armor_point);
    }
}
