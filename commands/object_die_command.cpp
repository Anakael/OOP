#include "object_die_command.h"
#include <mediator/mediator.h>

namespace game::commands
{
    object_die_command::object_die_command(game::object& _sender)
            : command(_sender)
    {
    }

    void object_die_command::operator()(field::field& _field)
    {
        _field.delete_object(sender.get_mediator().get_coords(sender));
    }
}


