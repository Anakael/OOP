#ifndef OOP_CREATE_OBJECT_COMMAND_H
#define OOP_CREATE_OBJECT_COMMAND_H

#include "command.h"
#include <memory>
#include <common/coordinates.h>

namespace game::commands
{
    class create_object_command : public command
    {
    private:
        std::shared_ptr<object> new_object;
        common::coordinates to;
    public:
        create_object_command(object& _sender, std::shared_ptr<object> _new_object, common::coordinates _to);

        common::coordinates get_to() const
        { return to; }

        std::shared_ptr<object> get_new_object() const
        { return new_object; }

        void operator()(field::field& _field) override;
    };
}

#endif //OOP_CREATE_OBJECT_COMMAND_H
