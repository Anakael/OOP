#include "neutral_object.h"

namespace game::field::neutral_objects
{
    void neutral_object::affect_to_unit(game::units::unit& _unit)
    {
        strategy->affect_to_unit(_unit);
    }

    void neutral_object::set_strategy(strategies::neutral_object_affect_strategy&& _strategy)
    {
        strategy.reset(&_strategy);
    }

    neutral_object::~neutral_object()
    = default;
}
