#ifndef OOP_OBJECT_DIE_COMMAND_H
#define OOP_OBJECT_DIE_COMMAND_H

#include "command.h"

namespace game::commands
{
    class object_die_command : public command
    {
    public:
        object_die_command(object& _sender);
        void operator()(field::field& _field) override;
    };
}

#endif //OOP_OBJECT_DIE_COMMAND_H
