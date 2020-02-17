#ifndef OOP_MOVE_COMMAND_H
#define OOP_MOVE_COMMAND_H

#include "command.h"
#include <common/coordinates.h>

namespace game
{
    class object;
}

namespace game::commands
{
    class move_command : public command
    {
    private:
        common::coordinates to;
    public:
        common::coordinates get_to() const
        { return to; }

        move_command(object& _sender, common::coordinates _to);

        void operator()(field::field& _field) override;
    };
}

#endif //OOP_MOVE_COMMAND_H
