#ifndef LAB1_NEUTRAL_OBJECT_H
#define LAB1_NEUTRAL_OBJECT_H

#include "field/neutral_objects/strategies/neutral_object_affect_strategy.h"
#include <memory>

namespace game::units
{
    class unit;
}

namespace game::field::neutral_objects
{
    class neutral_object
    {
    protected:
        std::unique_ptr<strategies::neutral_object_affect_strategy> strategy;
        void set_strategy(strategies::neutral_object_affect_strategy&& _strategy);
    public:
        virtual bool affect_to_unit(game::units::unit& _unit);
        virtual ~neutral_object() = 0;
    };

}

#endif //LAB1_NEUTRAL_OBJECT_H
