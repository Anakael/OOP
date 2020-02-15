#ifndef LAB1_HEALING_STRATEGY_H
#define LAB1_HEALING_STRATEGY_H

#include "neutral_object_affect_strategy.h"

namespace game::field::neutral_objects::strategies
{
    class healing_strategy : public neutral_object_affect_strategy
    {
    private:
        int heal_point = 200;
    public:
        bool affect_to_unit(game::units::unit &_unit) override;
    };
}


#endif //LAB1_HEALING_STRATEGY_H
