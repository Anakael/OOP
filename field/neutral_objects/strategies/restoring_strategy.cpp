#include <objects/units/mages/mage.h>
#include "restoring_strategy.h"
#include <iostream>

namespace game::field::neutral_objects::strategies
{
    void restoring_strategy::affect_to_unit(game::units::unit& _unit)
    {
        auto* mage = dynamic_cast<game::units::mages::mage*>(&_unit);
        if (mage)
        {
            mage->restore_mana(mana_point);
        }
        else
        {
            std::cout << "Such type of units can't take this" << std::endl;
        }
    }
}
