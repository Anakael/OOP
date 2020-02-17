#ifndef OOP_MEDIATOR_H
#define OOP_MEDIATOR_H

#include <vector>
#include <memory>
#include <common/coordinates.h>
#include <commands/command.h>
#include <commands/move_command.h>
#include <commands/create_object_command.h>
#include <commands/object_die_command.h>
#include <map>


namespace game::field
{
    class field;
}

namespace game
{
    class mediator
    {
    private:
        field::field& field;
        std::map<object*, common::coordinates> object_coords;
    public:
        explicit mediator(field::field& _field);

        void send(commands::command&& _command);

        void send(commands::move_command&& _command);

        void send(commands::create_object_command&& _command);

        void send(commands::object_die_command&& _command);

        common::coordinates get_coords(object& _object);
    };
}

#endif //OOP_MEDIATOR_H
