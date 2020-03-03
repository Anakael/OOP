#include <objects/units/mages/mage.h>
#include "restoring_strategy.h"
#include <iostream>

namespace game::field::neutral_objects::strategies
{
    void restoring_strategy::operator()(game::units::unit& _unit)
    {
        std::cout << "Can't use this object" << std::endl;
    }

    void restoring_strategy::operator()(game::units::mages::mage& _mage)
    {
        _mage.restore_mana(mana_point);
    }
}
