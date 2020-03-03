#include "mediator.h"
#include <field/field.h>
#include <field/field_iterator.h>

namespace game
{
    mediator::mediator(field::field& _field)
            : field(_field)
    {
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

    field::cell& mediator::get_cell(common::coordinates _coord)
    {
        return field.get(_coord);
    }

    void mediator::restore()
    {
        object_coords.clear();
        for (int i = 0; i < field.get_length(); ++i)
        {
            for (int j = 0; j < field.get_length(); ++j)
            {
                auto obj = field.get({i, j}).get_object().get();
                obj->set_mediator(*this);
                object_coords[obj] = {i, j};
            }
        }
    }
}


