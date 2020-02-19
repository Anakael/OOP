#ifndef OOP_MOVE_HANDLER_H
#define OOP_MOVE_HANDLER_H

#include "handler.h"
#include <objects/units/unit.h>
#include <common/coordinates.h>

namespace game::handlers
{
    class move_handler : public handler
    {
    private:
        units::unit& unit;
        common::coordinates to;
    public:
        move_handler(units::unit& _unit, common::coordinates _to);

        void handle() override;
    };
}

#endif //OOP_MOVE_HANDLER_H
