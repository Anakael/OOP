#include "attack_handler.h"

namespace game::handlers
{
    attack_handler::attack_handler(units::unit& _unit, common::coordinates _to)
            : unit(_unit), to(_to)
    {
    }

    void attack_handler::handle()
    {
        unit.attack_to(to);
    }
}


