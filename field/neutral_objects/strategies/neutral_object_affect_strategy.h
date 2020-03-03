#ifndef LAB1_NEUTRAL_OBJECT_AFFECT_STRATEGY_H
#define LAB1_NEUTRAL_OBJECT_AFFECT_STRATEGY_H

namespace game::units
{
    class unit;
}

namespace game::field::neutral_objects::strategies
{
    class neutral_object_affect_strategy
    {
    public:
        virtual void operator()(game::units::unit& _unit) = 0;
        virtual ~neutral_object_affect_strategy();
    };
}

#endif //LAB1_NEUTRAL_OBJECT_AFFECT_STRATEGY_H
