#include <objects/units/mages/mage.h>
#include "restoring_strategy.h"
#include <iostream>

namespace game::field::neutral_objects::strategies
{
    void restoring_strategy::affect_to_unit(game::units::unit& _unit)
    {
        std::cout << "Can't use this object" << std::endl;
    }

    void restoring_strategy::affect_to_unit(game::units::mages::mage& _mage)
    {
        _mage.restore_mana(mana_point);
    }
}
