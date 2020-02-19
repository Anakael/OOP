#include "pick_up_neutral_object_command.h"
#include <mediator/mediator.h>
#include <iostream>

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
        if (!unit)
        {
            std::cout << "Sender is not unit" << std::endl;
            return;
        }
        if (sender.get_coords().distance_to(neutral_object.get_coords()) > 1)
        {
            std::cout << "To muck distance" << std::endl;
            return;
        }

        neutral_object.affect_to_unit(*unit);
    }
}


