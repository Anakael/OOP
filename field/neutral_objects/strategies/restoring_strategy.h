#ifndef LAB1_RESTORING_STRATEGY_H
#define LAB1_RESTORING_STRATEGY_H

#include "neutral_object_affect_strategy.h"

namespace game::field::neutral_objects::strategies
{
    class restoring_strategy : public neutral_object_affect_strategy
    {
    private:
        int mana_point = 200;
    public:
        void affect_to_unit(game::units::unit &_unit) override;
    };
}

#endif //LAB1_RESTORING_STRATEGY_H
