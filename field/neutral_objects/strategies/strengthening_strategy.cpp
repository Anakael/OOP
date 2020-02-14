#include "strengthening_strategy.h"

namespace game::field::neutral_objects::strategies
{
    void strengthening_strategy::affect_to_unit(game::units::unit& _unit)
    {
        _unit.increase_armore(armor_point);
    }
}
