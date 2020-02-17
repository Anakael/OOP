#include "create_object_command.h"

namespace game::commands
{
    create_object_command::create_object_command(object& _sender, std::shared_ptr<object> _new_object, common::coordinates _to)
            : command(_sender), new_object(std::move(_new_object)), to(_to)
    {
    }

    void create_object_command::operator()(field::field& _field)
    {
        _field.add_object(new_object, to);
    }
}


