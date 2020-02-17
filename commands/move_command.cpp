#include "move_command.h"
#include <field/field.h>
#include <objects/object.h>
#include <mediator/mediator.h>

namespace game::commands
{
    move_command::move_command(object& _sender, common::coordinates _to)
            : command(_sender), to(_to)
    {
    }

    void move_command::operator()(field::field& _field)
    {
        auto from = sender.get_mediator().get_coords(sender);
        _field.move_object(from, to);
    }
}


