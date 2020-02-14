#include "water.h"

namespace game::field::landscape
{
    void water::affect_to_unit(game::units::unit_proxy& _unit_proxy)
    {
        _unit_proxy.set_can_move_to(false);
    }
}


