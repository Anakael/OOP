#include "strengthening_object.h"
#include <field/neutral_objects/strategies/strengthening_strategy.h>

namespace game::field::neutral_objects
{
    strengthening_object::strengthening_object()
    {
        set_strategy(std::move(*(new strategies::strengthening_strategy())));
    }
}

