#include <objects/units/mages/mage.h>
#include "restoring_strategy.h"
#include <iostream>

namespace game::field::neutral_objects::strategies
{
    bool restoring_strategy::affect_to_unit(game::units::unit& _unit)
    {
        return false;
    }

    bool restoring_strategy::affect_to_unit(game::units::mages::mage& _mage)
    {
        _mage.restore_mana(mana_point);
        return true;
    }
}
