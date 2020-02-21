#include "attack_handler.h"

namespace game::handlers
{
    attack_handler::attack_handler(units::unit& _unit, object& _target)
            : unit(_unit), target(_target)
    {
    }

    void attack_handler::handle()
    {
        unit.attack_to(target);
    }
}


