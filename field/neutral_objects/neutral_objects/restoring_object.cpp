#include "restoring_object.h"
#include <field/neutral_objects/strategies/restoring_strategy.h>

namespace game::field::neutral_objects
{
    restoring_object::restoring_object()
    {
        set_strategy(strategies::restoring_strategy());
    }
}


