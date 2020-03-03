#ifndef LAB1_RESTORING_STRATEGY_H
#define LAB1_RESTORING_STRATEGY_H

#include "neutral_object_affect_strategy.h"
#include <objects/units/mages/mage.h>

namespace game::field::neutral_objects::strategies
{
    class restoring_strategy : public neutral_object_affect_strategy
    {
    private:
        int mana_point = 200;
    public:
        void operator()(game::units::unit &_unit) override;

        void operator()(game::units::mages::mage& _mage);
    };
}

#endif //LAB1_RESTORING_STRATEGY_H
