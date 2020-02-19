#include "create_unit_handler.h"

namespace game::handlers
{
    create_unit_handler::create_unit_handler(game::base& _base, common::coordinates _to)
        : base(_base), to(_to)
    {

    }

    void create_unit_handler::handle()
    {
        base.create_unit(to);
    }
}


