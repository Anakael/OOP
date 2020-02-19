#ifndef OOP_CREATE_UNIT_HANDLER_H
#define OOP_CREATE_UNIT_HANDLER_H

#include "handler.h"
#include <objects/base/base.h>
#include <common/coordinates.h>

namespace game::handlers
{
    class create_unit_handler : public handler
    {
    private:
        game::base& base;
        common::coordinates to;
    public:
        create_unit_handler(game::base& _base, common::coordinates _to);

        void handle() override;
    };
}

#endif //OOP_CREATE_UNIT_HANDLER_H
