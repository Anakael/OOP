#include "pick_up_neutral_object_command.h"
#include <mediator/mediator.h>

namespace game::commands
{
    pick_up_neutral_object_command::pick_up_neutral_object_command(game::object& sender,
                                                                   game::field::neutral_objects::neutral_object& _neutral_object)
            : command(sender), neutral_object(_neutral_object)
    {

    }

    void pick_up_neutral_object_command::operator()(game::field::field& _field)
    {
        auto unit = dynamic_cast<units::unit*>(&sender);
        neutral_object(*unit);
    }
}


