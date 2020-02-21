#ifndef OOP_PICKUP_NEUTRAL_OBJECT_HANDLER_H
#define OOP_PICKUP_NEUTRAL_OBJECT_HANDLER_H

#include "handler.h"
#include <objects/units/unit.h>
#include <field/neutral_objects/neutral_objects/neutral_object.h>

namespace game::handlers
{
    class pickup_neutral_object_handler : public handler
    {
    public:
        units::unit& unit;
        field::neutral_objects::neutral_object& target;
    public:
        pickup_neutral_object_handler(units::unit& _unit, field::neutral_objects::neutral_object& _target);

        void handle() override;
    };
}


#endif //OOP_PICKUP_NEUTRAL_OBJECT_HANDLER_H
