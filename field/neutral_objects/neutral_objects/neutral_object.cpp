#include "neutral_object.h"
#include <commands/object_die_command.h>
#include <mediator/mediator.h>

namespace game::field::neutral_objects
{
    void neutral_object::operator()(game::units::unit& _unit)
    {
        (*strategy)(_unit);
        mediator_ref->send(commands::object_die_command(*this));
    }

    void neutral_object::set_strategy(strategies::neutral_object_affect_strategy&& _strategy)
    {
        strategy.reset(&_strategy);
    }

    neutral_object::neutral_object()
            : object(0, 0)
    {
    }

    neutral_object::~neutral_object()
    = default;
}
