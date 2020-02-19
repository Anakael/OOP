#ifndef LAB1_NEUTRAL_OBJECT_H
#define LAB1_NEUTRAL_OBJECT_H

#include <objects/object.h>
#include "field/neutral_objects/strategies/neutral_object_affect_strategy.h"
#include <memory>


namespace game::units
{
    class unit;
}

namespace game::field::neutral_objects
{
    class neutral_object : public object
    {
    protected:
        std::unique_ptr<strategies::neutral_object_affect_strategy> strategy;
        void set_strategy(strategies::neutral_object_affect_strategy&& _strategy);
    public:
        neutral_object();
        virtual void affect_to_unit(game::units::unit& _unit) = 0;
        ~neutral_object() override;
    };

}

#endif //LAB1_NEUTRAL_OBJECT_H
