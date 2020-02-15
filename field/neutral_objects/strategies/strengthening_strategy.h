#ifndef LAB1_STRENGTHENING_STRATEGY_H
#define LAB1_STRENGTHENING_STRATEGY_H

#include "neutral_object_affect_strategy.h"

namespace game::field::neutral_objects::strategies
{
    class strengthening_strategy : public neutral_object_affect_strategy
    {
    private:
        int armor_point = 3;
    public:
        bool affect_to_unit(game::units::unit &_unit) override;
    };
}

#endif //LAB1_STRENGTHENING_STRATEGY_H
