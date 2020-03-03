#include "strengthening_strategy.h"
#include <objects/units/unit.h>

namespace game::field::neutral_objects::strategies
{
    void strengthening_strategy::operator()(game::units::unit& _unit)
    {
        _unit.increase_armor(armor_point);
    }
}
