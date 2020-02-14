#include "healing_object.h"
#include <field/neutral_objects/strategies/healing_strategy.h>

namespace game::field::neutral_objects
{
    healing_object::healing_object()
    {
        set_strategy(strategies::healing_strategy());
    }
}
