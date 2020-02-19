#include "move_handler.h"

namespace game::handlers
{
    move_handler::move_handler(game::units::unit& _unit, common::coordinates _to)
        : unit(_unit), to(_to)
    {

    }

    void move_handler::handle()
    {
        unit.move_to(to);
    }
}
