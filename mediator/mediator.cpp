#include "mediator.h"
#include <field/field.h>
#include <field/field_iterator.h>

namespace game
{
    mediator::mediator(field::field& _field)
            : field(_field)
    {
        _field.set_mediator(*this);
    }

    void mediator::send(commands::command&& _command)
    {
        _command(field);
    }

    void mediator::send(commands::move_command&& _command)
    {
        _command(field);
        object_coords[&_command.get_sender()] = _command.get_to();
    }

    common::coordinates mediator::get_coords(object& _object)
    {
        return object_coords[&_object];
    }

    void mediator::send(commands::create_object_command&& _command)
    {
        _command(field);
        object_coords[_command.get_new_object().get()] = _command.get_to();
    }

    void mediator::send(commands::object_die_command&& _command)
    {
        _command(field);
        object_coords.erase(&_command.get_sender());
    }
}


