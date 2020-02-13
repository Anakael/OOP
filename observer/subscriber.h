#ifndef LAB1_SUBSCRIBER_H
#define LAB1_SUBSCRIBER_H


#include <objects/units/unit.h>

namespace game
{
    class object;

    class subscriber
    {
    public:
        virtual void update(const units::unit& _object) = 0;
    };
}

#endif //LAB1_SUBSCRIBER_H
