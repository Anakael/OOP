#ifndef LAB1_KILLING_STRATEGY_H
#define LAB1_KILLING_STRATEGY_H

#include "neutral_object_affect_strategy.h"

namespace game::field::neutral_objects::strategies
{
    class killing_strategy : public neutral_object_affect_strategy
    {
        void operator()(game::units::unit &_unit) override;
    };
}


#endif //LAB1_KILLING_STRATEGY_H
