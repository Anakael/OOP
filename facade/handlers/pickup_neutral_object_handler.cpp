#include "pickup_neutral_object_handler.h"

namespace game::handlers
{
    pickup_neutral_object_handler::pickup_neutral_object_handler(game::units::unit& _unit,
                                                                 game::field::neutral_objects::neutral_object& _target)
            : unit(_unit), target(_target)
    {
    }

    void pickup_neutral_object_handler::handle()
    {
        unit.pick_up_neutral_object(target);
    }
}


