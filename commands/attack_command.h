#ifndef OOP_ATTACK_COMMAND_H
#define OOP_ATTACK_COMMAND_H

#include "command.h"
#include <common/coordinates.h>

namespace game::commands
{
    class attack_command : public command
    {
    private:
        common::coordinates to;
    public:
        attack_command(object& _sender, common::coordinates _to);
        void operator()(field::field& _field) override;
    };
}

#endif //OOP_ATTACK_COMMAND_H
