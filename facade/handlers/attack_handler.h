#ifndef OOP_ATTACK_HANDLER_H
#define OOP_ATTACK_HANDLER_H

#include "handler.h"
#include <objects/units/unit.h>
#include <common/coordinates.h>

namespace game::handlers
{
    class attack_handler : public handler
    {
    private:
        units::unit& unit;
        object& target;
    public:
        attack_handler(units::unit& _unit, object& _target);

        void handle() override;
    };
}

#endif //OOP_ATTACK_HANDLER_H
